/*
** dependencies.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Tue Apr 26 16:11:14 2016 Arch Kureuil
** Last update Wed Apr 27 11:51:28 2016 Arch Kureuil
*/

#define _GNU_SOURCE
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <gelf.h>
#include "error/error.h"
#include "vector/vector.h"
#include "ftrace-funcall.h"

static void
charp_destroy(char **strp)
{
  free(*strp);
}

static int
ftrace_funcall_dependencies_search_list(const char *list,
					const char *name,
					char **pathp)
{
  char				*entry;
  MANAGED(charp_destroy) char	*listbkp;
  char				*listcpy;
  char				path[PATH_MAX];

  assert(list != NULL);
  assert(name != NULL);
  assert(pathp != NULL);
  if ((listbkp = strdup(list)) == NULL)
    return (error_raise_errno(), -1);
  listcpy = listbkp;
  while ((entry = strsep(&listcpy, ":")) != NULL)
    {
      strcpy(path, entry);
      strcat(path, "/");
      strcat(path, name);
      if (access(path, R_OK) == 0)
	{
	  *pathp = strdup(path);
	  if (*pathp == NULL)
	    return (error_raise_errno(), -1);
	  return (0);
	}
    }
  return (error_raise_ctx(strerror(ENOENT), name), -1);
}

static int
ftrace_funcall_dependencies_find(const char *name,
				 char **pathp)
{
  char	*ldpath;

  assert(name != NULL);
  assert(pathp != NULL);
  if (strchr(name, '/') != NULL)
    {
      if (access(name, R_OK) == 0)
	{
	  *pathp = strdup(name);
	  if (*pathp == NULL)
	    return (error_raise_errno(), -1);
	  return (0);
	}
      return (-1);
    }
  if ((ldpath = secure_getenv("LD_LIBRARY_PATH")) != NULL)
    {
      if (ftrace_funcall_dependencies_search_list(ldpath, name, pathp) == 0)
	return (0);
    }
  return (ftrace_funcall_dependencies_search_list(FTRACE_LDPATH_DEFAULT,
						  name, pathp));
}

static int
ftrace_funcall_dependencies_fetch(GElf_Dyn *dynent,
				  const struct s_ftrace_elf_section *dynstr,
				  struct s_vector *symbols)
{
  int				depfd;
  Elf				*depelf;
  char				*depname;
  MANAGED(charp_destroy) char	*deppath;

  assert(dynent != NULL);
  assert(dynstr != NULL);
  assert(symbols != NULL);
  depname = (char *) dynstr->data->d_buf + dynent->d_un.d_ptr;
  deppath = NULL;
  if (ftrace_funcall_dependencies_find(depname, &deppath))
    return (-1); 
 depfd = open(deppath, O_RDONLY);
  if (depfd == -1)
    return (error_raise_errno_ctx(deppath), -1);
  depelf = elf_begin(depfd, ELF_C_READ, NULL);
  if (depelf == NULL)
    return (error_raise_ctx(elf_errmsg(-1), deppath), -1);
  if (ftrace_funcall_symbols_load(depelf, symbols))
    error_handle("ftrace");
  elf_end(depelf);
  close(depfd);
  return (0);
}

int
ftrace_funcall_dependencies_load(Elf *elf,
				 struct s_ftrace_elf_section *dynamic,
				 struct s_vector *symbols)
{
  struct s_ftrace_elf_section	dynstr;
  GElf_Dyn			dynent;
  size_t			i;

  assert(elf != NULL);
  assert(dynamic != NULL);
  assert(symbols != NULL);
  if (ftrace_funcall_section_load(elf, ".dynstr", &dynstr))
    return (-1);
  i = 0;
  while (true)
    {
      if (gelf_getdyn(dynamic->data, i, &dynent) != &dynent)
	return (error_raise(elf_errmsg(-1)), -1);
      if (dynent.d_tag == DT_NULL)
	break;
      else if (dynent.d_tag == DT_NEEDED)
	{
	  if (ftrace_funcall_dependencies_fetch(&dynent, &dynstr, symbols))
	    error_handle("ftrace");
	}
      i++;
    }
  return (0);
}

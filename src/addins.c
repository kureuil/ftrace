/*
** addins.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Thu Apr 14 13:47:43 2016 Arch Kureuil
** Last update Sat Apr 16 17:48:34 2016 Arch Kureuil
*/

#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include "error/error.h"
#include "array/array.h"
#include "ftrace.h"

int
ftrace_addins_locate(char *buf, size_t bufsize)
{
  pid_t		curpid;
  ssize_t	linked;
  char		*last;
  char		path[17];
  char		exepath[PATH_MAX];

  assert(buf != NULL);
  assert(bufsize != 0);
  curpid = getpid();
  memset(path, 0, sizeof(path));
  if (snprintf(path, sizeof(path), "/proc/%hu/exe", curpid) == -1)
    return (error_raise_errno(), -1);
  linked = readlink(path, exepath, sizeof(exepath) - 1);
  if (linked == -1)
    return (error_raise_errno(), -1);
  exepath[linked] = '\0';
  last = strrchr(exepath, '/');
  *(last + 1) = '\0';
  strcat(exepath, "plugins");
  strncpy(buf, exepath, bufsize - 1);
  buf[bufsize - 1] = '\0';
  return (0);
}

static int
ftrace_addins_scan(const struct dirent *dirent)
{
  size_t	len;

  assert(dirent != NULL);
  len = strlen(dirent->d_name);
  if (strncmp(dirent->d_name,
	      FTRACE_ADDINS_PREFIX, FTRACE_ADDINS_PREFIX_LENGTH))
    return (0);
  if (strcmp(dirent->d_name + len - FTRACE_ADDINS_SUFFIX_LENGTH,
	     FTRACE_ADDINS_SUFFIX))
    return (0);
  return (1);
}

int
ftrace_addins_load_addin(struct s_array *plugins,
			 const char *path,
			 struct dirent *addinent,
			 size_t i)
{
  struct s_ftrace_addin	addin;
  size_t		pathlen;

  pathlen = strlen(path) + strlen(addinent->d_name) + 2;
  addin.path = malloc(pathlen);
  if (addin.path == NULL)
    return (error_raise_errno(), -1);
  strcat(strcat(strcpy(addin.path, path), "/"), addinent->d_name);
  addin.handle = dlopen(addin.path, RTLD_LAZY);
  if (addin.handle == NULL)
    return (error_raise_ctx(dlerror(), addin.path), -1);
  free(addinent);
  if (array_set(plugins, i, &addin))
    return (-1);
  return (0);
}

int
ftrace_addins_load(const char *path, struct s_array *plugins)
{
  struct dirent		**addinsent;
  size_t		addinscount;
  size_t		i;
  int			scanret;

  assert(path != NULL);
  assert(plugins != NULL);
  scanret = scandir(path, &addinsent, &ftrace_addins_scan, alphasort);
  if (scanret == -1)
    return (error_raise_errno(), -1);
  addinscount = (size_t) scanret;
  if (addinscount == 0)
    return (0);
  if (array_init(plugins, addinscount, sizeof(struct s_ftrace_addin)))
    return (error_raise_errno(), -1);
  i = 0;
  while (i < addinscount)
    {
      if (ftrace_addins_load_addin(plugins, path, addinsent[i], i))
	return (-1);
      i++;
    }
  free(addinsent);
  return (0);
}

int
ftrace_addins_unload(struct s_array *plugins)
{
  struct s_ftrace_addin	addin;
  size_t		i;

  assert(plugins != NULL);
  i = 0;
  while (i < plugins->size)
    {
      if (array_get(plugins, i, &addin))
	return (-1);
      free(addin.path);
      if (dlclose(addin.handle))
	return (-1);
      i++;
    }
  array_destroy(plugins);
  return (0);
}

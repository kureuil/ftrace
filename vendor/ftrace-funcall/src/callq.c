/*
** callq.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 17 11:55:54 2016 Arch Kureuil
** Last update Mon Apr 25 18:39:59 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <libelf.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <gelf.h>
#include "vector/vector.h"
#include "error/error.h"
#include "ftrace-funcall.h"
#include "ftrace.h"

static struct s_vector *g_symbols = NULL;

static int
ftrace_funcall_section_fetch(Elf *elf, const char *section, Elf_Scn **scnp)
{
  size_t	shstrndx;
  Elf_Scn	*cursor;
  GElf_Shdr	shdr;
  const char	*sname;

  assert(elf != NULL);
  assert(section != NULL);
  assert(scnp != NULL);
  if (elf_getshdrstrndx(elf, &shstrndx))
    return (error_raise(elf_errmsg(-1)), -1);
  cursor = NULL;
  while ((cursor = elf_nextscn(elf, cursor)) != NULL)
    {
      if (gelf_getshdr(cursor, &shdr) != &shdr)
	return (error_raise(elf_errmsg(-1)), -1);
      sname = elf_strptr(elf, shstrndx, shdr.sh_name);
      if (sname == NULL)
	return (error_raise(elf_errmsg(-1)), -1);
      if (!strcmp(sname, section))
	{
	  *scnp = cursor;
	  return (0);
	}
    }
  return (error_raise_ctx("Section was not found in ELF file", section), -1);
}

static int
ftrace_funcall_section_load(Elf *elf,
			    const char *name,
			    struct s_ftrace_elf_section *section)
{
  assert(elf != NULL);
  assert(name != NULL);
  assert(section != NULL);
  if (ftrace_funcall_section_fetch(elf, name, &section->section))
    return (-1);
  section->data = NULL;
  if ((section->data = elf_getdata(section->section, section->data)) == NULL)
    return (error_raise(elf_errmsg(-1)), -1);
  if (gelf_getshdr(section->section, &section->header) != &section->header)
    return (error_raise(elf_errmsg(-1)), -1);
  return (0);
}

static int
ftrace_funcall_symbols_makesym(struct s_ftrace_elf_symbol *symbol,
			       GElf_Sym *raw,
			       char *name)
{
  assert(symbol != NULL);
  assert(raw != NULL);
  assert(name != NULL);
  memset(symbol, 0, sizeof(*symbol));
  memcpy(&symbol->raw, raw, sizeof(*raw));
  symbol->address = raw->st_value;
  strncpy(symbol->name, name, sizeof(symbol->name) - 1);
  return (0);
}

static int
ftrace_funcall_symbols_fetch(const struct s_ftrace_elf_section *symtab,
			     const struct s_ftrace_elf_section *strtab,
			     size_t i,
			     struct s_vector *symbols)
{
  struct s_ftrace_elf_symbol	symbol;
  GElf_Sym			raw;
  char				*name;

  if (gelf_getsym(symtab->data, i, &raw) != &raw)
    return (error_raise(elf_errmsg(-1)), -1);
  if (GELF_ST_TYPE(raw.st_info) != STT_FUNC || raw.st_value == 0)
    return (0);
  name = (char *) strtab->data->d_buf + raw.st_name;
  ftrace_funcall_symbols_makesym(&symbol, &raw, name);
  fprintf(stderr, "Adding symbol '%s'@%#lx\n", symbol.name, symbol.address);
  vector_push_back(symbols, &symbol);
  return (0);
}

static int
ftrace_funcall_symbols_load(Elf *elf,
			    struct s_vector *symbols)
{
  struct s_ftrace_elf_section	symtab;
  struct s_ftrace_elf_section	strtab;
  size_t			len;
  size_t			i;

  assert(elf != NULL);
  assert(symbols != NULL);
  if (ftrace_funcall_section_load(elf, ".symtab", &symtab))
    return (-1);
  if (ftrace_funcall_section_load(elf, ".strtab", &strtab))
    return (-1);
  len = symtab.header.sh_size / symtab.header.sh_entsize;
  i = 0;
  while (i < len)
    {
      if (ftrace_funcall_symbols_fetch(&symtab, &strtab, i, symbols))
	return (-1);
      i++;
    }
  return (0);
}

static int
ftrace_funcall_dependencies_fetch(GElf_Dyn *dynent,
				  const struct s_ftrace_elf_section *dynstr,
				  struct s_vector *symbols)
{
  int	depfd;
  Elf	*depelf;
  char	deppath[PATH_MAX];

  assert(dynent != NULL);
  assert(dynstr != NULL);
  assert(symbols != NULL);
  strcpy(deppath, "/usr/lib/");
  strcat(deppath, (char *) dynstr->data->d_buf + dynent->d_un.d_ptr);
  if (access(deppath, R_OK))
    return (0);
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

static int
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

static int
ftrace_funcall_symbols_init(const struct s_ftrace_opts *opts)
{
  struct s_ftrace_elf_section	dynamic;

  assert(opts != NULL);
  if (vector_new(&g_symbols, 256, sizeof(struct s_ftrace_elf_symbol)))
    return (-1);
  if (ftrace_funcall_symbols_load(opts->elf, g_symbols))
    error_handle("ftrace");
  if (ftrace_funcall_section_load(opts->elf, ".dynamic", &dynamic))
    return (-1);
  if (ftrace_funcall_dependencies_load(opts->elf, &dynamic, g_symbols))
    return (-1);
  return (0);
}

static int
ftrace_funcall_symbol_get_by_addr(uintptr_t addr,
				  const struct s_vector *symbols,
				  char **namep)
{
  struct s_ftrace_elf_symbol	symbol;
  size_t			i;

  assert(addr != 0);
  assert(symbols != NULL);
  assert(namep != NULL);
  i = 0;
  while (i < symbols->size)
    {
      vector_get(symbols, i, &symbol);
      if (addr == symbol.address)
	{
	  *namep = &symbol.name[0];
	  return (0);
	}
      i++;
    }
  return (-1);
}

int
ftrace_funcall_handler_callq(unsigned long long int value,
			     const struct user_regs_struct *regs,
			     const struct s_ftrace_opts *opts)
{
  unsigned long long int	addr;
  char				*symbol_name;

  assert(regs != NULL);
  assert(opts != NULL);
  if (g_symbols == NULL && ftrace_funcall_symbols_init(opts))
    return (-1);
  ftrace_event_trigger("ftrace:printline-begin", NULL);
  addr = (value >> 8 & 0xffffffff) + regs->rip + 5;
  if (ftrace_funcall_symbol_get_by_addr(addr, g_symbols, &symbol_name))
    {
      fprintf(stderr, "Callq %#llx at %#llx\n", value, addr);
    }
  else
    {
      fprintf(stderr, "Callq %s at %#llx\n", symbol_name, addr);
    }
  return (0);
}

static void __attribute__((destructor))
ftrace_funcall_symbols_destroy()
{
  if (g_symbols != NULL)
    vector_delete(&g_symbols);
}

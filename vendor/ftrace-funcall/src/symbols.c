/*
** symbols.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Tue Apr 26 15:33:08 2016 Arch Kureuil
** Last update Wed Apr 27 12:04:24 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <gelf.h>
#include "error/error.h"
#include "vector/vector.h"
#include "ftrace-funcall.h"

int
ftrace_funcall_symbols_init(const struct s_ftrace_opts *opts,
			    struct s_vector **symbolsp)
{
  struct s_ftrace_elf_section	dynamic;

  assert(opts != NULL);
  assert(symbolsp != NULL);
  if (*symbolsp != NULL)
    return (0);
  if (vector_new(symbolsp, 256, sizeof(struct s_ftrace_elf_symbol)))
    return (-1);
  if (ftrace_funcall_symbols_load(opts->elf, *symbolsp))
    error_handle("ftrace");
  if (ftrace_funcall_section_load(opts->elf, ".dynamic", &dynamic))
    return (-1);
  if (ftrace_funcall_dependencies_load(opts->elf, &dynamic, *symbolsp))
    return (-1);
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
  memset(&symbol, 0, sizeof(symbol));
  memcpy(&symbol.raw, &raw, sizeof(raw));
  symbol.address = raw.st_value;
  strncpy(symbol.name, name, sizeof(symbol.name) - 1);
  fprintf(stderr, "Adding symbol '%s'@%#lx\n", symbol.name, symbol.address);
  vector_push_back(symbols, &symbol);
  return (0);
}

static int
ftrace_funcall_symbols_parse(Elf *elf,
			     const char *symname,
			     const char *strname,
			     struct s_vector *symbols)
{
  struct s_ftrace_elf_section	symtab;
  struct s_ftrace_elf_section	strtab;
  size_t			len;
  size_t			i;

  assert(symname != NULL);
  assert(strname != NULL);
  assert(symbols != NULL);
  if (ftrace_funcall_section_load(elf, symname, &symtab))
    return (-1);
  if (ftrace_funcall_section_load(elf, strname, &strtab))
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

int
ftrace_funcall_symbols_load(Elf *elf,
			    struct s_vector *symbols)
{
  assert(elf != NULL);
  assert(symbols != NULL);
  if (ftrace_funcall_symbols_parse(elf, ".symtab", ".strtab", symbols))
    error_handle("ftrace");
  if (ftrace_funcall_symbols_parse(elf, ".dynsym", ".dynstr", symbols))
    error_handle("ftrace");
  return (0);
}

int
ftrace_funcall_symbols_get_by_addr(uintptr_t addr,
				   const struct s_vector *symbols,
				   char *name)
{
  struct s_ftrace_elf_symbol	symbol;
  size_t			i;

  assert(addr != 0);
  assert(symbols != NULL);
  assert(name != NULL);
  i = 0;
  while (i < symbols->size)
    {
      vector_get(symbols, i, &symbol);
      if (addr == symbol.address)
	{
	  strncpy(name, symbol.name, FTRACE_SYMBOL_MAX_LENGTH - 1);
	  name[FTRACE_SYMBOL_MAX_LENGTH - 1] = '\0';
	  return (0);
	}
      i++;
    }
  return (-1);
}

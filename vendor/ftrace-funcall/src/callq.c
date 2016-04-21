/*
** callq.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 17 11:55:54 2016 Arch Kureuil
** Last update Thu Apr 21 13:15:49 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <libelf.h>
#include <string.h>
#include <stdio.h>
#include <gelf.h>
#include "error/error.h"
#include "ftrace.h"

static Elf_Scn *g_symtab_scn = NULL;
static Elf_Data *g_symtab_data = NULL;
static Elf_Scn *g_strtab_scn = NULL;
static Elf_Data *g_strtab_data = NULL;

static int
ftrace_funcall_fetch_section(Elf *elf, const char *section, Elf_Scn **scnp)
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
ftrace_funcall_init_sections(const struct s_ftrace_opts *opts)
{
  assert(opts != NULL);
  if (g_symtab_scn == NULL)
    {
      if (ftrace_funcall_fetch_section(opts->elf, ".symtab", &g_symtab_scn))
	return (-1);
      if ((g_symtab_data = elf_getdata(g_symtab_scn, g_symtab_data)) == NULL)
	return (error_raise(elf_errmsg(-1)), -1);
    }
  if (g_strtab_scn == NULL)
    {
      if (ftrace_funcall_fetch_section(opts->elf, ".strtab", &g_strtab_scn))
	return (-1);
      if ((g_strtab_data = elf_getdata(g_strtab_scn, g_strtab_data)) == NULL)
	return (error_raise(elf_errmsg(-1)), -1);
    }
  return (0);
}

static int
ftrace_funcall_symbol_get_by_addr(uintptr_t addr, char **namep)
{
  size_t	i;
  size_t	len;
  Elf64_Sym	*cursor;

  assert(addr != 0);
  assert(namep != NULL);
  len = g_symtab_data->d_size / sizeof(Elf64_Sym);
  i = 0;
  while (i < len)
    {
      cursor = (Elf64_Sym *) g_symtab_data->d_buf + i;
      if (addr == (uintptr_t) cursor->st_value)
	{
	  *namep = (char *) g_strtab_data->d_buf + cursor->st_name;
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
  if (ftrace_funcall_init_sections(opts))
    return (-1);
  ftrace_event_trigger("ftrace:printline-begin", NULL);
  addr = (value >> 8 & 0xffffffff) + regs->rip + 5;
  if (ftrace_funcall_symbol_get_by_addr(addr, &symbol_name))
    {
      fprintf(stderr, "Callq %#llx at %#llx\n", value, addr);
    }
  else
    {
      fprintf(stderr, "Callq %s at %#llx\n", symbol_name, addr);
    }
  return (0);
}

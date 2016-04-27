/*
** section.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Tue Apr 26 16:08:52 2016 Arch Kureuil
** Last update Tue Apr 26 16:31:07 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <gelf.h>
#include "error/error.h"
#include "ftrace-funcall.h"

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

int
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

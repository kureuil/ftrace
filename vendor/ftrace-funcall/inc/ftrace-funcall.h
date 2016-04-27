/*
** ftrace-funcall.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 22:25:17 2016 Arch Kureuil
** Last update Wed Apr 27 10:07:02 2016 Arch Kureuil
*/

#ifndef FTRACE_FUNCALL_H_
# define FTRACE_FUNCALL_H_

# include <libelf.h>
# include <stdlib.h>
# include <gelf.h>
# include "ftrace.h"
# include "vector/vector.h"

# define FTRACE_CALLQ_BITMASK		(0xffull)
# define FTRACE_CALLQ_INSTRUCTION	(0xe8ull)

# define FTRACE_RETQ_BITMASK		(0xffull)
# define FTRACE_RETQ_INSTRUCTION	(0xc3ull)

# define FTRACE_SYMBOL_MAX_LENGTH	(256)

# define FTRACE_LDPATH_DEFAULT		("/lib:/lib/x86_64-linux-gnu:/usr/lib:/usr/lib/x86_64-linux-gnu")

struct s_ftrace_elf_section
{
  Elf_Scn	*section;
  Elf_Data	*data;
  GElf_Shdr	header;
};

struct s_ftrace_elf_symbol
{
  GElf_Sym	raw;
  uintptr_t	address;
  char		name[FTRACE_SYMBOL_MAX_LENGTH];
};

/*
** Handle a callq instruction.
**
** @see t_handler
*/
int
ftrace_funcall_handler_callq(unsigned long long int instruction,
			     const struct user_regs_struct *regs,
			     const struct s_ftrace_opts *opts);

/*
** Handle a retq instruction.
**
** @see t_handler
*/
int
ftrace_funcall_handler_retq(unsigned long long int instruction,
			    const struct user_regs_struct *regs,
			    const struct s_ftrace_opts *opts);

/*
** Find all symbols refenrenced in opts->elf & its dependencies.
**
** @param opts The options given to ftrace
** @param symbolsp Pointer to the vector to fill
** @returns 0 in case of success, any other value otherwise
*/
int
ftrace_funcall_symbols_init(const struct s_ftrace_opts *opts,
			    struct s_vector **symbolsp);

/*
** Get a symbol name by its address.
** Fills the name parameter on FTRACE_SYMBOL_MAX_LENGTH characters max.
**
** @param add The address of the symbol
** @param symbols The vector to search in
** @param name The name of the found symbol
** @return 0 if the symbol was found, any other value otherwise
*/
int
ftrace_funcall_symbols_get_by_addr(uintptr_t addr,
				   const struct s_vector *symbols,
				   char *name);
/*
** Load the symbols of an ELF file.
**
** @param elf The ELF file to parse
** @param symbols The vector to fill
** @return 0 in case of success, any other value otherwise
*/
int
ftrace_funcall_symbols_load(Elf *elf,
			    struct s_vector *symbols);

/*
** Load the dependencies for the given ELF file.
**
** @param elf The ELF to parse
** @param dynamic The .dynamic section of the given ELF file
** @param symbols The symbols vector to fill
*/
int
ftrace_funcall_dependencies_load(Elf *elf,
				 struct s_ftrace_elf_section *dynamic,
				 struct s_vector *symbols);

/*
** Load a section from an ELF file by its name.
**
** @param elf The ELF file to search in
** @param name The name of the section to load
** @param section The resulting section
** @return 0 in case of success, any other value otherwise
*/
int
ftrace_funcall_section_load(Elf *elf,
			    const char *name,
			    struct s_ftrace_elf_section *section);

#endif

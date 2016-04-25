/*
** ftrace-funcall.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 22:25:17 2016 Arch Kureuil
** Last update Mon Apr 25 16:53:50 2016 Arch Kureuil
*/

#ifndef FTRACE_FUNCALL_H_
# define FTRACE_FUNCALL_H_

# include <libelf.h>
# include <stdlib.h>
# include <gelf.h>
# include "ftrace.h"

# define FTRACE_CALLQ_BITMASK		(0xffull)
# define FTRACE_CALLQ_INSTRUCTION	(0xe8ull)

# define FTRACE_RETQ_BITMASK		(0xffull)
# define FTRACE_RETQ_INSTRUCTION	(0xc3ull)

# define FTRACE_SYMBOL_MAX_LENGTH	(256)

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

#endif

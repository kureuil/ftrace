/*
** ftrace-funcall.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 22:25:17 2016 Arch Kureuil
** Last update Sun Apr 17 11:58:44 2016 Arch Kureuil
*/

#ifndef FTRACE_FUNCALL_H_
# define FTRACE_FUNCALL_H_

# include "ftrace.h"

# define FTRACE_CALLQ_BITMASK		(0xffull)
# define FTRACE_CALLQ_INSTRUCTION	(0xe8ull)

# define FTRACE_RETQ_BITMASK		(0xffull)
# define FTRACE_RETQ_INSTRUCTION	(0xc3ull)

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

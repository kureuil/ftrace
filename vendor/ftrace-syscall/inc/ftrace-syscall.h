/*
** ftrace-syscall.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 23:17:54 2016 Arch Kureuil
** Last update Sun Apr 17 11:20:08 2016 Arch Kureuil
*/

#ifndef FTRACE_SYSCALL_H_
# define FTRACE_SYSCALL_H_

# include <stdbool.h>
# include <stddef.h>

# define FTRACE_SYSCALL_BITMASK		(0xffffull)
# define FTRACE_SYSCALL_INSTRUCTION	(0x50full)

/*
** Represent a System Call argument
**
** @member custom Use a custom function to print the value
** @member printer Union containing either the type of the value, or the
** function to call to print the value.
*/
struct s_syscall_arg
{
  bool	custom;
  union
  {
    enum e_type	type;
    t_printer	callback;
  }	printer;
};

/*
** Represent a System Call
**
** @member id The syscall id
** @member name The syscall name
** @member noreturn Does the syscall not return to the caller
** @member retval Type of the return value
** @member argc The number of arguments of the syscall
** @member args The arguments description
*/
struct s_syscall
{
  unsigned long long	id;
  const char		*name;
  bool			noreturn;
  enum e_type		retval;
  size_t		argc;
  struct s_syscall_arg	args[FTRACE_SYSCALL_ARGS_MAX];
};

extern struct s_syscall g_syscalls[];

extern bool g_ftrace_syscall_prettify;

void
ftrace_syscall_register_handlers(const char *name, void *data);

/*
** Handle a syscall instruction.
**
** @see t_handler
*/
int
ftrace_syscall_handler(unsigned long long int instruction,
		       const struct user_regs_struct *regs,
		       const struct s_ftrace_opts *opts);

/*
** Print flags given to open(2)
**
** @see t_printer
*/
int
ftrace_print_flags_open(unsigned long long int value,
			pid_t child,
			const struct user_regs_struct *regs,
			const struct s_ftrace_opts *opts);

/*
** Print flags given to stat(2)
**
** @see t_printer
*/
int
ftrace_print_stat_struct(unsigned long long int value,
			 pid_t child,
			 const struct user_regs_struct *regs,
			 const struct s_ftrace_opts *opts);

/*
** Print flags given to mmap(2)
**
** @see t_printer
*/
int
ftrace_print_mmap_flags(unsigned long long int value,
			pid_t child,
			const struct user_regs_struct *regs,
			const struct s_ftrace_opts *opts);

#endif

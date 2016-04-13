/*
** hexa.c for ftrace in /home/kureuil/Work/ftrace/src
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 10 17:22:46 2016 Arch Kureuil
** Last update Wed Apr 13 10:08:48 2016 Arch Kureuil
*/

#include <sys/types.h>
#include <sys/user.h>
#include <stdio.h>
#include "ftrace.h"

int
ftrace_print_hexa(unsigned long long int value,
		  pid_t child,
		  const struct user_regs_struct *regs,
		  const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) regs;
  return (fprintf(opts->output, "0x%llx", value));
}

int
ftrace_print_integer(unsigned long long int value,
		     pid_t child,
		     const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) regs;
  return (fprintf(opts->output, "%d", (int) value));
}

int
ftrace_print_pointer(unsigned long long int value,
		     pid_t child,
		     const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) regs;
  if (value == 0)
    return (fprintf(opts->output, "NULL"));
  else
    return (fprintf(opts->output, "%#llx", value));
}

int
ftrace_print_long(unsigned long long int value,
		  pid_t child,
		  const struct user_regs_struct *regs,
		  const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) regs;
  return (fprintf(opts->output, "%ld", (long) value));
}

int
ftrace_print_ulong(unsigned long long int value,
		   pid_t child,
		   const struct user_regs_struct *regs,
		   const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) regs;
  return (fprintf(opts->output, "%lu", (unsigned long) value));
}


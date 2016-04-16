/*
** hexa.c for ftrace in /home/kureuil/Work/ftrace/src
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 10 17:22:46 2016 Arch Kureuil
** Last update Sat Apr 16 22:21:28 2016 Arch Kureuil
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
  (void) opts;
  return (fprintf(stderr, "0x%llx", value));
}

int
ftrace_print_integer(unsigned long long int value,
		     pid_t child,
		     const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) regs;
  (void) opts;
  return (fprintf(stderr, "%d", (int) value));
}

int
ftrace_print_pointer(unsigned long long int value,
		     pid_t child,
		     const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) opts;
  (void) regs;
  if (value == 0)
    return (fprintf(stderr, "NULL"));
  else
    return (fprintf(stderr, "%#llx", value));
}

int
ftrace_print_long(unsigned long long int value,
		  pid_t child,
		  const struct user_regs_struct *regs,
		  const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) opts;
  (void) regs;
  return (fprintf(stderr, "%ld", (long) value));
}

int
ftrace_print_ulong(unsigned long long int value,
		   pid_t child,
		   const struct user_regs_struct *regs,
		   const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) opts;
  (void) regs;
  return (fprintf(stderr, "%lu", (unsigned long) value));
}


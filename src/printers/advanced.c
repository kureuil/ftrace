/*
** advanced.c for strace in /home/kureuil/Work/strace/src
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 10 17:24:59 2016 Arch Kureuil
** Last update Sat Apr 16 22:21:12 2016 Arch Kureuil
*/

#undef _GNU_SOURCE
#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#include <sys/types.h>
#include <sys/user.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ftrace.h"

int
ftrace_print_flags(unsigned long long int value,
		   size_t size,
		   const struct s_flag *flags,
		   const struct s_ftrace_opts *opts)
{
  size_t	i;
  size_t	j;
  int		printed;
  long long int	cdb;

  (void) opts;
  i = j = 0;
  printed = 0;
  cdb = (long long int) value;
  while (i < size)
    {
      if ((cdb & flags[i].value) == flags[i].value)
	{
	  if (j > 0)
	    printed += fprintf(stderr, "|");
	  printed += fprintf(stderr, "%s", flags[i].name);
	  j++;
	}
      i++;
    }
  return (printed);
}

int
ftrace_print_string(unsigned long long int value,
		    pid_t child,
		    const struct user_regs_struct *regs,
		    const struct s_ftrace_opts *opts)
{
  char	*str;
  int	ret;

  (void) opts;
  (void) regs;
  if (value == 0)
    return (fprintf(stderr, "NULL"));
  else
    {
      str = NULL;
      ftrace_peek_string(child, value, &str);
      ret = fprintf(stderr, "\"%s\"", str);
      free(str);
      return (ret);
    }
}

int
ftrace_print_errno(unsigned long long int value,
		   pid_t child,
		   const struct user_regs_struct *regs,
		   const struct s_ftrace_opts *opts)
{
  int	errnum;
  char	msg[128];

  (void) opts;
  (void) child;
  (void) regs;
  errnum = (int) value;
  if (errnum >= 0)
    return (0);
  errnum *= -1;
  memset(msg, 0, sizeof(msg));
  if (strerror_r(errnum, msg, sizeof(msg) - 1))
    return (0);
  return (fprintf(stderr, " %s", msg));
}

int
ftrace_print_size_t(unsigned long long int value,
		    pid_t child,
		    const struct user_regs_struct *regs,
		    const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) regs;
  (void) opts;
  return (fprintf(stderr, "%zu", (size_t) value));
}

int
ftrace_print_ssize_t(unsigned long long int value,
		     pid_t child,
		     const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) opts;
  (void) regs;
  return (fprintf(stderr, "%zu", (ssize_t) value));
}

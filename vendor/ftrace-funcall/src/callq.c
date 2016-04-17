/*
** callq.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 17 11:55:54 2016 Arch Kureuil
** Last update Sun Apr 17 11:57:19 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "ftrace.h"

int
ftrace_funcall_handler_callq(unsigned long long int value,
			     const struct user_regs_struct *regs,
			     const struct s_ftrace_opts *opts)
{
  assert(regs != NULL);
  assert(opts != NULL);
  ftrace_event_trigger("ftrace:printline-begin", NULL);
  fprintf(stderr, "Callq %#llx\n", value);
  return (0);
}

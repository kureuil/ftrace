/*
** retq.c<2> for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 17 11:56:52 2016 Arch Kureuil
** Last update Sun Apr 17 11:57:14 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "ftrace.h"

int
ftrace_funcall_handler_retq(unsigned long long int instruction,
			    const struct user_regs_struct *regs,
			    const struct s_ftrace_opts *opts)
{
  assert(regs != NULL);
  assert(opts != NULL);
  ftrace_event_trigger("ftrace:printline-begin", NULL);
  fprintf(stderr, "Retq %#llx\n", instruction);
  return (0);
}

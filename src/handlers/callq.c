/*
** callq.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Wed Apr 13 10:35:21 2016 Arch Kureuil
** Last update Wed Apr 13 10:46:38 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include "ftrace.h"

int
ftrace_handler_callq(const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts)
{
  assert(regs != NULL);
  assert(opts != NULL);
  fprintf(opts->output, "Callq\n");
  return (0);
}

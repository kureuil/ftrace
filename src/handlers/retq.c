/*
** retq.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Wed Apr 13 10:44:26 2016 Arch Kureuil
** Last update Thu Apr 14 09:36:29 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include "ftrace.h"

int
ftrace_handler_retq(unsigned long long int instruction,
		    const struct user_regs_struct *regs,
		    const struct s_ftrace_opts *opts)
{
  assert(regs != NULL);
  assert(opts != NULL);
  fprintf(opts->output, "Retq %#llx\n", instruction);
  return (0);
}

/*
** prettify.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 11:43:53 2016 Arch Kureuil
** Last update Mon Apr 11 11:53:03 2016 Arch Kureuil
*/

#include <assert.h>
#include "ftrace.h"

int
ftrace_option_prettify(const char *arg,
		       struct s_ftrace_opts *opts)
{
  assert(opts != NULL);
  (void) arg;
  opts->prettify = true;
  return (0);
}

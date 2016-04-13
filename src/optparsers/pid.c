/*
** pid.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 11:41:28 2016 Arch Kureuil
** Last update Mon Apr 11 11:52:53 2016 Arch Kureuil
*/

#include <errno.h>
#include <assert.h>
#include <stdlib.h>
#include "ftrace.h"

int
ftrace_option_pid(const char *arg,
		  struct s_ftrace_opts *opts)
{
  assert(arg != NULL);
  assert(opts != NULL);
  errno = 0;
  opts->pid = (pid_t) strtol(arg, NULL, 10);
  if (errno)
    return (-1);
  if (opts->pid <= 0)
    {
      errno = EINVAL;
      return (-1);
    }
  return (0);
}

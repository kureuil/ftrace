/*
** timestamp.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 11:48:33 2016 Arch Kureuil
** Last update Mon Apr 11 11:53:52 2016 Arch Kureuil
*/

#include <assert.h>
#include <errno.h>
#include "ftrace.h"

int
ftrace_option_timestamp(const char *arg,
			struct s_ftrace_opts *opts)
{
  assert(opts != NULL);
  (void) arg;
  if (opts->timestamp_type == TS_NONE)
    opts->timestamp_type = TS_TIME;
  else if (opts->timestamp_type == TS_TIME)
    opts->timestamp_type = TS_MILLISECOND;
  else
    {
      errno = EINVAL;
      return (-1);
    }
  return (0);
}

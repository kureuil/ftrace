/*
** file.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 11:45:00 2016 Arch Kureuil
** Last update Mon Apr 11 11:53:33 2016 Arch Kureuil
*/

#include <assert.h>
#include "ftrace.h"

static int
ftrace_option_file_command(const char *arg,
			   struct s_ftrace_opts *opts)
{
  opts->output = popen(arg + 1, "w");
  if (opts->output == NULL)
    return (-1);
  opts->output_type = O_COMMAND;
  return (0);
}

static int
ftrace_option_file_path(const char *arg,
			struct s_ftrace_opts *opts)
{
  opts->output = fopen(arg, "w+");
  if (opts->output == NULL)
    return (-1);
  opts->output_type = O_FILE;
  return (0);
}

int
ftrace_option_file(const char *arg,
		   struct s_ftrace_opts *opts)
{
  assert(arg != NULL);
  assert(opts != NULL);
  if (arg[0] == '|' || arg[0] == '!')
    return (ftrace_option_file_command(arg, opts));
  return (ftrace_option_file_path(arg, opts));
}

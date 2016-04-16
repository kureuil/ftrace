/*
** main.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 09:47:02 2016 Arch Kureuil
** Last update Sat Apr 16 20:13:31 2016 Arch Kureuil
*/

#include <sys/ptrace.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "error/error.h"
#include "ftrace.h"
#include "optparser.h"

static void
opts_init(struct s_ftrace_opts *opts)
{
  opts->pid = 0;
  opts->command = NULL;
  opts->prettify = false;
  opts->output = stderr;
  opts->output_type = O_INNATE;
  opts->timestamp_type = TS_NONE;
}

static void
opts_destroy(struct s_ftrace_opts *opts)
{
  free(opts->command);
  if (opts->output_type == O_FILE)
    fclose(opts->output);
  else if (opts->output_type == O_COMMAND)
    pclose(opts->output);
}

static int
exec(struct s_ftrace_opts *opts)
{
  pid_t	pid;

  if (opts->command != NULL)
    {
      pid = fork();
      if (pid == -1)
	return (error_raise_errno(), -1);
      else if (pid == 0)
	{
	  if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1)
	    return (error_raise_errno(), -1);
	  execvp(opts->command[0], opts->command);
	  return (error_raise_errno(), -1);
	}
      opts->pid = pid;
    }
  else
    {
      if (ptrace(PTRACE_ATTACH, opts->pid, 0, 0) == -1)
	return (error_raise_errno(), -1);
    }
  return (0);
}

int
main(int argc, char **argv)
{
  MANAGED(ftrace_addins_unload) struct s_array	plugins;
  MANAGED(opts_destroy) struct s_ftrace_opts	opts;
  char						addinspath[PATH_MAX];

  opts_init(&opts);
  memset(&plugins, 0, sizeof(plugins));
  if (ftrace_addins_locate(addinspath, sizeof(addinspath)))
    return (error_handle(argv[0]), EXIT_FAILURE);
  if (ftrace_addins_load(addinspath, &plugins))
    return (error_handle(argv[0]), EXIT_FAILURE);
  ftrace_event_trigger("optparser:register", NULL);
  if (argc == 1 || optparser(argc, argv, &opts))
    {
      optparser_print_usage(argv[0]);
      return (EXIT_FAILURE);
    }
  if (opts.pid == 0 && opts.command == NULL)
    return (error_handle(argv[0]), EXIT_FAILURE);
  if (exec(&opts))
    return (error_handle(argv[0]), EXIT_FAILURE);
  ftrace_event_trigger("ftrace:trace-start", NULL);
  if (ftrace(&opts))
    return (error_handle(argv[0]), EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

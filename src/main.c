/*
** main.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 09:47:02 2016 Arch Kureuil
** Last update Tue Apr 12 09:47:44 2016 Arch Kureuil
*/

#include <sys/ptrace.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ftrace.h"
#include "optparser.h"

static void
usage(FILE *stream, const char *prgm)
{
  fprintf(stream, "\nUSAGE: %s [OPTIONS...] COMMAND [ARGS]\n\n", prgm);
  fprintf(stream, "OPTIONS:\n");
  fprintf(stream, "\t-s       Prettify output of syscalls\n");
  fprintf(stream, "\t-p PID   Trace program with id = PID instead of launching"
	  " COMMAND\n");
  fprintf(stream, "\t-f FILE  Write ftrace output to FILE (default=stderr)\n");
  fprintf(stream, "\t-t       Print a timestamp before every output. If twice"
	  ", include milliseconds in timestamp.\n");
  fprintf(stream, "\tCOMMAND  Program to execute & trace\n");
  fprintf(stream, "\tARGS     Arguments given to the executed program\n");
}

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
	return (-1);
      else if (pid == 0)
	{
	  if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1)
	    return (-1);
	  execvp(opts->command[0], opts->command);
	  return (-1);
	}
      opts->pid = pid;
    }
  else
    {
      if (ptrace(PTRACE_ATTACH, opts->pid, 0, 0) == -1)
	return (-1);
    }
  return (0);
}

int
main(int argc, char **argv)
{
  MANAGED(opts_destroy) struct s_ftrace_opts	opts;

  opts_init(&opts);
  if (argc == 1 || optparser(argc, argv, &opts))
    {
      usage(stderr, argv[0]);
      return (EXIT_FAILURE);
    }
  if (opts.pid == 0 && opts.command == NULL)
    {
      usage(stderr, argv[0]);
      return (EXIT_FAILURE);
    }
  if (exec(&opts))
    {
      perror(argv[0]);
      return (EXIT_FAILURE);
    }
  if (ftrace(&opts))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

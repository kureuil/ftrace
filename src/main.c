/*
** main.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 09:47:02 2016 Arch Kureuil
** Last update Thu Apr 21 12:28:54 2016 Arch Kureuil
*/

#include <sys/ptrace.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "error/error.h"
#include "ftrace.h"
#include "optparser.h"

static struct s_ftrace_opts g_ftrace_opts = {
  .pid = 0,
  .command = NULL,
};

static void
opts_destroy()
{
  if (ftrace_elf_close(&g_ftrace_opts))
    {
      error_handle("ftrace");
      return ;
    }
  free(g_ftrace_opts.command);
}

static int
ftrace_option_pid(const char *arg)
{
  assert(arg != NULL);
  errno = 0;
  g_ftrace_opts.pid = (pid_t) strtol(arg, NULL, 10);
  if (errno)
    return (error_raise_errno(), -1);
  if (g_ftrace_opts.pid <= 0)
    {
      error_raise("Invalid process ID");
      return (-1);
    }
  return (0);
}

static const struct s_option g_ftrace_pid_option = {
  .flag = 'p',
  .has_value = true,
  .callback = &ftrace_option_pid,
  .argname = "PID",
  .help = "Trace process whose id is PID instead of launching COMMAND"
};

int
main(int argc, char **argv)
{
  MANAGED(ftrace_addins_unload) struct s_array	plugins;
  char						addinspath[PATH_MAX];

  atexit(opts_destroy);
  memset(&plugins, 0, sizeof(plugins));
  if (ftrace_addins_locate(addinspath, sizeof(addinspath)))
    return (error_handle(argv[0]), EXIT_FAILURE);
  if (ftrace_addins_load(addinspath, &plugins))
    return (error_handle(argv[0]), EXIT_FAILURE);
  optparser_register(&g_ftrace_pid_option);
  ftrace_event_trigger("optparser:register", NULL);
  if (argc == 1 || optparser(argc, argv, &g_ftrace_opts))
    {
      optparser_print_usage(argv[0]);
      return (EXIT_FAILURE);
    }
  if (g_ftrace_opts.pid == 0 && g_ftrace_opts.command == NULL)
    return (error_handle(argv[0]), EXIT_FAILURE);
  if (ftrace_exec(&g_ftrace_opts))
    return (error_handle(argv[0]), EXIT_FAILURE);
  ftrace_event_trigger("ftrace:trace-start", NULL);
  if (ftrace(&g_ftrace_opts))
    return (error_handle(argv[0]), EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

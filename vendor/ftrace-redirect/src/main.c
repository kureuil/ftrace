/*
** main.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 13:14:41 2016 Arch Kureuil
** Last update Sat Apr 16 20:43:06 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "error/error.h"
#include "ftrace.h"
#include "optparser.h"

static FILE *g_output = NULL;
static enum e_output_type g_output_type = O_INNATE;

static int
ftrace_redirect_option(const char *arg)
{
  assert(arg != NULL);
  if (arg[0] == '|' || arg[0] == '!')
    {
      g_output = popen(arg + 1, "w");
      if (g_output == NULL)
	return (error_raise_errno(), -1);
      g_output_type = O_COMMAND;
      return (0);
    }
  g_output = fopen(arg, "w+");
  if (g_output == NULL)
    return (error_raise_errno(), -1);
  g_output_type = O_FILE;
  return (0);
}

static const struct s_option g_redirect_option = {
  .flag = 'f',
  .has_value = true,
  .callback = &ftrace_redirect_option,
  .argname = "FILE",
  .help = "Write ftrace output to FILE (default=stderr)",
};

static void
ftrace_redirect_register(const char *name, void *data)
{
  assert(name != NULL);
  (void) data;
  optparser_register(&g_redirect_option);
}

static void
ftrace_redirect_dup(const char *name, void *data)
{
  assert(name != NULL);
  (void) data;
  if (g_output_type != O_INNATE)
    {
      fflush(stderr);
      dup2(fileno(g_output), STDERR_FILENO);
      if (g_output_type == O_FILE)
	fclose(g_output);
    }
}

int __attribute__((constructor))
ftrace_redirect_start(void)
{
  ftrace_event_listen("optparser:register", &ftrace_redirect_register);
  ftrace_event_listen("ftrace:trace-start", &ftrace_redirect_dup);
  return (0);
}

int __attribute__((destructor))
ftrace_redirect_exit(void)
{
  return (0);
}

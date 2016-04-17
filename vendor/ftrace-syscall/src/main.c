/*
** main.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 13:14:41 2016 Arch Kureuil
** Last update Sun Apr 17 11:19:43 2016 Arch Kureuil
*/

#include <stdio.h>
#include "optparser.h"
#include "ftrace.h"
#include "ftrace-syscall.h"

bool g_ftrace_syscall_prettify = false;

static int
ftrace_syscall_prettify(const char *arg)
{
  (void) arg;
  g_ftrace_syscall_prettify = true;
  return (0);
}

static const struct s_option g_syscall_option = {
  .flag = 's',
  .has_value = false,
  .callback = &ftrace_syscall_prettify,
  .argname = "",
  .help = "Prettify output of syscalls"
};

static void
ftrace_syscall_register_opts(const char *name, void *data)
{
  (void) name;
  (void) data;
  optparser_register(&g_syscall_option);
}

int __attribute__((constructor))
ftrace_start(void)
{
  ftrace_event_listen("optparser:register", &ftrace_syscall_register_opts);
  ftrace_event_listen("ftrace:handlers-register",
		      &ftrace_syscall_register_handlers);
  return (0);
}

int __attribute__((destructor))
ftrace_exit(void)
{
  return (0);
}

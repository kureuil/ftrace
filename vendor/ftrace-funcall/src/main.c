/*
** main.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 13:14:41 2016 Arch Kureuil
** Last update Mon Apr 18 17:20:14 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "error/error.h"
#include "ftrace-funcall.h"
#include "ftrace.h"
#include "optparser.h"

static const struct s_ftrace_handler g_ftrace_callq_handler = {
  .bitmask = FTRACE_CALLQ_BITMASK,
  .instruction = FTRACE_CALLQ_INSTRUCTION,
  .callback = &ftrace_funcall_handler_callq,
};

static const struct s_ftrace_handler g_ftrace_retq_handler = {
  .bitmask = FTRACE_RETQ_BITMASK,
  .instruction = FTRACE_RETQ_INSTRUCTION,
  .callback = &ftrace_funcall_handler_retq,
};

static void
ftrace_funcall_register(const char *name, void *data)
{
  assert(name != NULL);
  (void) data;
  ftrace_handlers_register(&g_ftrace_callq_handler);
  ftrace_handlers_register(&g_ftrace_retq_handler);
}

int __attribute__((constructor))
ftrace_redirect_start(void)
{
  ftrace_event_listen("ftrace:handlers-register", &ftrace_funcall_register);
  return (0);
}

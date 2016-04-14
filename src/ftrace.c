/*
** ftrace.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Tue Apr 12 09:42:43 2016 Arch Kureuil
** Last update Thu Apr 14 09:33:04 2016 Arch Kureuil
*/

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdlib.h>
#include "ftrace.h"

static const struct s_ftrace_handler g_handlers[] = {
  {
    .bitmask = FTRACE_SYSCALL_BITMASK,
    .instruction = FTRACE_SYSCALL_INSTRUCTION,
    .callback = &ftrace_handler_syscall,
  },
  {
    .bitmask = FTRACE_CALLQ_BITMASK,
    .instruction = FTRACE_CALLQ_INSTRUCTION,
    .callback = &ftrace_handler_callq,
  },
  {
    .bitmask = FTRACE_RETQ_BITMASK,
    .instruction = FTRACE_RETQ_INSTRUCTION,
    .callback = &ftrace_handler_retq,
  },
  {
    .bitmask = 0ull,
    .instruction = 0ull,
    .callback = NULL,
  },
};

static int
handler_get(long instruction,
	    struct s_ftrace_handler *handler)
{
  size_t	i;

  assert(handler != NULL);
  i = 0;
  while (g_handlers[i].callback != NULL)
    {
      if ((instruction & g_handlers[i].bitmask) == g_handlers[i].instruction)
	{
	  *handler = g_handlers[i];
	  return (0);
	}
      i++;
    }
  return (-1);
}

int
ftrace(const struct s_ftrace_opts *opts)
{
  int				status;
  struct user_regs_struct	regs;
  long				curinst;
  struct s_ftrace_handler	handler;

  if (waitpid(opts->pid, &status, 0) == -1)
    return (-1);
  while (WIFSTOPPED(status))
    {
      if (ftrace_peek_registers(opts->pid, &regs))
	return (-1);
      if (ftrace_peek_instruction(opts->pid, &regs, &curinst))
	return (-1);
      if (!handler_get(curinst, &handler))
	{
	  status = handler.callback(curinst, &regs, opts);
	  if (status)
	    return (status < 0 ? -1 : 0);
	}
      if (ptrace(PTRACE_SINGLESTEP, opts->pid, 0, 0) == -1)
	return (-1);
      if (waitpid(opts->pid, &status, 0) == -1)
	return (-1);
    }
  return (0);
}

/*
** ftrace.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Tue Apr 12 09:42:43 2016 Arch Kureuil
** Last update Wed Apr 27 10:13:47 2016 
*/

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdlib.h>
#include "vector/vector.h"
#include "ftrace.h"

static struct s_vector g_handlers;

static int
ftrace_handlers_dispatch(long instruction,
			 struct user_regs_struct *regs,
			 const struct s_ftrace_opts *opts)
{
  size_t			i;
  struct s_ftrace_handler	handler;
  int				status;

  i = 0;
  while (i < g_handlers.size)
    {
      if (vector_get(&g_handlers, i, &handler))
	return (-1);
      if ((instruction & handler.bitmask) == handler.instruction)
	{
	  status = handler.callback(instruction, regs, opts);
	  if (status)
	    return (status);
	}
      i++;
    }
  return (0);
}

int
ftrace_handlers_register(const struct s_ftrace_handler *handler)
{
  assert(handler != NULL);
  if (g_handlers.capacity == 0)
    {
      if (vector_init(&g_handlers, 16, sizeof(struct s_ftrace_handler)))
	return (-1);
    }
  return (vector_push_back(&g_handlers, handler));
}

int
ftrace(const struct s_ftrace_opts *opts)
{
  int				status;
  struct user_regs_struct	regs;
  long				curinst;

  ftrace_event_trigger("ftrace:handlers-register", NULL);
  if (waitpid(opts->pid, &status, 0) == -1)
    return (-1);
  while (WIFSTOPPED(status))
    {
      if (ftrace_peek_registers(opts->pid, &regs))
	return (-1);
      if (ftrace_peek_instruction(opts->pid, &regs, &curinst))
	return (-1);
      status = ftrace_handlers_dispatch(curinst, &regs, opts);
      if (status)
	return (status < 0 ? -1 : 0);
      if (ptrace(PTRACE_SINGLESTEP, opts->pid, 0, 0) == -1)
	return (-1);
      if (waitpid(opts->pid, &status, 0) == -1)
	return (-1);
    }
  return (0);
}

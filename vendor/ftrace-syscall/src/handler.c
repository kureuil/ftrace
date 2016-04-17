/*
** syscall.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Tue Apr 12 11:47:22 2016 Arch Kureuil
** Last update Sun Apr 17 11:19:06 2016 Arch Kureuil
*/

#include <sys/ptrace.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "ftrace.h"
#include "ftrace-syscall.h"

static const t_printer g_printers[] = {
  &ftrace_print_hexa,
  &ftrace_print_integer,
  &ftrace_print_pointer,
  &ftrace_print_string,
  &ftrace_print_long,
  &ftrace_print_ulong,
  &ftrace_print_size_t,
  &ftrace_print_ssize_t,
  NULL
};

static int
ftrace_syscall_get_by_id(unsigned long long id, struct s_syscall *scallp)
{
  size_t	i;

  i = 0;
  while (g_syscalls[i].name != NULL)
    {
      if (g_syscalls[i].id == id)
	{
	  *scallp = g_syscalls[i];
	  return (0);
	}
      i++;
    }
  return (-1);
}

static int
ftrace_syscall_print_call(const struct s_syscall *scall,
			  const struct user_regs_struct *regs,
			  const struct s_ftrace_opts *opts)
{
  size_t			i;
  unsigned long long int	value;

  ftrace_event_trigger("ftrace:printline-begin", NULL);
  fprintf(stderr, "%s(", scall->name);
  i = 0;
  while (i < scall->argc)
    {
      if (i != 0)
	fprintf(stderr, ", ");
      value = ftrace_registers_get_by_idx(regs, i);
      if (g_ftrace_syscall_prettify)
	{
	  if (scall->args[i].custom)
	    scall->args[i].printer.callback(value, opts->pid, regs, opts);
	  else
	    g_printers[scall->args[i].printer.type](value, opts->pid,
						    regs, opts);
	}
      else
	ftrace_print_hexa(value, opts->pid, regs, opts);
      i++;
    }
  return (0);
}

static int
ftrace_syscall_print_return(const struct s_syscall *scall,
			    const struct user_regs_struct *regs,
			    const struct s_ftrace_opts *opts)
{
  long long	filtered;

  if (!scall->noreturn)
    {
      fprintf(stderr, ") = ");
      if (g_ftrace_syscall_prettify)
	{
	  filtered = ((long long) regs->rax < 0) ?
	    (unsigned long long) -1 : regs->rax;
	  g_printers[scall->retval](filtered, opts->pid, regs, opts);
	  ftrace_print_errno(regs->rax, opts->pid, regs, opts);
	}
      else
	ftrace_print_hexa(regs->rax, opts->pid, regs, opts);
      fprintf(stderr, "\n");
    }
  else
    {
      fprintf(stderr, ") = ?\n");
    }
  return (0);
}

int
ftrace_syscall_handler(unsigned long long int instruction,
		       const struct user_regs_struct *regs,
		       const struct s_ftrace_opts *opts)
{
  int				status;
  struct user_regs_struct	registers;
  struct s_syscall		scall;

  assert(regs != NULL);
  assert(opts != NULL);
  (void) instruction;
  if (ftrace_syscall_get_by_id(regs->rax, &scall))
    return (0);
  ftrace_syscall_print_call(&scall, regs, opts);
  if (ptrace(PTRACE_SINGLESTEP, opts->pid, 0, 0) == -1)
    return (-1);
  wait(&status);
  if (!scall.noreturn)
    {
      if (ftrace_peek_registers(opts->pid, &registers))
	return (-1);
    }
  ftrace_syscall_print_return(&scall, &registers, opts);
  if (!WIFSTOPPED(status))
    {
      fprintf(stderr, "+++ exited with %d +++\n", WEXITSTATUS(status));
      return (1);
    }
  return (0);
}

static const struct s_ftrace_handler g_ftrace_syscall_handler = {
  .bitmask = FTRACE_SYSCALL_BITMASK,
  .instruction = FTRACE_SYSCALL_INSTRUCTION,
  .callback = &ftrace_syscall_handler,
};

void
ftrace_syscall_register_handlers(const char *name, void *data)
{
  (void) name;
  (void) data;
  ftrace_handlers_register(&g_ftrace_syscall_handler);
}

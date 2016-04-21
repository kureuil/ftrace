/*
** exec.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Thu Apr 21 12:20:11 2016 Arch Kureuil
** Last update Thu Apr 21 12:55:46 2016 Arch Kureuil
*/

#include <sys/ptrace.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "error/error.h"
#include "ftrace.h"

static int
ftrace_exec_fork(struct s_ftrace_opts *opts)
{
  opts->pid = fork();
  if (opts->pid == -1)
    return (error_raise_errno(), -1);
  else if (opts->pid == 0)
    {
      if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1)
	return (error_raise_errno(), -1);
      execvp(opts->command[0], opts->command);
      return (error_raise_errno_ctx(opts->command[0]), -1);
    }
  return (0);
}

static int
ftrace_exec_attach(struct s_ftrace_opts *opts)
{
  if (ptrace(PTRACE_ATTACH, opts->pid, 0, 0) == -1)
    return (error_raise_errno(), -1);
  return (0);
}

int
ftrace_exec(struct s_ftrace_opts *opts)
{
  char	path[PATH_MAX];

  assert(opts != NULL);
  if (opts->command != NULL)
    {
      if (ftrace_exec_fork(opts))
	return (-1);
      if (ftrace_elf_get_executable_path(opts->command[0], path, sizeof(path)))
	return (-1);
    }
  else
    {
      if (ftrace_exec_attach(opts))
	return (-1);
      if (ftrace_elf_get_pid_path(opts->pid, path, sizeof(path)))
	return (-1);
    }
  if (ftrace_elf_open(path, opts))
    return (-1);
  return (0);
}

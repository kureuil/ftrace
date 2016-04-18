/*
** elf.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 18 11:00:07 2016 Arch Kureuil
** Last update Mon Apr 18 11:54:48 2016 Arch Kureuil
*/

#include <sys/types.h>
#include <libelf.h>
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>
#include <elf.h>
#include "error/error.h"
#include "ftrace.h"

static int
ftrace_elf_get_executable_path(pid_t pid, char *buf, size_t bufsize)
{
  char		path[32];
  ssize_t	linked;

  assert(pid != 0);
  assert(buf != NULL);
  assert(bufsize != 0);
  memset(path, 0, sizeof(path));
  if (snprintf(path, sizeof(path), "/proc/%d/exe", pid) == -1)
    return (error_raise_errno(), -1);
  linked = readlink(path, buf, bufsize - 1);
  if (linked == -1)
    return (error_raise_errno(), -1);
  buf[linked] = '\0';
  return (0);
}

int
ftrace_elf_open(pid_t pid, struct s_ftrace_opts *opts)
{
  char	exepath[PATH_MAX];

  assert(pid != 0);
  assert(opts != NULL);
  if (elf_version(EV_CURRENT) == EV_NONE)
    return (error_raise(elf_errmsg(-1)), -1);
  if (ftrace_elf_get_executable_path(pid, exepath, sizeof(exepath)))
    return (-1);
  opts->elf_fd = open(exepath, O_RDONLY);
  if (opts->elf_fd == -1)
    return (error_raise_errno(), -1);
  opts->elf = elf_begin(opts->elf_fd, ELF_C_READ, NULL);
  if (opts->elf == NULL)
    return (error_raise_ctx(exepath, elf_errmsg(-1)), -1);
  return (0);
}

int
ftrace_elf_close(const struct s_ftrace_opts *opts)
{
  assert(opts != NULL);
  elf_end(opts->elf);
  close(opts->elf_fd);
  return (0);
}

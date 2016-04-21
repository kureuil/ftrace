/*
** elf.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 18 11:00:07 2016 Arch Kureuil
** Last update Thu Apr 21 14:55:50 2016 Arch Kureuil
*/

#include <sys/types.h>
#include <libelf.h>
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <elf.h>
#include "error/error.h"
#include "ftrace.h"

int
ftrace_elf_get_pid_path(pid_t pid, char *buf, size_t bufsize)
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
  printf("Opening '%s' for (%d)\n", buf, pid);
  return (0);
}

static char *
safe_strncpy(char *dest, const char *src, size_t n)
{
  size_t	i;

  i = 0;
  while (src[i] && i < (n -1))
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int
ftrace_elf_get_executable_path(const char *cmd, char *buf, size_t bufsize)
{
  char	*path;
  char	*pentry;

  assert(cmd != NULL);
  assert(buf != NULL);
  assert(bufsize != 0);
  if (!access(cmd, X_OK))
    {
      safe_strncpy(buf, cmd, bufsize);
      return (0);
    }
  else if (strchr(cmd, '/') != NULL)
    return (error_raise_ctx(strerror(ENOENT), cmd), -1);
  path = getenv("PATH");
  if (path == NULL || strlen(path) == 0)
    return (error_raise_ctx("No such value in environment", "PATH"), -1);
  while ((pentry = strsep(&path, ":")) != NULL)
    {
      safe_strncpy(buf, pentry, bufsize);
      strncat(buf, "/", bufsize - strlen(pentry));
      strncat(buf, cmd, bufsize - strlen(pentry) - 1);
      if (!access(buf, X_OK))
	return (0);
    }
  return (error_raise_ctx(strerror(ENOENT), cmd), -1);
}

int
ftrace_elf_open(const char *path, struct s_ftrace_opts *opts)
{
  assert(path != NULL);
  assert(opts != NULL);
  if (elf_version(EV_CURRENT) == EV_NONE)
    return (error_raise(elf_errmsg(-1)), -1);
  opts->elf_fd = open(path, O_RDONLY);
  if (opts->elf_fd == -1)
    return (error_raise_errno(), -1);
  opts->elf = elf_begin(opts->elf_fd, ELF_C_READ, NULL);
  if (opts->elf == NULL)
    return (error_raise_ctx(elf_errmsg(-1), path), -1);
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

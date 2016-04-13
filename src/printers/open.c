/*
** open.c for ftrace in /home/kureuil/Work/ftrace/src
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 10 17:35:04 2016 Arch Kureuil
** Last update Tue Apr 12 12:14:32 2016 Arch Kureuil
*/

#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/types.h>
#include "ftrace.h"

static const struct s_flag g_open_flags[] = {
  { .value = O_APPEND, .name = "O_APPEND" },
  { .value = O_ASYNC, .name = "O_ASYNC" },
  { .value = O_CLOEXEC, .name = "O_CLOEXEC" },
  { .value = O_CREAT, .name = "O_CREAT" },
  { .value = O_DIRECT, .name = "O_DIRECT" },
  { .value = O_DIRECTORY, .name = "O_DIRECTORY" },
  { .value = O_EXCL, .name = "O_EXCL" },
  { .value = O_NOATIME, .name = "O_NOATIME" },
  { .value = O_NOCTTY, .name = "O_NOCTTY" },
  { .value = O_NOFOLLOW, .name = "O_NOFOLLOW" },
  { .value = O_NONBLOCK, .name = "O_NONBLOCK" },
  { .value = O_PATH, .name = "O_PATH" },
  { .value = O_SYNC, .name = "O_SYNC" },
  { .value = O_TRUNC, .name = "O_TRUNC" },
  { .value = O_RDONLY, .name = "O_RDONLY" },
  { .value = O_WRONLY, .name = "O_WRONLY" },
  { .value = O_RDWR, .name = "O_RDWR" },
};

int
ftrace_print_flags_open(unsigned long long int value,
			pid_t child,
			const struct user_regs_struct *regs,
			const struct s_ftrace_opts *opts)
{
  (void) child;
  (void) regs;
  return (ftrace_print_flags(value, ARRAYSIZE(g_open_flags),
			     g_open_flags, opts));
}

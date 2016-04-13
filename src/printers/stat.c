/*
** stat.c for ftrace in /home/kureuil/Work/ftrace/src
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 10 17:32:36 2016 Arch Kureuil
** Last update Wed Apr 13 10:09:41 2016 Arch Kureuil
*/

#define _GNU_SOURCE
#include <sys/user.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "ftrace.h"

static const struct s_flag g_stat_flags[] = {
  { .value = S_IFMT, .name = "S_IFMT" },
  { .value = S_IFSOCK, .name = "S_IFSOCK" },
  { .value = S_IFLNK, .name = "S_IFLNK" },
  { .value = S_IFREG, .name = "S_IFREG" },
  { .value = S_IFBLK, .name = "S_IFBLK" },
  { .value = S_IFDIR, .name = "S_IFDIR" },
  { .value = S_IFCHR, .name = "S_IFCHR" },
  { .value = S_IFIFO, .name = "S_IFIFO" },
  { .value = S_ISUID, .name = "S_ISUID" },
  { .value = S_ISGID, .name = "S_ISGID" },
  { .value = S_ISVTX, .name = "S_ISVTX" },
  { .value = S_IRWXU, .name = "S_IRWXU" },
  { .value = S_IRUSR, .name = "S_IRUSR" },
  { .value = S_IWUSR, .name = "S_IWUSR" },
  { .value = S_IWUSR, .name = "S_IWUSR" },
  { .value = S_IRWXG, .name = "S_IRWXG"},
  { .value = S_IRGRP, .name = "S_IRGRP"},
  { .value = S_IWGRP, .name = "S_IWGRP"},
  { .value = S_IXGRP, .name = "S_IXGRP"},
  { .value = S_IRWXO, .name = "S_IRWXO"},
  { .value = S_IROTH, .name = "S_IROTH"},
  { .value = S_IWOTH, .name = "S_IWOTH"},
  { .value = S_IXOTH, .name = "S_IXOTH"}
};

int
ftrace_print_stat_struct(unsigned long long int addr,
                         pid_t child,
                         const struct user_regs_struct *regs,
			 const struct s_ftrace_opts *opts)
{
  struct stat	stat_data;
  size_t	printed;

  (void) regs;
  printed = 0;
  if (ftrace_peek_buffer(child, addr, sizeof(stat_data), &stat_data))
    return (0);
  printed = fprintf(opts->output, "{st_mode=");
  printed += ftrace_print_flags(stat_data.st_mode,
				ARRAYSIZE(g_stat_flags),
				g_stat_flags,
				opts);
  printed += fprintf(opts->output, "|%u, st_size=%lu, ...}",
		     stat_data.st_mode, stat_data.st_size);
  return (printed);
}


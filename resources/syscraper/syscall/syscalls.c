/*
** syscalls.c for  in /home/vagrant/Projects/insru/strace/PSU_2015_strace
**
** Made by Babine
** Login   <vagrant@epitech.net>
**
** Started on  Sat Apr  9 19:30:52 2016
** Last update Sun Apr 10 15:42:14 2016 Arch Kureuil
*/

#include <stdlib.h>
#include "strace.h"

struct s_syscall	g_syscalls[] = {
    {
        .id = 0,
        .name = "read",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 1,
        .name = "write",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 2,
        .name = "open",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 3,
        .name = "close",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
        }
    },
    {
        .id = 4,
        .name = "stat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 5,
        .name = "fstat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 6,
        .name = "lstat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 7,
        .name = "poll",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 8,
        .name = "lseek",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 9,
        .name = "mmap",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 10,
        .name = "mprotect",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 11,
        .name = "munmap",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 12,
        .name = "brk",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 13,
        .name = "rt_sigaction",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 14,
        .name = "rt_sigprocmask",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 15,
        .name = "rt_sigreturn",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 16,
        .name = "ioctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 17,
        .name = "pread64",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 18,
        .name = "pwrite64",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 19,
        .name = "readv",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 20,
        .name = "writev",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 21,
        .name = "access",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 22,
        .name = "pipe",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 23,
        .name = "select",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 24,
        .name = "sched_yield",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 25,
        .name = "mremap",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 26,
        .name = "msync",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 27,
        .name = "mincore",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 28,
        .name = "madvise",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 29,
        .name = "shmget",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 30,
        .name = "shmat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 31,
        .name = "shmctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 32,
        .name = "dup",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 33,
        .name = "dup2",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 34,
        .name = "pause",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 35,
        .name = "nanosleep",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 36,
        .name = "getitimer",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 37,
        .name = "alarm",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 38,
        .name = "setitimer",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 39,
        .name = "getpid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 40,
        .name = "sendfile",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 41,
        .name = "socket",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 42,
        .name = "connect",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 43,
        .name = "accept",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 44,
        .name = "sendto",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 45,
        .name = "recvfrom",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 46,
        .name = "sendmsg",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 47,
        .name = "recvmsg",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 48,
        .name = "shutdown",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 49,
        .name = "bind",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 50,
        .name = "listen",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 51,
        .name = "getsockname",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 52,
        .name = "getpeername",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 53,
        .name = "socketpair",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 54,
        .name = "setsockopt",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 55,
        .name = "getsockopt",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 56,
        .name = "clone",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 57,
        .name = "fork",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 58,
        .name = "vfork",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 59,
        .name = "execve",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 60,
        .name = "exit",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 61,
        .name = "wait4",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 62,
        .name = "kill",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 63,
        .name = "uname",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 64,
        .name = "semget",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 65,
        .name = "semop",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 66,
        .name = "semctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 67,
        .name = "shmdt",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 68,
        .name = "msgget",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
        }
    },
    {
        .id = 69,
        .name = "msgsnd",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
        }
    },
    {
        .id = 70,
        .name = "msgrcv",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 71,
        .name = "msgctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 72,
        .name = "fcntl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 73,
        .name = "flock",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 74,
        .name = "fsync",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 75,
        .name = "fdatasync",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
        }
    },
    {
        .id = 76,
        .name = "truncate",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 77,
        .name = "ftruncate",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 78,
        .name = "getdents",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 79,
        .name = "getcwd",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 80,
        .name = "chdir",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 81,
        .name = "fchdir",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 82,
        .name = "rename",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 83,
        .name = "mkdir",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 84,
        .name = "rmdir",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 85,
        .name = "creat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 86,
        .name = "link",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 87,
        .name = "unlink",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 88,
        .name = "symlink",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 89,
        .name = "readlink",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 90,
        .name = "chmod",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 91,
        .name = "fchmod",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 92,
        .name = "chown",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 93,
        .name = "fchown",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 94,
        .name = "lchown",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 95,
        .name = "umask",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 96,
        .name = "gettimeofday",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 97,
        .name = "getrlimit",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 98,
        .name = "getrusage",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 99,
        .name = "sysinfo",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 100,
        .name = "times",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 101,
        .name = "ptrace",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 102,
        .name = "getuid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 103,
        .name = "syslog",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 104,
        .name = "getgid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 105,
        .name = "setuid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 106,
        .name = "setgid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 107,
        .name = "geteuid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 108,
        .name = "getegid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 109,
        .name = "setpgid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 110,
        .name = "getppid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 111,
        .name = "getpgrp",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 112,
        .name = "setsid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 113,
        .name = "setreuid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 114,
        .name = "setregid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 115,
        .name = "getgroups",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 116,
        .name = "setgroups",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 117,
        .name = "setresuid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 118,
        .name = "getresuid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 119,
        .name = "setresgid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 120,
        .name = "getresgid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 121,
        .name = "getpgid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 122,
        .name = "setfsuid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 123,
        .name = "setfsgid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 124,
        .name = "getsid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 125,
        .name = "capget",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 126,
        .name = "capset",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 127,
        .name = "rt_sigpending",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 128,
        .name = "rt_sigtimedwait",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 129,
        .name = "rt_sigqueueinfo",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 130,
        .name = "rt_sigsuspend",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 131,
        .name = "sigaltstack",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 132,
        .name = "utime",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 133,
        .name = "mknod",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 134,
        .name = "uselib",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 135,
        .name = "personality",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 136,
        .name = "ustat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 137,
        .name = "statfs",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 138,
        .name = "fstatfs",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 139,
        .name = "sysfs",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 140,
        .name = "getpriority",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 141,
        .name = "setpriority",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 142,
        .name = "sched_setparam",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 143,
        .name = "sched_getparam",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 144,
        .name = "sched_setscheduler",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 145,
        .name = "sched_getscheduler",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 146,
        .name = "sched_get_priority_max",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 147,
        .name = "sched_get_priority_min",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 148,
        .name = "sched_rr_get_interval",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 149,
        .name = "mlock",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 150,
        .name = "munlock",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 151,
        .name = "mlockall",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 152,
        .name = "munlockall",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 153,
        .name = "vhangup",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 154,
        .name = "modify_ldt",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 155,
        .name = "pivot_root",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 156,
        .name = "_sysctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 157,
        .name = "prctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 158,
        .name = "arch_prctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 159,
        .name = "adjtimex",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 160,
        .name = "setrlimit",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 161,
        .name = "chroot",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 162,
        .name = "sync",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 163,
        .name = "acct",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 164,
        .name = "settimeofday",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 165,
        .name = "mount",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 166,
        .name = "umount2",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 167,
        .name = "swapon",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 168,
        .name = "swapoff",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 169,
        .name = "reboot",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 170,
        .name = "sethostname",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 171,
        .name = "setdomainname",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 172,
        .name = "iopl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 173,
        .name = "ioperm",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 174,
        .name = "create_module",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 175,
        .name = "init_module",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 176,
        .name = "delete_module",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 177,
        .name = "get_kernel_syms",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 178,
        .name = "query_module",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 179,
        .name = "quotactl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 180,
        .name = "nfsservctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 181,
        .name = "getpmsg",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 182,
        .name = "putpmsg",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 183,
        .name = "afs_syscall",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 184,
        .name = "tuxcall",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 185,
        .name = "security",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 186,
        .name = "gettid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 187,
        .name = "readahead",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 188,
        .name = "setxattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 189,
        .name = "lsetxattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 190,
        .name = "fsetxattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 191,
        .name = "getxattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 192,
        .name = "lgetxattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 193,
        .name = "fgetxattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 194,
        .name = "listxattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 195,
        .name = "llistxattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 196,
        .name = "flistxattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 197,
        .name = "removexattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 198,
        .name = "lremovexattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 199,
        .name = "fremovexattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 200,
        .name = "tkill",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 201,
        .name = "time",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 202,
        .name = "futex",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 203,
        .name = "sched_setaffinity",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 204,
        .name = "sched_getaffinity",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 205,
        .name = "set_thread_area",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 206,
        .name = "io_setup",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 207,
        .name = "io_destroy",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 208,
        .name = "io_getevents",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 209,
        .name = "io_submit",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 210,
        .name = "io_cancel",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 211,
        .name = "get_thread_area",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 212,
        .name = "lookup_dcookie",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 213,
        .name = "epoll_create",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 214,
        .name = "epoll_ctl_old",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 215,
        .name = "epoll_wait_old",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 216,
        .name = "remap_file_pages",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 217,
        .name = "getdents64",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 218,
        .name = "set_tid_address",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 219,
        .name = "restart_syscall",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 220,
        .name = "semtimedop",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 221,
        .name = "fadvise64",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 222,
        .name = "timer_create",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 223,
        .name = "timer_settime",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 224,
        .name = "timer_gettime",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 225,
        .name = "timer_getoverrun",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 226,
        .name = "timer_delete",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 227,
        .name = "clock_settime",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 228,
        .name = "clock_gettime",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 229,
        .name = "clock_getres",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 230,
        .name = "clock_nanosleep",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 231,
        .name = "exit_group",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 232,
        .name = "epoll_wait",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 233,
        .name = "epoll_ctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 234,
        .name = "tgkill",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 235,
        .name = "utimes",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 236,
        .name = "vserver",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 237,
        .name = "mbind",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 238,
        .name = "set_mempolicy",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 239,
        .name = "get_mempolicy",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 240,
        .name = "mq_open",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 241,
        .name = "mq_unlink",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 242,
        .name = "mq_timedsend",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 243,
        .name = "mq_timedreceive",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 244,
        .name = "mq_notify",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 245,
        .name = "mq_getsetattr",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 246,
        .name = "kexec_load",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 247,
        .name = "waitid",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 248,
        .name = "add_key",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 249,
        .name = "request_key",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 250,
        .name = "keyctl",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 251,
        .name = "ioprio_set",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 252,
        .name = "ioprio_get",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 253,
        .name = "inotify_init",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 254,
        .name = "inotify_add_watch",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 255,
        .name = "inotify_rm_watch",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 256,
        .name = "migrate_pages",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 257,
        .name = "openat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 258,
        .name = "mkdirat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 259,
        .name = "mknodat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 260,
        .name = "fchownat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 261,
        .name = "futimesat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 262,
        .name = "newfstatat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 263,
        .name = "unlinkat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 264,
        .name = "renameat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 265,
        .name = "linkat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 266,
        .name = "symlinkat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 267,
        .name = "readlinkat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 268,
        .name = "fchmodat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 269,
        .name = "faccessat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 270,
        .name = "pselect6",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 271,
        .name = "ppoll",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 272,
        .name = "unshare",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 273,
        .name = "set_robust_list",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 274,
        .name = "get_robust_list",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 275,
        .name = "splice",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 1,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
        }
    },
    {
        .id = 276,
        .name = "tee",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 4,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 277,
        .name = "sync_file_range",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 2,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 278,
        .name = "vmsplice",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 279,
        .name = "move_pages",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 280,
        .name = "utimensat",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 6,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 281,
        .name = "epoll_pwait",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 5,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 282,
        .name = "signalfd",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 3,
        .args = {
            {
                .custom = false,
                .printer = {
                    .type = T_INTEGER
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
            {
                .custom = false,
                .printer = {
                    .type = T_DEFAULT
                }
            },
        }
    },
    {
        .id = 283,
        .name = "timerfd_create",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 284,
        .name = "eventfd",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 285,
        .name = "fallocate",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 286,
        .name = "timerfd_settime",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 287,
        .name = "timerfd_gettime",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 288,
        .name = "accept4",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 289,
        .name = "signalfd4",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 290,
        .name = "eventfd2",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 291,
        .name = "epoll_create1",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 292,
        .name = "dup3",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 293,
        .name = "pipe2",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 294,
        .name = "inotify_init1",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 295,
        .name = "preadv",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 296,
        .name = "pwritev",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 297,
        .name = "rt_tgsigqueueinfo",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 298,
        .name = "perf_event_open",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 299,
        .name = "recvmmsg",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 300,
        .name = "fanotify_init",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 301,
        .name = "fanotify_mark",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 302,
        .name = "prlimit64",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 303,
        .name = "name_to_handle_at",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 304,
        .name = "open_by_handle_at",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 305,
        .name = "clock_adjtime",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 306,
        .name = "syncfs",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 307,
        .name = "sendmmsg",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 308,
        .name = "setns",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 309,
        .name = "getcpu",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 310,
        .name = "process_vm_readv",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 311,
        .name = "process_vm_writev",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = 312,
        .name = "kcmp",
        .noreturn = false,
        .retval = T_DEFAULT,
        .argc = 0,
        .args = {
            { 0 }
        }
    },
    {
        .id = (unsigned long long) -1,
        .name = NULL,
        .noreturn = false,
        .retval = 0,
        .argc = 0,
        .args = {{ 0 }},
    },
};


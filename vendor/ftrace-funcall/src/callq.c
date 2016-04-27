/*
** callq.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-funcall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sun Apr 17 11:55:54 2016 Arch Kureuil
** Last update Wed Apr 27 11:24:06 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <libelf.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <gelf.h>
#include "vector/vector.h"
#include "error/error.h"
#include "ftrace-funcall.h"
#include "ftrace.h"

static struct s_vector *g_symbols = NULL;

int
ftrace_funcall_handler_callq(unsigned long long int value,
			     const struct user_regs_struct *regs,
			     const struct s_ftrace_opts *opts)
{
  unsigned long long int	addr;
  char				symbol_name[FTRACE_SYMBOL_MAX_LENGTH];

  assert(regs != NULL);
  assert(opts != NULL);
  if (ftrace_funcall_symbols_init(opts, &g_symbols))
    return (-1);
  ftrace_event_trigger("ftrace:printline-begin", NULL);
  addr = (value >> 8 & 0xffffffff) + regs->rip + 5;
  if (ftrace_funcall_symbols_get_by_addr(addr, g_symbols, symbol_name))
    {
      fprintf(stderr, "Callq %#llx at %#llx\n", value, addr);
    }
  else
    {
      fprintf(stderr, "Callq %s at %#llx\n", symbol_name, addr);
    }
  return (0);
}

static void __attribute__((destructor))
ftrace_funcall_symbols_destroy()
{
  if (g_symbols != NULL)
    vector_delete(&g_symbols);
}

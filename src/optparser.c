/*
** optparser.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 11:37:51 2016 Arch Kureuil
** Last update Sat Apr 16 20:35:40 2016 Arch Kureuil
*/

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include "error/error.h"
#include "vector/vector.h"
#include "optparser.h"
#include "ftrace.h"

static struct s_vector g_opts;

int
optparser_register(const struct s_option *option)
{
  size_t		i;
  struct s_option	tmp;

  assert(option != NULL);
  if (g_opts.capacity == 0)
    {
      if (vector_init(&g_opts, 16, sizeof(struct s_option)))
	return (-1);
    }
  i = 0;
  while (i < g_opts.size)
    {
      if (vector_get(&g_opts, i, &tmp))
	return (-1);
      assert(tmp.flag != option->flag);
      i++;
    }
  return (vector_push_back(&g_opts, option));
}

static int
optparser_get_option(char flag, struct s_option *opt)
{
  size_t	i;

  assert(flag != '\0');
  assert(opt != NULL);
  i = 0;
  while (i < g_opts.size)
    {
      if (vector_get(&g_opts, i, opt))
	return (-1);
      if (opt->flag == flag)
	return (0);
      i++;
    }
  return (-1);
}

static int
optparser_generate_flags(char **strp)
{
  struct s_option	tmp;
  size_t		i;
  size_t		j;

  assert(strp != NULL);
  *strp = malloc(g_opts.size * 2 + 1);
  if (*strp == NULL)
    return (error_raise_errno(), -1);
  **strp = '\0';
  i = j = 0;
  while (i < g_opts.size)
    {
      if (vector_get(&g_opts, i, &tmp))
	return (free(*strp), -1);
      (*strp)[j++] = tmp.flag;
      if (tmp.has_value)
	(*strp)[j++] = ':';
      i++;
    }
  (*strp)[j] = '\0';
  return (0);
}

void
optparser_print_usage(const char *prgm)
{
  size_t		i;
  struct s_option	opt;

  fprintf(stderr, "\nUSAGE: %s [OPTIONS...] COMMAND [ARGS]\n\n", prgm);
  fprintf(stderr, "OPTIONS:\n");
  i = 0;
  while (i < g_opts.size)
    {
      if (vector_get(&g_opts, i, &opt))
	return ;
      fprintf(stderr, "\t-%c %-16s %s\n",
	      opt.flag,
	      (opt.has_value ? opt.argname : ""),
	      opt.help);
      i++;
    }
  fprintf(stderr, "\tCOMMAND %11s Program to execute & trace\n", "");
  fprintf(stderr, "\tARGS %14s Arguments given to the executed program\n", "");
}

int
optparser(int argc, char **argv, struct s_ftrace_opts *opts)
{
  char			*flags;
  char			c; 
  int			i;
  struct s_option	opt;

  flags = NULL;
  if (optparser_generate_flags(&flags))
    return (-1);
  fprintf(stderr, "Flags: '%s'\n", flags);
  while ((c = getopt(argc, argv, flags)) != -1)
    {
      optparser_get_option(c, &opt);
      if (opt.callback(optarg))
	return (-1);
    }
  opts->command = calloc(argc - optind + 1, sizeof(char *));
  if (opts->command == NULL)
    return (-1);
  i = 0;
  while (optind + i < argc)
    {
      opts->command[i] = argv[optind + i];
      i++;
    }
  opts->command[i] = NULL;
  return (0);
}

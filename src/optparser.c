/*
** optparser.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 11:37:51 2016 Arch Kureuil
** Last update Mon Apr 11 12:47:52 2016 Arch Kureuil
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "optparser.h"
#include "ftrace.h"

static const struct s_option g_opts[] = {
  { .flag = 'p', .callback = &ftrace_option_pid },
  { .flag = 's', .callback = &ftrace_option_prettify },
  { .flag = 'f', .callback = &ftrace_option_file },
  { .flag = 't', .callback = &ftrace_option_timestamp },
  { .flag = '\0', .callback = NULL },
};

static int
optparser_get_option(char flag,
		     struct s_option *opt)
{
  size_t	i;

  i = 0;
  while (g_opts[i].flag)
    {
      if (g_opts[i].flag == flag)
	{
	  *opt = g_opts[i];
	  return (0);
	}
      i++;
    }
  return (-1);
}

int
optparser_get_arguments(char ***argp, int argc, char **argv)
{
  int	i;

  *argp = calloc(argc - optind + 1, sizeof(char *));
  if (*argp == NULL)
    return (-1);
  i = 0;
  while (optind + i < argc)
    {
      (*argp)[i] = argv[optind + i];
      i++;
    }
  (*argp)[i] = NULL;
  return (0);
}

int
optparser(int argc, char **argv, struct s_ftrace_opts *opts)
{
  char			c;
  struct s_option	opt;

  while ((c = getopt(argc, argv, "sp:f:t")) != -1)
    {
      if (optparser_get_option(c, &opt))
	return (-1);
      if (opt.callback(optarg, opts))
	return (-1);
    }
  if (opts->pid == 0 && argc - optind == 0)
    return (-1);
  return (optparser_get_arguments(&opts->command, argc, argv));
}

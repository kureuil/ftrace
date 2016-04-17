/*
** optparser.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 11:34:43 2016 Arch Kureuil
** Last update Sun Apr 17 11:34:12 2016 Arch Kureuil
*/

#ifndef OPTPARSER_H_
# define OPTPARSER_H_

# include <stdbool.h>

struct s_ftrace_opts;

typedef int (*t_optparser)(const char *arg);

struct		s_option
{
  char		flag;
  bool		has_value;
  t_optparser	callback;
  const char	*argname;
  const char	*help;
};

int	optparser(int argc, char **av, struct s_ftrace_opts *opts);

int	optparser_register(const struct s_option *option);

void	optparser_print_usage(const char *prgm);

#endif

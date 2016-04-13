/*
** optparser.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 11:34:43 2016 Arch Kureuil
** Last update Mon Apr 11 11:51:57 2016 Arch Kureuil
*/

#ifndef OPTPARSER_H_
# define OPTPARSER_H_

struct s_ftrace_opts;

typedef int (*t_optparser)(const char *arg, struct s_ftrace_opts *opts);

struct		s_option
{
  char		flag;
  t_optparser	callback;
};

int	optparser(int argc, char **av, struct s_ftrace_opts *opts);

int	ftrace_option_pid(const char *arg, struct s_ftrace_opts *opts);

int	ftrace_option_prettify(const char *arg, struct s_ftrace_opts *opts);

int	ftrace_option_file(const char *arg, struct s_ftrace_opts *opts);

int	ftrace_option_timestamp(const char *arg, struct s_ftrace_opts *opts);

#endif

/*
** main.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 13:14:41 2016 Arch Kureuil
** Last update Sat Apr 16 20:00:52 2016 Arch Kureuil
*/

#include <stdio.h>

int __attribute__((constructor))
ftrace_start(void)
{
  return (0);
}

int __attribute__((destructor))
ftrace_exit(void)
{
  return (0);
}

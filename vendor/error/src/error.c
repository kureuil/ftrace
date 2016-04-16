/*
** error.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/error
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 17:13:45 2016 Arch Kureuil
** Last update Sat Apr 16 17:25:42 2016 Arch Kureuil
*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

static const char *g_error;

static const char *g_ctx;

int
error_raise(const char *error)
{
  assert(error != NULL);
  g_error = error;
  g_ctx = NULL;
  return (0);
}

int
error_raise_ctx(const char *error, const char *ctx)
{
  assert(error != NULL);
  assert(ctx != NULL);
  if (error_raise(error))
    return (-1);
  g_ctx = ctx;
  return (0);
}

int
error_raise_errno(void)
{
  assert(errno != 0);
  return (error_raise(strerror(errno)));
}

int
error_raise_errno_ctx(const char *ctx)
{
  assert(errno != 0);
  if (error_raise_errno())
    return (-1);
  g_ctx = ctx;
  return (0);
}

int
error_handle(const char *prefix)
{
  if (g_ctx != NULL)
    {
      if (fprintf(stderr, "%s: %s\n", prefix, g_error) == -1)
	return (-1);
    }
  else
    {
      if (fprintf(stderr, "%s: %s: %s\n", prefix, g_ctx, g_error) == -1)
	return (-1);
    }
  return (0);
}

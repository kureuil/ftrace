/*
** main.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 13:14:41 2016 Arch Kureuil
** Last update Sat Apr 16 22:40:48 2016 Arch Kureuil
*/

#include <sys/time.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "error/error.h"
#include "ftrace-timestamp.h"
#include "ftrace.h"
#include "optparser.h"

static enum e_timestamp_type g_timestamp_type = TS_NONE;

static int
ftrace_timestamp_option(const char *arg)
{
  (void) arg;
  if (g_timestamp_type == TS_NONE)
    g_timestamp_type = TS_TIME;
  else if (g_timestamp_type == TS_TIME)
    g_timestamp_type = TS_MILLISECOND;
  else
    return (error_raise("Invalid option given"), -1);
  return (0);
}

static const struct s_option g_timestamp_option = {
  .flag = 't',
  .has_value = false,
  .callback = &ftrace_timestamp_option,
  .argname = "",
  .help = "Print a timestamp before every output."
  " If twice, include milliseconds in timestamp.",
};

static void
ftrace_timestamp_register(const char *name, void *data)
{
  assert(name != NULL);
  (void) data;
  optparser_register(&g_timestamp_option);
}

static void
ftrace_timestamp_print(const char *name, void *data)
{
  struct tm		*tm;
  time_t		curtime;
  struct timeval	timeval;

  assert(name != NULL);
  (void) data;
  if (g_timestamp_type != TS_NONE)
    {
      curtime = time(NULL);
      tm = localtime(&curtime);
      fprintf(stderr, "%02d:%02d:%02d", tm->tm_hour, tm->tm_min, tm->tm_sec);
      if (g_timestamp_type == TS_MILLISECOND)
	{
	  if (!gettimeofday(&timeval, NULL))
	    fprintf(stderr, ".%06lu", timeval.tv_usec % 1000000);
	}
      fprintf(stderr, " ");
    }
}

int __attribute__((constructor))
ftrace_redirect_start(void)
{
  ftrace_event_listen("optparser:register", &ftrace_timestamp_register);
  ftrace_event_listen("ftrace:printline-begin", &ftrace_timestamp_print);
  return (0);
}

int __attribute__((destructor))
ftrace_redirect_exit(void)
{
  return (0);
}

/*
** event.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 12:23:13 2016 Arch Kureuil
** Last update Sat Apr 16 13:13:06 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "ftrace.h"

static const char *g_events[FTRACE_EVENT_MAX];
static t_listener g_listeners[FTRACE_EVENT_MAX][FTRACE_EVENT_MAX];

int
ftrace_event_trigger(const char *name, void *data)
{
  size_t	event;
  size_t	i;

  assert(name != NULL);
  event = 0;
  while (event < (FTRACE_EVENT_MAX - 1) && g_events[event] != NULL)
    {
      if (!strcmp(g_events[event], name))
	break;
      event++;
    }
  if (event == (FTRACE_EVENT_MAX - 1) || g_listeners[event] == NULL)
    return (-1);
  i = 0;
  while (i < (FTRACE_EVENT_MAX - 1))
    {
      if (g_listeners[event][i] == NULL)
	break;
      g_listeners[event][i](name, data);
      i++;
    }
  return (0);
}

int
ftrace_event_listen(const char *name, t_listener listener)
{
  size_t	event;
  size_t	i;

  assert(name != NULL);
  assert(listener != NULL);
  event = 0;
  while (event < (FTRACE_EVENT_MAX - 1) && g_events[event] != NULL)
    {
      if (!strcmp(g_events[event], name))
	break;
      event++;
    }
  if (event == (FTRACE_EVENT_MAX - 1))
    return (-1);
  else if (g_events[event] == NULL)
    g_events[event] = name;
  i = 0;
  while (g_listeners[event][i] != NULL)
    {
      if (i >= FTRACE_EVENT_MAX)
	return (-1);
      i++;
    }
  g_listeners[event][i] = listener;
  return (0);
}

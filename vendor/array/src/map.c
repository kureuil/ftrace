/*
** map.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Feb 22 00:41:47 2016 Louis Person
** Last update Mon Feb 22 00:43:54 2016 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "array.h"

int
array_map(struct s_array *array, t_array_mapper fn)
{
  size_t	i;

  assert(array != NULL);
  assert(fn != NULL);
  i = 0;
  while (i < array->size)
  {
    if (fn(ARRAY_SHFT(array, i)))
      return (-1);
    i++;
  }
  return (0);
}

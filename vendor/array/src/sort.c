/*
** sort.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sun Feb 21 23:00:31 2016 Louis Person
** Last update Mon Feb 22 10:41:51 2016 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "array.h"

int
array_sort(const struct s_array *array, t_array_cmp cmp)
{
  size_t	i;
  size_t	j;
  uint8_t	buf[array->entsize];

  assert(array != NULL);
  assert(cmp != NULL);
  i = -1;
  while (++i < array->size)
  {
    j = i + 1;
    while (--j > 0)
    {
      if (cmp(ARRAY_SHFT(array, j - 1), ARRAY_SHFT(array, j)) > 0)
      {
	memcpy(buf, ARRAY_SHFT(array, j - 1), array->entsize);
	memcpy(ARRAY_SHFT(array, j - 1), ARRAY_SHFT(array, j), array->entsize);
	memcpy(ARRAY_SHFT(array, j), buf, array->entsize);
      }
      else
	break;
    }
  }
  return (0);
}

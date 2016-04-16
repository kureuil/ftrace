/*
** sort.c for libvector in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/vector/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sun Feb 21 23:00:31 2016 Louis Person
** Last update Sat Apr 16 18:40:00 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "vector.h"

int
vector_sort(const struct s_vector *vector, t_vector_cmp cmp)
{
  size_t	i;
  size_t	j;
  uint8_t	buf[vector->entsize];

  assert(vector != NULL);
  assert(cmp != NULL);
  i = -1;
  while (++i < vector->size)
  {
    j = i + 1;
    while (--j > 0)
    {
      if (cmp(ARRAY_SHFT(vector, j - 1), ARRAY_SHFT(vector, j)) > 0)
      {
	memcpy(buf, ARRAY_SHFT(vector, j - 1), vector->entsize);
	memcpy(ARRAY_SHFT(vector, j - 1), ARRAY_SHFT(vector, j), vector->entsize);
	memcpy(ARRAY_SHFT(vector, j), buf, vector->entsize);
      }
      else
	break;
    }
  }
  return (0);
}

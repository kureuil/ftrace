/*
** map.c for libvector in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/vector/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Mon Feb 22 00:41:47 2016 Louis Person
** Last update Sat Apr 16 18:03:51 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include "vector.h"

int
vector_map(struct s_vector *vector, t_vector_mapper fn)
{
  size_t	i;

  assert(vector != NULL);
  assert(fn != NULL);
  i = 0;
  while (i < vector->size)
  {
    if (fn(ARRAY_SHFT(vector, i)))
      return (-1);
    i++;
  }
  return (0);
}

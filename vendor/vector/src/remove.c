/*
** remove.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:56:22 2016 Louis Person
** Last update Sat Apr 16 18:17:58 2016 Arch Kureuil
*/

#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "vector.h"

int
vector_remove(const struct s_vector *vector,
	      size_t index)
{
  void	*dest;

  assert(vector != NULL);
  assert(index < vector->size);
  dest = (void *)((uintptr_t)vector->data + index * vector->entsize);
  memset(dest, 0, vector->entsize);
  return (0);
}

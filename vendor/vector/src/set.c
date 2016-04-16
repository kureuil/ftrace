/*
** set.c for libvector in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/vector/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:49:11 2016 Louis Person
** Last update Sat Apr 16 18:18:02 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int
vector_set(const struct s_vector *vector,
	   size_t index,
	   const void *data)
{
  void	*dest;

  assert(vector != NULL);
  assert(index < vector->size);
  assert(data != NULL);
  dest = (void *)((uintptr_t)vector->data + index * vector->entsize);
  memcpy(dest, data, vector->entsize);
  return (0);
}

/*
** get.c for libvector in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/vector/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:53:32 2016 Louis Person
** Last update Sat Apr 16 18:17:39 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int
vector_get(const struct s_vector *vector,
	   size_t index,
	   void *data)
{
  void	*src;

  assert(vector != NULL);
  assert(index < vector->size);
  assert(data != NULL);
  src = (void *)((uintptr_t)vector->data + vector->entsize * index);
  memcpy(data, src, vector->entsize);
  return (0);
}

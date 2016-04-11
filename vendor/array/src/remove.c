/*
** remove.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:56:22 2016 Louis Person
** Last update Sat Feb 20 19:07:56 2016 Louis Person
*/

#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "array.h"

int
array_remove(const struct s_array *array,
	     size_t index)
{
  void	*dest;

  assert(array != NULL);
  assert(index < array->size);
  dest = (void *)((uintptr_t)array->data + index * array->entsize);
  memset(dest, 0, array->entsize);
  return (0);
}

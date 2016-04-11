/*
** set.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:49:11 2016 Louis Person
** Last update Sat Feb 20 19:08:52 2016 Louis Person
*/

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

int
array_set(const struct s_array *array,
	  size_t index,
	  const void *data)
{
  void	*dest;

  assert(array != NULL);
  assert(index < array->size);
  assert(data != NULL);
  dest = (void *)((uintptr_t)array->data + index * array->entsize);
  memcpy(dest, data, array->entsize);
  return (0);
}

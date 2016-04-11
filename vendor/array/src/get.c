/*
** get.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:53:32 2016 Louis Person
** Last update Sat Feb 20 19:07:01 2016 Louis Person
*/

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

int
array_get(const struct s_array *array,
	  size_t index,
	  void *data)
{
  void	*src;

  assert(array != NULL);
  assert(index < array->size);
  assert(data != NULL);
  src = (void *)((uintptr_t)array->data + array->entsize * index);
  memcpy(data, src, array->entsize);
  return (0);
}

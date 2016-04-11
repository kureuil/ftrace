/*
** init.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:44:40 2016 Louis Person
** Last update Sat Feb 20 19:07:17 2016 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "array.h"

int
array_init(struct s_array *array,
	   size_t size,
	   size_t entsize)
{
  assert(array != NULL);
  assert(size > 0);
  assert(entsize > 0);
  array->size = size;
  array->entsize = entsize;
  array->data = calloc(size, entsize);
  if (array->data == NULL)
    return (-1);
  return (0);
}

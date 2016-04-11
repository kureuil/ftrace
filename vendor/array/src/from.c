/*
** from.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sun Feb 21 23:40:37 2016 Louis Person
** Last update Mon Feb 22 00:49:36 2016 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

int
array_from(struct s_array *array,
	   const void *src,
	   size_t len,
	   size_t entsize)
{
  assert(array != NULL);
  assert(src != NULL);
  assert(len > 0);
  assert(entsize > 0);
  array->size = len;
  array->entsize = entsize;
  array->data = calloc(len, entsize);
  if (array->data == NULL)
    return (-1);
  memcpy(array->data, src, len * entsize);
  return (0);
}

/*
** new.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:47:00 2016 Louis Person
** Last update Sat Feb 20 19:07:21 2016 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "array.h"

int
array_new(struct s_array **array,
	  size_t size,
	  size_t entsize)
{
  assert(array != NULL);
  assert(size > 0);
  assert(entsize > 0);
  *array = malloc(sizeof(struct s_array));
  if (*array == NULL)
    return (-1);
  return (array_init(*array, size, entsize));
}

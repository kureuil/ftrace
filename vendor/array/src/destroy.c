/*
** destroy.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 19:04:54 2016 Louis Person
** Last update Sat Feb 20 19:05:43 2016 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "array.h"

int
array_destroy(struct s_array *array)
{
  assert(array != NULL);
  free(array->data);
  return (0);
}

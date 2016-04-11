/*
** clear.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:58:10 2016 Louis Person
** Last update Sat Feb 20 19:07:27 2016 Louis Person
*/

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"

int
array_clear(const struct s_array *array)
{
  assert(array != NULL);
  assert(array->data != NULL);
  memset(array->data, 0, array->size * array->entsize);
  return (0);
}

/*
** delete.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 19:05:52 2016 Louis Person
** Last update Sat Feb 20 19:07:32 2016 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "array.h"

int
array_delete(struct s_array **array)
{
  assert(array != NULL);
  if (array_destroy(*array))
    return (-1);
  free(*array);
  return (0);
}

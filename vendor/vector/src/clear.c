/*
** clear.c for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:58:10 2016 Louis Person
** Last update Sat Apr 16 18:01:40 2016 Arch Kureuil
*/

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

int
vector_clear(const struct s_vector *vector)
{
  assert(vector != NULL);
  assert(vector->data != NULL);
  memset(vector->data, 0, vector->size * vector->entsize);
  return (0);
}

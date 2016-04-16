/*
** init.c for libvector in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/vector/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:44:40 2016 Louis Person
** Last update Sat Apr 16 19:29:50 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include "error/error.h"
#include "vector.h"

int
vector_init(struct s_vector *vector,
	    size_t size,
	    size_t entsize)
{
  assert(vector != NULL);
  assert(size > 0);
  assert(entsize > 0);
  vector->size = 0;
  vector->capacity = size;
  vector->entsize = entsize;
  vector->data = calloc(size, entsize);
  if (vector->data == NULL)
    return (error_raise_errno(), -1);
  return (0);
}

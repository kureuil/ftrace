/*
** from.c for libvector in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/vector/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sun Feb 21 23:40:37 2016 Louis Person
** Last update Sat Apr 16 18:17:33 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "error/error.h"
#include "vector.h"

int
vector_from(struct s_vector *vector,
	    const void *src,
	    size_t len,
	    size_t entsize)
{
  assert(vector != NULL);
  assert(src != NULL);
  assert(len > 0);
  assert(entsize > 0);
  vector->size = len;
  vector->capacity = len;
  vector->entsize = entsize;
  vector->data = calloc(len, entsize);
  if (vector->data == NULL)
    return (error_raise_errno(), -1);
  memcpy(vector->data, src, len * entsize);
  return (0);
}

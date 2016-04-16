/*
** new.c for libvector in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/vector/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 18:47:00 2016 Louis Person
** Last update Sat Apr 16 18:17:49 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include "error/error.h"
#include "vector.h"

int
vector_new(struct s_vector **vector,
	   size_t size,
	   size_t entsize)
{
  assert(vector != NULL);
  assert(size > 0);
  assert(entsize > 0);
  *vector = malloc(sizeof(struct s_vector));
  if (*vector == NULL)
    return (error_raise_errno(), -1);
  return (vector_init(*vector, size, entsize));
}

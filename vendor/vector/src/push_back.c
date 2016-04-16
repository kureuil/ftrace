/*
** push_back.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/vector
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 17:52:06 2016 Arch Kureuil
** Last update Sat Apr 16 18:41:15 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "error/error.h"
#include "vector.h"

int
vector_push_back(struct s_vector *vector,
		 const void *data)
{
  assert(vector != NULL);
  assert(data != NULL);
  if (vector->size == vector->capacity)
    {
      vector->capacity = (size_t)(((float) vector->capacity) * 1.5);
      vector->data = realloc(vector->data, vector->capacity);
      if (vector->data == NULL)
	return (error_raise_errno(), -1);
    }
  memcpy(ARRAY_SHFT(vector, vector->size), data, vector->entsize);
  vector->size++;
  return (0);
}

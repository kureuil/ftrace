/*
** pop_back.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/vector
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 17:52:34 2016 Arch Kureuil
** Last update Sat Apr 16 18:41:39 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int
vector_pop_back(struct s_vector *vector,
		void *data)
{
  assert(vector != NULL);
  if (data != NULL)
    memcpy(data, ARRAY_SHFT(vector, vector->size - 1), vector->entsize);
  memset(ARRAY_SHFT(vector, vector->entsize), 0, vector->entsize);
  vector->size--;
  return (0);
}

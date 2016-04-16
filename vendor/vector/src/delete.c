/*
** delete.c for libvector in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/vector/src
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 19:05:52 2016 Louis Person
** Last update Sat Apr 16 18:01:57 2016 Arch Kureuil
*/

#include <assert.h>
#include <stdlib.h>
#include "vector.h"

int
vector_delete(struct s_vector **vector)
{
  assert(vector != NULL);
  if (vector_destroy(*vector))
    return (-1);
  free(*vector);
  return (0);
}

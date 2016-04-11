/*
** array.h for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/inc
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 15:53:01 2016 Louis Person
** Last update Mon Feb 22 00:44:15 2016 Louis Person
*/

#ifndef ARRAY_H_
# define ARRAY_H_

# include <stddef.h>
# include <stdint.h>

#define ARRAY_SHFT(a, i) (void *)((uintptr_t)((a)->data) + (a)->entsize * (i))

typedef int	(*t_array_cmp)(void *left, void *right);

typedef int	(*t_array_mapper)(void *data);

struct		s_array
{
  size_t	size;
  size_t	entsize;
  void		*data;
};

/*
** Initialize a new array.
**
** @param array the array to initialize
** @param size the number of entries that the array will contain
** @param entsize the size of one individual entry (in bytes)
** @returns 0 in case of success, any other value otherwise
*/
int	array_init(struct s_array *array, size_t size, size_t entsize);

/*
** Initialize a new array, from given data.
**
** @param array the array to initialize
** @param src the source data
** @param len the number of entry that the array will contain
** @param entsize the size (in bytes) of one individual entry
** @returns 0 in case of success, any other value otherwise
*/
int	array_from(struct s_array *array,
		   const void *src,
		   size_t len,
		   size_t entsize);

/*
** Allocate & initialize an array
**
** @param array the pointer to the to be initialized array
** @param size the number of entries that the array will contain
** @param entsize the size of one individual entry (in bytes)
** @returns 0 in case of success, any other value otherwise
*/
int	array_new(struct s_array **array, size_t size, size_t entsize);

/*
** Sets an element in the array by copying n bytes from data.
**
** @param array
** @param index the index in the array
** @param data the data to be stored
** @returns 0 case of success, any other value otherwise
*/
int	array_set(const struct s_array *array, size_t index, const void *data);

/*
** Get an element from the array by its index.
**
** @param array
** @param index the index in the array
** @param data where to write the content
** @returns 0 in case of success, any other value otherwise
*/
int	array_get(const struct s_array *array, size_t index, void *data);

/*
** Sort an array using the given comparison function.
**
** @param array the array to sort
** @param cmp the comparison function
** @returns 0 in case of success, any other value otherwise
*/
int	array_sort(const struct s_array *array, t_array_cmp cmp);

/*
** Set a array index to 0.
**
** @param array
** @param index
** @returns 0 in case of success, any other value otherwise
*/
int	array_remove(const struct s_array *array, size_t index);

/*
** Execute a function on all the elements of the array.
**
** @param array the array to map
** @param fn the function to execute
** @returns 0 in case of success, any other value otherwise
*/
int	array_map(struct s_array *array, t_array_mapper fn);

/*
** Set the entire array to 0.
**
** @param array
** @returns 0 in case of success, any other value otherwise
*/
int	array_clear(const struct s_array *array);

/*
** Destroy an array.
**
** @param array
** @returns 0 in case of success, any other value otherwise
*/
int	array_destroy(struct s_array *array);

/*
** Delete an array, & free its pointer
**
** @param array the pointer to the to be deleted array
** @returns 0 in case of success, any other value otherwise
*/
int	array_delete(struct s_array **array);

#endif /* !ARRAY_H_ */

/*
** array.h for libarray in /home/louis/work/sysunix/PSU_2015_nmobjdump/vendor/array/inc
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Sat Feb 20 15:53:01 2016 Louis Person
** Last update Sat Apr 16 18:04:12 2016 Arch Kureuil
*/

#ifndef VECTOR_H_
# define VECTOR_H_

# include <stddef.h>
# include <stdint.h>

# ifndef ARRAY_SHFT
#  define ARRAY_SHFT(a, i) (void *)((uintptr_t)((a)->data) + (a)->entsize * (i))
# endif

typedef int	(*t_vector_cmp)(void *left, void *right);

typedef int	(*t_vector_mapper)(void *data);

struct		s_vector
{
  size_t	capacity;
  size_t	size;
  size_t	entsize;
  void		*data;
};

/*
** Initialize a new vector
**
** @param vector the vectory to initialize
** @param size the number of entries that the vector will contain
** @param entsize the size of one individual entry (in bytes)
** @return 0 in case of success, any other value otherwise
*/
int	vector_init(struct s_vector *vector, size_t size, size_t entsize);

/*
** Initialize a new vector, from given data.
**
** @param vector the vector to initialize
** @param src the source data
** @param len the number of entry that the vector will contain
** @param entsize the size (in bytes) of one individual entry
** @return 0 in case of success, any other value otherwise
*/
int	vector_from(struct s_vector *vector,
		    const void *src,
		    size_t len,
		    size_t entsize);

/*
** Allocate & initialize an vector
**
** @param vector the pointer to the to be initialized vector
** @param size the number of entries that the vector will contain
** @param entsize the size of one individual entry (in bytes)
** @return 0 in case of success, any other value otherwise
*/
int	vector_new(struct s_vector **vector, size_t size, size_t entsize);

/*
** Sets an element in the vector by copying n bytes from data.
**
** @param vector
** @param index the index in the vector
** @param data the data to be stored
** @return 0 case of success, any other value otherwise
*/
int	vector_set(const struct s_vector *vector, size_t index, const void *data);

/*
** Get an element from the vector by its index.
**
** @param vector
** @param index the index in the vector
** @param data where to write the content
** @return 0 in case of success, any other value otherwise
*/
int	vector_get(const struct s_vector *vector, size_t index, void *data);

/*
** Append a value at the end of the vector growing it if necessary.
**
** @param vector
** @param data The data to append at the end of the array
** @return 0 in case of success, any other value otherwise
*/
int	vector_push_back(struct s_vector *vector, const void *data);

/*
** Remove a value at the end of the vector shrnking it if possible.
** If data is not NULL, the removed data is stored in it.
**
** @param vector
** @param data The data to removed from the array
** @return 0 in case of success, any other value otherwise
*/
int	vector_pop_back(struct s_vector *vector, void *data);

/*
** Sort an vector using the given comparison function.
**
** @param vector the vector to sort
** @param cmp the comparison function
** @return 0 in case of success, any other value otherwise
*/
int	vector_sort(const struct s_vector *vector, t_vector_cmp cmp);

/*
** Set a vector index to 0.
**
** @param vector
** @param index
** @return 0 in case of success, any other value otherwise
*/
int	vector_remove(const struct s_vector *vector, size_t index);

/*
** Execute a function on all the elements of the vector.
**
** @param vector the vector to map
** @param fn the function to execute
** @return 0 in case of success, any other value otherwise
*/
int	vector_map(struct s_vector *vector, t_vector_mapper fn);

/*
** Set the entire vector to 0.
**
** @param vector
** @return 0 in case of success, any other value otherwise
*/
int	vector_clear(const struct s_vector *vector);

/*
** Destroy an vector.
**
** @param vector
** @return 0 in case of success, any other value otherwise
*/
int	vector_destroy(struct s_vector *vector);

/*
** Delete an vector, & free its pointer
**
** @param vector the pointer to the to be deleted vector
** @return 0 in case of success, any other value otherwise
*/
int	vector_delete(struct s_vector **vector);

#endif /* !VECTOR_H_ */

/*
** error.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/error
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 17:09:29 2016 Arch Kureuil
** Last update Mon Apr 25 17:39:36 2016 Arch Kureuil
*/

#ifndef ERROR_H_
# define ERROR_H_

/*
** Raise an error.
**
** @param error The error message
** @return 0 in case of success, any other value otherwise
*/
int
error_raise(const char *error);

/*
** Raise a error with a context value
**
** @param error The error message
** @param ctx The associated context message
** @return 0 in case of success, any other value otherwise
*/
int
error_raise_ctx(const char *error, const char *ctx);

/*
** Raise the error currently stored in errno.
**
** @return 0 in case of success, any other value otherwise
*/
int
error_raise_errno(void);

/*
** Raise the error currently stored in errno with a context value
**
** @param ctx The associated context message
** @return 0 in case of success, any other value otherwise
*/
int
error_raise_errno_ctx(const char *ctx);

/*
** Print the last raised error message & print it on the standard error
**
** @param prefix The roefix of the error
** @return 0 in case of success, any other value otherwise
*/
int
error_handle(const char *prefix);

#endif

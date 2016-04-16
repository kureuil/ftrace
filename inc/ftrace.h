/*
** ftrace.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 10:03:45 2016 Arch Kureuil
** Last update Sat Apr 16 22:16:46 2016 Arch Kureuil
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# include <sys/types.h>
# include <sys/user.h>
# include <stdbool.h>
# include <stdio.h>
# include "array/array.h"

# define MANAGED(dtor)			__attribute__((__cleanup__(dtor)))
# define MAX(x, y)			((x) ^ (((x) ^ (y)) & -((x) < (y))))
# define ARRAYSIZE(arr)			(sizeof(arr) / sizeof(arr[0]))

# define FTRACE_ADDINS_PREFIX		("libftrace-")
# define FTRACE_ADDINS_PREFIX_LENGTH	(strlen(FTRACE_ADDINS_PREFIX))
# define FTRACE_ADDINS_SUFFIX		(".so")
# define FTRACE_ADDINS_SUFFIX_LENGTH	(strlen(FTRACE_ADDINS_SUFFIX))

# define FTRACE_SYSCALL_BITMASK		(0xffffull)
# define FTRACE_SYSCALL_INSTRUCTION	(0x50full)
# define FTRACE_SYSCALL_ARGS_MAX	(6)

# define FTRACE_CALLQ_BITMASK		(0xffull)
# define FTRACE_CALLQ_INSTRUCTION	(0xe8ull)

# define FTRACE_RETQ_BITMASK		(0xffull)
# define FTRACE_RETQ_INSTRUCTION	(0xc3ull)

# define FTRACE_EVENT_MAX		(128ul)

/*
** Types of timestamp:
**
** * TS_NONE: No timestamp displayed
** * TS_TIME: Timestamp including current hour, minute, and second
** * TS_MILLISECOND: TS_TIME + current milliseconds
*/
enum e_timestamp_type
  {
    TS_NONE,
    TS_TIME,
    TS_MILLISECOND
  };

/*
** Represent the value of a bitmask flag.
**
** @member name The name of the option
** @member value The value of the bitmask flag
*/
struct s_flag
{
  const char	*name;
  int		value;
};

/*
** Represent the options of the ftrace program.
**
** @member pid The PID of the traced process
** @member command The array given to execve (if any)
** @member prettify Guess arguments type and rettify them
** @member timestamp_type The type of timestamp dsplayed before any output
** (see enum e_timestamp_type)
*/
struct s_ftrace_opts
{
  pid_t			pid;
  char			**command;
  bool			prettify;
  enum e_timestamp_type	timestamp_type;
};

/*
** Reprensent a ftrace addin.
**
** @member path Path of the plugin shared object file
** @member handle Handle obtained by dlopen'ing the path
*/
struct s_ftrace_addin
{
  char		*path;
  void		*handle;
};

/*
** Handle an instruction type.
**
** @param instruction The instruction that triggered the handler
** @param regs The registers of the tracee
** @param opts The options given to ftrace
** @return 0 in case of success, -1 in case of error,
** any positive value if the tracee exited.
*/
typedef int (*t_handler)(unsigned long long int instruction,
			 const struct user_regs_struct *regs,
			 const struct s_ftrace_opts *opts);

/*
** Print a value on the screen.
**
** @param value The value to print
** @param child The PID of the tracee
** @param regs The registers od the tracee
** @param opts The options given to ftrace
*/
typedef int (*t_printer)(unsigned long long int value,
			 pid_t child,
			 const struct user_regs_struct *regs,
			 const struct s_ftrace_opts *opts);

/*
** Represent a value type
*/
enum e_type
  {
    T_DEFAULT,
    T_INTEGER,
    T_POINTER,
    T_STRING,
    T_LONG,
    T_ULONG,
    T_SIZE_T,
    T_SSIZE_T,
  };

/*
** Represent a System Call argument
**
** @member custom Use a custom function to print the value
** @member printer Union containing either the type of the value, or the
** function to call to print the value.
*/
struct s_syscall_arg
{
  bool	custom;
  union
  {
    enum e_type	type;
    t_printer	callback;
  }	printer;
};

/*
** Represent a System Call
**
** @member id The syscall id
** @member name The syscall name
** @member noreturn Does the syscall not return to the caller
** @member retval Type of the return value
** @member argc The number of arguments of the syscall
** @member args The arguments description
*/
struct s_syscall
{
  unsigned long long	id;
  const char		*name;
  bool			noreturn;
  enum e_type		retval;
  size_t		argc;
  struct s_syscall_arg	args[FTRACE_SYSCALL_ARGS_MAX];
};

extern struct s_syscall g_syscalls[];

/*
** Store an instruction handler.
**
** @member bitmask The bitmask used to identify the instruction type
** @member instruction The instruction to match with the bitmask
** @member callback The function to call if instruction matched
*/
struct s_ftrace_handler
{
  unsigned long long int	bitmask;
  unsigned long long int	instruction;
  t_handler			callback;
  int				priority;
};

/*
** Trace a program & print all of its call events to opts->output.
**
** @param child the pid of the tracee
** @param opts the options given to the program
** @return 0 case of success, any other value otherwise
*/
int
ftrace(const struct s_ftrace_opts *opts);

int
ftrace_addins_locate(char *buf, size_t bufsize);

int
ftrace_addins_load(const char *path, struct s_array *addins);

int
ftrace_addins_unload(struct s_array *addins);

typedef void (*t_listener)(const char *name, void *data);

/*
** Trigger an event.
**
** @param name The name of the event
** @param data The data given to the event listener
** @return 0 in case of success, any other value otherwise
*/
int
ftrace_event_trigger(const char *name, void *data);

/*
** Add a callback to an event
**
** @param name The name of the event
** @param listener THe callback to call when the event is triggered.
** @return 0 in case of success, any other value otherwise
*/
int
ftrace_event_listen(const char *name, t_listener listener);

/*
** Peek at tracee registers and store their valieu in regs.
*/
int
ftrace_peek_registers(pid_t child,
		      struct user_regs_struct *regs);

/*
** Peek the current instruction executed by the tracee.
*/
int
ftrace_peek_instruction(pid_t child,
			const struct user_regs_struct *regs,
			long *instrp);

/*
** Peek the NUL terminated string pointed by addr.
*/
int
ftrace_peek_string(pid_t child,
		   unsigned long long int addr,
		   char **strp);

/*
** Read n bytes pointed by addr.
*/
int
ftrace_peek_buffer(pid_t child,
		   unsigned long long int addr,
		   size_t n,
		   void *buffer);

/*
** Get register value by its index.
**
** @param regs all the registers values
** @param idx idx of the to be fetched register
** @return the register value
*/
unsigned long long int
ftrace_registers_get_by_idx(const struct user_regs_struct *regs,
			    size_t idx);

/*
** Handle a syscall instruction.
**
** @see t_handler
*/
int
ftrace_handler_syscall(unsigned long long int instruction,
		       const struct user_regs_struct *regs,
		       const struct s_ftrace_opts *opts);

/*
** Handle a callq instruction.
**
** @see t_handler
*/
int
ftrace_handler_callq(unsigned long long int instruction,
		     const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts);

/*
** Handle a retq instruction.
**
** @see t_handler
*/
int
ftrace_handler_retq(unsigned long long int instruction,
		    const struct user_regs_struct *regs,
		    const struct s_ftrace_opts *opts);

/*
** Function printing flags found in a value.
**
** @param value the flagged value
** @param size the size of the flags array
** @param flags the flags array
** @return the number of printed characters
*/
int
ftrace_print_flags(unsigned long long int value,
                   size_t size,
                   const struct s_flag *flags,
		   const struct s_ftrace_opts *opts);

/*
** Print the string pointed by value
**
** @param value the address of the NUL-terminated string
** @param child the pid of the tracee
** @param regs the registers of the tracee
** @return the number of printed characters
*/
int
ftrace_print_string(unsigned long long int value,
		    pid_t child,
		    const struct user_regs_struct *regs,
		    const struct s_ftrace_opts *opts);

/*
** Print value as a size_t
**
** @return the number of printed characters
*/
int
ftrace_print_size_t(unsigned long long int value,
		    pid_t child,
		    const struct user_regs_struct *regs,
		    const struct s_ftrace_opts *opts);

/*
** Print value as a ssize_t
**
** @return the number of printed characters
*/
int
ftrace_print_ssize_t(unsigned long long int value,
		     pid_t child,
		     const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts);

/*
** Print value as errno (if value is negative)
**
** @return the number of printed characters
*/
int
ftrace_print_errno(unsigned long long int value,
		   pid_t child,
		   const struct user_regs_struct *regs,
		   const struct s_ftrace_opts *opts);

/*
** Print value as a hexadecimal number
**
** @return the number of printed characters
*/
int
ftrace_print_hexa(unsigned long long int value,
		  pid_t child,
		  const struct user_regs_struct *regs,
		  const struct s_ftrace_opts *opts);

/*
** Print value as a decimal integer
**
** @return the number of printed characters
*/
int
ftrace_print_integer(unsigned long long int value,
		     pid_t child,
		     const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts);

/*
** Print value as a pointer
**
** @return the number of printed characters
*/
int
ftrace_print_pointer(unsigned long long int value,
		     pid_t child,
		     const struct user_regs_struct *regs,
		     const struct s_ftrace_opts *opts);

/*
** Print value as a long int
**
** @return the number of printed characters
*/
int
ftrace_print_long(unsigned long long int value,
		  pid_t child,
		  const struct user_regs_struct *regs,
		  const struct s_ftrace_opts *opts);

/*
** Print value as an unsigned long int
**
** @return the number of printed characters
*/
int
ftrace_print_ulong(unsigned long long int value,
		   pid_t child,
		   const struct user_regs_struct *regs,
		   const struct s_ftrace_opts *opts);

/*
** Print flags given to open(2)
*/
int
ftrace_print_flags_open(unsigned long long int value,
			pid_t child,
			const struct user_regs_struct *regs,
			const struct s_ftrace_opts *opts);

/*
** Print flags given to stat(2)
*/
int
ftrace_print_stat_struct(unsigned long long int value,
			 pid_t child,
			 const struct user_regs_struct *regs,
			 const struct s_ftrace_opts *opts);

/*
** Print flages given to mmap(2)
*/
int
ftrace_print_mmap_flags(unsigned long long int value,
			pid_t child,
			const struct user_regs_struct *regs,
			const struct s_ftrace_opts *opts);

#endif

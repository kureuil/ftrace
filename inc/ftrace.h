/*
** ftrace.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Mon Apr 11 10:03:45 2016 Arch Kureuil
** Last update Mon Apr 11 10:25:57 2016 Arch Kureuil
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# define MANAGED(dtor)			__attribute__((__cleanup__(dtor)))
# define MAX(x, y)			((x) ^ (((x) ^ (y)) & -((x) < (y))))
# define ARRAYSIZE(arr)			(sizeof(arr) / sizeof(arr[0]))

/*
** Types of event:
**
** * E_SYSTEM_CALL: syscall
** * E_INTERNAL_CALL: function defined in binary
** * E_EXTERNAL_CALL: function defined in dynamically loaded library
** * E_SIGNAL: signal received by the tracee
*/
enum e_event
  {
    E_SYSTEM_CALL,
    E_INTERNAL_CALL,
    E_EXTERNAL_CALL,
    E_SIGNAL,
  };

/*
** Types of output:
**
** * O_INNATE: system stream, shouldn't be closed (e.g: stderr)
** * O_FILE: fopen's file, should be closed at the end of the program
** * O_COMMAND: popen's process, should be closed at the end of the program
*/
enum e_output_type
  {
    O_INNATE,
    O_FILE,
    O_COMMAND
  };

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
** Represent the options of the ftrace program.
**
** @member pid The PID of the traced process
** @member command The array given to execve (if any)
** @member prettify Guess arguments type and rettify them
** @member output The FILE where the output is written
** @member output_type The tpe of the output stream (see enum e_output_type)
** @member timestamp_type The type of timestamp dsplayed before any output
** (see enum e_timestamp_type)
*/
struct s_ftrace_opts
{
  pid_t			pid;
  char			**command;
  bool			prettify;
  FILE			*output;
  enum e_output_type	output_type;
  enum e_timestamp_type	timestamp_type;
};

/*
** Trace a program & print all of its call events to opts->output.
**
** @param child the pid of the tracee
** @param opts the options given to the program
** @return 0 case of success, any other value otherwise
*/
int	ftrace(pid_t child,
	       const struct s_ftrace_opts *opts);

#endif

/*
** ftrace-redirect.h for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-redirect
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 19:50:46 2016 Arch Kureuil
** Last update Sat Apr 16 21:52:27 2016 Arch Kureuil
*/

#ifndef FTRACE_REDIRECT_H_
# define FTRACE_REDIRECT_H_

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

#endif

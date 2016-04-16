/*
** ftrace-timestamp.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-timestamp
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Sat Apr 16 22:25:17 2016 Arch Kureuil
** Last update Sat Apr 16 22:25:56 2016 Arch Kureuil
*/

#ifndef FTRACE_TIMESTAMP_H_
# define FTRACE_TIMESTAMP_H_

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

#endif

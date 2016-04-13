/*
** peek.c for ftrace in /home/kureuil/Work/PSU_2015_ftrace
** 
** Made by Arch Kureuil
** Login   <kureuil@epitech.net>
** 
** Started on  Tue Apr 12 10:41:48 2016 Arch Kureuil
** Last update Tue Apr 12 11:06:40 2016 Arch Kureuil
*/

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

int
ftrace_peek_registers(pid_t child,
		      struct user_regs_struct *regs)
{
  assert(child != 0);
  assert(regs != NULL);
  errno = 0;
  if (ptrace(PTRACE_GETREGS, child, 0, regs) && errno)
    return (-1);
  return (0);
}

int
ftrace_peek_instruction(pid_t child,
			const struct user_regs_struct *regs,
			long *instrp)
{
  long	instruction;

  assert(child != 0);
  assert(regs != NULL);
  assert(instrp != NULL);
  errno = 0;
  instruction = ptrace(PTRACE_PEEKTEXT, child, regs->rip, 0);
  if (instruction == -1 && errno)
    return (-1);
  *instrp = instruction;
  return (0);
}

static int
ftrace_peek_string_slice(pid_t child,
			 unsigned long long int addr,
			 size_t readb,
			 char **strp)
{
  unsigned long	tmp;

  errno = 0;
  tmp = ptrace(PTRACE_PEEKDATA, child, addr + readb);
  if (errno)
    {
      (*strp)[readb] = '\0';
      return (-1);
    }
  memcpy(*strp + readb, &tmp, sizeof(tmp));
  if (memchr(&tmp, 0, sizeof(tmp)) != NULL)
    return (1);
  return (0);
}

void
ftrace_peek_string(pid_t child,
		   unsigned long long int addr,
		   char **strp)
{
  size_t	allocated;
  size_t	readb;

  allocated = 16;
  readb = 0;
  if ((*strp = realloc(*strp, allocated)) == NULL)
    return ;
  while (true)
    {
      if ((readb + sizeof(unsigned long)) > allocated)
	{
	  allocated <<= 1;
	  if ((*strp = realloc(*strp, allocated)) == NULL)
	    return ;
	}
      if (ftrace_peek_string_slice(child, addr, readb, strp))
	return ;
      readb += sizeof(unsigned long);
    }
}

int
ftrace_peek_buffer(pid_t child,
		   unsigned long long addr,
		   size_t n,
		   void *buffer)
{
  unsigned long tmp;
  size_t        readb;
  size_t	written;

  readb = 0;
  while (readb < n)
    {
      errno = 0;
      tmp = ptrace(PTRACE_PEEKDATA, child, addr + readb);
      if (errno)
	return (-1);
      if ((n - readb) / sizeof(tmp))
	written = sizeof(tmp);
      else
	written = n % sizeof(tmp);
      memcpy((void *)((uintptr_t)buffer + readb), &tmp, written);
      readb += written;
    }
  return (0);
}

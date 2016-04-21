##
## config.mk for philo in /home/louis/work/sysunix/PSU_2015_philo
##
## Made by Louis Person
## Login   <person_l@epitech.net>
##
## Started on  Tue Mar 01 19:25:03 2016 Louis Person
## Last update Thu Apr 21 12:52:16 2016 Arch Kureuil
##

NAME	= ftrace

SRCS	= \
	src/main.c \
	src/optparser.c \
	src/ftrace.c \
	src/event.c \
	src/peek.c \
	src/addins.c \
	src/elf.c \
	src/exec.c \
	src/registers.c \
	src/printers/base.c \
	src/printers/advanced.c \
	src/printers/mmap.c \
	src/printers/open.c \
	src/printers/stat.c

TSTSRCS =

LDFLAGS	+= -rdynamic -l dl -l elf

LIBS	= lib/libarray.a \
	lib/liberror.a \
	lib/libvector.a

ADDINS	= plugins/libftrace-syscall.so \
	plugins/libftrace-redirect.so \
	plugins/libftrace-timestamp.so \
	plugins/libftrace-funcall.so

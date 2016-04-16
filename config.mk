##
## config.mk for philo in /home/louis/work/sysunix/PSU_2015_philo
##
## Made by Louis Person
## Login   <person_l@epitech.net>
##
## Started on  Tue Mar 01 19:25:03 2016 Louis Person
## Last update Sat Apr 16 22:17:52 2016 Arch Kureuil
##

NAME	= ftrace

SRCS	= \
	src/main.c \
	src/optparser.c \
	src/optparsers/pid.c \
	src/optparsers/prettify.c \
	src/ftrace.c \
	src/event.c \
	src/peek.c \
	src/addins.c \
	src/registers.c \
	src/syscalls.c \
	src/handlers/syscall.c \
	src/printers/base.c \
	src/printers/advanced.c \
	src/printers/mmap.c \
	src/printers/open.c \
	src/printers/stat.c \
	src/handlers/callq.c \
	src/handlers/retq.c \

TSTSRCS =

LDFLAGS	+= -rdynamic -l dl

LIBS	= lib/libarray.a \
	lib/liberror.a \
	lib/libvector.a

ADDINS	= plugins/libftrace-syscall.so \
	plugins/libftrace-redirect.so

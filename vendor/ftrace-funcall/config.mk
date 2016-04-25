##
## config.mk for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
## 
## Made by Arch Kureuil
## Login   <kureuil@epitech.net>
## 
## Started on  Sat Apr 16 12:49:58 2016 Arch Kureuil
## Last update Mon Apr 25 15:40:57 2016 Arch Kureuil
##

TYPE		= "addin"

ADDINNAME	= ftrace-funcall

SRCS		= src/main.c \
		src/callq.c \
		src/retq.c

VENDOR		= ../

DEPS		= lib/liberror.a \
		lib/libvector.a

LIBS		= lib/libvector.a

CFLAGS		+= -I ../../inc/

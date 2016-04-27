##
## config.mk for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
## 
## Made by Arch Kureuil
## Login   <kureuil@epitech.net>
## 
## Started on  Sat Apr 16 12:49:58 2016 Arch Kureuil
## Last update Tue Apr 26 16:10:50 2016 Arch Kureuil
##

TYPE		= "addin"

ADDINNAME	= ftrace-funcall

SRCS		= src/main.c \
		src/callq.c \
		src/retq.c \
		src/symbols.c \
		src/section.c \
		src/dependencies.c

VENDOR		= ../

DEPS		= lib/liberror.a \
		lib/libvector.a

LIBS		= lib/libvector.a

CFLAGS		+= -I ../../inc/

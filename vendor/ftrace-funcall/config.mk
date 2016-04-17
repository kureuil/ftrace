##
## config.mk for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
## 
## Made by Arch Kureuil
## Login   <kureuil@epitech.net>
## 
## Started on  Sat Apr 16 12:49:58 2016 Arch Kureuil
## Last update Sun Apr 17 11:57:38 2016 Arch Kureuil
##

TYPE		= "addin"

ADDINNAME	= ftrace-funcall

SRCS		= src/main.c \
		src/callq.c \
		src/retq.c

VENDOR		= ../

DEPS		= lib/liberror.a

CFLAGS		+= -I ../../inc/

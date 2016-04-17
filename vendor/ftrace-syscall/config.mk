##
## config.mk for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
## 
## Made by Arch Kureuil
## Login   <kureuil@epitech.net>
## 
## Started on  Sat Apr 16 12:49:58 2016 Arch Kureuil
## Last update Sat Apr 16 23:37:19 2016 Arch Kureuil
##

TYPE		= "addin"

NAME		= libftrace-syscall.so

SRCS		= src/main.c \
		src/handler.c \
		src/syscalls.c

CFLAGS		+= -I ../../inc/

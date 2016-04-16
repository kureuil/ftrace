##
## config.mk for ftrace in /home/kureuil/Work/PSU_2015_ftrace/vendor/ftrace-syscall
## 
## Made by Arch Kureuil
## Login   <kureuil@epitech.net>
## 
## Started on  Sat Apr 16 12:49:58 2016 Arch Kureuil
## Last update Sat Apr 16 19:52:23 2016 Arch Kureuil
##

TYPE		= "addin"

NAME		= libftrace-redirect.so

SRCS		= src/main.c

VENDOR		= ../

DEPS		= lib/liberror.a

CFLAGS		+= -I ../../inc/

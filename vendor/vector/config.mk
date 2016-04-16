##
## config.mk for nmobjdump in /home/louis/work/sysunix/PSU_2015_nmobjdump/nm
##
## Made by Louis Person
## Login   <person_l@epitech.net>
##
## Started on  Mon Feb 15 21:06:24 2016 Louis Person
## Last update Sat Apr 16 18:21:33 2016 Arch Kureuil
##

TYPE		= "lib"

LIBNAME		= vector

VENDOR		= ../

SRCS		= src/clear.c \
		  src/delete.c \
		  src/destroy.c \
		  src/from.c \
		  src/get.c \
		  src/init.c \
		  src/map.c \
		  src/new.c \
		  src/remove.c \
		  src/set.c \
		  src/sort.c \
		  src/push_back.c \
		  src/pop_back.c \

DEPS		= lib/liberror.a

INCLUDES	= inc/vector.h

##
## rules.mk for philo in /home/louis/work/sysunix/PSU_2015_philo
##
## Made by Louis Person
## Login   <person_l@epitech.net>
##
## Started on  Tue Mar 01 19:29:43 2016 Louis Person
## Last update Sat Apr  9 13:34:58 2016 Arch Kureuil
##

run:
	./$(NAME)
.PHONY: run

resources/syscall.o: resources/syscall.s
	nasm -f elf64 -o $@ $^

resources/a.out: resources/syscall.o
	gcc -o resources/a.out -nostdlib $^

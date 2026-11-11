main: main.o list.o
	gcc main.o list.o -o main

main.o: main.c list.h
	gcc -Wall -Werror=vla -c main.c -o main.o

list.o: list.c list.h
	gcc -Wall -Werror=vla -c list.c -o list.o

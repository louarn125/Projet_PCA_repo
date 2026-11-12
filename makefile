main: main.o list.o
	gcc main.o list.o -o main

main.o: main.c list.h
	gcc -Wall -Werror=vla -c main.c -o main.o

list.o: list.c list.h
	gcc -Wall -Werror=vla -c list.c -o list.o

strhash: test_strhash.o strhash.o list.o
	gcc test_strhash.o strhash.o list.o -o test_strhash -lm

strhash.o: strhash.c strhash.h
	gcc -Wall -Werror=vla -c strhash.c -o strhash.o

test_strhash.o: test_strhash.c strhash.h
	gcc -Wall -Werror=vla -c test_strhash.c -o test_strhash.o
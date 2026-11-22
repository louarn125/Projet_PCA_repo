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

jeton: jeton_test.o jeton.o strhash.o list.o
	gcc jeton_test.o jeton.o strhash.o list.o -o jeton

jeton.o: jeton.c jeton.h
	gcc -Wall -Werror=vla -c jeton.c -o jeton.o

jeton_test.o: jeton_test.c jeton.h
	gcc -Wall -Werror=vla -c jeton_test.c -o jeton_test.o

espace_youenn: espace_youenn.o jeton.o strhash.o list.o
	gcc espace_youenn.o jeton.o strhash.o list.o -o espace_youenn -lm

espace_youenn.o: espace_youenn.c jeton.h
	gcc -Wall -Werror=vla -c espace_youenn.c -o espace_youenn.o
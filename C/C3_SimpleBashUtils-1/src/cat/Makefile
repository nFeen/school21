CC=gcc
CFLAGS=-Werror -Wall -Wextra

all: s21_cat

s21_cat: s21_cat.o declaration.o
	$(CC) $(CFLAGS) s21_cat.o declaration.o -o s21_cat

s21_cat.o: s21_cat.c
	$(CC) -c $(CFLAGS) s21_cat.c

declaration.o: declaration.c
	$(CC) -c $(CFLAGS) declaration.c

clean:
	rm *.o s21_cat

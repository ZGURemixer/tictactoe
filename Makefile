CC=gcc
CFLAGS=-I -Wall -Wextra -Werror

tictactoe: main.c ai.h structures.h
	gcc -o tictactoe main.c -I
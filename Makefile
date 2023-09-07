CC 		= gcc
FLAGS = -Wall -Wextra -Werror
DBG 	= -g

all: binmath.c calc.o
		$(CC) $(FLAGS) $(DBG) binmath.c calc.o -o binmath 

calc.o: calc.c calc.h
		$(CC) -c calc.c

clean:
		rm -f binmath.exe calc.o

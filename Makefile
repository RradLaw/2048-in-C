OBJS=	tilt.o \
	board.o \
	keyboard.o

all:	2048 test

%.o:	%.c Makefile 2048.h
	gcc -Wall -g -c $<

2048:	main.o $(OBJS)
	gcc -Wall -g -o 2048 main.o $(OBJS)

test:	test.o $(OBJS)
	gcc -Wall -g -o test test.o $(OBJS)

clean:
	rm 2048 test *.o

CC=gcc
CFLAGS=-std=c99 -Wall
EXEC=integrate

all : ${EXEC}

integrate : main.c integrate.o integrate.h
	$(CC) $(CFLAGS) $^ -o ${EXEC} -lm

integrate.o : integrate.c integrate.h
	$(CC) $(CFLAGS) -c $^ 

clean:
	-rm -rf *.o *~ core *.dSYM *.gch

clobber:
	-rm -rf *.o *~ core *.dSYM *.gch $(ALL)

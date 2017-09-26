CFLAGS= -g -Wall -pedantic

p1: main.o prefixTree.o trees.o
	gcc $(CFLAGS) -o p1 trees.o prefixTree.o main.o

main.o: main.c prefixTree.h trees.h
	gcc $(CFLAGS) -c main.c

prefixTree.o: prefixTree.c prefixTree.h trees.h
	gcc $(CFLAGS) -c prefixTree.c

trees.o: trees.c trees.h
	gcc $(CFLAGS) -c trees.c

clean:
	rm -f *.o *.~  *.gch p1
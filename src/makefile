CFLAGS= -g -Wall -pedantic

p1: main.o prefixTree.o trees.o utils.o
	gcc $(CFLAGS) -o p1 utils.o trees.o prefixTree.o main.o

main.o: main.c prefixTree.h trees.h utils.h
	gcc $(CFLAGS) -c main.c

prefixTree.o: prefixTree.c prefixTree.h trees.h utils.h
	gcc $(CFLAGS) -c prefixTree.c

trees.o: trees.c trees.h
	gcc $(CFLAGS) -c trees.c

item.o: item.c item.h
	gcc $(CFLAGS) -c item.c

utils.o: utils.c utils.h prefixTree.h
	gcc $(CFLAGS) -c utils.c

clean:
	rm -f *.o *.~  *.gch p1
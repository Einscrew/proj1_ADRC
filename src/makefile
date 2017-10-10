CFLAGS= -g -Wall -pedantic

p1: main.o prefixTree.o binaryTree.o trees.o utils.o 
	gcc $(CFLAGS) -o p1 utils.o trees.o binaryTree.o prefixTree.o main.o

main.o: main.c prefixTree.h binaryTree.h trees.h utils.h
	gcc $(CFLAGS) -c main.c

prefixTree.o: prefixTree.c prefixTree.h binaryTree.h trees.h utils.h
	gcc $(CFLAGS) -c prefixTree.c

trees.o: trees.c trees.h
	gcc $(CFLAGS) -c trees.c

binaryTree.o: binaryTree.c binaryTree.h
	gcc $(CFLAGS) -c binaryTree.c
	
utils.o: utils.c utils.h prefixTree.h binaryTree.h
	gcc $(CFLAGS) -c utils.c

clean:
	rm -f *.o *.~  *.gch p1
CFLAGS= -g -Wall -pedantic

#lab06: lab06.o trees.o
#	gcc $(CFLAGS) -o lab06 trees.o lab06.o

#lab06.o: lab06.c trees.h queue.h
#	gcc $(CFLAGS) -c lab06.c

tree.o: trees.c trees.h
	gcc $(CFLAGS) -c trees.c

clean:
	rm -f *.o *.~  *.gch #lab06
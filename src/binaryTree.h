#ifndef BINARY_TREES
#define BINARY_TREES

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define NOT_CREATE -10


struct _BNode{
	int value;
	struct _BNode *one, *two, *three, *four;
};

typedef struct _BNode BNode;


BNode *allocBNode();
BNode *newBNode(int num);
BNode *getOne(BNode * node);
BNode *getTwo(BNode * node);
BNode *getThree(BNode * node);
BNode *getFour(BNode * node);
int getBValue(BNode *node);
BNode *setOne(BNode *node, int num);
BNode *setTwo(BNode *node, int num);
BNode *setThree(BNode *node, int num);
BNode *setFour(BNode *node, int num);
void setBValue(BNode *node, int num);
void freeBTree(BNode *root);

#endif

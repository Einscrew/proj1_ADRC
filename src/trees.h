#include <stdlib.h>
#include <stdio.h>

#ifndef TREES
#define TREES

typedef enum{
	FALSE=0,
	TRUE=1
} Boolean;

typedef struct _Node Node;

Node *allocNode();
Node *newNode(int num);
void freeTree(Node * root);

#endif
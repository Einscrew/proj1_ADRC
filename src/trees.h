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
Node *getRight(Node * node);
Node *getLeft(Node * node);
int getValue(Node * node);
void setRight(Node * node, int num);
void setLeft(Node * node, int num);
void setValue(Node ** node, int num);
void freeTree(Node * root);

#endif
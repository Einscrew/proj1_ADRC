#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef TREES
#define TREES

typedef enum{
	FALSE=0,
	TRUE=1
} Boolean;

typedef struct _Node Node;

Node *allocNode();
Node *newNode(int num, int prefixLen);
Node *getRight(Node *node);
Node *getLeft(Node *node);
int getValue(Node *node);
char *getPrefix(Node *node);
void setRight(Node *node, int num, int prefixLen);
void setLeft(Node *node, int num, int prefixLen);
void setValue(Node ** node, int num);
void setPrefix(Node *node, char *prefix);
void freeTree(Node *root);

#endif

#include <string.h>
#include "trees.h"

#ifndef PREF
#define PREF

#define NO_HOPE -1

//void insertNode(char * ptrPref, int nextHop, int height, Node * node, int i);
void insertNode(Node *node, char prefix[16], int nextHop, int prefixLength, int number);
void printTree(Node * node);

#endif

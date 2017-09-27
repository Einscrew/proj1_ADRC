#include <string.h>
#include "trees.h"

#ifndef PREF
#define  PREF

#define NO_HOPE -1

void insertNode(char * ptrPref, int nextHop, int height, Node * node, int i);
Node* PrefixTree();
void printTree(Node * node);

#endif
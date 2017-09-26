#include <string.h>
#include "trees.h"

#ifndef PREF
#define  PREF

void insertNode(char * ptrPref, int nextHop, int height, Node * node, int i);
Node* PrefixTree();
void printTree(Node * node);

#endif
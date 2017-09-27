#include <string.h>
#include "trees.h"

#ifndef PREF
#define PREF

#define NO_HOPE -1

Node* PrefixTree();

void insertNode(char* prefix, int nextHop, int prefixLength, Node *node, int index);
//void insertNode(Node *node, char prefix[16], int nextHop, int prefixLength, int number);
void printTree(Node * node);

#endif

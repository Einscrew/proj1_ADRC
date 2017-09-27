#include <string.h>
#include "trees.h"

#ifndef _PREF_
#define _PREF_

#define NO_HOP -1

Node* PrefixTree();
int lookUp(Node * node, char * address);
void insertNode(char* prefix, int nextHop, int prefixLength, Node *node, int index);
void printTree(Node * node);

#endif

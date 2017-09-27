#include <string.h>
#include "trees.h"

#ifndef _PREF_
#define  _PREF_

void insertNode(char * ptrPref, int nextHop, int height, Node * node, int i);
Node* PrefixTree();
int lookUp(Node * node, char * address);
void printTree(Node * node);

#endif
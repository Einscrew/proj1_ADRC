#include <string.h>
#include "trees.h"
#include "utils.h"

#ifndef _PREF_
#define _PREF_

#define NO_HOP -1


Node* PrefixTree(char const * file);
void PrintTable(Node *node);
int LookUp(Node * node, char * address);
void InsertPrefix(char* prefix, int nextHop, int prefixLength, Node *node, int index);
void DeletePrefix(Node * root, char * prefix);
void PrintPrefix(int hop);


#endif

#include <string.h>
#include "trees.h"

#ifndef _PREF_
#define _PREF_

#define NO_HOP -1

void menu(Node *node);
Node* PrefixTree();
void PrintTable(Node *node);
int LookUp(Node * node, char * address);
void InsertPrefix(char* prefix, int nextHop, int prefixLength, Node *node, int index);
void DeletePrefix(Node * root, char * prefix);
void PrintPrefix(int hop);
void showMenu();

#endif

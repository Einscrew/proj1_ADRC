#ifndef _PREF_
#define _PREF_

#include <string.h>
#include "trees.h"
#include "utils.h"
#include "binaryTree.h"

#define NO_HOP -1
#define PREF_MAX_SIZE 16
#define LINE 20
#define DEFAULT -2

#define RETURN 0
#define ERASE 1

#define RIGHT 1
#define LEFT 0
#define REMOVE -3


Node* PrefixTree(char const * file);
void PrintTable(Node *node, char *str1, char *str2);
int LookUp(Node * node, char * address);
void InsertPrefix(char* prefix, int nextHop, int prefixLength, Node *node, int index);
void DeletePrefix(Node * root, char*prefix);
int deleteP(Node *node, char *prefix, int index, int prefixLength);
void BinaryToTwoBit(Node * BinTree, BNode * TwoBit);
void PrintTableEven(BNode *node, char *str1, char *str2);


//void PrintPrefix(int hop);
//void PrintTable(Node *node);

#endif

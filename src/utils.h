#ifndef _UTILS_
#define _UTILS_

#include "prefixTree.h"

#define NOT_VALID -5
#define VALID 1

void menu(Node *node);
void showMenu();
int checkPrefix(char * prefix);
void * mallocVerified(int number, int size);

#endif

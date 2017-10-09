#ifndef _UTILS_
#define _UTILS_

#include "prefixTree.h"

#define NOT_VALID -5
#define VALID 1

#define DFLT_STR "E"
#define DFLT_CHAR 'E'

void menu(Node *node);
void showMenu();
int checkPrefix(char * prefix);
int scanOption();
void * mallocVerified(int number, int size);

#endif

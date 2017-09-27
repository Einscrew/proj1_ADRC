#include <stdlib.h>
#ifndef _ITEM_
#define _ITEM_

typedef int Item;

Item newItem(Item value);
Item changeItem(Item item, Item newValue);
void freeItem(Item item);

#endif
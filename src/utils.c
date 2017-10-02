#include "utils.h"

int checkPrefix(char * prefix){
	return strlen(prefix) < 16 ? 1 : 0;
}
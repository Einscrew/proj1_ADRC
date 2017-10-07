#include "prefixTree.h"

int main(int argc, char const *argv[])
{
	// Last argument is the file to read from
	char const * file = argv[argc-1];
	Node *root = PrefixTree(file);

	if(root != NULL)	
		menu(root);
	
	freeTree(root);
	return 0;
}

#include "prefixTree.h"

int main(int argc, char const *argv[])
{
	// Last argument is the file to read from
	char const * file = argv[argc-1];
	Node *root = PrefixTree(file);

	if(root != NULL)	
		menu(root);
	//PrintTree(root, "", "");
	//DeletePrefix(root, "1");
	/*InsertPrefix("1111000011110000", 13, 16, root, 0);
	printf("-----------------------------------------\n");
	PrintTree(root, "", "");

	printf("-----------------------------------------\n");
	PrintTree(root, "", "");*/
	
	freeTree(root);
	return 0;
}

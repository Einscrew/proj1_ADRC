#include "prefixTree.h"

int main(int argc, char const *argv[])
{
	// Last argument is the file to read from
	char const * file = argv[argc-1];
	Node *root = PrefixTree(file);
	menu(root);
	/*int i = 5;
	char address[17] = "\0";*/
	/*while(i){
		fgets(address, 18, stdin);
		printf("\n->%d\n\n", lookUp(root, address));
		i--;
	}*/
	/*PrintTable(root);
	DeletePrefix(root, "1");
	printf("---------------\n");
	PrintTable(root);*/
	freeTree(root);
	return 0;
}

#include "prefixTree.h"

int main(int argc, char const *argv[])
{

	Node * root = PrefixTree();
	int i = 5;
	char address[17] = "\0";
	while(i){
		fgets(address, 18, stdin);
		printf("\n->%d\n\n", lookUp(root, address));
		i--;
	}

	PrintTable(root);

	freeTree(root);
	return 0;
}

#include "prefixTree.h"


void PrintTree(Node * node, char*str1, char*str2){
	if(node == NULL){
			return;
	}

	char * aux = mallocVerified(strlen(str1)+strlen(str2) +1, sizeof(char*));
	for(int i=0; i < strlen(str1)+strlen(str2) + 1 ; i++){
		aux[i] = '\0';
	}
	strcat(aux, str1);
	strcat(aux, str2);

	PrintTree(getLeft(node), aux, "0");
	PrintTree(getRight(node), aux, "1");

	if(getValue(node) != -1){
		printf("%s >%d\n",aux, getValue(node));
	}

	free(aux);

}

int main(int argc, char const *argv[])
{
	// Last argument is the file to read from
	char const * file = argv[argc-1];
	Node *root = PrefixTree(file);
	//menu(root);
	PrintTree(root, "", "");
	//DeletePrefix(root, "1");
	InsertPrefix("1111000011110000", 13, 16, root, 0);
	printf("-----------------------------------------\n");
	PrintTree(root, "", "");

	printf("-----------------------------------------\n");
	PrintTree(root, "", "");
	freeTree(root);
	return 0;
}

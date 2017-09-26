#include "stdlib"
#include "stdio.h"
#include "trees.h"
#include "prefixTree.h"

Node* PrefixTree(){

	FILE* ptr = fopen("nome_do_ficheiro", "r");
	char line[20];
	char prefix[16];
	int nextHop = 0;
	Node *root = newNode(-1);

	if(ptr == NULL)
	{
		printf("There isn't any file");
		exit(-1);
	}

	while((line = fgets(line, 20, "nome_do_ficheiro")) != EOF)
	{
		sscanf(line, "%s %d", prefix, nextHop);
		//insertNode(prefix, nextHop);
	}


	fclose(ptr);	
	return root;

}
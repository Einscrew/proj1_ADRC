#include "prefixTree.h"

#define FICH "t.txt"
#define PREF_MAX_SIZE 16
#define LINE 20

/*void insertNode(char* p, int nextHop, int height, Node * node, int i){
	if(height > 0){
		if(p[i] == '1'){
			if(getRight(node) == NULL)
				setRight(node, -1);

			insertNode(p, nextHop, --height, (Node *)getRight(node),++i);
			
		}
		else if(p[i]=='0'){
			if(getLeft(node) == NULL)
				setLeft(node, -1);

			insertNode(p, nextHop, --height, (Node *)getLeft(node),++i);
			
		}
	}
	else{
		setValue(&node, nextHop);
	}
}*/

Node* PrefixTree(){

	FILE* ptr = fopen(FICH, "r");
	char line[LINE];
	char prefix[PREF_MAX_SIZE];
	int nextHop = 0;
	Node *root = newNode(-1);

	if(ptr == NULL)
	{
		printf("There isn't any file");
//------------exit(-1);
		return NULL;
	}

	while(fgets(line, 20, ptr)!= NULL){
	
		sscanf(line, "%s %d", prefix, &nextHop);
		printf("\t\t%s----%d\n", prefix, nextHop);
		//insertNode(prefix, nextHop, strlen(prefix), root, 0);
		insertNode(root, prefix, nextHop, strlen(prefix), 0);
	}
	//printf("%d || %d\n",getValue(getLeft(root)), getValue(getLeft(getLeft(root))) );
	printTree(root);


	fclose(ptr);	
	return root;

}

/* number - indice para tirar o 0 ou 1 de cada posição do vector
   prefixLength - tamanho do prefixo 
   o primeiro nó, a root, não pode ser nulo */


void insertNode(Node *node, char prefix[16], int nextHop, int prefixLength, int number){

	if(node == NULL){

		if(number < prefixLength){
			node = newNode(NO_HOPE);
			number++;
		}
		else{
			newNode(nextHop);
			return;
		}
	}

	if(strcmp(prefix[number], "0") == 0)
		(Node *)getLeft(node) = insertNode((Node *)getLeft(node), prefix, nextHop, prefixLength, number+1);
	else
		(Node *)getRight(node) = insertNode((Node *)getRight(node), prefix, nextHop, prefixLength, number+1);
		
}





void printTree(Node * node){
	if(getLeft(node) == NULL){
		printf("%d\n", getValue(node));
	}
	else
		printTree(getLeft(node));

	if(getRight(node) == NULL){
		printf("%d\n", getValue(node));
	}
	else
		printTree(getRight(node));
}
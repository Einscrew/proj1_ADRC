#include "prefixTree.h"

#define FICH "t.txt"
#define PREF_MAX_SIZE 16
#define LINE 20

void insertNode(char* prefix, int nextHop, int prefixLength, Node *node, int index){

	if(prefixLength > 0){
		if(prefix[index] == '1'){
			if(getRight(node) == NULL)
				setRight(node, -1);
			insertNode(prefix, nextHop, --prefixLength, (Node *)getRight(node),++index);
			
		}
		else if(prefix[index]=='0'){
			if(getLeft(node) == NULL)
				setLeft(node, -1);
			insertNode(prefix, nextHop, --prefixLength, (Node *)getLeft(node),++index);
		}
	}
	else
		setValue(&node, nextHop);
}

Node* PrefixTree(){

	FILE* ptr = fopen(FICH, "r");
	char line[LINE];
	char prefix[PREF_MAX_SIZE];
	int nextHop = 0;
	Node *root = newNode(NO_HOPE);
	Node *aux = root;

	if(ptr == NULL)
	{
		printf("There isn't any file");
//------------exit(-1);
		return NULL;
	}

	while(fgets(line, 20, ptr)!= NULL){
	
		sscanf(line, "%s %d", prefix, &nextHop);
		printf("\t\t%s----%d\n", prefix, nextHop);
		insertNode(prefix, nextHop, strlen(prefix), root, 0);
		//insertNode(aux, prefix, nextHop, strlen(prefix), 0);
	}
	//printf("%d || %d\n",getValue(getLeft(root)), getValue(getLeft(getLeft(root))) );
	printTree(root);


	fclose(ptr);	
	return root;

}

/* number - indice para tirar o 0 ou 1 de cada posição do vector
   prefixLength - tamanho do prefixo 
   o primeiro nó, a root, não pode ser nulo */


/*
	printf("len: %d\n", prefixLength);
	printf("prefix: %s\n", prefix);
	printf("Index: %d\n", number);
	printf("nextHop: %d\n", nextHop);

	if(node == NULL){

		if(number < prefixLength){

			node = newNode(NO_HOPE);
			number++;
			printf("criou nó\n");
		}
		else{

			node = newNode(nextHop);
			setValue(&node, nextHop);
			printf("criou nó nextHop\n");
			return;
		}
	}
	else if(node != NULL && number == prefixLength){
		setValue(&node, nextHop);
		return;
	}


	if(strcmp(&prefix[number], "0") == 0)
		insertNode((Node *)getLeft(node), prefix, nextHop, prefixLength, number+1);
	else
		insertNode((Node *)getRight(node), prefix, nextHop, prefixLength, number+1);
		
}*/





/*void printTree(Node * node){

	printf("ROOT next hop: %d\n", getValue(node));

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
}*/

void printTree(Node *n) /*see declaration of TNode below*/

{

     if(n==NULL)
         return;

     printTree(getLeft(n));

     printTree(getRight(n));

     printf("%d\n", getValue(n));

}
 




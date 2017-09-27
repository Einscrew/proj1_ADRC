#include "prefixTree.h"

#define FICH "t.txt"
#define PREF_MAX_SIZE 16
#define LINE 20
#define NO_HOP -1

void insertNode(char* p, int nextHop, int height, Node * node, int i){
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
}

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
		insertNode(prefix, nextHop, strlen(prefix), root, 0);
	}
	//printf("%d || %d\n",getValue(getLeft(root)), getValue(getLeft(getLeft(root))) );
	//printTree(root);

	fclose(ptr);	
	return root;

}


int lookUp(Node* root, char * address){
	Node * aux = root;
	int ret = -1;
	int i = 0;
	while(aux != NULL){
		if(getValue(aux)!= NO_HOP)
			ret = getValue(aux);

		if( address[i++] == '0'){
			aux = getLeft(aux);
		}
		else
			aux = getRight(aux);
	}

	return ret;
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
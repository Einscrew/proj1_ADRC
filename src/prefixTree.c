#include "prefixTree.h"

#define FICH "t.txt"
#define PREF_MAX_SIZE 16
#define LINE 20
#define NO_HOP -1

void insertPrefix(char* prefix, int nextHop, int prefixLength, Node *node, int index){

	if(prefixLength > 0){
		if(prefix[index] == '1'){
			if(getRight(node) == NULL)
				setRight(node, NO_HOP, prefixLength);
			insertPrefix(prefix, nextHop, --prefixLength, (Node *)getRight(node), ++index);
			
		}
		else if(prefix[index]=='0'){
			if(getLeft(node) == NULL)
				setLeft(node, NO_HOP, prefixLength);
			insertPrefix(prefix, nextHop, --prefixLength, (Node *)getLeft(node), ++index);
		}
	}
	else{
		setValue(&node, nextHop);
		setPrefix(node, prefix);
	}
}

Node* PrefixTree(){

	FILE* ptr = fopen(FICH, "r");
	char line[LINE];
	char prefix[PREF_MAX_SIZE];
	int nextHop = 0;
	Node *root = newNode(NO_HOP, 1);

	if(ptr == NULL)
	{
		printf("There isn't any file");
		return NULL;
	}

	while(fgets(line, 20, ptr)!= NULL){
	
		sscanf(line, "%s %d", prefix, &nextHop);
		//printf("\t\t%s----%d\n", prefix, nextHop);
		insertPrefix(prefix, nextHop, strlen(prefix), root, 0);
	}
	
	fclose(ptr);	
	return root;

}

void PrintTable(Node *node){

     if(node == NULL)
        return;
 
     /* first recur on left child */
     PrintTable(getLeft(node));
 
     /* then print the data of node */
     if(getValue(node) != NO_HOP)
     	printf("%s %d\n", getPrefix(node), getValue(node));  
 
     /* now recur on right child */
     PrintTable(getRight(node));

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

void deletePrefix(Node * root, char * prefix){
	// If the node to remove has no childs, then it can be erases,
	// but if it does, only the nextHop is changed
	Node * aux = root;
	int i = 0;
	int prefixLength = strlen(prefix);
	while(i < prefixLength){
		if( prefix[i++] == '0')
			aux = getLeft(aux);
		
		else
			aux = getRight(aux);
	}
	if(getRight(aux) == NULL && getLeft(aux) == NULL){
		free(getPrefix(aux));
		free(aux);
	}
	else{
		setPrefix(aux, NULL);
		setValue(&aux, NO_HOP);
	}
}

/* To test */

/*
void printTree(Node *node)
{
     if(node == NULL)
        return;
 
     printTree(getLeft(node));
 

     printf("%d\n", getValue(node));
     printf("%s\n", getPrefix(node)); 
 

     printTree(getRight(node));
}
*/





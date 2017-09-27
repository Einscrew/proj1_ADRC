#include "prefixTree.h"

#define FICH "t.txt"
#define PREF_MAX_SIZE 16
#define LINE 20

void insertNode(char* prefix, int nextHop, int prefixLength, Node *node, int index){

	if(prefixLength > 0){
		if(prefix[index] == '1'){
			if(getRight(node) == NULL)
				setRight(node, NO_HOPE);
			insertNode(prefix, nextHop, --prefixLength, (Node *)getRight(node), ++index);
			
		}
		else if(prefix[index]=='0'){
			if(getLeft(node) == NULL)
				setLeft(node, NO_HOPE);
			insertNode(prefix, nextHop, --prefixLength, (Node *)getLeft(node), ++index);
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

	if(ptr == NULL)
	{
		printf("There isn't any file");
		return NULL;
	}

	while(fgets(line, 20, ptr)!= NULL){
	
		sscanf(line, "%s %d", prefix, &nextHop);
		printf("\t\t%s----%d\n", prefix, nextHop);
		insertNode(prefix, nextHop, strlen(prefix), root, 0);
	}
	
	printTree(root);


	fclose(ptr);	
	return root;

}


/* To test */

void printTree(Node *node)
{
     if (node == NULL)
          return;
 
     /* first recur on left child */
     printTree(getLeft(node));
 
     /* then print the data of node */
     printf("%d\n", getValue(node));  
 
     /* now recur on right child */
     printTree(getRight(node));
}
 




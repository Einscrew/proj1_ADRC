#include "prefixTree.h"

#define FICH "t.txt"
#define PREF_MAX_SIZE 16
#define LINE 20
#define NO_HOP -1
#define DEFAULT -2

#define RIGHT 1
#define LEFT 0
#define REMOVE -3

int prefixMap[PREF_MAX_SIZE] = {NO_HOP};
int prefixIndex = -1;

void insertPrefix(char* prefix, int nextHop, int prefixLength, Node *node, int index){

	if(prefixLength > 0){
		if(prefix[index] == '1'){
			if(getRight(node) == NULL)
				setRight(node, NO_HOP);
			insertPrefix(prefix, nextHop, --prefixLength, (Node *)getRight(node), ++index);
			
		}
		else if(prefix[index]=='0'){
			if(getLeft(node) == NULL)
				setLeft(node, NO_HOP);
			insertPrefix(prefix, nextHop, --prefixLength, (Node *)getLeft(node), ++index);
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
	Node *root = newNode(NO_HOP);

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


void PrintPrefix(int hop){

	int i = 0;
	
	while(i <= prefixIndex){
		printf("%d", prefixMap[i]);
		i++;
	}
	printf("  >%d\n",hop );
}


void PrintTable(Node *node){

	if (node == NULL)
		return;

	if(getValue(node) != NO_HOP)
		PrintPrefix(getValue(node));

	prefixMap[++prefixIndex] = LEFT;
	PrintTable(getLeft(node));
	prefixMap[prefixIndex--] = NO_HOP;


	prefixMap[++prefixIndex] = RIGHT;
	PrintTable(getRight(node));
	prefixMap[prefixIndex--] = NO_HOP;

}

int lookUp(Node* root, char *address){
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

void deletePrefix(Node *root, char *prefix){
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
	if(getRight(aux) == NULL && getLeft(aux) == NULL)
		free(aux);
	else
		setValue(&aux, NO_HOP);
}


void menu(Node *node){

	int option = 0;
	int nextHop = NO_HOP;
	char *address;
	char *prefix;

	showMenu();

	while(option != 5){

		scanf("%d", &option);

		//system("clear");

		switch(option){

			case 1: 
				PrintTable(node);
				break;
			case 2:
				printf("Enter an address to search: \n");
				address = (char*)malloc(16 * sizeof(char));
				scanf("%s", address);
				nextHop = lookUp(node, address);
				printf("\nNext Hop: %d\n", nextHop);
				free(address);
				break;
			case 3:
				printf("Enter a new prefix and, after a space, the associated next hop: \n");
				prefix = (char*)malloc(16 * sizeof(char));
				scanf("%s %d", prefix, &nextHop);
				insertPrefix(prefix, nextHop, strlen(prefix), node, 0);
				free(prefix);
				break;
			case 4:
				printf("Enter the prefix to delete: \n");
				prefix = (char*)malloc(16 * sizeof(char));
				scanf("%s", prefix);
				deletePrefix(node, prefix);
				free(prefix);
				break;
			case 5:
				freeTree(node);
				exit(-1);
				break;
			default:
				printf("Enter a valid option\n");
		}

		showMenu();
	}


	/*while(scanf("%d", &option)){

		address = "";
		prefix = "";

		if(option == 1)
			PrintTable(node);
		else if(option == 2){

			printf("Enter an address to search: ");
			scanf("%s", address);
			lookUp(node, address);
		}
		else if(option == 3){

			printf("Enter a new prefix and after a space the associated next hop: ");
			scanf("%s %d", prefix, &nextHop);
			insertPrefix(prefix, nextHop, strlen(prefix), node, 0);
		}
		else if(option == 4){

			printf("Enter the prefix to delete: ");
			scanf("%s", prefix);
			deletePrefix(node, prefix);
		}
		else if(option == 5)
			return;
		else
			printf("Enter a valid option\n");
	}*/
}


void showMenu(){

	printf("\n- Choose an option:\n\n");
	printf("1. Print Prefix Table\n");
	printf("2. Insert an address and get the next hop\n");
	printf("3. Insert a new prefix in tree and the associated next hop\n");
	printf("4. Delete a prefix from the tree\n");
	printf("5. Exit\n\n");

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





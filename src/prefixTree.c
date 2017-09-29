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

/******************************************************************************************
 * menu()
 *
 * Arguments: node - pointer to tree root
 *			 
 * Returns: (void)
 * Side-Effects: prints the menu
 *
 * Description: prints the menu to the screen in order to show all commands available to the
 * user
 *
 ******************************************************************************************/

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
				nextHop = LookUp(node, address);
				printf("\nNext Hop: %d\n", nextHop);
				free(address);
				break;
			case 3:
				printf("Enter a new prefix and, after a space, the associated next hop: \n");
				prefix = (char*)malloc(16 * sizeof(char));
				scanf("%s %d", prefix, &nextHop);
				InsertPrefix(prefix, nextHop, strlen(prefix), node, 0);
				free(prefix);
				break;
			case 4:
				printf("Enter the prefix to delete: \n");
				prefix = (char*)malloc(16 * sizeof(char));
				scanf("%s", prefix);
				DeletePrefix(node, prefix);
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
}

/******************************************************************************************
 * PrefixTree()
 *
 * Arguments: (none)
 * Returns: root tree
 * Side-Effects: builds the tree through the file given
 *
 * Description: reads a file line by line and constructs the tree according to th file
 *
 ******************************************************************************************/

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
		InsertPrefix(prefix, nextHop, strlen(prefix), root, 0);
	}
	
	fclose(ptr);	
	return root;

}

/******************************************************************************************
 * PrintTable()
 *
 * Arguments: node - pointer to a tree node
 *
 * Returns: (void)
 * Side-Effects: prints a prefix table having a prefix tree as a input
 *
 * Description: giving the root tree, all the nodes of that tree are visited, recursively, 
 * and the prefix at each node is kept in order to print a prefix, if there is a next hop 
 * associated with that node
 *
 ******************************************************************************************/

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

/******************************************************************************************
 * LookUp()
 *
 * Arguments: node - pointer to tree root
 *			  address - address given to search in tree
 * Returns: next hop of the address the user is looking for
 * Side-Effects: search the next hop of the addres given
 *
 * Description: having a tree as an input and a given address, it returns the next hop of
 * that address
 *
 ******************************************************************************************/

int LookUp(Node *root, char *address){

	Node *aux = root;
	int ret = -1;
	int i = 0;

	while(aux != NULL){

		if(getValue(aux)!= NO_HOP)
			ret = getValue(aux);

		if(address[i++] == '0')
			aux = getLeft(aux);
		else
			aux = getRight(aux);
	}

	return ret;
}

/******************************************************************************************
 * InsertPrefix()
 *
 * Arguments: prefix - prefix to insert in tree
 *			  nextHop - next hop of the prefix to insert
 *			  prefixLength - prefix length
 *			  node - pointer to tree root
 *			  index - iterates de prefix
 * Returns: (void)
 * Side-Effects: insert a new prefix in tree
 *
 * Description: given a certain prefix and the associated next hop, this function inserts a
 * new node in the tree, searching for the right place to put it, recursively
 *
 ******************************************************************************************/

void InsertPrefix(char *prefix, int nextHop, int prefixLength, Node *node, int index){

	if(prefixLength > 0){
		if(prefix[index] == '1'){
			if(getRight(node) == NULL)
				setRight(node, NO_HOP);
			InsertPrefix(prefix, nextHop, --prefixLength, (Node *)getRight(node), ++index);
			
		}
		else if(prefix[index]=='0'){
			if(getLeft(node) == NULL)
				setLeft(node, NO_HOP);
			InsertPrefix(prefix, nextHop, --prefixLength, (Node *)getLeft(node), ++index);
		}
	}
	else
		setValue(&node, nextHop);

}

/**********************************************************************************************
 * DeletePrefix()
 *
 * Arguments: root - pointer to tree root
 *			  prefix - prefix to delete
 * Returns: (void)
 * Side-Effects: deletes a node from the tree
 *
 * Description: if the node to remove has no children, then it can be erased, otherwise, only
 * the next hop is changed to NO_HOP
 *
 **********************************************************************************************/

void DeletePrefix(Node *root, char *prefix){
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

/******************************************************************************************
 * PrintPrefix()
 *
 * Arguments: hop - next hop of the node
 *
 * Returns: (void)
 * Side-Effects: prints the prefix and the correspondent next hop
 *
 * Description: used to print both prefix and next hop of a node
 *
 ******************************************************************************************/

void PrintPrefix(int hop){

	int i = 0;
	
	while(i <= prefixIndex){
		printf("%d", prefixMap[i]);
		i++;
	}
	printf("  >%d\n",hop );
}

/*********************************************************************************************
 * showMenu()
 *
 * Arguments: (none)
 * Returns: (void)
 * Side-Effects: prints a simple menu
 *
 * Description: prints a menu with all options that user haa to deal with the tree
 *
 *********************************************************************************************/


void showMenu(){

	printf("\n- Choose an option:\n\n");
	printf("1. Print Prefix Table\n");
	printf("2. Insert an address and get the next hop\n");
	printf("3. Insert a new prefix in tree and the associated next hop\n");
	printf("4. Delete a prefix from the tree\n");
	printf("5. Exit\n\n");

}




#include "utils.h"

#define PREF_MAX_SIZE 16

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
	char *address = NULL;
	char *prefix = NULL;


	showMenu();
	while(option != 5){
		
		printf(" OPTION _____ANTES_____ %d\n", option);
		option = 0;
		scanf("%d", &option);

		system("clear");
		printf(" OPTION _______________ %d\n", option);

		switch(option){

			case 1: 
				//PrintTable(node);
				PrintTree(node, "", "");
				printf("SAIU DO PRINTTABLE\n");

				break;
			case 2:
				printf("Enter an address to search: \n");
				address = (char*)malloc((PREF_MAX_SIZE+1) * sizeof(char));
				scanf("%s", address);
				nextHop = LookUp(node, address);
				printf("\nNext Hop: %d\n", nextHop);
				free(address);
				break;
			case 3:
				printf("Enter a new prefix and, after a space, the associated next hop: \n");
				prefix = (char*)malloc((PREF_MAX_SIZE+1) * sizeof(char));
				scanf("%s %d", prefix, &nextHop);
				printf("\n%s %d\n", prefix, nextHop);

				checkPrefix(prefix);
				InsertPrefix(prefix, nextHop, strlen(prefix), node, 0);
				free(prefix);
				prefix = NULL;
				break;
			case 4:
				printf("Enter the prefix to delete: \n");
				prefix = (char*)malloc((PREF_MAX_SIZE+1) * sizeof(char));
				scanf("%s", prefix);
				DeletePrefix(node, prefix);
				free(prefix);
				break;
			case 5:
				return;
				break;
			default:
				printf("Enter a valid option\n");
		}
		showMenu();

	}
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

	printf("\n- Choose an option (by pressing it's number):\n\n");
	printf("1. Print Prefix Table\n");
	printf("2. Insert an address and get the next hop\n");
	printf("3. Insert a new prefix in tree and the associated next hop\n");
	printf("4. Delete a prefix from the tree\n");
	printf("5. Exit\n\n");

}

/******************************************************************************************
 * checkPrefix()
 *
 * Arguments: prefix - prefix to be verified
 *			 
 * Returns: (int)
 * Side-Effects: -
 *
 * Description: Used to confirme if 'prefix' has a length between 0 and 16 bits
 * 
 *
 ******************************************************************************************/


int checkPrefix(char * prefix){
	return strlen(prefix) <= 16 ? 1 : 0;
}

void * mallocVerified(int number, int size){
	void * ptr = malloc(size * number);

	if(ptr == NULL){
		printf("ERROR on malloc\n");
		exit(1);
	}
	return ptr;
}


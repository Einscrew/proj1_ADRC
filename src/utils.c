#include "utils.h"

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
	int check = 0;


	showMenu();
	while(option != 5){
		
		//option = 0;
		scanf("%d", &option);

		system("clear");

		switch(option){

			case 1: 
				PrintTable(node, "", "");
				break;
			case 2:
				printf("Enter an address to search: \n");
				address = (char*)mallocVerified((PREF_MAX_SIZE+8), sizeof(char));
				scanf("%s", address);
				nextHop = LookUp(node, address);
				if(nextHop != NO_HOP && nextHop != DEFAULT && nextHop != NOT_VALID)
					printf("\nNext Hop: %d\n", nextHop);
				else if(nextHop == NOT_VALID)
					printf("\nAddress is not valid. Please enter a valid address and get the next-hop\n");
				else
					printf("\nThere's no next-hop for that address\n");
				free(address);
				break;
			case 3:
				printf("Enter a new prefix and, after a space, the associated next hop: \n");
				prefix = mallocVerified((PREF_MAX_SIZE+8), sizeof(char));
				scanf("%s %d", prefix, &nextHop);
				printf("\n%s %d\n", prefix, nextHop);
				check = checkPrefix(prefix);
				printf("\nCheck: %d\n", check);
				if(check == VALID)
					InsertPrefix(prefix, nextHop, strlen(prefix), node, 0);
				else
					printf("\nPrefix is not valid. Please insert a valid prefix.\n");
				free(prefix);
				break;
			case 4:
				printf("Enter the prefix to delete: \n");
				prefix = mallocVerified((PREF_MAX_SIZE+8), sizeof(char));
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

int checkPrefix(char *prefix){

	int i = 0;

	for(i=0; i < strlen(prefix); i++){
		if(prefix[i] != '0' && prefix[i] != '1')
			return NOT_VALID;
	}

	if(i > PREF_MAX_SIZE)
		return NOT_VALID;
	else
		return VALID;
}

/******************************************************************************************
 * mallocVerified()
 *
 * Arguments: number - size to be allocated
 *			  size - soze of the variable
 *			 
 * Returns: (viod)
 * Side-Effects: -
 *
 * Description: Verifies if memory was allocated correctly
 * 
 *
 ******************************************************************************************/

void *mallocVerified(int number, int size){
	void * ptr = malloc(size * number);

	if(ptr == NULL){
		printf("ERROR on malloc\n");
		exit(1);
	}
	return ptr;
}


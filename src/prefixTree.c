/****************************************************************************************************
*
* This file has functions that preform all tasks available to users.
* PrefixTree receives a file as input and translate it into a prefix tree.
* PrintTable prints a prefix table receiving as input a prefix tree.
* LookUp checks what is the next-hop of an address given by user.
* InsertPrefix inserts a new prefix in the tree and the correspondent next-hop.
* DeletePrefix deletes a prefix from the tree given by user.
* There are also two more functions: deleteP and Erase. These functions are called when DeletePrefix 
* is called.
* 
*****************************************************************************************************/
#include "prefixTree.h"


/******************************************************************************************
 * PrefixTree()
 *
 * Arguments: file - file that contains the prefixes of the tree
 * Returns: root tree
 * Side-Effects: builds the tree through the file given
 *
 * Description: reads a file line by line and constructs the tree according to the file
 *
 ******************************************************************************************/

Node* PrefixTree(char const *file){

	FILE* ptr = fopen(file, "r");
	char line[LINE];
	char prefix[PREF_MAX_SIZE];
	int nextHop = 0;
	Node *root = newNode(DEFAULT);

	if(ptr == NULL)
	{
		printf("There isn't any file\n");
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
 *			  str1 and str2 - auxiliar strings that hold the prefix to print
 *
 * Returns: (void)
 * Side-Effects: prints a prefix table having a prefix tree as an input
 *
 * Description: giving the root tree, all the nodes of that tree are visited, recursively, 
 * and the prefix at each node is kept in order to print a prefix, if there is a next hop 
 * associated with that node
 *
 ******************************************************************************************/

void PrintTable(Node *node, char *str1, char *str2){

	int i=0;

	if(node == NULL)
		return;

	char *aux = mallocVerified(strlen(str1)+strlen(str2) +1, sizeof(char*));

	for(i=0; i < strlen(str1)+strlen(str2) + 1 ; i++)
		aux[i] = '\0';
	
	strcat(aux, str1);
	strcat(aux, str2);

	PrintTable(getLeft(node), aux, "0");
	PrintTable(getRight(node), aux, "1");

	if(getValue(node) != NO_HOP && getValue(node) != DEFAULT){
		printf("+-----------------+---------+\n");
		printf("| ");
		if(strlen(aux) == 0)
			printf("E");
		else
			printf("%s ", aux);
		for(i = strlen(aux); i < 18; i++){
			printf(" ");
		}
		printf(">  %d   |\n", getValue(node));	
		
	}

	free(aux);

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
	int nextHop = -1;
	int i = 0;
	int addrlen = strlen(address);
	nextHop = getValue(root);

	if(!strcmp(address,DFLT_STR)){
		return getValue(root);
	}
	while(aux != NULL && i<=addrlen){

		if(getValue(aux) != NO_HOP && getValue(aux) != DEFAULT){
			nextHop = getValue(aux);
			if(i == addrlen)
				break;
		}
		
		if(address[i] == '0'){
			aux = getLeft(aux);
		}
		else if(address[i] == '1')
			aux = getRight(aux);
		else if(i != addrlen){
			nextHop = NOT_VALID;
			break;
		}
			
		i++;
	}

	return nextHop;
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
		else if(prefix[index]== 'E'){
			setValue(node, nextHop);
			printf("Default setted\n");	
		}
	}
	else
		setValue(node, nextHop);

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

	int i = 0;
	int prefixLength = strlen(prefix);

	if(prefix[0] == DFLT_CHAR){
		setValue(root,NO_HOP);
		return;
	}

	for (i = 0; i < strlen(prefix); i++){

		if (!(prefix[i] == '0' || prefix[i] == '1')){
			printf("\n> Invalid Prefix\n");
			return;
		}
	}
	if(prefix[0] == '0'){
		if(deleteP(root->left, prefix, 0, prefixLength) == ERASE)
			root->left = NULL;
	}
	else{
		if(deleteP(root->right, prefix, 0, prefixLength) == ERASE)
			root->right = NULL;
	}
}

/**********************************************************************************************
 * Erase()
 *
 * Arguments: node - pointer to a node from the tree
 *			  
 * Returns: if node was deleted or not from the tree
 * Side-Effects: deletes a node from the tree
 *
 * Description: this is an auxiliar function to delete a node from the tree if the node could
 * be deleted
 *
 **********************************************************************************************/

int Erase(Node **node){
	
	if(getRight(*node) != NULL || getLeft(*node) != NULL){
		setValue(*node, NO_HOP);
		return RETURN;
	}
	else{
		free(*node);
		return ERASE;
	}
}

/*****************************************************************************************************
 * deleteP()
 *
 * Arguments: node - pointer to a node from the tree
 *			  prefix - prefix to delete
 *			  index - index to iterate the prefix
 *			  prefixLength - size of the prefix to delete
 *			  
 * Returns: if node could be deleted or not from the tree
 * Side-Effects: analises all the tree in order to delete a prefix
 *
 * Description: this function analises all nodes starting at the root to the prefix to be deleted in 
 * order to know if there are more nodes that could be erased 
 *
 *****************************************************************************************************/

int deleteP(Node *node, char *prefix, int index, int prefixLength){

	int ret = RETURN;

	if(node == NULL){
		printf("\nPrefix not found\n");
		return RETURN;
	}

	if(index+1 == prefixLength && getValue(node) != DEFAULT){
		if(Erase(&node))
			return ERASE;
		else
			return RETURN;
	}


	if(prefix[index+1] == '0'){
		Node *left = getLeft(node);
		ret = deleteP(left, prefix, index+1, prefixLength);
		if(ret == ERASE)
			node->left = NULL;
	}
	else if(prefix[index+1] == '1'){
		Node *right = getRight(node); 
		ret = deleteP(right, prefix, index+1, prefixLength);
		if(ret == ERASE)
			node->right = NULL;
	}
	else{
		printf("\nInvalid Prefix\n");
		return RETURN;
	}

	if(ret == ERASE && getValue(node) == NO_HOP && getRight(node) == NULL && getLeft(node) == NULL){
		printf("Parent erased\n");
		free(node);
		return ERASE;
	}
	else
		return RETURN;
}



/*****************************************************************************************************
 * BinaryToTwoBit()
 *
 * Arguments: BinTree - pointer to a node of the "original" tree
 *			  TwoBit - pointer to a node of the TwoBitTree
 *
 * Returns: -
 * Side-Effects: For a TwoBit node allocates it's four childs
 *
 * Description: For a given TwoBit node, the original three is analysed
 * and the atribution of TwoBit node values is made
 *
 *****************************************************************************************************/


void BinaryToTwoBit(Node * BinTree, BNode * TwoBit){
	Node *one = NULL;
	Node *two = NULL;
	Node *three = NULL;
	Node *four = NULL;
	int createNumber = NOT_CREATE;

	if(BinTree == NULL || TwoBit == NULL){
		return;
	}


	createNumber = getValue(getLeft(BinTree));

	// the first and second child of TwoBit node
	// only exit if the LEFT child of BinTree exists
	if(createNumber != NOT_CREATE){
		//grandson of binary tree node
		one = getLeft(getLeft(BinTree));
		// The value of grandson is inherited from is father
		// if it is either unexistent or with no Hop
		if(one == NULL || getValue(one) == NO_HOP){
			setOne(TwoBit, createNumber);			
		}
		else{
			setOne(TwoBit, getValue(one));
		}

		//grandson of binary tree node
		two = getRight(getLeft(BinTree));
		if(two == NULL || getValue(two) == NO_HOP){
			setTwo(TwoBit, createNumber);			
		}
		else{
			setTwo(TwoBit, getValue(two));
		}
	}

	// the thrird and fourth child of TwoBit node
	// only exit if the RIGHT child of BinTree exists
	createNumber = getValue(getRight(BinTree));
	if(createNumber != NOT_CREATE){
		//grandson of binary tree node
		three = getLeft(getRight(BinTree));
		if(three == NULL || getValue(three) == NO_HOP){
			setThree(TwoBit, createNumber);			
		}
		else{
			setThree(TwoBit, getValue(three));
		}
		//grandson of binary tree node
		four = getRight(getRight(BinTree));
		if(four == NULL || getValue(four) == NO_HOP){
			setFour(TwoBit, createNumber);			
		}
		else{
			setFour(TwoBit, getValue(four));
		}

	}
	
	// The recursion is applied with the TwoBit node sons
	// and with the Binary tree node grandsons, if they exist
	BinaryToTwoBit(one, getOne(TwoBit));
	BinaryToTwoBit(two, getTwo(TwoBit));
	BinaryToTwoBit(three, getThree(TwoBit));
	BinaryToTwoBit(four, getFour(TwoBit));

	return;
}

/******************************************************************************************
 * PrintTableEven()
 *
 * Arguments: node - pointer to a twobit tree node
 *			  str1 and str2 - auxiliar strings that hold the prefix to print
 *
 * Returns: (void)
 * Side-Effects: prints a even prefix table having a even prefix tree as an input
 *
 * Description: giving the root tree, all the nodes of that tree are visited, recursively, 
 * and the prefix at each node is kept in order to print a prefix, if there is a next hop 
 * associated with that node
 *
 ******************************************************************************************/


void PrintTableEven(BNode *node, char *str1, char *str2){

	int i=0;

	if(node == NULL)
		return;

	char *aux = mallocVerified(strlen(str1)+strlen(str2) +1, sizeof(char*));

	for(i=0; i < strlen(str1)+strlen(str2) + 1 ; i++)
		aux[i] = '\0';
	
	strcat(aux, str1);
	strcat(aux, str2);

	PrintTableEven(getOne(node), aux, "00");
	PrintTableEven(getTwo(node), aux, "01");
	PrintTableEven(getThree(node), aux, "10");
	PrintTableEven(getFour(node), aux, "11");

	if(getBValue(node) != NO_HOP && getBValue(node) != DEFAULT){
		
		printf("+-----------------+---------+\n");
		printf("| ");
		if(strlen(aux) == 0)
			printf("E");
		else
			printf("%s ", aux);
		for(i = strlen(aux); i < 18; i++){
			printf(" ");
		}
		printf(">  %d   |\n", getBValue(node));	
	}

	free(aux);
}

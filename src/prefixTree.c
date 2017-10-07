#include "prefixTree.h"

/******************************************************************************************
 * PrefixTree(file)
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

	if(getValue(node) != -1 && getValue(node) != DEFAULT)
		printf("%s >%d\n", aux, getValue(node));

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
		else{
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

	for (i = 0; i < strlen(prefix); i++){

		if (!(prefix[i] == '0' || prefix[i] == '1')){
			printf(">Invalid Prefix\n");
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
	//printf("ERASEDDD: %d\n", getValue(node));
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
		printf("Prefix not found\n");
		return RETURN;
	}

	printf("interation:%d - %c\n", index,  prefix[index]);

	if(index+1 == prefixLength && getValue(node) != DEFAULT){
		if(Erase(&node)){
			//free(node);
			return ERASE;
		}
		else
			return RETURN;
	}


	if(prefix[index+1] == '0'){
		Node * left = getLeft(node);
		ret = deleteP(left, prefix, index+1, prefixLength);
		if(ret == ERASE){
			//free(node->left);
			node->left = NULL;
		}
	}
	else if(prefix[index+1] == '1'){
		Node *right = getRight(node); 
		ret = deleteP(right, prefix, index+1, prefixLength);
		if(ret == ERASE){
			//free(node->right);
			node->right = NULL;
		}
	}
	else{
		printf("Invalid Prefix\n");
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

/*void PrintPrefix(int hop){

	int i = 0;
	
	while(i <= prefixIndex){
		printf("%d", prefixMap[i]);
		i++;
	}
	if(prefixIndex >= 0){
		printf("  >%d\n",hop );
	}
}*/

/*void PrintTable(Node *node){

	Node *aux = node;

	if (aux == NULL || prefixIndex >= PREF_MAX_SIZE)
		return;

	if(getValue(aux) != NO_HOP)
		PrintPrefix(getValue(aux));

	prefixMap[++prefixIndex] = LEFT;
	PrintTable(getLeft(aux));
	prefixMap[prefixIndex--] = NO_HOP;


	prefixMap[++prefixIndex] = RIGHT;
	PrintTable(getRight(aux));
	prefixMap[prefixIndex--] = NO_HOP;

}*/





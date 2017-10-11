/*************************************************************************
*
* This file contains functions that handle simple tasks in two-bit trees.
* 
*************************************************************************/

#include "binaryTree.h"

/******************************************************************************************
 * allocNode()
 *
 * Arguments: (none)
 * Returns: node
 * Description: creates a node
 *
 ******************************************************************************************/

BNode *allocBNode(){
	return ((BNode *) malloc(sizeof(BNode)));
}

/******************************************************************************************
 * newNode()
 *
 * Arguments: num - value of the node
 * Returns: new node
 * Description: creates a new node
 *
 ******************************************************************************************/

BNode *newBNode(int num){
	
	BNode *node;

	node = allocBNode();
	node->value = num;
	node->one = node->two = node->three = node->four = NULL;

	return node;
}

/******************************************************************************************
 * getRight()
 *
 * Arguments: node - node from the tree
 * Returns: right child of a node
 * Description: gets the right child of a node
 *
 ******************************************************************************************/

BNode *getOne(BNode * node){
	return node->one;
}

BNode *getTwo(BNode * node){
	return node->two;
}

BNode *getThree(BNode * node){
	return node->three;
}

BNode *getFour(BNode * node){
	return node->four;
}


/******************************************************************************************
 * getValue()
 *
 * Arguments: node - node from the tree
 * Returns: value of the node
 * Description: gets the value of the node
 *
 ******************************************************************************************/

int getBValue(BNode * node){
	return node->value;
}

/******************************************************************************************
 * setRight()
 *
 * Arguments: node - node from the tree
 *			  num - value of the node
 * Returns: (void)
 * Description: creates the right child of a node if doesn't exists or change its value, 
 * if it already exists
 *
 ******************************************************************************************/


BNode * setOne(BNode *node, int num){

	if(num == NOT_CREATE){
		return NULL;
	}
	if(node->one == NULL)
		node->one=newBNode(num);
	else
		setBValue(node->one, num);
	return node->one;
}

BNode * setTwo(BNode *node, int num){
	if(num == NOT_CREATE){
		return NULL;
	}
	if(node->two == NULL)
		node->two=newBNode(num);
	else
		setBValue(node->two, num);
	return node->two;
}

BNode * setThree(BNode *node, int num){
	if(num == NOT_CREATE){
		return NULL;
	}
	if(node->three == NULL)
		node->three=newBNode(num);
	else
		setBValue(node->three, num);
	return node->three;
}

BNode * setFour(BNode *node, int num){
	if(num == NOT_CREATE){
		return NULL;
	}
	if(node->four == NULL)
		node->four=newBNode(num);
	else
		setBValue(node->four, num);
	return node->four;
}
/******************************************************************************************
 * setValue()
 *
 * Arguments: node - node from the tree
 *			  num - value of the node
 * Returns: (void)
 * Description: sets the value of a node
 *
 ******************************************************************************************/

void setBValue(BNode *node, int num){
	if(node == NULL)
		return;
	node->value = num;
}

/******************************************************************************************
 * freeTree()
 *
 * Arguments: root - root of the tree
 * Returns: (void)
 * Description: free all memory allocated within the tree
 *
 ******************************************************************************************/

void freeBTree(BNode * root){
	if(root != NULL){
		freeBTree(root->one);
		freeBTree(root->two);
		freeBTree(root->three);
		freeBTree(root->four);
		free(root);
	}
}

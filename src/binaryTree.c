/*************************************************************************
*
* This file contains functions that handle simple tasks in two-bit trees.
* 
*************************************************************************/

#include "binaryTree.h"

/******************************************************************************************
 * allocBNode()
 *
 * Arguments: (none)
 * Returns: node
 * Description: creates a node of type BNode
 *
 ******************************************************************************************/

BNode *allocBNode(){
	return ((BNode *) malloc(sizeof(BNode)));
}

/******************************************************************************************
 * newBNode()
 *
 * Arguments: num - value of the node
 * Returns: new node
 * Description: creates a new node with four children
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
 * getOne()
 *
 * Arguments: node - node from the tree
 * Returns: first child of the two-bit tree
 * Description: gets the first child of a two-bit tree
 *
 ******************************************************************************************/

BNode *getOne(BNode *node){
	return node->one;
}

/******************************************************************************************
 * getTwo()
 *
 * Arguments: node - node from the tree
 * Returns: second child of the two-bit tree
 * Description: gets the second child of a two-bit tree
 *
 ******************************************************************************************/

BNode *getTwo(BNode * node){
	return node->two;
}

/******************************************************************************************
 * getthree()
 *
 * Arguments: node - node from the tree
 * Returns: third child of the two-bit tree
 * Description: gets the third child of a two-bit tree
 *
 ******************************************************************************************/

BNode *getThree(BNode * node){
	return node->three;
}

/******************************************************************************************
 * getFour()
 *
 * Arguments: node - node from the tree
 * Returns: fourth child of the two-bit tree
 * Description: gets the fourth child of a two-bit tree
 *
 ******************************************************************************************/

BNode *getFour(BNode * node){
	return node->four;
}

/******************************************************************************************
 * getBValue()
 *
 * Arguments: node - node from the tree
 * Returns: value of the node
 * Description: gets the value of the node from a two-bit tree
 *
 ******************************************************************************************/

int getBValue(BNode * node){
	return node->value;
}

/**********************************************************************************************
 * setOne()
 *
 * Arguments: node - node from the tree
 *			  num - value of the node
 * Returns: first child of a node from a two-bit prefix tree 
 * Description: creates the first child of a Bnode type if doesn't exists or change its value, 
 * if it already exists
 *
 **********************************************************************************************/

BNode *setOne(BNode *node, int num){

	if(num == NOT_CREATE){
		return NULL;
	}
	if(node->one == NULL)
		node->one=newBNode(num);
	else
		setBValue(node->one, num);
	return node->one;
}

/**********************************************************************************************
 * setTwo()
 *
 * Arguments: node - node from the tree
 *			  num - value of the node
 * Returns: second child of a node from a two-bit prefix tree 
 * Description: creates the second child of a Bnode type if doesn't exists or change its value, 
 * if it already exists
 *
 **********************************************************************************************/

BNode *setTwo(BNode *node, int num){
	if(num == NOT_CREATE){
		return NULL;
	}
	if(node->two == NULL)
		node->two=newBNode(num);
	else
		setBValue(node->two, num);
	return node->two;
}

/**********************************************************************************************
 * setThree()
 *
 * Arguments: node - node from the tree
 *			  num - value of the node
 * Returns: third child of a node from a two-bit prefix tree 
 * Description: creates the third child of a Bnode type if doesn't exists or change its value, 
 * if it already exists
 *
 **********************************************************************************************/

BNode *setThree(BNode *node, int num){
	if(num == NOT_CREATE){
		return NULL;
	}
	if(node->three == NULL)
		node->three=newBNode(num);
	else
		setBValue(node->three, num);
	return node->three;
}

/**********************************************************************************************
 * setFour()
 *
 * Arguments: node - node from the tree
 *			  num - value of the node
 * Returns: fourth child of a node from a two-bit prefix tree 
 * Description: creates the fourth child of a Bnode type if doesn't exists or change its value, 
 * if it already exists
 *
 **********************************************************************************************/

BNode *setFour(BNode *node, int num){
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
 * setBValue()
 *
 * Arguments: node - node from the tree
 *			  num - value of the node
 * Returns: (void)
 * Description: sets the value of a node of type BNode
 *
 ******************************************************************************************/

void setBValue(BNode *node, int num){
	if(node == NULL)
		return;
	node->value = num;
}

/******************************************************************************************
 * freeBTree()
 *
 * Arguments: root - root of the tree
 * Returns: (void)
 * Description: free all memory allocated within the two-bit tree
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

#include "trees.h"

/******************************************************************************************
 * allocNode()
 *
 * Arguments: (none)
 * Returns: node
 * Description: creates a node
 *
 ******************************************************************************************/

Node *allocNode(){
	return ((Node *) malloc(sizeof(Node)));
}

/******************************************************************************************
 * newNode()
 *
 * Arguments: num - value of the node
 * Returns: new node
 * Description: creates a new node
 *
 ******************************************************************************************/

Node *newNode(int num){
	
	Node *node;

	node = allocNode();
	node->value = num;
	node->right = node->left = NULL;

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

Node *getRight(Node * node){
	return node->right;
}

/******************************************************************************************
 * getLeft()
 *
 * Arguments: node - node from the tree
 * Returns: left child of a node
 * Description: gets the left child of a node
 *
 ******************************************************************************************/

Node *getLeft(Node * node){
	return node->left;
}

/******************************************************************************************
 * getValue()
 *
 * Arguments: node - node from the tree
 * Returns: value of the node
 * Description: gets the value of the node
 *
 ******************************************************************************************/

int getValue(Node * node){
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

void setRight(Node *node, int num){
	if(node->right == NULL)
		node->right=newNode(num);
	else
		setValue(node->right, num);
}

/******************************************************************************************
 * setLeft()
 *
 * Arguments: node - node from the tree
 *			  num - value of the node
 * Returns: (void)
 * Description: creates the left child of a node if doesn't exists or change its value, 
 * if it already exists
 *
 ******************************************************************************************/

void setLeft(Node * node, int num){
	if(node->left == NULL)
		node->left=newNode(num);
	else
		setValue(node->left, num);
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

void setValue(Node *node, int num){
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

void freeTree(Node * root){

	if(root != NULL){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

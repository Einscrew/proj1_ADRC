#include "trees.h"

struct _Node{
	int value;
	struct _Node *left, *right;
};

Node *allocNode(){
	return ((Node *) malloc(sizeof(Node)));
}

Node *getRight(Node * node){
	return node->right;
}

Node *getLeft(Node * node){
	return node->left;
}

int getValue(Node * node){
	return node->value;
}

void setRight(Node * node, int num){
	if(node->right == NULL)
		node->right=newNode(num);
	else
		setValue(&node->right, num);
}

void setLeft(Node * node, int num){
	if(node->left == NULL)
		node->left=newNode(num);
	else
		setValue(&node->left, num);
}
void setValue(Node ** node, int num){
	(*node)->value = num;
}

Node *newNode(int num){
	
	Node* aux;

	aux = allocNode();
	aux->value = num;
	aux->right = aux->left = NULL;

	return aux;
}

void freeTree(Node * root){

	if(root != NULL){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}


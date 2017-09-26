#include "trees.h"

struct _Node{
	int value;
	struct _Node *left, *right;
};

Node *allocNode(){
	return ((Node *) malloc(sizeof(Node)));
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



/*

insert
free

*/
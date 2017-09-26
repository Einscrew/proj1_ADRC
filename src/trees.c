#include "trees.h"

struct {
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
	auz->right = aux->left = NULL;

	return aux;
}
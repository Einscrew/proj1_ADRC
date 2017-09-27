#include "trees.h"

struct _Node{
	int value;
	char *prefix;
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

char *getPrefix(Node *node){
	return (node->prefix);
}

void setRight(Node * node, int num, int prefixLen){
	if(node->right == NULL)
		node->right=newNode(num, prefixLen);
	else
		setValue(&node->right, num);
}

void setLeft(Node * node, int num, int prefixLen){
	if(node->left == NULL)
		node->left=newNode(num, prefixLen);
	else
		setValue(&node->left, num);
}

void setValue(Node **node, int num){
	(*node)->value = num;
}

void setPrefix(Node *node, char *prefix){
	strcpy(node->prefix, prefix);
}

Node *newNode(int num, int prefixLen){
	
	Node* aux;

	aux = allocNode();
	aux->value = num;
	aux->right = aux->left = NULL;
	aux-> prefix = (char*)malloc(prefixLen * sizeof(char));

	return aux;
}

void freeTree(Node * root){

	if(root != NULL){
		free(root->prefix);
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}


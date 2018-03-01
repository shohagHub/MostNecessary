// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <malloc.h>

typedef struct NodeStruct{
	int data;
	struct NodeStruct *left;
	struct NodeStruct *right;
}Node;

int search(Node *root, int value){
	if (root == NULL)
		return 0;
	if (root->data > value)
		return search(root->left, value);
	if (root->data < value)
		return search(root->right, value);
	if (root->data == value)
		return 1;
}

Node * insertNode(Node *root, int value){
	if (root == NULL){
		root = (Node *)malloc(sizeof(Node));
		root->data = value;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data > value)
		root->left = insertNode(root->left, value);
	else if (root->data < value)
		root->right = insertNode(root->right, value);
	return root;
}

void inOrder(Node *root){
	if (root == NULL)
		return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void postOrder(Node *root){
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

void preOrder(Node *root){
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

Node *deleteNode(Node* root, int data){
	if (root == NULL)
		return NULL;
	Node *ret;

	if (root->data > data)
		root->left = deleteNode(root->left, data);

	else if (root->data < data)
		root->right = deleteNode(root->right, data);

	else{
		if (root->left == NULL && NULL == root->right){
			free(root);
			return NULL;
		}
		if (root->left == NULL){
			ret = root->right;
			free(root);
			return ret;
		}
		if (root->right == NULL){
			ret = root->left;
			free(root);
			return ret;
		}

		Node *leftMost = root->right;
		while (leftMost->left)
			leftMost = leftMost->left;
		root->data = leftMost->data;
		root->right = deleteNode(leftMost, leftMost->data);
	}
}

int main(){
	Node *root;
	root = NULL;
	//root = insertNode(root, 5);
	//printf("%d\n", root->data);

	int choice, data;
	do{
		printf("\nPreOrder: ");
		preOrder(root);
		printf("\nInOrder: ");
		inOrder(root);
		printf("\nPostOrder: ");
		postOrder(root);
		printf("\nPlease Enter no between 0 to 7: ");
		printf("\n0. Exit");
		printf("\n1. Insert");
		printf("\n2. Search");
		printf("\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: 
			printf("\nEnter value to insert ");
			scanf("%d", &data);
			root = insertNode(root, data);
			break;
		case 2:
			printf("\nEnter value to search ");
			scanf("%d", &data);
			if (search(root, data))
				printf("\n%d value found in tree\n", data);
			else
				printf("\n%d value not found\n", data);
		default:
			break;
		}
	} while (choice);
	
	return 0;
}

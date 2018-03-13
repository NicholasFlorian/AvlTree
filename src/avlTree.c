#include <stdio.h>
#include <stdlib.h>
#include "avlTree.h"


AvlTree *createAvlTree(void (*deleteData)(void *data), char* (*printData)(void *data),
					   int (*compareData)(void *data1, void *data2)){
	
	//var
	AvlTree* avlTree;
	
	
	//assign values
	avlTree = malloc(sizeof(AvlTree));
	
	if(avlTree == NULL)
		return NULL;
	
	avlTree->size = 0;
	avlTree->depth = 0;
	
	avlTree->head = NULL;
	
	avlTree->deleteData = deleteData;
	avlTree->printData = printData;
	avlTree->compareData = compareData;
	
	return avlTree;
	
}

AvlNode *createAvlNode(void *data){
	
	//var
	AvlNode* avlNode;
	
	//assign values
	avlNode = malloc(sizeof(AvlNode));
	
	//check if memory was successfully allocated
	if(avlNode == NULL)
		return NULL;
	
	//set NULL values
	avlNode->data = data;
	
	avlNode->left = NULL;
	avlNode->left = NULL;
	
	return avlNode;
	
}

int hasAvlLeft(AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return 0;
	
	//check
	if(avlNode->left != NULL)
		return 1;
	
	return 0;
	
}

int hasAvlRight(AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return 0;
	
	//check
	if(avlNode->right != NULL)
		return 1;
	
	return 0;
	
}

int hasAvlLeafs(AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return 0;
	
	//check
	if(hasAvlRight(avlNode) || hasAvlLeft(avlNode))
		return 1;
	
	return 0;
	
}

int heightAvl(AvlNode *avlNode, int hieght){
	
	//var
	int left;
	int right;
	
	
	//set values
	left = 0;
	right = 0;
	
	//soften input
	if(avlNode == NULL)
		return height;
	
	//get child hieghts
	if(hasAvlLeft(avlNode))
		left = hieght(avlNode->left, hieght);
	
	if(hasAvlRight(avlNode))
		right = hieght(avlNode->right, hieght);


	//return max
	if(right > left)
		return ++right;
	else
		return ++left;
	
}

void deleteAvlTree(AvlTree* avlTree, AvlNode *avlNode){
	
	//Use DFS
	
	//soften input
	if(avlNode == NULL)
		return;
	
	if(avlTree == NULL)
		return;
	
	//recursive run through
	if(hasAvlLeft(avlNode))
		deleteDFS(avlTree, avlNode->left);
	
	if(hasAvlRight(avlNode))
		deleteDFS(avlTree, avlNode->right);
	
	//delete node
	deleteNode(avlTree, avlNode);
	
	free(avlTree);
	
}

void deleteAvlNode(AvlTree* avlTree, AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return;
	
	if(avlTree == NULL)
		return;
	
	//delete data
	avlTree->deleteData(avlNode->data);
	
	free(avlNode);
	
}

void insertAvlData(AvlTree* avlTree, void* data){
	
	//var
	AvlNode* insertNode;
	
	
	//soften input
	if(avlNode == NULL)
		return;
	
	if(avlTree == NULL)
		return;
	
	
	//create node
	insertNode = createAvlNode(data);
	
	//insert it
	insertAvlNode(avlTree, avlTree->head, insertNode);
	
	//rebalance tree
	balanceAvlTree(avlTree, avlTree->next);
	
}

void insertAvlNode(avlTree* avlTree, AvlNode* iter, AvlNode *avlNode){

	//soften input
	if(avlNode == NULL)
		return;
	
	if(avlTree == NULL)
		return;
	
	//go until the tree is empty
	if(iter == NULL){
		
		iter = avlNode;
		return;
		
	}
	
	//binary search next leaf
	if(avlTree->compareData(avlNode->data, iter->data))
		inserNode(avlTree, iter->right, avlNode);
	else
		inserNode(avlTree, iter->left, avlNode);
	
	return;
	
}

void balanceAvlTree(AvlTree* avlTree, AvlNode* avlNode){
	
	//var
	int balance;
	
	//leave recursion
	if(avlNode == NULL)
		return;
	
	//recursive run through
	if(hasAvlLeft(avlNode))
		balanceAvlTree(avlTree, avlNode->left);
	
	if(hasAvlRight(avlNode))
		rebalance(avlTree, avlNode->right);

	
	balance = balanceAvlNode(avlTree, avlNode);
	
	
	if(balance >= 2)
		if(avlBalanceNode(avlTree, avlNode->left))
			
	
}

int balanceAvlNode(AvlTree* avlTree, AvlNode* avlNode){
	
	//var
	int balance;
	
	
	//set defualt values
	balance = 0;
	
	//assing balance
	if(hasAvlLeft(avlNode))
		balance += heightAvl(avlNode->left, 0);
	
	if(hasAvlRight(avlNode))
		balance -= heightAvl(avlNode->right, 0);
	
	return balance;
	
}








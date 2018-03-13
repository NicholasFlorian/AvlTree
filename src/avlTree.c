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

AvlNode *createHashNode(void *data){
	
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

int hasLeft(AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return 0;
	
	//check
	if(avlNode->left != NULL)
		return 1;
	
	return 0;
	
}

int hasRight(AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return 0;
	
	//check
	if(avlNode->right != NULL)
		return 1;
	
	return 0;
	
}

int hasLeafs(AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return 0;
	
	//check
	if(hasRight(avlNode) || hasLeft(avlNode))
		return 1;
	
	return 0;
	
}


void deleteTree(AvlTree* avlTree){
	
	//soften input
	if(avlTree == NULL)
		return;
	
	//free nodes
	deleteDFS(avlTree, avlTree->head);
	
	//delete rest of data
	free(avlTree);

}

void deleteDFS(AvlTree* avlTree, AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return;
	
	if(avlTree == NULL)
		return;
	
	//recursive run through
	if(hasLeft(avlNode))
		deleteDFS(avlTree, avlNode->left);
	
	if(hasRight(avlNode))
		deleteDFS(avlTree, avlNode->right);
	
	//delete node
	deleteNode(avlTree, avlNode);
	
}

void deleteNode(AvlTree* avlTree, AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return;
	
	if(avlTree == NULL)
		return;
	
	//delete data
	avlTree->deleteData(avlNode->data);
	
	free(avlNode);
	
}


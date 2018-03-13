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

	if(avlNode == NULL)
		return NULL;
	
	avlNode->data = data;
	
	avlNode->left = NULL;
	avlNode->left = NULL;
	
	return avlNode;
	
}

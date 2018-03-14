#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int getHeightAvl(AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return 0;
	
	return heightAvl(avlNode, 0);
	
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
		return hieght;
	
	//get child hieghts
	if(hasAvlLeft(avlNode))
		left = getHeightAvl(avlNode->left);
	
	if(hasAvlRight(avlNode))
		right = getHeightAvl(avlNode->right);
	
	
	//return max
	if(right > left)
		return ++right;
	else
		return ++left;
	
}


void deleteAvlTree(AvlTree* avlTree){
	
	//soften input
	if(avlTree == NULL)
		return;
	
	//delete node
	deleteAvl(avlTree, avlTree->head);
	
	free(avlTree);
	
}

void deleteAvl(AvlTree* avlTree, AvlNode *avlNode){
	
	//Uses DFS
	
	//soften input
	if(avlNode == NULL)
		return;
	
	if(avlTree == NULL)
		return;
	
	//recursive run through
	if(hasAvlLeft(avlNode))
		deleteAvl(avlTree, avlNode->left);
	
	if(hasAvlRight(avlNode))
		deleteAvl(avlTree, avlNode->right);
	
	//delete node
	deleteAvlNode(avlTree, avlNode);
	
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
	if(avlTree == NULL)
		return;
	
	if(data == NULL)
		return;
	
	//create node
	insertNode = createAvlNode(data);
	
	//insert it
	insertAvlNode(avlTree, &avlTree->head, insertNode);
	
	char* temp = printAvlTree(avlTree);
	printf("%s\n", temp);
	free(temp);
	
	//rebalance tree
	balanceAvlTree(avlTree);
	
}

void insertAvlNode(AvlTree* avlTree, AvlNode** iter, AvlNode *avlNode){
	
	//soften input
	if(avlNode == NULL)
		return;
	
	if(avlTree == NULL)
		return;
	
	
	//go until the tree is empty
	if(*iter == NULL){
		
		*iter = avlNode;
		return;
		
	}
	
	//binary search next leaf
	if(avlTree->compareData(avlNode->data, (*iter)->data))
		insertAvlNode(avlTree, &(*iter)->right, avlNode);
	else
		insertAvlNode(avlTree, &(*iter)->left, avlNode);
	
	return;
	
}

/*
void* searchAvlTree(){
	
	

	
}

void * searchAvlNode(){
	
	
	
}*/

char* printAvlTree(AvlTree* avlTree){
	
	//var
	char* string;
	char* t;
	
	
	//soften input
	if(avlTree == NULL)
		return NULL;
	
	//create start of print
	string = malloc(sizeof(char) * 9);
	if(string == NULL)
		return NULL;
	strcpy(string,"AvlTree\n");
	
	//check head
	if(avlTree->head == NULL)
		return string;
	
	
	//print data in nodes
	t = printAvlNode(avlTree, avlTree->head);
	
	//soften input
	if(t == NULL){
		return string;
	}
	
	//adjust amount
	string = realloc(string,
					 (sizeof(char) * (strlen(string) + 1)) +
					 (sizeof(char) * (strlen(t) + 1)));
	
	strcat(string, t);
	
	
	free(t);
	return string;
	
}

char* printAvlNode(AvlTree* avlTree, AvlNode* avlNode){
	
	//var
	char* string;
	char* temp;
	
	string = NULL;
	
	//soften input
	if(avlNode == NULL)
		return NULL;
	
	if(avlTree == NULL)
		return NULL;
	
	//check head
	if(avlTree->head == NULL)
		return string;

	
	string = malloc(sizeof(char));
	string[0] = '\0';
	
	//recursive run through
	if(hasAvlLeft(avlNode)){
		
		//var
		char *t;
		
		//print data in nodes
		t = printAvlNode(avlTree, avlNode->left);
		
		//soften input
		if(t != NULL){
			
			
			//adjust amount
			string = realloc(string,
							 (sizeof(char) * (strlen(string) + 1)) +
							 (sizeof(char) * (strlen(t) + 1)));
			
			strcat(string, t);
			
			free(t);
			
		}
		
	}
	
	//adjust amount
	temp = avlTree->printData(avlNode->data);
	string = realloc(string,
					 (sizeof(char) * (strlen(string) + 1)) +
					 (sizeof(char) * (strlen(temp) + 1)));
	
	strcat(string, temp);
	
	if(hasAvlRight(avlNode)){
		
		//var
		char *t;
		
		//print data in nodes
		t = printAvlNode(avlTree, avlNode->right);
		
		//soften input
		if(t != NULL){
			
			//adjust amount
			string = realloc(string,
							 (sizeof(char) * (strlen(string) + 1)) +
							 (sizeof(char) * (strlen(t) + 1)));
			
			strcat(string, t);
			
			free(t);
			
		}
		
	}
	
	return string;

}

void balanceAvlTree(AvlTree* avlTree){
	
	//soften input
	if(avlTree == NULL)
		return;
	
	if(avlTree->head == NULL)
		return;
	
	//balance tree
	avlTree->head = balanceAvlNode(avlTree, avlTree->head);
	
}

AvlNode* balanceAvlNode(AvlTree* avlTree, AvlNode* avlNode){
	
	//leave recursion
	if(avlNode == NULL)
		return avlNode;
	
	if(!hasAvlLeafs(avlNode))
		return avlNode;
	
	//recursive run through
	if(hasAvlLeft(avlNode))
		avlNode->left = balanceAvlNode(avlTree, avlNode->left);
	
	if(hasAvlRight(avlNode))
		avlNode->right = balanceAvlNode(avlTree, avlNode->right);
	
	printf("DELTA %d\n", deltaAvl(avlTree, avlNode));
	
	//Rotate
	if(deltaAvl(avlTree, avlNode) >= 2){
		
		if(deltaAvl(avlTree, avlNode) <= -1)
			return lrAvl(avlNode);
		else
			return llAvl(avlNode);
		
	}
	else if(deltaAvl(avlTree, avlNode) <= -2){
		
		if(deltaAvl(avlTree, avlNode) >= 1)
			return rlAvl(avlNode);
		else
			return rrAvl(avlNode);
		
	}
	
	return avlNode;
}

int deltaAvl(AvlTree* avlTree, AvlNode* avlNode){
	
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

AvlNode* llAvl(AvlNode* avlNode){
	
	//var
	AvlNode* a;
	AvlNode* b;
	
	
	//assign
	a = avlNode;
	b = a->left;
	
	//switch
	a->left = b->right;
	b->right = a;
	
	printf("LL\n");
	
	return(b);
	
}

AvlNode* lrAvl(AvlNode* avlNode){
	
	//var
	AvlNode* a;
	AvlNode* b;
	AvlNode* c;
	
	
	//assign
	a = avlNode;
	b = a->left;
	c = b->right;
	
	//switch
	a->left = c->right;
	b->right = c->left;
	c->left = b;
	c->right = a;
	
		printf("LRs\n");
	
	return(c);
	
}

AvlNode* rlAvl(AvlNode* avlNode){
	
	//var
	AvlNode* a;
	AvlNode* b;
	AvlNode* c;
	
	
	//assign
	a = avlNode;
	b = a->right;
	c = b->left;
	
	//switch
	a->right = c->left;
	b->left = c->right;
	c->right = b;
	c->left = a;
	
		printf("RL\n");
	
	return(b);
	
}

AvlNode* rrAvl(AvlNode* avlNode){
	
	//var
	AvlNode* a;
	AvlNode* b;
	
	
	//assign
	a = avlNode;
	b = a->right;
	
	//switch
	a->right = b->left;
	b->left = a;
	
		printf("RR\n");
	
	return(b);
	
}

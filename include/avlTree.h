/**
 * @file HashTable.h
 * @author Michael Ellis
 * @edited by Nicholas Florian
 * @date February 2017
 * @brief File containing the function definitions of a hash table
 
 * SEVERLY EDITED BY NICHOLAS FLORIAN
 */

#ifndef HASH_API_
#define HASH_API_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *Node of the avlTree.
 **/
typedef struct avlNode{

	void *data; ///< pointer to generic data that is to be stored in the hash table
	
	struct avlNode* parent; ///<parent of avlNode
	struct avlNode* left; ///< pointer to the left leaf
	struct avlNode* right; ///< oointer to the right leaf
	
} AvlNode;

/**
 *Hash table structure
 **/
typedef struct avlTree{
	
	int size;
	int depth;
	
	AvlNode* head;
	
	void (*deleteData)(void *data); ///< destroy node data
	char* (*printData)(void *data); ///< print data in avl
	int (*compareData)(void *data1, void *data2); ///< compare two data items
	
} AvlTree;


/**
 **/
AvlTree *createAvlTree(void (*deleteData)(void *data), char* (*printData)(void *data),
	int (*compareData)(void *data1, void *data2));

/**
 **/
AvlNode *createAvlNode(void *data);

/**
 **/
int hasAvlLeft(AvlNode *avlNode);

/**
 **/
int hasAvlRight(AvlNode *avlNode);

/**
 **/
int hasAvlLeafs(AvlNode *avlNode);

int getHeightAvl(AvlNode *avlNode);

int heightAvl(AvlNode *avlNode, int hieght);

/**
 **/
void deleteAvl(AvlTree* avlTree, AvlNode* avlNode);

/**
 **/
void deleteAvlNode(AvlTree* avlTree, AvlNode *avlNode);


/**
 **/
void insertAvlData(AvlTree* avlTree, void* data);

/**
 **/
void insertAvlNode(AvlTree* avlTree, AvlNode** iter, AvlNode *avlNode);

/**
 **/
char* printAvlTree(AvlTree* avlTree);

/**
 **/
char* printAvlNode(AvlTree* avlTree, AvlNode* avlNode);

/**
 **/
void balanceAvlTree(AvlTree* avlTree);

/**
 **/
AvlNode* balanceAvlNode(AvlTree* avlTree, AvlNode* avlNode);

/**
 **/
int deltaAvl(AvlTree* avlTree, AvlNode* avlNode);

/**
 **/
AvlNode* llAvl(AvlNode* avlNode);
AvlNode* lrAvl(AvlNode* avlNode);
AvlNode* rlAvl(AvlNode* avlNode);
AvlNode* rrAvl(AvlNode* avlNode);

void deleteAvlTree(AvlTree* avlTree);
#endif

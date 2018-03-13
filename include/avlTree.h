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

/**
 *Node of the avlTree.
 **/
typedef struct avlNode{

	int delta;///<stores data about tree balancing

	void *data; ///< pointer to generic data that is to be stored in the hash table
	struct avlNode *left; ///< pointer to the left leaf
	struct avlNode *right; ///< oointer to the right leaf
	
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
int hasLeft(AvlNode *avlNode);

/**
 **/
int hasRight(AvlNode *avlNode);

/**
 **/
int hasLeafs(AvlNode *avlNode);

/**
 **/
void deleteTree(AvlTree* avlTree);

/**
 **/
void deleteDFS(AvlTree* avlTree, AvlNode *avlNode);

/**
 **/
void deleteNode(AvlTree* avlTree, AvlNode *avlNode);


#endif

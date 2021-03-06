#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "avlTree.h"
#include "int.h"

int rando(int range){
	
	return rand() % range;
	
}

int main(int args, char **argv){
	
	//Var
	AvlTree* intAvlTree;
	char* s;
	
	intAvlTree = createAvlTree(&deleteInt, &printInt, &compareInts);

	srand(time(NULL));
	
	for(int i = 0; i < 10; i++){
		
		//var
		int* in;
		
		in = malloc(sizeof(int));
		*in = rando(1000);
		
		insertAvlData(intAvlTree, in);
	
	}
	
	s = printAvlTree(intAvlTree);
	printf("%s\n", s);

	deleteAvlTree(intAvlTree);
	
	
	return 0;
	
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "avlTree.h"
#include "int.h"

int main(int args, char **argv){
	
	//Var
	AvlTree* intAvlTree;
	char* s;
	
	intAvlTree = createAvlTree(&deleteInt, &printInt, &compareInts);

	for(int i = 0; i < 10; i++){
		
		//var
		int* in;
		
		in = malloc(sizeof(int));
		
		srand(time(NULL));
		*in = rand();
		
		insertAvlData(intAvlTree, in);
		
		printf("%d \n", in);
		
	}
	
	s = printAvlTree(intAvlTree);
	
	printf("%s\n", s);
	
	deleteAvlTree(intAvlTree);
	
	
	
	
	return 0;
	
}

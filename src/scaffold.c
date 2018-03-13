#include <stdlib.h>
#include <stdio.h>
#include "avlTree.h"
#include "int.h"

int main(int args, char **argv){
	
	//Var
	AvlTree* intAvlTree;
	
	
	intAvlTree = createAvlTree(&deleteInt, &printInt, &compareInts);
	
	return 0;
	
}

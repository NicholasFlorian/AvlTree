CC = gcc
CFLAGS = -Wall -g -Iinclude -std=c11

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
#main-> avlTree.a


all: main

main: lib/libavlTree.a scaffold.o
	$(CC) $(CFLAGS) scaffold.o -o bin/main -lm -L./lib/ -lavlTree -lint

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 

avlTree: lib/libavlTree.a

lib/libavlTree.a: avlTree.o
	ar cr lib/libavlTree.a avlTree.o

avlTree.o: src/avlTree.c
	$(CC) $(CFLAGS) -c src/avlTree.c

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
#scaffold -> ioHandler.h


scaffold: scaffold.o

scaffold.o: src/scaffold.c
	$(CC) $(CFLAGS) -c src/scaffold.c

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 

#Utility Funtions


clean:
	rm *.o
	rm lib/libavlTree.a
	rm bin/main

run:
	./bin/main

cclear:
	clear
	clear

r: cclear clean main run


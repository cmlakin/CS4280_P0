#Corrina Lakin CS4280 P0

CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o buildtree.o traversals.o
TARGET = P0

bst: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o bst

main.o: main.cpp node.h traversals.h BST.h
	$(CC) $(CFLAGS) -c main.cpp

traversals.o: traversals.cpp traversals.h
	$(CC) $(CFLAGS) -c traversals.cpp

buildtree.o: buildtree.cpp BST.h
	$(CC) $(CFLAGS) -c buildtree.cpp

clean:
	rm *.o bst

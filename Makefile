#Corrina Lakin CS4280 P0

CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o buildtree.o traversals.o
TARGET = P0

P0: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o P0

main.o: main.cpp node.h traversals.h buildtree.h
	$(CC) $(CFLAGS) -c main.cpp

traversals.o: traversals.cpp traversals.h
	$(CC) $(CFLAGS) -c traversals.cpp

buildtree.o: buildtree.cpp buildtree.h
	$(CC) $(CFLAGS) -c buildtree.cpp

clean:
	rm *.o P0

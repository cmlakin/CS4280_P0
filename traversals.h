#ifndef _TRAVERSALS_h
#define _TRAVERSALS_h

#include <fstream>

using std::ofstream;

void preOrder(node_t*, ofstream&);
void printPostOrder(node_t*, ofstream&);
void postOrder(node_t*, ofstream&);
void printLevelOrder(node_t*, ofstream&);
void printCurrentLevel(node_t*, int, ofstream&);
int height(node_t*);
//node_t* newnode_t(int);

#endif TRAVERSALS_h

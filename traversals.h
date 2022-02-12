#include <fstream>

using std::fstream;

void preOrder(node_t*, fstream&);
void postOrder(node_t*);
void printLevelOrder(node_t*);
void printCurrentLevel(node_t*, int);
int height(node_t*);
//node_t* newnode_t(int);

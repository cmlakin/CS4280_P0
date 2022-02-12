

#include <iostream>
#include <cassert>
#include <stdlib.h>
#include "node.h"
#include "buildtree.h"

using namespace std;
node_t* root = nullptr;

node_t* getRoot() {
  return root;
}


void insert(char value, const string& uWord) {

    node_t* child = new node_t(value); // create new node_t which will be inserted

    if (root == nullptr) {
        root = child; // new child becomes root
        return;
    }

    node_t* parent = nullptr;
    node_t* p = root;			// start from p = root
    while (p != nullptr) {	// keep searching for empty spot to insert our new node_t
        parent = p;
        if (value < p->value) {
            p = p->left;
        }
        else if (value > p->value){
          p = p->right;
        }
        else {
          p->words.push_back(uWord);
        }
    }	// while loop exits when p->left or p->right = null ptr

    if (value < parent->value) {
        assert(parent->left == nullptr);	// double-check to see if while loop worked correctly
        parent->left = child;	// insert our new node_t
    }
    else { // same as above
        assert(parent->right == nullptr);
        parent->right = child;
    }
    child->parent = parent;
}

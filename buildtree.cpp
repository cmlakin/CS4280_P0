

#include <iostream>
#include <cassert>
#include <stdlib.h>
#include "node.h"
#include "buildtree.h"

using namespace std;
Node* root = nullptr;

Node* getRoot() {
  return root;
}


void insert(char value) {

    Node* child = new Node(value); // create new Node which will be inserted

    if (root == nullptr) {
        root = child; // new child becomes root
        return;
    }

    Node* parent = nullptr;
    Node* p = root;			// start from p = root
    while (p != nullptr) {	// keep searching for empty spot to insert our new Node
        parent = p;
        if (value < p->value) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }	// while loop exits when p->left or p->right = null ptr

    if (value < parent->value) {
        assert(parent->left == nullptr);	// double-check to see if while loop worked correctly
        parent->left = child;	// insert our new node
    }
    else { // same as above
        assert(parent->right == nullptr);
        parent->right = child;
    }
    child->parent = parent;
}

#include <iostream>
#include <stdlib.h>
#include "node.h"
#include "traversals.h"


using namespace std;

void preOrder(Node* p) {
    if (p == nullptr) {
        return;
    } else {
        cout << p->value << " ";
        preOrder(p->left);
        preOrder(p->right);
    }
}

void postOrder(Node* p) {
    if (p == nullptr) {
        return;
    } else {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->value << " ";
    }
}

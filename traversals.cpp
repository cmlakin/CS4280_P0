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

// level order functions from:
// https://www.geeksforgeeks.org/level-order-tree-traversal/

/* Function to print level
order traversal a tree*/
void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

/* Print nodes at a current level */
void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->value << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(Node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

// Node* newNode(int value)
// {
//     Node* Node = new Node();
//     Node->value = value;
//     Node->left = NULL;
//     Node->right = NULL;
//
//     return (Node);
// }

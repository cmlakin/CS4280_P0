#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "traversals.h"

using namespace std;

string output;
fstream outFile;

void preOrder(node_t* p) {
    if (p == nullptr) {
        return;
    } else {
        output = "P0.levelorder";
        outFile.open(output);
        outFile << p->value << " ";
        preOrder(p->left);
        preOrder(p->right);
        outFile.close();
    }
}

void postOrder(node_t* p) {
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
void printLevelOrder(node_t* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

/* Print node_ts at a current level */
void printCurrentLevel(node_t* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1){
        cout << root->value << ":";
    }
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

/* Compute the "height" of a tree -- the number of
    node_ts along the longest path from the root node_t
    down to the farthest leaf node_t.*/
int height(node_t* node_t)
{
    if (node_t == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node_t->left);
        int rheight = height(node_t->right);

        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

// node_t* newnode_t(int value)
// {
//     node_t* node_t = new node_t();
//     node_t->value = value;
//     node_t->left = NULL;
//     node_t->right = NULL;
//
//     return (node_t);
// }

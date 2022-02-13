#include <iostream>
#include <stdlib.h>
#include <string>
#include "node.h"
#include "traversals.h"


using namespace std;

void preOrder(node_t* p, ofstream& out) {
  if (p == nullptr) {
    return;
  } else {
    for(int i = 0; i < p->level; i++) {
      out << "  ";
    }
    out << p->level << " " << p->value << " ";
    for (string s: p->words) out << s << " ";
    out << endl;
    preOrder(p->left, out);
    preOrder(p->right, out);
  }
}

void postOrder(node_t* p, ofstream& out) {
  if (p == nullptr) {
    return;
  } else {
    postOrder(p->left, out);
    postOrder(p->right, out);
    for(int i = 0; i < p->level; i++) {
      out << "  ";
    }
    out << p->level << " " << p->value << " ";
    for (string s: p->words) out << s << " ";
    out << endl;

  }

}

// level order functions from:
// https://www.geeksforgeeks.org/level-order-tree-traversal/

/* Function to print level
order traversal a tree*/
void printLevelOrder(node_t* root, ofstream& out)
{
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++) {
    printCurrentLevel(root, i, out);
  }

}

/* Print node_ts at a current level */
void printCurrentLevel(node_t* p, int level, ofstream& out)
{
  if (p == NULL)
    return;
  if (level == 1){
    for(int j = 0; j < p->level; j++) {
      out << "  ";
    }
    out << p->level << " " << p->value << " ";
    for (const string& s: p->words) out << s << " ";
    out << endl;
  }
  else if (level > 1) {
    printCurrentLevel(p->left, level - 1, out);
    printCurrentLevel(p->right, level - 1, out);
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

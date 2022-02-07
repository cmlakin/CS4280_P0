/* Code based on template from Dr. Nandakumar, professor at The University
 * of Texas at Austin, EE 312 Software Implementation 1.
 * Inorder, preorder, postorder funcitons from starting out with C++ from
 * Control Structures through objects. 9th Edition. Tony Gaddis.
 * Height function from geeksforgeeks.org, Write a program to find the
 * maximum depth or height of a tree.
 */
#ifndef _BST_h
#define _BST_h

#include <stdlib.h>
using namespace std;


struct BST {

    static Node* successor(Node* p) {
        if (p->right != 0) { // p has a right subtree
            /* successor to p will be smallest node  right subtree */
            Node* next = p->right;
            while (next->left != 0) {
                next = next->left;
            }
            return next;
        }
        else { // p does not have a right subtree
            /* successor to p will be closest ancestor where we go up a left branch */
            Node* parent = p->parent;
            while (parent != 0 && parent->right == p) {
                p = parent;
                parent = p->parent;
            }
            return parent;
        }
    }



};

#endif _BST_h

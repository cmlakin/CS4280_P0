/***************************************************************
 * Corrina Lakin
 * Project 3 - Part A
 * Create BST with given elements. Print traversals. Search for
 * given keys and print their path. Search for height of tree and
 * smallest and largest keys. Modify tree by deleting specified
 * node and print traversals again.
 */

#include <iostream>
#include "node.h"
#include "traversals.h"
#include "buildtree.h"

using namespace std;

int main(int argc, char * argv[]) {


    // dynamically allocate memory for user entered strings
    // change arrary to hold last character of string entered
    //int treeArray[SIZE] = {};

    int choice = 0;
    string userWord;

    do {
      cout << "Enter a word to add to BST: ";
      cin >> userWord;

      char last = userWord.back();
      cout << "last = " << last << " " << int(last) << endl;
      insert(last);

      cout << "do you want to enter another word?\n";
      cout << "enter 1 for yes or 0 for no: ";
      cin >> choice;

    } while(choice == 1);

    // for (int i = 0; i < SIZE; ++i){
    //     my_tree.insert(treeArray[i]);
    // }

    // print traversals
    cout << "\nPre-order: ";
    preOrder(getRoot());
    cout << "\nPost-order: ";
    postOrder(getRoot());
    cout << "\nLevel-order: ";
    printLevelOrder(getRoot());
    //
    // //determine height
    // cout << "\n\nHeight of tree: ";
    // cout << BST::height(my_tree.getRoot());

    return 0;
}

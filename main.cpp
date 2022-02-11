/***************************************************************
 * Corrina Lakin
 * Project 3 - Part A
 * Create BST with given elements. Print traversals. Search for
 * given keys and print their path. Search for height of tree and
 * smallest and largest keys. Modify tree by deleting specified
 * node_t and print traversals again.
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "node.h"
#include "traversals.h"
#include "buildtree.h"

using namespace std;

void buildTree(istream&);

int main(int argc, char * argv[]) {

    int choice;
    char* filename;
    fstream inFile;
    string userWord;

    // parse commandline arguements
    if (argc == 2) {
      filename = argv[1];

      inFile.open(filename);
      buildTree(inFile);
      inFile.close();
    }
    else {
      // for (int i = 1; i < argc; i++) {
      //   cin >> userWord;
      //   char last = userWord.back();
      //   insert(last);
      // }

      cout << "word: ";
      buildTree(cin);
    }

    //
    // // print traversals
    // cout << "\nPre-order: ";
    // preOrder(getRoot());
    // cout << "\nPost-order: ";
    // postOrder(getRoot());
    cout << "\nLevel-order: ";
    printLevelOrder(getRoot());

    return 0;
}

void buildTree(istream& in) {
  string userWord;
  while(in >> userWord) {
    char last = userWord.back();
    cout << "last = " << last << " " << int(last) << endl;
    insert(last);
  }

}

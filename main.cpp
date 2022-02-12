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

    char* filenameIn;
    //char* filePre = "P0.preOrder";
    // char* filePost = "P0.postorder";
    // char* fileLevel = "P0.levelorder";
    fstream inFile;
    fstream outFile;
    string userWord;

    // parse commandline arguements
    if (argc == 2) {
      filenameIn = argv[1];

      inFile.open(filenameIn);
      buildTree(inFile);
      inFile.close();
    }
    else {
      cout << "Enter words. When finished enter [ctrl]d to stop\n";
      buildTree(cin);
    }

    outFile.open("P0.preOrder");
    // // print traversals
    cout << "\nPre-order: ";
    preOrder(getRoot(), outFile);

    cout << "\nPost-order: ";
    // postOrder(getRoot());
    // cout << "\nLevel-order: ";
    // printLevelOrder(getRoot());
    outFile.close();
    return 0;
}

void buildTree(istream& in) {
  string userWord;
  while(in >> userWord) {

    // for (int i = 0; i < userWord.size(); i++){
    //   if (!isalpha(userWord[i])) {
    //     // print error message
    //     cout << "Error. Only lowercase letters accepted.\n";
    //     cout << "Exiting program.\n";
    //     return;
    //   }
    // }
    char last = userWord.back();
    cout << "last = " << last << " " << int(last) << endl;
    insert(last, userWord);
  }
}

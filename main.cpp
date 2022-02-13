/***************************************************************
 * Corrina Lakin
 * CS4280 P0
 * Description:
    Create Binary Search Tree.
    Print Traversals: levelorder, preorder, postorder
    No numbers or special characters
    Proper error messages
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
  ifstream inFile;
  ofstream outFile1;
  ofstream outFile2;
  ofstream outFile3;
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

  //print traversals
  outFile1.open("P0.preorder");
  preOrder(getRoot(), outFile1);
  outFile1.close();

  outFile2.open("P0.postorder");
  postOrder(getRoot(), outFile2);
  outFile2.close();

  outFile3.open("P0.levelorder");
  printLevelOrder(getRoot(), outFile3);
  outFile3.close();

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
    insert(last, userWord);
  }
}

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
#include <type_traits>
#include "node.h"
#include "traversals.h"
#include "buildtree.h"

using namespace std;

void buildTree(istream&);

int main(int argc, char * argv[]) {

  char* filenameIn;
  ifstream inFile;
  ofstream outFile;
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

  //print traversals to designated file
  outFile.open("P0.preorder");
  preOrder(getRoot(), outFile);
  outFile.close();

  outFile.open("P0.postorder");
  postOrder(getRoot(), outFile);
  outFile.close();

  outFile.open("P0.levelorder");
  printLevelOrder(getRoot(), outFile);
  outFile.close();

  return 0;
}

// https://mathbits.com/MathBits/CompSci/Files/End.htm
// used as example for checking for empty file

void buildTree(istream& in) {
  string userWord;
  in >> userWord;
  if (in.eof()) {
    cout << "Error: Empty file, no words to input.\n";
    cout << "Exiting program.\n";
  }
  while(!in.eof()) {
    cout << "userWord = " << userWord << endl;
    for (int i = 0; i < userWord.size(); i++){
      if (!isalpha(userWord[i])) {
        // print error message
        cout << "Error: Number(s) and/or special character(s) detected: ";
        cout << userWord << endl;
        cout << "Only lowercase letters accepted. Exiting program.\n";
        return;
      }
      else if (isupper(userWord[i])) {
        cout << "Error: Capital letter(s) detected.\n" << userWord << endl;
        cout << "Only lowercase letters accepted. Exiting program.\n";
        return;
      }
    }
    char last = userWord.back();
    insert(last, userWord);
    in >> userWord;
  }
}

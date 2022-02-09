/***************************************************************
 * Corrina Lakin
 * Project 3 - Part A
 * Create BST with given elements. Print traversals. Search for
 * given keys and print their path. Search for height of tree and
 * smallest and largest keys. Modify tree by deleting specified
 * node_t and print traversals again.
 */

#include <iostream>
#include <fstream>
#include "node.h"
#include "traversals.h"
#include "buildtree.h"

using namespace std;

int main(int argc, char * argv[]) {

    char* filename;
    fstream inFile;
    int choice = 0; // choice to enter another word or not
    string userWord;

    // parse commandline arguements
    if (argc == 2) {
      // prints file name if ./P0 < P0_test1 P0_test2 is entered
      // output: filename = P0_test2

      filename = argv[1];
      cout << "filename = " << filename << endl;

      filename = argv[1];
      inFile.open(filename);

      while(inFile) {
        inFile >> userWord;
        char last = userWord.back();
        cout << "last = " << last << " " << int(last) << endl;
        insert(last);
      }
      inFile.close();
    }
    else {
      for (int i =  1; i < argc; i++) {
        userWord = argv[i];
        char last = userWord.back();
        insert(last);
      }
    }




    //
    // // print traversals
    cout << "\nPre-order: ";
    preOrder(getRoot());
    cout << "\nPost-order: ";
    postOrder(getRoot());
    // cout << "\nLevel-order: ";
    // printLevelOrder(getRoot());

    return 0;
}

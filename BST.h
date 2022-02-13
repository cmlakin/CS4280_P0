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
 private:
     struct Node {
         int value;
         Node* left;
         Node* right;
         Node* parent;

         // value constructor
         Node(int value) {
             this->value = value;
             left = right = parent = nullptr;
         }

         // copy constructor
         Node(const Node& rhs) { }

         // destructor
         ~Node(void) {
             delete left;  // calls delete of left, which recursively calls delete on its left and right
             delete right;
         }
     }; // end of struct Node

 private:

     static void recursiveDelete(Node* root) {
         if (root == nullptr) { return;  }
         recursiveDelete(root->left);
         recursiveDelete(root->right);
         delete root; // calls Node's destructor
     }

     static Node* recursiveCopy(Node* root) { }

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

     void remove(Node* p) {
         if (p == 0) {
             return;
         }

         if (p->right == nullptr) { // easy case!
             Node* child = p->left;
             Node* parent = p->parent;
             if (parent == nullptr) {
                 if (child != nullptr) {
                     child->parent = nullptr;
                 }
                 root = child;
                 p->left = p->right = nullptr;
                 delete p;
                 return;
             }
             if (p == parent->left) {
                 parent->left = child;
             }
             else {
                 parent->right = child;
             }
             if (child != nullptr) {
                 child->parent = parent;
             }
             delete p;
         }
         else { // nasty case!
             Node* dNode = successor(p);
             p->value = dNode->value;
             Node* parent = dNode->parent;
             Node* child = dNode->right;
             if (parent->left == dNode) {
                 parent->left = child;
             }
             else {
                 parent->right = child;
             }
             if (child != nullptr) {
                 child->parent = parent;
             }
             dNode->right = dNode->left = nullptr;
             delete dNode;
         }
     }

     /* recursive version of find */
     static Node* findNoPath(Node* root, int value) {
         if (root == nullptr) { return root; }
         if (root->value == value) { return root; }
         if (value < root->value) {
             return findNoPath(root->left, value);
         }
         return findNoPath(root->right, value);
     }

     Node* root;

 public:

     /* default constructor */
     BST(void) {
         root = nullptr;
     }

     /* destructor */
     ~BST(void) {
         delete root;
     }

     /* copy constructor */
     BST(const BST& that) { }

     /* assignment operator */
     BST& operator=(const BST& that) { }

     Node* getRoot(){
         return root;
     }

     void insert(int value) {
         Node* child = new Node(value); // create new Node which will be inserted

         if (root == nullptr) {
             root = child; // new child becomes root
             return;
         }

         Node* parent = nullptr;
         Node* p = root;			// start from p = root
         while (p != nullptr) {	// keep searching for empty spot to insert our new Node
             parent = p;
             if (value < p->value) {
                 p = p->left;
             }
             else {
                 p = p->right;
             }
         }	// while loop exits when p->left or p->right = null ptr

         if (value < parent->value) {
             assert(parent->left == nullptr);	// double-check to see if while loop worked correctly
             parent->left = child;	// insert our new node
         }
         // values that are duplicates or greater then will be right children
         else { // same as above
             assert(parent->right == nullptr);
             parent->right = child;
         }
         child->parent = parent;
     }

     void remove(int value) {
         Node* p = findNoPath(root, value);
         remove(p);
     }

     Node* find(Node* root, int value) {
         if (root == nullptr) {
             cout << "null";
             return root; }
         if (root->value == value) {
             cout << root->value;
             return root;
         } else if (value < root->value) {
             cout << root->value << " ";
             return find(root->left, value);
         } else {
             cout << root->value << " ";
             return find(root->right, value);
         }
     }
     /* print the tree  sorted order (-order); left, root, right
      */
     void print(const char* spec) {
         if (root == nullptr) { return; } // special case for empty tree
         Node* p;

         /* set p to smallest */
         p = root;
         while (p->left != nullptr) {
             p = p->left;
         }

         const char* prefix = "";
         while (p != nullptr) {
             printf("%s", prefix);
             printf(spec, p->value);
             prefix = ", ";
             p = successor(p);
         }
         printf("\n");
     }

     void inOrder(Node* p) const {

         if (p == nullptr) {
             return;
         } else {
             inOrder(p->left);
             cout << p->value << " ";
             inOrder(p->right);
         }
     }

     void preOrder(Node* p) const {
         if (p == nullptr) {
             return;
         } else {
             cout << p->value << " ";
             preOrder(p->left);
             preOrder(p->right);
         }
     }

     void postOrder(Node* p) const {
         if (p == nullptr) {
             return;
         } else {
             postOrder(p->left);
             postOrder(p->right);
             cout << p->value << " ";
         }
     }

     void smallest(Node* p) const {
         if ( p->left == nullptr) {
             cout << p->value;
         } else {
             smallest(p->left);
         }
     }

     void largest(Node* p) const {
         if ( p->right == nullptr) {
             cout << p->value;
         } else {
             largest(p->right);
         }
     }

     int height(Node* p) {

         if (p == nullptr)
             return 0;
         else
         {
             /* compute the depth of each subtree */
             int lDepth = height(p->left);
             int rDepth = height(p->right);

             /* use the larger one */
             if (lDepth > rDepth) {
                 //cout << lDepth + 1;
                 return(lDepth + 1);
             }
             else {
                 //cout << rDepth + 1;
                 return(rDepth + 1);
             }
         }
     }

 };

 #endif _BST_h

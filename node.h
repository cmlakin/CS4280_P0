struct Node {
    char value; // change to list of words
    Node* left;
    Node* right;
    Node* parent;

    // value constructor
    Node(char value) {
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

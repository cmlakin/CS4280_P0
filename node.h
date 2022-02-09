struct node_t {
    char value; // last character of word
    //list<string> words; // list of words each node holds
    node_t* left;
    node_t* right;
    node_t* parent;

    // value constructor
    node_t(char value) {
        this->value = value;
        left = right = parent = nullptr;
    }

    // copy constructor
    node_t(const node_t& rhs) { }

    // destructor
    ~node_t(void) {
        delete left;  // calls delete of left, which recursively calls delete on its left and right
        delete right;
    }
}; // end of struct node_t

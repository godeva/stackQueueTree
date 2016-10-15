/** Class to define a node; each entry can hold a pointer to anything.
*/

class Tnode {
public:
  // Fields:
  char* data; // A pointer to a C-style string. Stores pointer
  Tnode* left; // Pointer to a left child
  Tnode* right; // Pointer to a right child

  // Function prototypes
  Tnode(char* value); // Tnode constructor
  void add_tnode(char* value); // Adds string to Tnode
  void print_tnode(); // Prints all the Tnode
  void free_tnode(); // Frees all the Tnodes and its children

};

/** Class to define a Tree; can hold information about a tree, such as a pointer to the root node.
*/

class Tree {
public:
  // Fields:
  Tnode* root; // Pointer to a root

  // Function prototypes
    Tree(); // Tree constructor
    ~Tree(); // Tree destructor
    void add_tree(char* value); // Adds a value to a tree
    void TreePrint(); // Prints root and all sub-nodes
    void free_tree(); // Frees root and all sub-nodes

};

char* ranStringGen(size_t size); // Generates random strings
char ranLetterGen(); // Generates random character from capital A-Z

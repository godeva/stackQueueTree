#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/* Class and function prototypes for Trees and Tnode are stored */
#include "node.h"

/** Tree and Tnode methods are stored in this file.
*/


/** Create a Tree by setting the root of the tree to Null
*/

Tree::Tree() { // Runs method
  root = NULL;
}

/** Destructor: Cleans up the node which includes the memory holding
* the entries and the structure, but not the entries themselves.
*/

Tree::~Tree() { // Runs method
  free(root); // Free memory block with root/Tnode entries.
}

/** Creates a new node to placed on tree algorithm
* @param value the string value thats being added
*/

Tnode::Tnode(char* value) { // Runs method
  data = value; // Set the string paramater to data
  left = NULL;
  right = NULL;
}


/** Tree first checks if it is empty.
* If it is, instantiates a Tnode with the data, and make that
* new node the root of the tree. If not, it call the add
* method of the Tnode class on the root node.
* @param value the string value thats being added
*/

void Tree::add_tree(char* value) { // Runs method
  if(this->root == NULL) { // If the root pointer is null, allocate a new node
    this->root= new Tnode(value);
  } else { // Adds add_tnode if NULL does not exist
    root->add_tnode(value);
  }
}

/** Compares the parameter string against the string in the current node.
* If the string comes alphabetically before the current string, goes to the left
* child; if after, goes to the right child. Then it look at that pointer.
* If it is NULL, instantiate a new node and make it the child. If not NULL,
* call the add method on the child.
* @param value the string value thats being added
* @return Pointer to the added node
*/

void Tnode::add_tnode(char* value) { // Runs method
  if(strcmp(value, data) < 0) { // The string at current node comes before value
    if(left == NULL){ // If left child is null, create a new node with given value
      left = new Tnode(value);
      return;
    }
    if(left != NULL){ // If left is not Null, add a new value to add_tnode
      left->add_tnode(value); // Add node to the right subtree
    }
  }
  else { // If string at current node matches or comes after the value
    if(right == NULL){ // If right child is null, create a new node with given value
      right = new Tnode(value);
      return;
    }
    if(right != NULL){ // If right is not Null, add a new value to add_tnode
      right->add_tnode(value); // Add node to the right subtree
    }
  }
  return;
}


/** Prints the Tree and all its sub nodes in ascending order.
* Follows InOrder traversal since this is because of how you build the tree.
*/

void Tree::TreePrint() { // Runs method
  if (root != NULL) { // Prints tree if not empty
    root->print_tnode();
  } else {
    printf("Tree is empty\n");
  }
}

/** Prints the Tnode and all its sub nodes in ascending order.
* Follows InOrder traversal since this is because of how you build the tree.
*/

void Tnode::print_tnode() { // Runs method
  if (this->left != NULL) // Prints left child if not empty
  this->left->print_tnode(); // Continues printing the next left child till NULL

  printf("%s\n", this->data);

  if (this->right != NULL)  // Prints right child if not empty
  this->right->print_tnode(); // Continues printing the next right child till NULL
}


/** Frees the Tree and all of the sub-nodes of it.
*/

void Tree::free_tree() { // Runs method
  if (root != NULL) // Checks if Root is empty otherwise sent to free_tnode
  root->free_tnode();
  root = NULL;
}


/** Frees the root node and all of the sub-nodes of it.
*/

void Tnode::free_tnode() { // Runs method
  if (this->left != NULL) // Checks if left child is not empty
  this->left->free_tnode(); // Frees left child nodes till empty
  if (this->right != NULL) // Checks if right child is not empty
  this->right->free_tnode(); // Frees right child nodes till empty
  free(this->data); // Frees string pointer
  free(this); // Frees parameter
}

/** Generates and returns a single random character
* Function is restricted to the 26 upper-case letters ABC...XYZ
* @return Random single character letter
*/

char ranLetterGen() { // Runs method
  return 'A' + (random() % 26); // Generates and returns a random captial letter
}

/** generates a random string of printable characters, with a specified length.
* @param size specfied length of the string
* @return Random string of specfied length
*/

char* ranStringGen(size_t size) { // Runs method
  char* randomString = NULL;

  if (size) { // Checks if size is entered
    randomString = (char*)malloc(sizeof(char)*(size+1));  // Allocates memory

    if (randomString) {
      for (int n = 0; n < size; n++) { // Terminates when string size is meet
        char value = ranLetterGen(); // Calls random letter generator function
        randomString[n] = value; // Generates each random characters in string
      }
      randomString[size] = '\0';
    }
  }
  return randomString;
}

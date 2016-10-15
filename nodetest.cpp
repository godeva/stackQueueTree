#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/* Allows the the use time command */
#include <time.h>
/* Class and function prototypes for Trees and Tnode are stored */
#include "node.h"


int main() { // Runs Program
  srand(time(NULL)); // Used to activate random tree later
  const int max_entries = 6; // Size of random strings


  printf("Printing the tree that was made:\n");
  printf("Original order in the test file\nNico\nAlbert\nSpencer\nBrian\nMarco\nJack\nLiam\n");

  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Printed Tree of the root and its children in ascending order!\n");

  Tree* treeTest = new Tree(); // Creates a new tree called treeTest

  char* Nico = strdup("Nico");
  treeTest->add_tree(Nico);
  treeTest->root->print_tnode(); // Prints root first
  char* Albert = strdup("Albert");
  treeTest->add_tree(Albert);
  char* Spencer = strdup("Spencer");
  treeTest->add_tree(Spencer);
  char* Brian = strdup("Brian");
  treeTest->add_tree(Brian);
  char* Marco = strdup("Marco");
  treeTest->add_tree(Marco);
  char* Jack = strdup("Jack");
  treeTest->add_tree(Jack);
  char* Liam = strdup("Liam");
  treeTest->add_tree(Liam);

  treeTest->root->print_tnode(); // Prints treeTest with all the added root and children

  printf("\n"); // Adds blank space line in terminal to make program easier to view

  printf("Freeing the nodes\n");
  treeTest->free_tree(); // Frees all the subnodes and root

  printf("\n"); // Adds blank space line in terminal to make program easier to view

  printf("Printing randomly generated strings in the tree:\n");
  char* str1 = ranStringGen(max_entries);
  printf("%s\n", str1);
  char* str2 = ranStringGen(max_entries);
  printf("%s\n", str2);
  char* str3 = ranStringGen(max_entries);
  printf("%s\n", str3);
  char* str4 = ranStringGen(max_entries);
  printf("%s\n", str4);
  char* str5 = ranStringGen(max_entries);
  printf("%s\n", str5);
  char* str6 = ranStringGen(max_entries);
  printf("%s\n", str6);

  Tree* RandomtreeTest = new Tree();  // Creates a new random tree called RandomtreeTest
  RandomtreeTest->add_tree(str1);
  RandomtreeTest->add_tree(str2);
  RandomtreeTest->add_tree(str3);
  RandomtreeTest->add_tree(str4);
  RandomtreeTest->add_tree(str5);
  RandomtreeTest->add_tree(str6);

  printf("\n");
  printf("Printing in-order traversal of tree:\n");
  RandomtreeTest->root->print_tnode();

  // Free all the nodes of the tree
  RandomtreeTest->free_tree();

  // Clean up
  delete(treeTest);
  delete(RandomtreeTest);
  delete(Nico);
  delete(Albert);
  delete(Spencer);
  delete(Brian);
  delete(Marco);
  delete(Jack);
  delete(Liam);
  delete(str1);
  delete(str2);
  delete(str3);
  delete(str4);
  delete(str5);
  delete(str6);

}

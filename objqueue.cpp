#include <stdlib.h>
#include <stdio.h>
/* Class and function prototypes for Queue are stored */
#include "objqueue.h"

/** Queue methods are stored in this file.
*/

/** Create a queue by initializing it and the fields of the object,
*  including allocating a structure to hold the queue data.
* @param max_cells Maximum entries in the queue
*/

Queue::Queue(int max_cells) { // Runs method
  // Fill in the queue
  this->max_cells = max_cells; // "this->" needed to specify field, not param.
  used = 0; // Empty to start

  // Now allocate space for the queue entries.
  this->base = (void **) calloc(sizeof(void *), max_cells);
  if (this->base == NULL) {
    // Should signal an exception
  }

  /*Starts at head and tail of array*/
  head = 0;
  tail = 0;

}


/** Destructor: Cleans up the queue which includes the memory holding
* the entries and the structure, but not the entries themselves.
*/

Queue::~Queue() { // Runs method
  free(base); // Free memory block with queue entries.
}


/** Adds an element to the queue
* @param ptr The element to be added.
* @return 0 if successful, -1 if not.
*/

int Queue::enqueue(void* ptr) {  // Runs method
  if(used >= max_cells) { // Checks if size of the head is used up
    used = max_cells; // Overide to prevent mistracking data
    return -1; // Unsuccessful due to overflow
  } else {
    if(head >= max_cells){ // Checks if there is space for cells
      head = 0;
    }
    base[head] = ptr; // Stores the pointer in the head of the queue
    head++; // Points to the next free cell
    used++; // Keeps track of used cells
    return 0; // Success
  }
}


/** Dequeues an element.
* Returns a null pointer if an error occurs
*/

void* Queue::dequeue() { // Runs method
  void* element; // Sets an element
  if (used <= 0) { // Checks if there is enough used space
    used = 0;
    return NULL;
  }

  element = base[tail]; // Stores pointer in queue of tail
  tail++;  // Points to the next free cell
  used--; // Keeps track of used cells
  if (tail == max_cells) { // Sets tails to zero if max cell is used
    tail = 0;
  }

  return element; // Returns the pointer
}

#include <stdlib.h>
#include <stdio.h>
/* Class and function prototypes for Queue are stored */
#include "objqueue.h"
/* Class and function prototypes for Foo are stored */
#include "foo.h"

using namespace std;

int main() { // Runs Program

  const int max_entries = 10; // Size of queue
  Foo* new_foo1;
  Foo* new_foo2;
  Foo* new_foo3;
  Foo* new_foo4;
  Foo* returned_foo;
  char *ts; // Points to string returned by toString();

  // Setting up each Foo
  new_foo1 = new Foo(10, 20.79);
  new_foo2 = new Foo(42, 42.79);
  new_foo3 = new Foo(1, 1.79);
  new_foo4 = new Foo(8, 16.79);

  // First, create a Queue
  Queue *newQueue = new Queue(max_entries);

  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Verifying if the function dequeue is empty!\n");

  //Verifying if the function dequeue is empty will return NULL
  returned_foo = (Foo *) newQueue->dequeue(); // Sets returned_foo to dequeue the new_queue
  if (returned_foo == NULL) {
    printf("Dequeue is successfully empty.\n");
  }


  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing for overflow!\n");

  //Testing for overflow
  int i;
  for (i = 0; i < 11; i++) { // Enqueues up to 11 elements instead of 10 elements do demonstrate overflow
    if ((newQueue->enqueue((void *) new_foo1)) == -1 && i > 9) { // Checks if return types catch overflow
      printf("Overflow worked correctly.\n");
    }
  }


  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing if dequeue work properly!\n");

  //Testing if dequeue work properly
  for (i = 0; i < 10; i++) // Dequeues 10 elements for checking if dequeue works
  newQueue->dequeue(); // Sets returned_foo to dequeue the new_queue
  if ((newQueue->used) == 0) // Checks if cells used in stack is empty
  printf("Queue emptied correctly.\n");


  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing correct queue order: First In First Out!\n");

  ts = new_foo1->toString();
  if((newQueue->enqueue((void *) new_foo1)) == 0) // Checks if enqueue is the right return type given
  printf("Enqueue: %s\n", ts);
  free(ts);

  ts = new_foo2->toString();
  if((newQueue->enqueue((void *) new_foo2)) == 0) // Checks if enqueue is the right return type given
  printf("Enqueue: %s\n", ts);
  free(ts);

  ts = new_foo3->toString();
  if((newQueue->enqueue((void *) new_foo3)) == 0) // Checks if enqueue is the right return type given
  printf("Enqueue: %s\n", ts);
  free(ts);

  ts = new_foo4->toString();
  if((newQueue->enqueue((void *) new_foo4)) == 0) // Checks if enqueue is the right return type given
  printf("Enqueue: %s\n", ts);
  free(ts);

  printf("\n"); // Adds blank space line in terminal to make program easier to view

  returned_foo = (Foo *) newQueue->dequeue(); // Sets returned_foo to dequeue newQueue
  ts = returned_foo->toString();
  printf("Dequeue: %s\n", ts);
  if (returned_foo == new_foo1) // Checks new_foo1 first since stack stores the first object pushed
  printf("Order matches correctly for new_foo1\n");
  free(ts);

  returned_foo = (Foo *) newQueue->dequeue(); // Sets returned_foo to dequeue newQueue
  ts = returned_foo->toString();
  printf("Dequeue: %s\n", ts);
  if (returned_foo == new_foo2) // Checks new_foo2 first since stack stores the first object pushed
  printf("Order matches correctly for new_foo2\n");
  free(ts);

  returned_foo = (Foo *) newQueue->dequeue(); // Sets returned_foo to dequeue newQueue
  ts = returned_foo->toString();
  printf("Dequeue: %s\n", ts);
  if (returned_foo == new_foo3) // Checks new_foo3 first since stack stores the first object pushed
  printf("Order matches correctly for new_foo3\n");
  free(ts);

  returned_foo = (Foo *) newQueue->dequeue(); // Sets returned_foo to dequeue newQueue
  ts = returned_foo->toString();
  printf("Dequeue: %s\n", ts);
  if (returned_foo == new_foo4) // Checks new_foo4 first since stack stores the first object pushed
  printf("Order matches correctly for new_foo4\n");
  free(ts);

  // Deletes queue and foos to prevent memory leaks
  delete(newQueue);
  delete(ts);
  delete(new_foo1);
  delete(new_foo2);
  delete(new_foo3);
  delete(new_foo4);

}

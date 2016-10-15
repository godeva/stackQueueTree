#include <stdlib.h>
#include <stdio.h>
#include "objstack.h"
#include "foo.h"

using namespace std;

int main() { // Runs Program
  const int max_entries = 5; // Size of stack
  Foo* new_foo1;
  Foo* new_foo2;
  Foo* new_foo3;
  Foo* new_foo4;
  Foo* returned_foo;
  char *ts; // Points to string returned by toString();

  // First, create a stack
  Stack *new_stack = new Stack(max_entries);

  // Allocate a Foo and push it onto the stack.
  new_foo1 = new Foo(6, 14.79);
  ts = new_foo1->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = new Foo(217, 3.14159);
  ts = new_foo2->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) new_foo2);

  // Peek at the top of the stack
  returned_foo = (Foo *) new_stack->peek();
  ts = returned_foo->toString();
  printf("Peeked: %s\n", ts);
  free(ts); // Do not free returned_foo, since we are still using it!

  // Retrieve the Foos and print them.
  returned_foo = (Foo *) new_stack->pop();
  if (!returned_foo) {
    printf("Stack is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("Popped: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  returned_foo = (Foo *) new_stack->pop();
  if (!returned_foo) {
    printf("Stack is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("Popped: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  /* Pushing elements onto the stack, pop some off, and push some more. Testing that stack is in the right order. */

  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing the order of push and pop!\n");

  new_foo3 = new Foo(42, 1234); //Setting additional values to test stack
  ts = new_foo3->toString();
  if((new_stack->push((void *) new_foo3)) == 0) // Checks if foo is the right return type when pushed
  printf("Pushed: %s\n", ts);
  free(ts);

  new_foo4 = new Foo(19, 19.00); //Setting additional values to test stack
  ts = new_foo4->toString();
  if((new_stack->push((void *) new_foo4)) == 0) // Checks if foo is the right return type when pushed
  printf("Pushed: %s\n", ts);
  free(ts);

  printf("\n"); // Adds blank space line in terminal to make program easier to view

  returned_foo = (Foo *) new_stack->pop(); // Sets returned_foo to popping the new_stack
  ts = returned_foo->toString();
  printf("Popped: %s\n", ts);
  if (returned_foo == new_foo4) // Checks new_foo4 first since stack stores the last object pushed
  printf("Order matches correctly for new_foo4\n");
  free(ts);

  returned_foo = (Foo *) new_stack->pop(); // Sets returned_foo to popping the new_stack
  ts = returned_foo->toString();
  printf("Popped: %s\n", ts);
  if (returned_foo == new_foo3) // Checks new_foo3 after new_foo4 due to stack order
  printf("Order matches correctly for new_foo3\n");
  free(ts);


  /* Testing the stack overflow if the condition works */

  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing condition for stack overflow!\n");

  int i;

  for (i = 0; i < 7; i++) { // Overflowing by looping more than what stack holds (five)
    int answer = (new_stack->push((void *) new_foo3)); // Setting push to check each value of i
    printf("Returned value of %d by Pushing %d elements\n", answer, i + 1);

    ts = new_foo3->toString();
    if (returned_foo != NULL) { // Prints all the pushes made in stack
      printf("Pushed: %s\n", ts);
      free(ts);
    }

    if (i >= 5 && answer == -1) { // Checks for return type for Overflow
      printf("Overflow got the correct return value.\n");
    }
  }


  /* Popping more elements off the stack to test the stack underflow condition */

  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printf("Testing condition for stack underflow!\n");

  for (i = 0; i < 6; i++) { // Underflowing
    returned_foo = (Foo *) new_stack->pop(); // Sets returned_foo to popping the new_stack
    if (returned_foo != NULL) { // Prints all the pops made in stack
      ts = returned_foo->toString();
      printf("Returned value of %s by Popping %d elements\n", ts, i + 1);
      printf("Popped: %s\n", ts);
      free(ts);
    }

    if (i >= 5 && returned_foo == NULL) { // Checks for return type for Underflow
      printf("Underflow got the correct return value.\n");
    }
  }

  // Clean up
  delete(new_stack);
  delete(new_foo1);
  delete(new_foo2);
  delete(new_foo3);
  delete(new_foo4);

  return 0;
}

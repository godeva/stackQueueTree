/** Class to define a queue; lets you create multiple queues that hold pointers
* includes size, head and tail pointers, and the location of the queue buffer in memory.
*/

class Queue {
public:
  // Fields:
  void** base; // Base pointer of the queue. Location of the queue buffer in memory
  int head; // Head pointer of queue
  int tail; // Tail pointer of queue
  int max_cells; // Size of the head in the queue
  int used; // Number of cells that were used

  // Function prototypes
  Queue (int max_cells); // Queue constructor
  ~Queue(); // Queue destructor
  int enqueue(void *ptr); // Adding an element in queue
  void* dequeue(); // Removing an element in queue

};

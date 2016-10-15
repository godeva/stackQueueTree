Program Description: 

In the “assig6” folder, there are 26 files/directories. Note: Objects files will not be included in this guide as all the descriptions would be simply compiled code from the corresponding code files. Also note that html and latex directories are part of the doxygen file that help run and store "make docs". Therfore, we will not be going over those directories.  


NOTE: IF YOU WANT TO USE DOXYEGEN COMMAND "Make Docs", TAKE THE READ ME FILE OUT OF THE ZIP IN A SEPERATE DIRECTORY SO THAT DOXYGEN DOESN'T REGISTER readme.txt syntax as file members online. Thanks! 

objstacktest: This file is an executable that runs and tests pushing and poping a stack, the correct ordering of pushing and popping in the stack,  the conditions for stack overflow and underflow. Prints all of these conditions to demonstrate that the stack works properly.

objstacktest.cpp: This is human readable code file for objstacktest. All the code from this file was compiled to create the executable.

objstack.cpp: This files stores all the functions for stack 

objstack.h: This is the header file and contains both the function prototype, classes of as well as there private stored values.

objqueuetest: This file is an executable that runs and tests the enqueue and dequeue methods which adds and deletes elements in a queue, if the function dequeue is empty, overflow, dequeue working properly, and the correct of queue order which is "First In First Out". Prints all of these conditions to demonstrate that the queue works properly.

objqueuetest.cpp: This is human readable code file for objqueuetest. All the code from this file was compiled to create the executable.

objqueue.cpp: This files stores all the functions for queue. 

objqueue.h: This is the header file and contains both the function prototype, classes of as well as there private stored values.

nodetest: This file is an executable that runs and tests creating trees in ascending order (nodes are freed after being printed) and also test tree with randomly generating strings for subclasses. Prints all of these conditions to demonstrate that the Tree and Nodes works properly.

nodetest.cpp: This is human readable code file for nodetest. All the code from this file was compiled to create the executable.

node.cpp: This files stores all the functions for Tnode and trees. 

node.h: This is the header file and contains both the function prototype, classes of as well as there private stored values.

Makefile: Makefile takes all of the code files and compiles them so that they are ready to be used for the computer to read. In the contents of the file, makefile shows the files that that are told to be compiled and link together and cleaned. To activate the contents of Makefile, type “make” on the command line which will allow the code files to be compiled to run the program. If you wish to uncompile the code files which removes the .o file, type “make clean” on the command prompt.

How to compile: 

Unzip the tar file and type "make" in the command prompt inside the "assig6" directory. This will compile all the files in the folder as well as link the header files with the same named code file. If you wish to uncompile, type "make clean" and it will delete all the object files and leave you with the code files, header files, Doxyfile, and makefile.

Test Data:

//Check if the stack program runs

Input: ./objstacktest


What to Expect:

Pushing: i = 6, x = 14.790000
Pushing: i = 217, x = 3.141590
Peeked: i = 217, x = 3.141590
Popped: i = 217, x = 3.141590
Popped: i = 6, x = 14.790000

Testing the order of push and pop!
Pushed: i = 42, x = 1234.000000
Pushed: i = 19, x = 19.000000

Popped: i = 19, x = 19.000000
Order matches correctly for new_foo4
Popped: i = 42, x = 1234.000000
Order matches correctly for new_foo3

Testing condition for stack overflow!
Returned value of 0 by Pushing 1 elements
Pushed: i = 42, x = 1234.000000
Returned value of 0 by Pushing 2 elements
Pushed: i = 42, x = 1234.000000
Returned value of 0 by Pushing 3 elements
Pushed: i = 42, x = 1234.000000
Returned value of 0 by Pushing 4 elements
Pushed: i = 42, x = 1234.000000
Returned value of 0 by Pushing 5 elements
Pushed: i = 42, x = 1234.000000
Returned value of -1 by Pushing 6 elements
Pushed: i = 42, x = 1234.000000
Overflow got the correct return value.
Returned value of -1 by Pushing 7 elements
Pushed: i = 42, x = 1234.000000
Overflow got the correct return value.

Testing condition for stack underflow!
Returned value of i = 42, x = 1234.000000 by Popping 1 elements
Popped: i = 42, x = 1234.000000
Returned value of i = 42, x = 1234.000000 by Popping 2 elements
Popped: i = 42, x = 1234.000000
Returned value of i = 42, x = 1234.000000 by Popping 3 elements
Popped: i = 42, x = 1234.000000
Returned value of i = 42, x = 1234.000000 by Popping 4 elements
Popped: i = 42, x = 1234.000000
Returned value of i = 42, x = 1234.000000 by Popping 5 elements
Popped: i = 42, x = 1234.000000
Underflow got the correct return value.
_________________________________________________________________

//Check if the queue program runs

Input: ./objqueuetest


What to Expect:

Verifying if the function dequeue is empty!
Dequeue is successfully empty.

Testing for overflow!
Overflow worked correctly.

Testing if dequeue work properly!
Queue emptied correctly.

Testing correct queue order: First In First Out!
Enqueue: i = 10, x = 20.790000
Enqueue: i = 42, x = 42.790000
Enqueue: i = 1, x = 1.790000
Enqueue: i = 8, x = 16.790000

Dequeue: i = 10, x = 20.790000
Order matches correctly for new_foo1
Dequeue: i = 42, x = 42.790000
Order matches correctly for new_foo2
Dequeue: i = 1, x = 1.790000
Order matches correctly for new_foo3
Dequeue: i = 8, x = 16.790000
Order matches correctly for new_foo4
_________________________________________________________________

//Check if the Tree/Node program runs

Input: ./nodetest


What to Expect:

Printing the tree that was made:
Original order in the test file
Nico
Albert
Spencer
Brian
Marco
Jack
Liam

Printed Tree of the root and its children in ascending order!
Nico
Albert
Brian
Jack
Liam
Marco
Nico
Spencer

Freeing the nodes

Printing randomly generated strings in the tree:
VBNTQD
HBBKJY
UREBEZ
LBEOJW
JJMHOB
KLCXEV

Printing in-order traversal of tree:
HBBKJY
JJMHOB
KLCXEV
LBEOJW
UREBEZ
VBNTQD
_________________________________________________________________

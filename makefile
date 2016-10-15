all: objstacktest objqueuetest nodetest

objstacktest: objstacktest.o objstack.o foo.o
	g++ -g objstacktest.o objstack.o foo.o -o objstacktest

objstack.o: objstack.cpp objstack.h
	g++ -g -c objstack.cpp

objstacktest.o: objstacktest.cpp objstack.h foo.h
	g++ -g -c objstacktest.cpp

objqueuetest: objqueuetest.o objqueue.o foo.o
	g++ -g objqueuetest.o objqueue.o foo.o -o objqueuetest

objqueue.o: objqueue.cpp objqueue.h
	g++ -g -c objqueue.cpp

objqueuetest.o: objqueuetest.cpp objqueue.h foo.h
	g++ -g -c objqueuetest.cpp

nodetest: nodetest.o node.o
	g++ -g nodetest.o node.o -o nodetest

node.o: node.cpp node.h
	g++ -g -c node.cpp

nodetest.o: nodetest.cpp node.h
	g++ -g -c nodetest.cpp

foo.o: foo.cpp foo.h
	g++ -g -c foo.cpp

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig6

clean:
	rm -f *.o
	rm -f objstacktest
	rm -f objqueuetest
	rm -f nodetest

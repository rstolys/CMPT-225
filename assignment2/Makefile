all: BSTtest BSTtest2 BSTtestCL BSTtestCD  BSTtestDD



BSTtest: BSTtest.o
	g++ -Wall -o BSTtest BSTtest.o  

BSTtest.o: BSTtest.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o BSTtest.o -c BSTtest.cpp 



BSTtest2: BSTtest2.o
	g++ -Wall -o BSTtest2 BSTtest2.o

BSTtest2.o: BSTtest2.cpp BinarySearchTreeDL.h dsexceptions.h
	g++ -Wall -o BSTtest2.o -c BSTtest2.cpp



BSTtestCL: BSTtestCL.o
	g++ -Wall -o BSTtestCL BSTtestCL.o

BSTtestCL.o: BSTtest2.cpp BinarySearchTreeCL.h dsexceptions.h
	g++ -Wall -o BSTtestCL.o -c BSTtestCL.cpp



BSTtestCD: BSTtestCD.o
	g++ -Wall -o BSTtestCD BSTtestCD.o

BSTtestCD.o: BSTtest2.cpp BinarySearchTreeCD.h dsexceptions.h
	g++ -Wall -o BSTtestCD.o -c BSTtestCD.cpp



BSTtestDD: BSTtestDD.o
	g++ -Wall -o BSTtestDD BSTtestDD.o

BSTtestDD.o: BSTtestDD.cpp BinarySearchTreeDD.h dsexceptions.h
	g++ -Wall -o BSTtestDD.o -c BSTtestDD.cpp



clean:
	rm -f BSTtest *.o 
	rm -f BSTtest2 *.o 
	rm -f BSTtestCL *.o 
	rm -f BSTtestCD *.o 
	rm -f BSTtestDD *.o 

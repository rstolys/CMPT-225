all: main



main: main.o
	g++ -Wall -o main main.o  

main.o: main.cpp BinarySearchTree.h AvlTree.h dsexceptions.h
	g++ -Wall -o main.o -c main.cpp 


clean:
	rm -f main *.o 

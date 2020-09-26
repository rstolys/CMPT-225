all: part1

part1: part1.o
	g++ -Wall -o part1 part1.o  

part1.o: part1.cpp 
	g++ -Wall -o part1.o -c part1.cpp 

clean:
	rm -f part1 *.o
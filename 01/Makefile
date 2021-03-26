CPP = g++
FLAGS = -O2 -Wall -std=c++17

all : tester.o allocator.o
	$(CPP) $(FLAGS) tester.o allocator.o -o tester
	
test: tester
	./tester

tester.o: test.cpp
	$(CPP) $(FLAGS) test.cpp -c -o tester.o

allocator.o: allocator.cpp
	$(CPP) $(FLAGS) allocator.cpp -c -o allocator.o

clean:
	rm -rf *.o tester

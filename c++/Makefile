all: main ex2-1

main: main.o
	g++ -o main main.o

ex2-1 : ex2-1.o
	g++ -o ex2-1 ex2-1.o

main.o: main.cc
	g++ -c main.cc -g -Wall --std=c++20

ex2-1.o: ex2-1.cc
	g++ -c ex2-1.cc -g -Wall --std=c++20

clean:
	rm -f *.o main ex2-1
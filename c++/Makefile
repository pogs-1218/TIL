CC = g++
CXXFLAGS = -g -Wall --std=c++20
OBJS = main.o
TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS)

main.o: my_class.h main.cc
	$(CC) $(CXXFLAGS) -c main.cc

.PHONY: clean
clean:
	rm -f $(OBJS) main ex2-1
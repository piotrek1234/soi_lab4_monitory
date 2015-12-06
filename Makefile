CC=g++
CFLAGS=-Wall -pthread --std=c++11

soi4.o: soi4.cpp fifo.h
	$(CC) $(CFLAGS) soi4.cpp -o soi4

fifo.o: fifo.h fifo.cpp
	$(CC) $(CFLAGS) fifo.cpp

all: soi4.o fifo.o
	$(CC) soi4.o fifo.o

.PHONY: clean

clean:
	rm -f *.o
	rm -f *.out
	rm -f soi4
CC=g++
CFLAGS=-Wall -std=c++11 -pthread -Wl,--no-as-needed

all: soi4.cpp fifo.h monitor.h produkcja.h
	$(CC) soi4.cpp -Wall -std=c++11 -pthread -o soi4

clean:
	rm -f *.o
	rm -f soi4

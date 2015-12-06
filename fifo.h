#ifndef FIFO_H
#define FIFO_H

#include <queue>

using namespace std;

class Fifo{
public:
	Fifo() {}
	~Fifo() {}
	int get();
	int pop();
	void push(int val);
private:
	queue<int> buf;
};

#endif
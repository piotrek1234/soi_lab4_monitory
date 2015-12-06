#ifndef FIFO_H
#define FIFO_H

#include <list>

using namespace std;

class Fifo{
public:
	Fifo() {}
	~Fifo() {}
	int get();
	int pop();
	void push(int val);
private:
	list<int> buf;
};

int Fifo::get()
{
	return buf.front();
}

int Fifo::pop()
{
	int tmp = buf.front();
	buf.pop_front();
	return tmp;
}

void Fifo::push(int val)
{
	buf.push_back(val);
}

#endif
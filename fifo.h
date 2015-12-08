#ifndef FIFO_H
#define FIFO_H

#include <list>
#include <ostream>

using namespace std;

class Fifo{
public:
	Fifo() {}
	~Fifo() {}
	int get();
	int pop();
	void push(int val);
	int size() { return buf.size(); }
	friend ostream& operator<< (ostream& os, const Fifo& fifo);
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

ostream& operator<< (ostream& os, const Fifo& fifo)
{
	int num = 9;
	for(auto it = fifo.buf.begin(); it != fifo.buf.end(); ++it)
	{
		os << '[' << *it << ']';
		--num;
	}
	
	for(int i=0; i<num; ++i)
		os << "[ ]";
	
	return os;
}

#endif
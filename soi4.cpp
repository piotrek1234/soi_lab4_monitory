#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "fifo.h"

using namespace std;

void producentA();
void producentB();
void konsumentA();
void konsumentB();

Fifo fifo;

int main(void)
{
	srand(time(NULL));

	thread thPrA(producentA);
	thread thPrB(producentB);
	thread thKoA(konsumentA);
	thread thKoB(konsumentB);

	thPrA.join();
	thPrB.join();
	thKoA.join();
	thKoB.join();

	return 0;
}

void producentA()
{
	for(int i=0; i<10; ++i)
	{
		int produkt = rand() % 100;
		cout << produkt <<' ';
	}
	
}

void producentB()
{

}

void konsumentA()
{

}

void konsumentB()
{

}

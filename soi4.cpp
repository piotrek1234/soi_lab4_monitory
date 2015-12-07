#include <iostream>
#include <thread>
#include "produkcja.h"
#include "delay.h"

using namespace std;

const int ILE_RAZY = 10;
Produkcja prod;

void produkujA()
{
	for(int i=0; i<ILE_RAZY; ++i)
	{
		delay();
		prod.produkujA();
	}
}

void produkujB()
{
	for(int i=0; i<ILE_RAZY; ++i)
	{
		delay();
		prod.produkujB();
	}
}

void konsumujA()
{
	for(int i=0; i<ILE_RAZY; ++i)
	{
		delay();
		delay();
		delay();
		prod.konsumujA();
	}
}

void konsumujB()
{
	for(int i=0; i<ILE_RAZY; ++i)
	{
		delay();
		delay();
		delay();
		prod.konsumujB();
	}
}

int main(void)
{
	
	thread p1(produkujA);
	thread p2(produkujB);
	thread k1(konsumujA);
	thread k2(konsumujB);

	p1.join();
	p2.join();
	k1.join();
	k2.join();

	return 0;
}

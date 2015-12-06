#include <iostream>
#include <thread>
#include "produkcja.h"

using namespace std;

const int ILE_RAZY = 10;
Produkcja prod;

void produkujA()
{
	for(int i=0; i<ILE_RAZY; ++i)
		prod.produkujA();
}

void produkujB()
{
	for(int i=0; i<ILE_RAZY; ++i)
		prod.produkujB();
}

void konsumujA()
{
	for(int i=0; i<ILE_RAZY; ++i)
		prod.konsumujA();
}

void konsumujB()
{
	for(int i=0; i<ILE_RAZY; ++i)
		prod.konsumujB();
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

#ifndef PRODUKCJA_H
#define PRODUKCJA_H

#include <iostream>
#include "monitor.h"
#include "fifo.h"

using namespace std;

class Produkcja : public Monitor{
public:
	Produkcja() : suma(0) {}
	~Produkcja() {}
	void produkujA();
	void produkujB();
	void konsumujA();
	void konsumujB();
private:
	Fifo fifo;
	int suma;
};

void Produkcja::produkujA()
{

}

void Produkcja::produkujB()
{

}

void Produkcja::konsumujA()
{

}

void Produkcja::konsumujB()
{

}

#endif
#ifndef PRODUKCJA_H
#define PRODUKCJA_H

#include <iostream>
#include "monitor.h"
#include "fifo.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class Produkcja : public Monitor{
public:
	Produkcja() : suma(0) { srand(time(0)); }
	~Produkcja() {}
	void produkujA();
	void produkujB();
	void konsumujA();
	void konsumujB();
private:
	Fifo fifo;
	int suma;
	Condition min3;
	Condition pelny;
	Condition suma20;
	static const int ZAKRES = 10;
};

// producentA wstawia tylko jeśli suma elementów jest mniejsza niż 20
void Produkcja::produkujA()
{
	int elem = rand() % ZAKRES;

	enter();

	if(fifo.size() >= 9)
	{
		cout << "Producent A czeka na wolne miejsca " << fifo << endl;
		wait(pelny);
	}

	if(suma >= 20)
	{
		wait(suma20);
	}
		
	fifo.push(elem);
	suma += elem;
	cout << "Producent A wstawia element (" << elem << "). Suma: " << suma << " " << fifo << endl;

	if(fifo.size() > 3)
		signal(min3);

	leave();
}

// producent B może wstawiać bez względu na dodatkowe warunki
void Produkcja::produkujB()
{
	int elem = rand() % ZAKRES;

	enter();

	if(fifo.size() >= 9)
		wait(pelny);

	fifo.push(elem);
	suma += elem;

	if(fifo.size() > 3)
		signal(min3);

	leave();
}

void Produkcja::konsumujA()
{
	enter();

	if(fifo.size() <= 3)
		wait(min3);

	int elem = fifo.pop();
	suma -= elem;
	
	cout << "A zdejmuje " << elem << ". Rozmiar: " << fifo.size() << ", suma: " << suma << endl;

	signal(pelny);

	if(suma < 20)
		signal(suma20);

	leave();
}

void Produkcja::konsumujB()
{
	enter();

	if(fifo.size() <= 3)
		wait(min3);

	int elem = fifo.pop();
	suma -= elem;
	
	cout << "B zdejmuje " << elem << ". Rozmiar: " << fifo.size() << ", suma: " << suma << endl;

	signal(pelny);
	
	if(suma < 20)
		signal(suma20);

	leave();
}

#endif
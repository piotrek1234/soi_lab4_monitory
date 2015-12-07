#ifndef PRODUKCJA_H
#define PRODUKCJA_H

#include <iostream>
#include "monitor.h"
#include "fifo.h"
#include <random>

using namespace std;

class Produkcja : public Monitor{
public:
	Produkcja() : suma(0) { distribution =  uniform_int_distribution<int>(0,9); }
	~Produkcja() {}
	void produkujA();
	void produkujB();
	void konsumujA();
	void konsumujB();
	int losuj() { return distribution(generator); }
private:
	Fifo fifo;
	int suma;
	Condition ponad3;
	Condition pelny;
	Condition suma20;
	static const int ZAKRES = 10;
	default_random_engine generator;
 	uniform_int_distribution<int> distribution;
};

// producentA wstawia tylko jeśli suma elementów jest mniejsza niż 20
void Produkcja::produkujA()
{
	int elem = losuj();

	enter();

	if(fifo.size() >= 9)
	{
		cout << "Producent A czeka na wolne miejsce " << fifo << endl;
		wait(pelny);
	}

	if(suma >= 20)
	{
		cout << "Producent A czeka na sume < 20 " << fifo << endl;
		wait(suma20);
	}
		
	fifo.push(elem);
	suma += elem;
	cout << "Producent A wstawia element (" << elem << "). Suma: " << suma << " " << fifo << endl;

	if(fifo.size() > 3)
		signal(ponad3);

	leave();
}

// producent B może wstawiać bez względu na dodatkowe warunki
void Produkcja::produkujB()
{
	int elem = losuj();

	enter();

	if(fifo.size() >= 9)
	{
		cout << "Producent B czeka na wolne miejsce " << fifo << endl;
		wait(pelny);
	}

	fifo.push(elem);
	suma += elem;
	cout << "Producent B wstawia element (" << elem << "). Suma: " << suma << " " << fifo << endl;

	if(fifo.size() > 3)
		signal(ponad3);

	leave();
}

void Produkcja::konsumujA()
{
	enter();

	if(fifo.size() <= 3)
	{
		cout << "Konsument A czeka na ponad 3 elementy " << fifo << endl;
		wait(ponad3);
		
	}

	int elem = fifo.pop();
	suma -= elem;
	
	cout << "Konsument A zdejmuje (" << elem << "). Rozmiar: " << fifo.size() << ", suma: " << suma << ' ' << fifo << endl;

	//ewentualnie warunek żeby puścić oba sygnały na raz
	signal(pelny);

	if(suma < 20)
		signal(suma20);

	leave();
}

void Produkcja::konsumujB()
{
	enter();

	if(fifo.size() <= 3)
	{
		cout << "Konsument B czeka na ponad 3 elementy " << fifo << endl;
		wait(ponad3);
	}

	int elem = fifo.pop();
	suma -= elem;
	
	cout << "Konsument B zdejmuje " << elem << ". Rozmiar: " << fifo.size() << ", suma: " << suma << ' ' << fifo << endl;

	signal(pelny);
	
	if(suma < 20)
		signal(suma20);

	leave();
}

#endif
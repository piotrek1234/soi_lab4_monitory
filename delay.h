#include <unistd.h>
#include <cstdlib>
#include <ctime>

void delay()
{
	int czas;
	srand(time(0));
	czas = (std::rand() % 300);

	usleep(1000*czas);
}
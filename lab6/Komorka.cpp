#include "Komorka.h"
using namespace std;

Komorka::Komorka()
{
	int k = 0;
	this->wartosc = &k;
}

Komorka::Komorka(void* wartosc)
{
	this->wartosc = wartosc;
}

void* Komorka::get_wartosc()
{
	return this->wartosc;
}

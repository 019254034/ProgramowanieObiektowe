#include "Komorka.h"
using namespace std;

Komorka::Komorka()
{
	this->wartosc = 0;
}

Komorka::Komorka(int wartosc)
{
	this->wartosc = wartosc;
}

int Komorka::get_wartosc()
{
	return this->wartosc;
}

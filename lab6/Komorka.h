#pragma once
#include <string>
class Komorka
{
public:
	Komorka();
	Komorka(void* wartosc);

	void* get_wartosc();

private:
	void* wartosc;
};


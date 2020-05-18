#include <iostream>
#include "Tablica.h"
using namespace std;

namespace
{
	void wyswietl_element(Tablica tablica, int wspolrzedna_x, int wspolrzedna_y)
	{
		cout << endl;
		cout << "Element[" << wspolrzedna_x << "][" << wspolrzedna_y << "] = ";
		cout << tablica.t[wspolrzedna_x][wspolrzedna_y] << endl << endl;
	}

	void wyswietl_wszystkie_elementy(Tablica tablica)
	{
		cout << endl;
		for (int i = 0; i < tablica.liczba_wierszy; i++)
		{
			for (int j = 0; j < tablica.liczba_kolumn; j++)
			{
				cout << tablica.t[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
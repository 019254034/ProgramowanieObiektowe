#include <iostream>
using namespace std;

namespace
{
	void wyswietl_element(int** tablica, int wspolrzedna_x, int wspolrzedna_y)
	{
		cout << endl;
		cout << "Element[" << wspolrzedna_x << "][" << wspolrzedna_y << "] = ";
		cout << tablica[wspolrzedna_x][wspolrzedna_y] << endl << endl;
	}

	void wyswietl_wszystkie_elementy(int** tablica, int rozmiar_x, int rozmiar_y)
	{
		cout << endl;
		for (int i = 0; i < rozmiar_x; i++)
		{
			for (int j = 0; j < rozmiar_y; j++)
			{
				cout << tablica[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
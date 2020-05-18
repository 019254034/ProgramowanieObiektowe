#include <iostream>
using namespace std;

namespace
{

	int** stworz_tablice(int rozmiar_x, int rozmiar_y)
	{
		//tworze pusta tablice dwuwymiarowa
		int ** tablica = new int* [rozmiar_x];
		for (int i = 0; i < rozmiar_x; i++)
		{
			tablica[i] = new int[rozmiar_y];
		}

		//zupelniam ja samymi zerami
		for (int i = 0; i < rozmiar_x; i++)
		{
			for (int j = 0; j < rozmiar_y; j++)
			{
				tablica[i][j] = 0;
			}
		}

		return tablica;
	}

	//jezeli zmienimy rozmiar na mniejszy stracimy dane
	int** zmien_rozmiar(int** tablica, int nowy_rozmiar_x, int nowy_rozmiar_y, int stary_rozmiar_x, int stary_rozmiar_y)
	{
		//tworze nowa tablice
		int** nowa_tablica = new int* [nowy_rozmiar_x];
		for (int i = 0; i < nowy_rozmiar_x; i++)
		{
			nowa_tablica[i] = new int[nowy_rozmiar_y];
		}

		//przenosze elementy ze starej tablicy do nowej
		for (int i = 0; i < nowy_rozmiar_x; i++)
		{
			for (int j = 0; j < nowy_rozmiar_y; j++)
			{
				if (i >= stary_rozmiar_x || j >= stary_rozmiar_y) 
				{
					nowa_tablica[i][j] = 0;
				}
				else
				{
					nowa_tablica[i][j] = tablica[i][j];
				}
			}
		}

		return nowa_tablica;
	}

	int** aktualizuj_element(int** tablica, int wspolrzedna_x, int wspolrzedna_y, int nowa_wartosc)
	{
		tablica[wspolrzedna_x][wspolrzedna_y] = nowa_wartosc;
		return tablica;
	}

}
#include <iostream>
#include "Tablica.h"
using namespace std;

namespace
{

	Tablica stworz_tablice(int rozmiar_x, int rozmiar_y)
	{
		//tworze pusta tablice dwuwymiarowa
		int** nowa_tablica = new int* [rozmiar_x];
		for (int i = 0; i < rozmiar_x; i++)
		{
			nowa_tablica[i] = new int[rozmiar_y];
		}

		//zupelniam ja samymi zerami
		for (int i = 0; i < rozmiar_x; i++)
		{
			for (int j = 0; j < rozmiar_y; j++)
			{
				nowa_tablica[i][j] = 0;
			}
		}

		Tablica t = { nowa_tablica, rozmiar_x, rozmiar_y };
		return t;
	}

	//jezeli zmienimy rozmiar na mniejszy stracimy dane
	int** zmien_rozmiar(Tablica tablica, int nowy_rozmiar_x, int nowy_rozmiar_y)
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
				if (i >= tablica.liczba_wierszy || j >= tablica.liczba_kolumn)
				{
					nowa_tablica[i][j] = 0;
				}
				else
				{
					nowa_tablica[i][j] = tablica.t[i][j];
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

	int sumuj_elementy_wiersza(Tablica tablica, int nr_wiersza) {
		int wynik = 0;
		for (int i = 0; i < tablica.liczba_kolumn - 1; i++)
		{
			wynik += tablica.t[nr_wiersza][i] + tablica.t[nr_wiersza][i + 1];
		}
		return wynik;
	}

	int sumuj_elementy_kolumny(Tablica tablica, int nr_kolumny) {
		int wynik = 0;
		for (int i = 0; i < tablica.liczba_wierszy - 1; i++)
		{
			wynik += tablica.t[i][nr_kolumny] + tablica.t[i + 1][nr_kolumny];
		}
		return wynik;
	}

	double srednia_elementow_wiersza(Tablica tablica, int nr_wiersza) {
		return sumuj_elementy_wiersza(tablica, nr_wiersza) / tablica.liczba_kolumn;
	}

	double srednia_elementow_kolumny(Tablica tablica, int nr_kolumny) {
		return sumuj_elementy_kolumny(tablica, nr_kolumny) / tablica.liczba_wierszy;
	}

	int najmniejsza_z_wiersza(Tablica tablica, int nr_wiersza) {
		int wynik = tablica.t[nr_wiersza][0];
		for (int i = 1; i < tablica.liczba_kolumn; i++)
		{
			if (wynik > tablica.t[nr_wiersza][i])
			{
				wynik = tablica.t[nr_wiersza][i];
			}
		}
		return wynik;
	}


	int najwieksza_z_wiersza(Tablica tablica, int nr_wiersza) {
		int wynik = tablica.t[nr_wiersza][0];
		for (int i = 1; i < tablica.liczba_kolumn; i++)
		{
			if (wynik < tablica.t[nr_wiersza][i])
			{
				wynik = tablica.t[nr_wiersza][i];
			}
		}
		return wynik;
	}

	int najmniejsza_z_kolumny(Tablica tablica, int nr_kolumny) {
		int wynik = tablica.t[0][nr_kolumny];
		for (int i = 1; i < tablica.liczba_wierszy - 1; i++)
		{
			if (wynik > tablica.t[i][nr_kolumny])
			{
				wynik = tablica.t[i][nr_kolumny];
			}
		}
		return wynik;
	}

	int najwieksza_z_kolumny(Tablica tablica, int nr_kolumny) {
		int wynik = tablica.t[0][nr_kolumny];
		for (int i = 1; i < tablica.liczba_wierszy - 1; i++)
		{
			if (wynik < tablica.t[i][nr_kolumny])
			{
				wynik = tablica.t[i][nr_kolumny];
			}
		}
		return wynik;
	}

}
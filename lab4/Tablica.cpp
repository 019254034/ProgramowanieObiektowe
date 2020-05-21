#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Tablica.h"
using namespace std;

Tablica::Tablica(int liczba_wierszy, int liczba_kolumn)
{
	this->liczba_wierszy = liczba_wierszy;
	this->liczba_kolumn = liczba_kolumn;
	this->t = this->stworz_tablice(liczba_wierszy, liczba_kolumn);
}

int** Tablica::get_t()
{
	return this->t;
}

int Tablica::get_liczba_wierszy()
{
	return this->liczba_wierszy;
}

int Tablica::get_liczba_kolumn()
{
	return this->liczba_kolumn;
}

int** Tablica::stworz_tablice(int rozmiar_x, int rozmiar_y)
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

	return nowa_tablica;
}

//jezeli zmienimy rozmiar na mniejszy stracimy dane
void Tablica::zmien_rozmiar(int nowy_rozmiar_x, int nowy_rozmiar_y)
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
			if (i >= this->liczba_wierszy || j >= this->liczba_kolumn)
			{
				nowa_tablica[i][j] = 0;
			}
			else
			{
				nowa_tablica[i][j] = this->t[i][j];
			}
		}
	}

	this->t = nowa_tablica;
	this->liczba_wierszy = nowy_rozmiar_x;
	this->liczba_kolumn = nowy_rozmiar_y;
}

void Tablica::aktualizuj_element(int wspolrzedna_x, int wspolrzedna_y, int nowa_wartosc)
{
	this->t[wspolrzedna_x][wspolrzedna_y] = nowa_wartosc;
}

int Tablica::sumuj_elementy_wiersza(int nr_wiersza) {
	int wynik = 0;
	for (int i = 0; i < this->liczba_kolumn - 1; i++)
	{
		wynik += this->t[nr_wiersza][i] + this->t[nr_wiersza][i + 1];
	}
	return wynik;
}

int Tablica::sumuj_elementy_kolumny(int nr_kolumny) {
	int wynik = 0;
	for (int i = 0; i < this->liczba_wierszy - 1; i++)
	{
		wynik += this->t[i][nr_kolumny] + this->t[i + 1][nr_kolumny];
	}
	return wynik;
}

double Tablica::srednia_elementow_wiersza(int nr_wiersza) {
	return sumuj_elementy_wiersza(nr_wiersza) / this->liczba_kolumn;
}

double Tablica::srednia_elementow_kolumny(int nr_kolumny) {
	return sumuj_elementy_kolumny(nr_kolumny) / this->liczba_wierszy;
}

int Tablica::najmniejsza_z_wiersza(int nr_wiersza) {
	int wynik = this->t[nr_wiersza][0];
	for (int i = 1; i < this->liczba_kolumn; i++)
	{
		if (wynik > this->t[nr_wiersza][i])
		{
			wynik = this->t[nr_wiersza][i];
		}
	}
	return wynik;
}


int Tablica::najwieksza_z_wiersza(int nr_wiersza) {
	int wynik = this->t[nr_wiersza][0];
	for (int i = 1; i < this->liczba_kolumn; i++)
	{
		if (wynik < this->t[nr_wiersza][i])
		{
			wynik = this->t[nr_wiersza][i];
		}
	}
	return wynik;
}

int Tablica::najmniejsza_z_kolumny(int nr_kolumny) {
	int wynik = this->t[0][nr_kolumny];
	for (int i = 1; i < this->liczba_wierszy - 1; i++)
	{
		if (wynik > this->t[i][nr_kolumny])
		{
			wynik = this->t[i][nr_kolumny];
		}
	}
	return wynik;
}

int Tablica::najwieksza_z_kolumny(int nr_kolumny) {
	int wynik = this->t[0][nr_kolumny];
	for (int i = 1; i < this->liczba_wierszy - 1; i++)
	{
		if (wynik < this->t[i][nr_kolumny])
		{
			wynik = this->t[i][nr_kolumny];
		}
	}
	return wynik;
}

void Tablica::zapisz_do_pliku(string nazwa_pliku)
{
	ofstream plik;
	plik.open(nazwa_pliku, ios::out);
	if (plik.is_open())
	{
		cout << "Otwarto plik " << nazwa_pliku << endl;
		for (int i = 0; i < this->liczba_wierszy; i++)
		{
			for (int j = 0; j < this->liczba_kolumn; j++)
			{
				plik << this->t[i][j];
				if (j != this->liczba_kolumn - 1)
				{
					plik << ",";
				}
			}
			plik << endl;
		}
		plik.close();
	}
	else
	{
		cout << "Nie mozna otworzyc pliku " << nazwa_pliku << endl;
	}
}

void Tablica::wczytaj_z_pliku(string nazwa_pliku, int rozmiar_x, int rozmiar_y)
{
	ifstream plik;
	plik.open(nazwa_pliku, ios::in);
	if (plik.is_open())
	{
		cout << "Nastepuje odczyt tablicy o rozmiarze [" << rozmiar_x << "][" << rozmiar_y << "] z pliku " << nazwa_pliku << endl;

		int** nowa_tablica = new int* [rozmiar_x];
		for (int i = 0; i < rozmiar_x; i++)
		{
			nowa_tablica[i] = new int[rozmiar_y];
		}

		string wiersz;
		int x = 0;
		int y = 0;
		while (getline(plik, wiersz))
		{
			cout << "Wiers:::::" << endl;
			cout << "Wiersz: " << wiersz << endl;
			stringstream ss(wiersz);
			while (ss.good())
			{
				string element;
				getline(ss, element, ',');
				cout << "Element: " << element << endl;
				nowa_tablica[x][y] = stoi(element);
				y++;
			}
			x++;
		}
		this->t = nowa_tablica;
	}
	else
	{
		cout << "Nie mozna otworzyc pliku " << nazwa_pliku << endl;
	}
}

void Tablica::wyswietl_element(int wspolrzedna_x, int wspolrzedna_y)
{
	cout << endl;
	cout << "Element[" << wspolrzedna_x << "][" << wspolrzedna_y << "] = ";
	cout << this->t[wspolrzedna_x][wspolrzedna_y] << endl << endl;
}

void Tablica::wyswietl_wszystkie_elementy()
{
	cout << endl;
	for (int i = 0; i < this->liczba_wierszy; i++)
	{
		for (int j = 0; j < this->liczba_kolumn; j++)
		{
			cout << this->t[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
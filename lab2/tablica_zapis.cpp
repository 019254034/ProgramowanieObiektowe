#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

namespace
{
	void zapisz_do_pliku(string nazwa_pliku, int** tablica, int rozmiar_x, int rozmiar_y)
	{
		ofstream plik;
		plik.open(nazwa_pliku, ios::out);
		if (plik.is_open()) 
		{
			cout << "Otwarto plik " << nazwa_pliku << endl;
			for (int i = 0; i < rozmiar_x; i++)
			{
				for (int j = 0; j < rozmiar_y; j++)
				{
					plik << tablica[i][j];
					if (j != rozmiar_y - 1)
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

	int** wczytaj_z_pliku(string nazwa_pliku, int rozmiar_x, int rozmiar_y)
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
			return nowa_tablica;
		}
		else
		{
			cout << "Nie mozna otworzyc pliku " << nazwa_pliku << endl;
			return NULL;
		}
	}

}

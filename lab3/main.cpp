#include <iostream>
#include "menu.cpp"
#include "tablica_operacje.cpp"
#include "tablica_wysw.cpp"
#include "tablica_zapis.cpp"
#include "Tablica.h"
using namespace std;

int main()
{
	bool zakonczyc_program = false;
	int odpowiedz_uzytkownika;
	int druga_odp;
	string nazwa_pliku;
	Tablica tab = stworz_tablice(2, 2);

	while (!zakonczyc_program)
	{
		glowne_menu(tab);
		cin >> odpowiedz_uzytkownika;

		switch (odpowiedz_uzytkownika)
		{
		case 1:
			int nowy_rozmiar_x, nowy_rozmiar_y;
			cout << "Podaj nowy rozmiar x tabeli: " << endl;
			cin >> nowy_rozmiar_x;
			cout << "Podaj nowy rozmiar x tabeli: " << endl;
			cin >> nowy_rozmiar_y;
			if (nowy_rozmiar_x <= 0 || nowy_rozmiar_y <= 0)
			{
				cout << "Podano niepoprawny rozmiar!" << endl;
				break;
			}
			else if (nowy_rozmiar_x < tab.liczba_wierszy || nowy_rozmiar_y < tab.liczba_kolumn)
			{
				cout << "Zmieniasz rozmiar tablicy na mniejszy, stracisz dane. Czy chcesz kontynuowac? [y/n]" << endl;
				string odp;
				cin >> odp;
				if (odp == "n")
				{
					break;
				}
			}
			tab.t = zmien_rozmiar(tab, nowy_rozmiar_x, nowy_rozmiar_y);
			tab.liczba_wierszy = nowy_rozmiar_x;
			tab.liczba_kolumn = nowy_rozmiar_y;
			cout << endl;
			break;
		case 2:
			int x, y, nowa_wartosc;
			cout << "Podaj wspolrzedna x elementu do zaktualizowania wartosci: " << endl;
			cin >> x;
			cout << "Podaj wspolrzedna y elementu do zaktualizowania wartosci: " << endl;
			cin >> y;
			cout << "Podaj nowa wartosc elementu: " << endl;
			cin >> nowa_wartosc;
			if (x < 0 || y < 0 || x >= tab.liczba_wierszy || y >= tab.liczba_kolumn)
			{
				cout << "W tablicy nie ma elementu o wspolrzednych (" << x << "," << y << ")!" << endl;
				break;
			}
			tab.t = aktualizuj_element(tab.t, x, y, nowa_wartosc);
			cout << endl;
			break;
		case 3:
			int wspolrzedna_x, wspolrzedna_y;
			cout << "Podaj wspolrzedna x elementu do wyswietlenia: " << endl;
			cin >> wspolrzedna_x;
			cout << "Podaj wspolrzedna y elementu do wyswietlenia: " << endl;
			cin >> wspolrzedna_y;
			if (wspolrzedna_x < 0 || wspolrzedna_y < 0 || wspolrzedna_x >= tab.liczba_wierszy || wspolrzedna_y >= tab.liczba_kolumn)
			{
				cout << "W tablicy nie ma elementu o wspolrzednych (" << wspolrzedna_x << "," << wspolrzedna_y << ")!" << endl;
				break;
			}
			wyswietl_element(tab, wspolrzedna_x, wspolrzedna_y);
			break;
		case 4:
			wyswietl_wszystkie_elementy(tab);
			break;
		case 5:
			cout << "Podaj nazwe pliku do zapisu: " << endl;
			cin >> nazwa_pliku;
			zapisz_do_pliku(nazwa_pliku, tab);
			break;
		case 6:
			int wiersze, kolumny;
			cout << "Podaj nazwe pliku do odczytu: " << endl;
			cin >> nazwa_pliku;
			cout << "Podaj liczbe wierszy tablicy z pliku: " << endl;
			cin >> wiersze;
			cout << "Podaj liczbe kolumn tablicy z pliku: " << endl;
			cin >> kolumny;
			tab.t = wczytaj_z_pliku(nazwa_pliku, wiersze, kolumny);
			tab.liczba_wierszy = wiersze;
			tab.liczba_wierszy = kolumny;
			wyswietl_wszystkie_elementy(tab);
			break;
		case 7:
			cout << "Podaj nr kolumny do zsumowania wartosci: " << endl;
			cin >> druga_odp;
			cout << "Suma elementow z kolumny " << druga_odp << ": " << sumuj_elementy_kolumny(tab, druga_odp) << endl;
			break;
		case 8:
			cout << "Podaj nr wiersza do zsumowania wartosci: " << endl;
			cin >> druga_odp;
			cout << "Suma elementow z wiersza " << druga_odp << ": " << sumuj_elementy_wiersza(tab, druga_odp) << endl;
			break;
		case 9:
			cout << "Podaj nr kolumny do obliczenia sredniej wszystkich wartosci: " << endl;
			cin >> druga_odp;
			cout << "Srednia wartosc elementow z kolumny " << druga_odp << ": " << srednia_elementow_kolumny(tab, druga_odp) << endl;
			break;
		case 10:
			cout << "Podaj nr wiersza do obliczenia sredniej wszystkich wartosci: " << endl;
			cin >> druga_odp;
			cout << "Srednia wartosc elementow z wiersza " << druga_odp << ": " << srednia_elementow_wiersza(tab, druga_odp) << endl;
			break;
		case 11:
			cout << "Podaj nr kolumny do wskazania najmniejszej wartosci: " << endl;
			cin >> druga_odp;
			cout << "Najmnijesza wartosc z kolumny " << druga_odp << ": " << najmniejsza_z_wiersza(tab, druga_odp) << endl;
			break;
		case 12:
			cout << "Podaj nr wiersza do wskazania najmniejszej wartosci: " << endl;
			cin >> druga_odp;
			cout << "Najmniejsza wartosc z wiersza " << druga_odp << ": " << najwieksza_z_wiersza(tab, druga_odp) << endl;
			break;
		case 13:
			cout << "Podaj nr kolumny do wskazania najwiekszej wartosci: " << endl;
			cin >> druga_odp;
			cout << "Najwieksza wartosc z kolumny " << druga_odp << ": " << najmniejsza_z_kolumny(tab, druga_odp) << endl;
			break;
		case 14:
			cout << "Podaj nr wiersza do wskazania najwiekszej wartosci: " << endl;
			cin >> druga_odp;
			cout << "Najwieksza wartosc z wiersza " << druga_odp << ": " << najwieksza_z_kolumny(tab, druga_odp) << endl;
			break;
		case 0:
		default:
			zakonczyc_program = true;
			break;
		}
	}

	return 0;
}
#include <iostream>
#include "menu.cpp"
#include "tablica.cpp"
#include "tablica_wysw.cpp"
#include "tablica_zapis.cpp"
using namespace std;

int main()
{
	int** tablica;
	bool zakonczyc_program = false;
	int odpowiedz_uzytkownika;
	int rozmiar_x = 2;
	int rozmiar_y = 2;
	string nazwa_pliku;
	tablica = stworz_tablice(rozmiar_x, rozmiar_y);

	while (!zakonczyc_program)
	{
		glowne_menu(rozmiar_x, rozmiar_y);
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
			else if (nowy_rozmiar_x < rozmiar_x || nowy_rozmiar_y < rozmiar_y)
			{
				cout << "Zmieniasz rozmiar tablicy na mniejszy, stracisz dane. Czy chcesz kontynuowac? [y/n]" << endl;
				string odp;
				cin >> odp;
				if (odp == "n")
				{
					break;
				}
			}
			tablica = zmien_rozmiar(tablica, nowy_rozmiar_x, nowy_rozmiar_y, rozmiar_x, rozmiar_y);
			rozmiar_x = nowy_rozmiar_x;
			rozmiar_y = nowy_rozmiar_y;
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
			if (x < 0 || y < 0 || x >= rozmiar_x || y >= rozmiar_y)
			{
				cout << "W tablicy nie ma elementu o wspolrzednych (" << x << "," << y << ")!" << endl;
				break;
			}
			tablica = aktualizuj_element(tablica, x, y, nowa_wartosc);
			cout << endl;
			break;
		case 3:
			int wspolrzedna_x, wspolrzedna_y;
			cout << "Podaj wspolrzedna x elementu do wyswietlenia: " << endl;
			cin >> wspolrzedna_x;
			cout << "Podaj wspolrzedna y elementu do wyswietlenia: " << endl;
			cin >> wspolrzedna_y;
			if (wspolrzedna_x < 0 || wspolrzedna_y < 0 || wspolrzedna_x >= rozmiar_x || wspolrzedna_y >= rozmiar_y)
			{
				cout << "W tablicy nie ma elementu o wspolrzednych (" << wspolrzedna_x << "," << wspolrzedna_y << ")!" << endl;
				break;
			}
			wyswietl_element(tablica, wspolrzedna_x, wspolrzedna_y);
			break;
		case 4:
			wyswietl_wszystkie_elementy(tablica, rozmiar_x, rozmiar_y);
			break;
		case 5:
			cout << "Podaj nazwe pliku do zapisu: " << endl;
			cin >> nazwa_pliku;
			zapisz_do_pliku(nazwa_pliku, tablica, rozmiar_x, rozmiar_y);
			break;
		case 6:
			int liczba_wierszy, liczba_kolumn;
			cout << "Podaj nazwe pliku do odczytu: " << endl;
			cin >> nazwa_pliku;
			cout << "Podaj liczbe wierszy tablicy z pliku: " << endl;
			cin >> liczba_wierszy;
			cout << "Podaj liczbe kolumn tablicy z pliku: " << endl;
			cin >> liczba_kolumn;
			tablica = wczytaj_z_pliku(nazwa_pliku, liczba_wierszy, liczba_kolumn);
			rozmiar_x = liczba_wierszy;
			rozmiar_y = liczba_kolumn;
			wyswietl_wszystkie_elementy(tablica, rozmiar_x, rozmiar_y);
			break;
		case 0:
		default:
			zakonczyc_program = true;
			break;
		}
	}

	return 0;
}
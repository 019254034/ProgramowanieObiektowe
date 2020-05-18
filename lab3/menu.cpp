#include <iostream>
using namespace std;

namespace 
{
	void glowne_menu(int wielkosc_x, int wielkosc_y) 
	{
		cout << "Obecna wielkosc tablicy to " << wielkosc_x << "x" << wielkosc_y << endl;
		cout << "Wprowadz liczbe od 0 do 4, aby wybrac operacje, ktora chcesz wykonac:" << endl << endl;
		cout << "1. Zmienic rozmiar tablicy" << endl;
		cout << "2. Zaktualizowac wybrany element tablicy" << endl;
		cout << "3. Wyswietlic konkretny element tablicy" << endl;
		cout << "4. Wyswietl wszystkie elementy tablicy" << endl;
		cout << "5. Zapisz tablice do pliku" << endl;
		cout << "6. Wczytaj tablice z pliku" << endl;
		cout << "0. Zakoncz program" << endl;
	}
}
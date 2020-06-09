#include <iostream>
#include "Tablica.h"
using namespace std;

namespace
{
	void glowne_menu(Tablica tablica)
	{
		cout << "Obecna wielkosc tablicy to " << tablica.get_liczba_wierszy() << "x" << tablica.get_liczba_kolumn() << endl;
		cout << "Wprowadz liczbe od 0 do 4, aby wybrac operacje, ktora chcesz wykonac:" << endl << endl;
		cout << "1. Zmienic rozmiar tablicy" << endl;
		cout << "2. Zaktualizowac wybrany element tablicy" << endl;
		cout << "3. Wyswietlic konkretny element tablicy" << endl;
		cout << "4. Wyswietl wszystkie elementy tablicy - wskazniki" << endl;
		cout << "5. Zapisz tablice do pliku" << endl;
		cout << "6. Wczytaj tablice z pliku" << endl;
		cout << "7. Zsumuj elemety z kolumny" << endl;
		cout << "8. Zsumuj elemety z wiersza" << endl;
		cout << "9. Oblicz srednia elemetow z kolumny" << endl;
		cout << "10. Oblicz srednia elemetow z wiersza" << endl;
		cout << "11. Znajdz najmniejsza wartosc w kolumnie" << endl;
		cout << "12. Znajdz najwieksza wartosc w kolumnie" << endl;
		cout << "13. Znajdz najmniejsza wartosc w wierszu" << endl;
		cout << "14. Znajdz najwieksza wartosc w wierszu" << endl;
		cout << "15. Wyswietl dany element liczbowy tablicy" << endl;
		cout << "16. Wyswietl dany element tekstowy tablicy" << endl;
		cout << "0. Zakoncz program" << endl;
	}
}
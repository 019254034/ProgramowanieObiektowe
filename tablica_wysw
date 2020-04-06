#include <iostream>
#include <ncurses.h>
#include "tablica.cpp"
#include "tablica_wysw.cpp"
#include "menu.cpp"
using namespace std;



int main() {
	int a = 5;
	int m;
	int size1, size2, newsize1, newsize2;

	menu_pocz();
	cout << "Podaj ilosc wierszy: ";
	cin >> size1;
	cout << "Podaj ilosc kolumn: ";
	cin >> size2;




	//tablica_powstanie(&size1, &size2);

	float** table;

	 tablica_powstanie(&size1, &size2);

	 table = tab;
	 tabl = table;

	 for (int i = 0; i < size1; i++) {
		 for (int j = 0; j < size2; j++) {

			 table[i][j] = 0;

		 }


	 }

	 tab = table;
	 tabl = table;


	while (a!=1)
	{
		table = tab;
		tabl = table;

		menu();
		cin >> m;
		
		switch (m)
		{
		case 1:


			tab = table;
		
			removing_table(&size2);

			cout << "Podaj ilosc wierszy: ";
			cin >> size1;
			cout << "Podaj ilosc kolumn: ";
			cin >> size2;

			tablica_powstanie(&size1, &size2);

			break;
		case 2:

			cout << "Wprowadz ilosc wierszy: ";
			cin >> newsize1;
			cout << "Wprowadz ilosc kolumn: ";
			cin >> newsize2;

			tablica_rozmiar(newsize1, newsize2, &size1, &size2);

			size1 = newsize1;
			size2 = newsize2;

			break;
		case 3:
			
			aktualizowanie(&size1, &size2);

			break;
		case 4:

			wyswietlanie(&size1, &size2);

			break;
		case 5:
			a = 1;
			break;
		default:
			a = 1;
			break;
		}

		

	}

	for (int i = 0; i < size2; i++)
		delete[] table[i];

	delete[] table;
	







	return 0;
}

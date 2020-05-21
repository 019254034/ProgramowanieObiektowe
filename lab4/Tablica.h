#pragma once
#include <string>
class Tablica
{
public:
	Tablica(int liczba_wierszy, int liczba_kolumn);

	int** get_t();
	int get_liczba_wierszy();
	int get_liczba_kolumn();

	int** stworz_tablice(int rozmiar_x, int rozmiar_y);
	void zmien_rozmiar(int nowy_rozmiar_x, int nowy_rozmiar_y);
	void aktualizuj_element(int wspolrzedna_x, int wspolrzedna_y, int nowa_wartosc);
	int sumuj_elementy_wiersza(int nr_wiersza);
	int sumuj_elementy_kolumny(int nr_kolumny);
	double srednia_elementow_wiersza(int nr_wiersza);
	double srednia_elementow_kolumny(int nr_kolumny);
	int najmniejsza_z_wiersza(int nr_wiersza);
	int najwieksza_z_wiersza(int nr_wiersza);
	int najmniejsza_z_kolumny(int nr_kolumny);
	int najwieksza_z_kolumny(int nr_kolumny);
	void zapisz_do_pliku(std::string nazwa_pliku); 
	void wczytaj_z_pliku(std::string nazwa_pliku, int rozmiar_x, int rozmiar_y);
	void wyswietl_element(int wspolrzedna_x, int wspolrzedna_y);
	void wyswietl_wszystkie_elementy();

private:
	int** t;
	int liczba_wierszy, liczba_kolumn;
};
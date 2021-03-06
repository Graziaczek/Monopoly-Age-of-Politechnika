#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;
int RNG(int a, int b);

class Pole
{
public:
	int ID = 0;
	int x = 0;
	int y = 0;
	Pole(int id, int a, int b);
};
class Kierunek				//ale nie zwrot
{
public:
	int ID_pola;
	string Nazwa = "";
	int Wydzial = 0;			//numer wydzialu do ktorego nalezy kierunek
	int LKW;
	int Koszt_zakupu = 0;
	int Wartosc_sprzedazy = 0;
	int Koszt_Budowy = 0;
	int Haracz = 0;
	int LiczbaBudynkow = 0; //zbudowanych juz oczywiscie
	bool Hotel = 0;
	int GraczID = 0;
	Sprite kolor;
	Sprite d1, d2, d3, d4;

	Kierunek(int ID, string nazwa1, int wydzial1, int lkw, int koszt_zakupu1, int koszt_budowy1, int haracz1);
};
class Gracz {
public:
	string nick ="";			//Nick Fury hehe
	bool n = 0;
	bool p = 0;
	double s = 1.0;
	int wiÍzienie = 0;
	int ID = 0;
	int ilosc_domkow = 0;
	int ilosc_hoteli = 0;
	long Hajs = 1500;
	int Akty_Wlasnosci[9]{}; //10 wydzialow po 2-3 kierunki
	int akademiki = 0;
	int alo = 0;
	Sprite g_s;
	Sprite kart_s;
	Sprite opcje_s;
	Color c;
	int Polozenie = 0;
	bool wyjscie = 0;
	Gracz(int id, Color k);
};
class Akademik
{
public:
	int ID;					//zamiast nazwy wystarczy ID w sumie
	int IDGracz = 0;
	int Haracz = 50;
	int KosztZakupu = 200;
	Sprite kolor;

	Akademik(int id);
};
class ALO
{
public:
	int ID;					//zamiast nazwy wystarczy ID w sumie
	int IDGracz = 0;
	int Haracz = 6;
	int KosztZakupu = 150;
	Sprite kolor;

	ALO(int id);
};
void zakup_kierunku(Gracz* X, Kierunek* K);
void zaplata(Gracz* Plac, Gracz* Otrz, Kierunek* K);
void zakup_akademika(Gracz* X, Akademik* A);
void zakup_alo(Gracz* X, ALO* A);
void zaplata_akademiki(Gracz* Plac, Gracz* Otrz, Akademik* A);
void zaplata_ALO(Gracz* Plac, Gracz* Otrz, ALO* A);

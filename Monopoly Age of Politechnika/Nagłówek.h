#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <random>

using namespace std;
int RNG(int a, int b);
class Karta
{
public:
	string nazwa;
	int id;					//moze sie przyda
	string cytat;			//jak nam sie bedzie chcialo/nudzilo
};
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
	string nazwa = "";
	int Wydzial = 0;			//numer wydzialu do ktorego nalezy kierunek
	int koszt_zakupu = 0;
	int warosc_sprzedazy = 0;
	int naleznosc = 0;
	int Koszt_Budowy = 0;
	int Haracz = 0;
	int LiczbaBudynkow = 0; //zbudowanych juz oczywiscie
	bool Hotel = 0;
	int GraczID = 0;
	Kierunek(string nazwa1, int wydzial1, int koszt_zakupu1, int wartosc_sprzedazy1, int naleznosc1, int koszt_budowy1, int haracz1);
};
class Gracz {
public:
	string nick ="";			//Nick Fury hehe
	int ID = 0;
	int ilosc_domkow = 0;
	int ilosc_hoteli = 0;
	unsigned long Hajs = 1500;
	int Akty_Wlasnosci[10][3]{}; //10 wydzialow po 2-3 kierunki
	int akademiki[4]{};
	int alo[2]{};
	int Polozenie = 0;
};
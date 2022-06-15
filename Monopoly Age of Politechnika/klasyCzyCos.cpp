#include <string>
#include <iostream>
#include <random>

using namespace std;

int RNG(int a, int b)
{
	random_device r;
	mt19937 generator(r());
	uniform_int_distribution<int> dist(a, b);
	return dist(generator);
}

class Karta
{
	string Nazwa;
	int ID;					//moze sie przyda
	string Cytat;			//jak nam sie bedzie chcialo/nudzilo
};

class Kierunek				//ale nie zwrot
{
	string Nazwa;
	int Wydzial;			//numer wydzialu do ktorego nalezy kierunek
	int Koszt_Budowy;
	int Haracz;
	int LiczbaBudynkow = 0; //zbudowanych juz oczywiscie
};

class Gracz
{
	string Nick;			//Nick Fury hehe
	unsigned long Hajs;
	Kierunek Akty_Wlasnosci[10][3]; //10 wydzialow po 2-3 kierunki
	int Polozenie;
};
#include "Nag³ówek.h"

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

//Gracz()
//{
//	
//};
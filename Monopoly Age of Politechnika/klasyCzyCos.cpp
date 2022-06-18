#include "Nag³ówek.h"

using namespace std;

Kierunek::Kierunek(string nazwa1, int wydzial1, int koszt_zakupu1, int wartosc_sprzedazy1, int naleznosc1, int koszt_budowy1, int haracz1) {
	nazwa = nazwa1;
	Wydzial = wydzial1;
	koszt_zakupu = koszt_zakupu1;
	warosc_sprzedazy = wartosc_sprzedazy1;
	naleznosc = naleznosc1;
	Koszt_Budowy = koszt_budowy1;
	Haracz = haracz1;
}
Pole::Pole(int id, int a, int b) {
	ID = id;
	x = a;
	y = b;
}
int RNG(int a, int b)
{
	random_device r;
	mt19937 generator(r());
	uniform_int_distribution<int> dist(a, b);
	return dist(generator);
}
void zakup_kierunku(Gracz X, Kierunek K)
{
	X.Hajs -= K.koszt_zakupu;
	//X.Akty_Wlasnosci[K.Wydzial] += 1;
	K.naleznosc = X.ID;
}


void sprzedawanie(Gracz X, Kierunek K)
{
	K.naleznosc = 0;
	K.Haracz = 0;
	K.LiczbaBudynkow = 0;
	X.Hajs += K.warosc_sprzedazy;
	//X.Akty_Wlasnosci[K.Wydzial] -= 1;
	K.warosc_sprzedazy = 0;
}

//void zaplata(Gracz Plac, Gracz Otrz, Kierunek K)
//{
//	if (Plac.Hajs >= K.Haracz)
//	{
//		Plac.Hajs -= K.Haracz;
//		Otrz.Hajs += K.Haracz;
//	}
//	else
//	{
//		Kierunek Wybran;
//		sprzedawanie(Plac, Wybran);
//		zaplata(Plac, Otrz, K);
//	}
//}
#include "Nag³ówek.h"

using namespace std;

Kierunek::Kierunek(int ID, string nazwa1, int wydzial1, int lkw, int koszt_zakupu1, int koszt_budowy1, int haracz1) {
	ID_pola = ID;
	Nazwa = nazwa1;
	Wydzial = wydzial1;
	LKW = lkw;
	Koszt_zakupu = koszt_zakupu1;
	Koszt_Budowy = koszt_budowy1;
	Haracz = haracz1;
}
Pole::Pole(int id, int a, int b) {
	ID = id;
	x = a;
	y = b;
}
Akademik::Akademik(int id) {
	ID = id;
}
ALO::ALO(int id) {
	ID = id;
}
Gracz::Gracz(int id, Color k) {
	ID = id;
	c = k;
}
void zakup_budynek(Gracz* X, Gracz* Y, Kierunek* K, int ile)
{
	if (X->Akty_Wlasnosci[4] == 2)
	{
		X->Hajs -= (K->Koszt_Budowy * ile * 0.9);
		K->Wartosc_sprzedazy += (K->Koszt_Budowy * ile * 0.45);
	}
	else
	{
		X->Hajs -= (K->Koszt_Budowy * ile);
		K->Wartosc_sprzedazy += (K->Koszt_Budowy * ile * 0.5);
	}
	if (K->LiczbaBudynkow + ile == 5)
	{
		X->ilosc_domkow -= K->LiczbaBudynkow;
		K->LiczbaBudynkow = 0;
		K->Hotel = true;
		X->ilosc_hoteli += 1;
		K->d1.setColor(Color::Yellow);
		K->d2.setColor(Color::Yellow);
		K->d3.setColor(Color::Yellow);
		K->d4.setColor(Color::Yellow);
	}
	else
	{
		K->LiczbaBudynkow += ile;
		X->ilosc_domkow += ile;
		if (K->LiczbaBudynkow == 1)
			K->d1.setColor(Color::Blue);
		if (K->LiczbaBudynkow == 2)
			K->d2.setColor(Color::Blue);
		if (K->LiczbaBudynkow == 3)
			K->d3.setColor(Color::Blue);
		if (K->LiczbaBudynkow == 4)
			K->d4.setColor(Color::Blue);
	}
	if(Y->Akty_Wlasnosci[1] == 3)
		Y->Hajs += 15;
}
int RNG(int a, int b)
{
	random_device r;
	mt19937 generator(r());
	uniform_int_distribution<int> distrib(a, b);
	return distrib(generator);
}
void zakup_kierunku(Gracz* X, Kierunek* K)
{
	float mnoznik = 1.0;
	if (X->Akty_Wlasnosci[6] == 2)
	{
		mnoznik = 0.8;
	}
	X->Hajs -= K->Koszt_zakupu * mnoznik;
	X->Akty_Wlasnosci[K->Wydzial] += 1;
	K->GraczID = X->ID;
	K->kolor.setColor(X->c);
	K->Wartosc_sprzedazy = K->Koszt_zakupu * mnoznik * 0.5;
}


void sprzedawanie(Gracz* X, Kierunek* K)
{
	K->GraczID = 0;
	K->Haracz = 0;
	K->LiczbaBudynkow = 0;
	X->Hajs += K->Wartosc_sprzedazy;
	X->Akty_Wlasnosci[K->Wydzial] -= 1;
	K->Wartosc_sprzedazy = 0;
}

void zaplata(Gracz* Plac, Gracz* Otrz, Kierunek* K)
{
	int pomoc = K->Haracz * (K->LiczbaBudynkow * 2 + K->Hotel * 6);
	float mnoznik1, mnoznik2 = 1.0;
	if (Plac->Akty_Wlasnosci[3] == 3)
	{
		mnoznik1 = 1 - ((K->LiczbaBudynkow * 0.05) + (K->Hotel * 0.3));
	}
	if (Otrz->Akty_Wlasnosci[8] == 2)
	{
		mnoznik2 = 1.05;
	}
	if (Plac->Hajs >= (K->Haracz * mnoznik1 * mnoznik2) + pomoc)
	{
		Plac->Hajs -= ((K->Haracz * mnoznik1 * mnoznik2) + pomoc);
		Otrz->Hajs += ((K->Haracz * mnoznik1 * mnoznik2) + pomoc);
	}
}
void zakup_akademika(Gracz* X, Akademik* A) {
	X->Hajs -= A->KosztZakupu;
	A->IDGracz = X->ID;
	X->akademiki += 1;
	A->kolor.setColor(X->c);
}
void zakup_alo(Gracz* X, ALO* A) {
	X->Hajs -= A->KosztZakupu;
	A->IDGracz = X->ID;
	X->alo += 1;
	A->kolor.setColor(X->c);

}
void zaplata_akademiki(Gracz* Plac, Gracz* Otrz, Akademik* A)
{
	float mnoznik = 1.0;
	if (Otrz->Akty_Wlasnosci[8] == 2)
	{
		mnoznik = 1.05;
	}
	Plac->Hajs -= A->Haracz * Otrz->akademiki * mnoznik;
	Otrz->Hajs += A->Haracz * Otrz->akademiki * mnoznik;
}
void zaplata_ALO(Gracz* Plac, Gracz* Otrz, ALO* A)
{
	float mnoznik = 1.0;
	if (Otrz->Akty_Wlasnosci[8] == 2)
	{
		mnoznik = 1.05;
	}
	Plac->Hajs -= A->Haracz * Otrz->alo * mnoznik;
	Otrz->Hajs += A->Haracz * Otrz->alo * mnoznik;
}
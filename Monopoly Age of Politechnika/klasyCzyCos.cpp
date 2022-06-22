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
void zakup_budynek(Gracz* X, Kierunek* K, int ile)
{
	if (X->Akty_Wlasnosci[4] == 2)
	{
		X->Hajs -= (K->Koszt_Budowy * ile * 0,9);
		K->Wartosc_sprzedazy += (K->Koszt_Budowy * ile * 0,45);
	}
	else
	{
		X->Hajs -= (K->Koszt_Budowy * ile);
		K->Wartosc_sprzedazy += (K->Koszt_Budowy * ile * 0, 5);
	}
	if (K->LiczbaBudynkow + ile == 5)
	{
		X->ilosc_domkow -= K->LiczbaBudynkow;
		K->LiczbaBudynkow = 0;
		K->Hotel = true;
		X->ilosc_hoteli += 1;
	}
	else
	{
		K->LiczbaBudynkow += ile;
		X->ilosc_domkow += ile;
	}
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
	X->Hajs -= K->Koszt_zakupu;
	X->Akty_Wlasnosci[K->Wydzial] += 1;
	K->GraczID = X->ID;
	K->kolor.setColor(X->c);
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
		Plac->Hajs -= K->Haracz;
		Otrz->Hajs += K->Haracz;
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
	Plac->Hajs -= A->Haracz * Otrz->akademiki;
	Otrz->Hajs += A->Haracz * Otrz->akademiki;
}
void zaplata_ALO(Gracz* Plac, Gracz* Otrz, ALO* A)
{
	Plac->Hajs -= A->Haracz * Otrz->alo;
	Otrz->Hajs += A->Haracz * Otrz->alo;
}
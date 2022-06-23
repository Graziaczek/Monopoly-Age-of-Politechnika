#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <conio.h>
#include "Nag³ówek.h"

using namespace sf;
using namespace std;
Gracz gracz1(1, Color::Green);
Gracz gracz2(2, Color::Red);
Pole start(1, 850, 750), aei_1(2, 730, 750), dr_1(3, 670, 750), aei_2(4, 610, 750), impreza(5, 550, 750), piast(6, 490, 750), e_1(7, 430, 750), dr_2(8, 370, 750), e_2(9, 310, 750), e_3(10, 250, 750), bos(11, 150, 780), mt_1(12, 150, 620), alo_r(13, 150, 560), mt_2(14, 150, 500), mt_3(15, 150, 440), karlik(16, 150, 380), budo_1(17, 150, 320), dr_3(18, 150, 260), budo_2(19, 150, 200), budo_3(20, 150, 140), strefa(21, 150, 40), arch_1(22, 250, 40), dr_4(23, 310, 40), arch_2(24, 370, 40), trans_1(25, 430, 40), solaris(26, 490, 40), trans_2(27, 550, 40), gorn_1(28, 610, 40), alo_g(29, 670, 40), gorn_2(30, 730, 40), wezwanie(31, 850, 40), chem_1(32, 850, 150), chem_2(33, 850, 210), dr_5(34, 850, 270), chem_3(35, 850, 330), elektron(36, 850, 390), dr_6(37, 850, 450), ms_1(38, 850, 510), afterek(39, 850, 570), ms_2(40, 850, 630);
Kierunek air_1(2, "AiR", 1, 2, 60, 50, 2), inf_1(4, "Informatyka", 1, 2, 60, 50, 4), mech_2(7, "Mech", 2, 3, 100, 50, 6), energ_2(9, "Energetyka", 2, 3, 100, 50, 6), inf_2(10, "Informatyka", 2, 3, 120, 50, 8), mech_3(12,"Mechanika i budowa maszyn", 3, 3, 140, 100, 10), inz_3(14,"In¿. Mat", 3, 3, 140, 100, 10), zarz_3(15, "Zarz¹dz. i In¿. Prod.", 3, 3, 160, 100, 12), budo_4(17, "Budownictwo", 4, 3, 180, 100, 14), budop_4(19, "Budo. Podziemne", 4, 3, 180, 100, 14), zarz_4(20, "Zarz¹dz. i In¿. Prod.", 4, 3, 200, 100, 16), archi_5(22, "Architektura", 5, 2, 220, 150, 18), archiw_5(24, "Archi. Wnêtrz", 5, 2, 220, 150, 20), logi_6(25, "Logistyka Transportu", 6, 2, 240, 150, 20), trans_6(27, "Trans. Przemys³owy", 6, 2, 240, 150, 22), gig_7(28, "Górnictwo i Geologia", 7, 2, 260, 150, 22), inzb_7(30,"In¿. Bezp.", 7, 2, 280, 150, 24), chem_8(32, "Chemia", 8, 3, 300, 200, 26), biotech_8(33, "Biotechnologia", 8, 3, 300, 200, 26), tech_8(35, "Tech. Chem.", 8, 3, 320, 200, 28), mat_9(38, "Matematyka", 9, 2, 350, 200, 35), inf_9(40, "Informatyka", 9, 2, 400, 200, 50);
Akademik pi(6), ka(16), so(26), el(36);
ALO ry(13), gl(29);
Texture p1, p2, kup;
Sprite p1_s, p2_s;
int liczniktur = 1;
int bot = 3;
void nazwy();
void bankrut(Gracz* g, Gracz* p);
Gracz ruch(Gracz g, Gracz p, RenderWindow & monopoly);
void loskarty(Gracz* g, Gracz* p);
void zakup_budynek(Gracz* X, Gracz* Y, Kierunek* K, int ile);
void akcja_kierunek(Gracz* X,Gracz* Y, Kierunek* K);
void akcja_akademik(Gracz* X, Akademik* K);
void akcja_alo(Gracz* X, ALO* K);
void akcja(Gracz* g, Gracz* p);
int przerzut(Gracz* g, int n);
void ruchbot(Gracz* X, Gracz* Y, int IQ);
void gra() {
	RenderWindow monopoly_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	monopoly_w.setFramerateLimit(60);

	Font tura, kasa;
	tura.loadFromFile("Cooper Black Regular.ttf");
	kasa.loadFromFile("Cooper Black Regular.ttf");

	Text tura_t, kasa_t;
	tura_t.setFont(tura);
	tura_t.setFillColor(Color::Blue);
	tura_t.setPosition(Vector2f(100, 850));
	kasa_t.setFont(kasa);
	kasa_t.setFillColor(Color::Blue);
	kasa_t.setPosition(Vector2f(800, 850));

	Texture plansza, bos, strefastudenta, start, wezwanie, ms_inf, ms_mat, aei_air, aei_inf, e_mech, e_energetyka, e_inf, mt_mechibud, mt_inzmat, mt_zarziinzprod, budo_budownictwo, budo_budopodz, budo_zarziinzprod, arch_architektura, arch_archiwnetrz, trans_logistyka, trans_transprzemyslowy, gorn_gornigeo, gorn_inzbezp, chem_chemia, chem_biotech, chem_techchem, piast, karlik, solaris, elektron, impreza, afterek, alo_rybnik, alo_gliwice, dzien_rektorski, koniec_tury, g1, g2, puste, color, domek;
	plansza.loadFromFile("plansza.jpg");
	color.loadFromFile("kolor.jpg");
	domek.loadFromFile("katedra.jpg");

	bos.loadFromFile("bos.jpg");
	strefastudenta.loadFromFile("strefa_studenta.jpg");
	start.loadFromFile("start.jpg");
	wezwanie.loadFromFile("wezwanie.jpg");
	
	ms_inf.loadFromFile("ms_inf.jpg");
	ms_mat.loadFromFile("ms_mat.jpg");
	aei_air.loadFromFile("aei_air.jpg");
	aei_inf.loadFromFile("aei_inf.jpg");
	e_mech.loadFromFile("e_mech.jpg");
	e_energetyka.loadFromFile("e_energetyka.jpg");
	e_inf.loadFromFile("e_inf.jpg");
	mt_mechibud.loadFromFile("mt_mechibud.jpg");
	mt_inzmat.loadFromFile("mt_in¿mat.jpg");
	mt_zarziinzprod.loadFromFile("mt_zarziinzprod.jpg");
	budo_budownictwo.loadFromFile("budo_budownictwo.jpg");
	budo_budopodz.loadFromFile("budo_budopodziemne.jpg");
	budo_zarziinzprod.loadFromFile("budo_zarziinzprod.jpg");
	arch_architektura.loadFromFile("arch_architektura.jpg");
	arch_archiwnetrz.loadFromFile("arch_archiwnetrz.jpg");
	trans_logistyka.loadFromFile("trans_logistyka.jpg");
	trans_transprzemyslowy.loadFromFile("trans_transprzemyslowy.jpg");
	gorn_gornigeo.loadFromFile("gorn_gornigeo.jpg");
	gorn_inzbezp.loadFromFile("gorn_inzbezp.jpg");
	chem_chemia.loadFromFile("chem_chemia.jpg");
	chem_biotech.loadFromFile("chem_biotech.jpg");
	chem_techchem.loadFromFile("chem_techchem.jpg");
	
	piast.loadFromFile("piast.jpg");
	karlik.loadFromFile("karlik.jpg");
	solaris.loadFromFile("solaris.jpg");
	elektron.loadFromFile("elektron.jpg");
	
	impreza.loadFromFile("impreza.jpg");
	afterek.loadFromFile("afterek.jpg");
	
	alo_rybnik.loadFromFile("alo_rybnik.jpg");
	alo_gliwice.loadFromFile("alo_gliwice.jpg");

	dzien_rektorski.loadFromFile("dzien_rektorski.jpg");

	koniec_tury.loadFromFile("koniec_tury.jpg");
	g1.loadFromFile("g1.jpg");
	g2.loadFromFile("g2.jpg");
	puste.loadFromFile("puste.jpg");

	Sprite plansza_s, bos_s, strefastudenta_s, start_s, wezwanie_s, ms_inf_s, ms_mat_s, aei_air_s, aei_inf_s, e_mech_s, e_energetyka_s, e_inf_s, mt_mechibud_s, mt_inzmat_s, mt_zarziinzprod_s, budo_budownictwo_s, budo_budopodz_s, budo_zarziinzprod_s, arch_architektura_s, arch_archiwnetrz_s, trans_logistyka_s, trans_transprzemyslowy_s, gorn_gornigeo_s, gorn_inzbezp_s, chem_chemia_s, chem_biotech_s, chem_techchem_s, piast_s, karlik_s, solaris_s, elektron_s, impreza_s, afterek_s, alo_rybnik_s, alo_gliwice_s, dzien_rektorski_1_s, dzien_rektorski_2_s, dzien_rektorski_3_s, dzien_rektorski_4_s, dzien_rektorski_5_s, dzien_rektorski_6_s, koniec_tury_s, karta;
	plansza_s.setTexture(plansza);

	bos_s.setTexture(bos);
	bos_s.setPosition(Vector2f(100, 671));
	strefastudenta_s.setTexture(strefastudenta);
	strefastudenta_s.setPosition(Vector2f(100, 0));
	start_s.setTexture(start);
	start_s.setPosition(Vector2f(771, 671));
	wezwanie_s.setTexture(wezwanie);
	wezwanie_s.setPosition(Vector2f(771, 0));

	ms_inf_s.setTexture(ms_inf);
	ms_inf_s.setPosition(Vector2f(771, 670));
	ms_inf_s.setRotation(-90);
	inf_9.kolor.setTexture(color);
	inf_9.kolor.setPosition(Vector2f(900, 670));
	inf_9.kolor.setRotation(-90);
	inf_9.d1.setTexture(domek);
	inf_9.d2.setTexture(domek);
	inf_9.d3.setTexture(domek);
	inf_9.d4.setTexture(domek);
	inf_9.d1.setPosition(Vector2f(940, 650));
	inf_9.d2.setPosition(Vector2f(940, 630));
	inf_9.d3.setPosition(Vector2f(920, 650));
	inf_9.d4.setPosition(Vector2f(920, 630));
	inf_9.d1.setRotation(-90);
	inf_9.d2.setRotation(-90);
	inf_9.d3.setRotation(-90);
	inf_9.d4.setRotation(-90);
	ms_mat_s.setTexture(ms_mat);
	ms_mat_s.setPosition(Vector2f(771, 550));
	ms_mat_s.setRotation(-90);
	mat_9.kolor.setTexture(color);
	mat_9.kolor.setPosition(Vector2f(900, 550));
	mat_9.kolor.setRotation(-90);
	mat_9.d1.setTexture(domek);
	mat_9.d2.setTexture(domek);
	mat_9.d3.setTexture(domek);
	mat_9.d4.setTexture(domek);
	mat_9.d1.setPosition(Vector2f(940, 530));
	mat_9.d2.setPosition(Vector2f(940, 510));
	mat_9.d3.setPosition(Vector2f(920, 530));
	mat_9.d4.setPosition(Vector2f(920, 510));
	mat_9.d1.setRotation(-90);
	mat_9.d2.setRotation(-90);
	mat_9.d3.setRotation(-90);
	mat_9.d4.setRotation(-90);
	aei_air_s.setTexture(aei_air);
	aei_air_s.setPosition(Vector2f(711, 671));
	aei_air_s.setRotation(0);
	air_1.kolor.setTexture(color);
	air_1.kolor.setPosition(Vector2f(711, 800));
	air_1.kolor.setRotation(0);
	air_1.d1.setTexture(domek);
	air_1.d2.setTexture(domek);
	air_1.d3.setTexture(domek);
	air_1.d4.setTexture(domek);
	air_1.d1.setPosition(Vector2f(750, 840));
	air_1.d2.setPosition(Vector2f(730, 840));
	air_1.d3.setPosition(Vector2f(750, 820));
	air_1.d4.setPosition(Vector2f(730, 820));
	air_1.d1.setRotation(0);
	air_1.d2.setRotation(0);
	air_1.d3.setRotation(0);
	air_1.d4.setRotation(0);
	aei_inf_s.setTexture(aei_inf);
	aei_inf_s.setPosition(Vector2f(591, 671));
	aei_inf_s.setRotation(0);
	inf_1.kolor.setTexture(color);
	inf_1.kolor.setPosition(Vector2f(591, 800));
	inf_1.kolor.setRotation(0);
	inf_1.d1.setTexture(domek);
	inf_1.d2.setTexture(domek);
	inf_1.d3.setTexture(domek);
	inf_1.d4.setTexture(domek);
	inf_1.d1.setPosition(Vector2f(630, 840));
	inf_1.d2.setPosition(Vector2f(610, 840));
	inf_1.d3.setPosition(Vector2f(630, 820));
	inf_1.d4.setPosition(Vector2f(610, 820));
	inf_1.d1.setRotation(0);
	inf_1.d2.setRotation(0);
	inf_1.d3.setRotation(0);
	inf_1.d4.setRotation(0);
	e_mech_s.setTexture(e_mech);
	e_mech_s.setPosition(Vector2f(411, 671));
	e_mech_s.setRotation(0);
	mech_2.kolor.setTexture(color);
	mech_2.kolor.setPosition(Vector2f(411, 800));
	mech_2.kolor.setRotation(0);
	mech_2.d1.setTexture(domek);
	mech_2.d2.setTexture(domek);
	mech_2.d3.setTexture(domek);
	mech_2.d4.setTexture(domek);
	mech_2.d1.setPosition(Vector2f(450, 840));
	mech_2.d2.setPosition(Vector2f(430, 840));
	mech_2.d3.setPosition(Vector2f(450, 820));
	mech_2.d4.setPosition(Vector2f(430, 820));
	mech_2.d1.setRotation(0);
	mech_2.d2.setRotation(0);
	mech_2.d3.setRotation(0);
	mech_2.d4.setRotation(0);
	e_energetyka_s.setTexture(e_energetyka);
	e_energetyka_s.setPosition(Vector2f(291, 671));
	e_energetyka_s.setRotation(0);
	energ_2.kolor.setTexture(color);
	energ_2.kolor.setPosition(Vector2f(291, 800));
	energ_2.kolor.setRotation(0);
	energ_2.d1.setTexture(domek);
	energ_2.d2.setTexture(domek);
	energ_2.d3.setTexture(domek);
	energ_2.d4.setTexture(domek);
	energ_2.d1.setPosition(Vector2f(330, 840));
	energ_2.d2.setPosition(Vector2f(310, 840));
	energ_2.d3.setPosition(Vector2f(330, 820));
	energ_2.d4.setPosition(Vector2f(310, 820));
	energ_2.d1.setRotation(0);
	energ_2.d2.setRotation(0);
	energ_2.d3.setRotation(0);
	energ_2.d4.setRotation(0);
	e_inf_s.setTexture(e_inf);
	e_inf_s.setPosition(Vector2f(230, 671));
	e_inf_s.setRotation(0);
	inf_2.kolor.setTexture(color);
	inf_2.kolor.setPosition(Vector2f(230, 800));
	inf_2.kolor.setRotation(0);
	inf_2.d1.setTexture(domek);
	inf_2.d2.setTexture(domek);
	inf_2.d3.setTexture(domek);
	inf_2.d4.setTexture(domek);
	inf_2.d1.setPosition(Vector2f(270, 840));
	inf_2.d2.setPosition(Vector2f(250, 840));
	inf_2.d3.setPosition(Vector2f(270, 820));
	inf_2.d4.setPosition(Vector2f(250, 820));
	inf_2.d1.setRotation(0);
	inf_2.d2.setRotation(0);
	inf_2.d3.setRotation(0);
	inf_2.d4.setRotation(0);
	mt_mechibud_s.setTexture(mt_mechibud);
	mt_mechibud_s.setPosition(Vector2f(229, 611));
	mt_mechibud_s.setRotation(90);
	mech_3.kolor.setTexture(color);
	mech_3.kolor.setPosition(Vector2f(100, 611));
	mech_3.kolor.setRotation(90);
	mech_3.d1.setTexture(domek);
	mech_3.d2.setTexture(domek);
	mech_3.d3.setTexture(domek);
	mech_3.d4.setTexture(domek);
	mech_3.d1.setPosition(Vector2f(60, 650));
	mech_3.d2.setPosition(Vector2f(80, 650));
	mech_3.d3.setPosition(Vector2f(60, 630));
	mech_3.d4.setPosition(Vector2f(80, 630));
	mech_3.d1.setRotation(90);
	mech_3.d2.setRotation(90);
	mech_3.d3.setRotation(90);
	mech_3.d4.setRotation(90);
	mt_inzmat_s.setTexture(mt_inzmat);
	mt_inzmat_s.setPosition(Vector2f(229, 491));
	mt_inzmat_s.setRotation(90);
	inz_3.kolor.setTexture(color);
	inz_3.kolor.setPosition(Vector2f(100, 491));
	inz_3.kolor.setRotation(90);
	inz_3.d1.setTexture(domek);
	inz_3.d2.setTexture(domek);
	inz_3.d3.setTexture(domek);
	inz_3.d4.setTexture(domek);
	inz_3.d1.setPosition(Vector2f(60, 530));
	inz_3.d2.setPosition(Vector2f(80, 530));
	inz_3.d3.setPosition(Vector2f(60, 510));
	inz_3.d4.setPosition(Vector2f(80, 510));
	inz_3.d1.setRotation(90);
	inz_3.d2.setRotation(90);
	inz_3.d3.setRotation(90);
	inz_3.d4.setRotation(90);
	mt_zarziinzprod_s.setTexture(mt_zarziinzprod);
	mt_zarziinzprod_s.setPosition(Vector2f(229, 431));
	mt_zarziinzprod_s.setRotation(90);
	zarz_3.kolor.setTexture(color);
	zarz_3.kolor.setPosition(Vector2f(100, 431));
	zarz_3.kolor.setRotation(90);
	zarz_3.d1.setTexture(domek);
	zarz_3.d2.setTexture(domek);
	zarz_3.d3.setTexture(domek);
	zarz_3.d4.setTexture(domek);
	zarz_3.d1.setPosition(Vector2f(80, 470));
	zarz_3.d2.setPosition(Vector2f(60, 470));
	zarz_3.d3.setPosition(Vector2f(80, 450));
	zarz_3.d4.setPosition(Vector2f(60, 450));
	zarz_3.d1.setRotation(90);
	zarz_3.d2.setRotation(90);
	zarz_3.d3.setRotation(90);
	zarz_3.d4.setRotation(90);
	budo_budownictwo_s.setTexture(budo_budownictwo);
	budo_budownictwo_s.setPosition(Vector2f(229, 311));
	budo_budownictwo_s.setRotation(90);
	budo_4.kolor.setTexture(color);
	budo_4.kolor.setPosition(Vector2f(100, 311));
	budo_4.kolor.setRotation(90);
	budo_4.d1.setTexture(domek);
	budo_4.d2.setTexture(domek);
	budo_4.d3.setTexture(domek);
	budo_4.d4.setTexture(domek);
	budo_4.d1.setPosition(Vector2f(80, 350));
	budo_4.d2.setPosition(Vector2f(60, 350));
	budo_4.d3.setPosition(Vector2f(80, 330));
	budo_4.d4.setPosition(Vector2f(60, 330));
	budo_4.d1.setRotation(90);
	budo_4.d2.setRotation(90);
	budo_4.d3.setRotation(90);
	budo_4.d4.setRotation(90);
	budo_budopodz_s.setTexture(budo_budopodz);
	budo_budopodz_s.setPosition(Vector2f(229, 191));
	budo_budopodz_s.setRotation(90);
	budop_4.kolor.setTexture(color);
	budop_4.kolor.setPosition(Vector2f(100, 191));
	budop_4.kolor.setRotation(90);
	budop_4.d1.setTexture(domek);
	budop_4.d2.setTexture(domek);
	budop_4.d3.setTexture(domek);
	budop_4.d4.setTexture(domek);
	budop_4.d1.setPosition(Vector2f(80, 230));
	budop_4.d2.setPosition(Vector2f(60, 230));
	budop_4.d3.setPosition(Vector2f(80, 210));
	budop_4.d4.setPosition(Vector2f(60, 210));
	budop_4.d1.setRotation(90);
	budop_4.d2.setRotation(90);
	budop_4.d3.setRotation(90);
	budop_4.d4.setRotation(90);
	budo_zarziinzprod_s.setTexture(budo_zarziinzprod);
	budo_zarziinzprod_s.setPosition(Vector2f(229, 130));
	budo_zarziinzprod_s.setRotation(90);
	zarz_4.kolor.setTexture(color);
	zarz_4.kolor.setPosition(Vector2f(100, 130));
	zarz_4.kolor.setRotation(90);
	zarz_4.d1.setTexture(domek);
	zarz_4.d2.setTexture(domek);
	zarz_4.d3.setTexture(domek);
	zarz_4.d4.setTexture(domek);
	zarz_4.d1.setPosition(Vector2f(80, 160));
	zarz_4.d2.setPosition(Vector2f(60, 160));
	zarz_4.d3.setPosition(Vector2f(80, 140));
	zarz_4.d4.setPosition(Vector2f(60, 140));
	zarz_4.d1.setRotation(90);
	zarz_4.d2.setRotation(90);
	zarz_4.d3.setRotation(90);
	zarz_4.d4.setRotation(90);
	arch_architektura_s.setTexture(arch_architektura);
	arch_architektura_s.setPosition(Vector2f(230, 0));
	arch_architektura_s.setRotation(0);
	archi_5.kolor.setTexture(color);
	archi_5.kolor.setPosition(Vector2f(230, 80));
	archi_5.kolor.setRotation(0);
	archi_5.d1.setTexture(domek);
	archi_5.d2.setTexture(domek);
	archi_5.d3.setTexture(domek);
	archi_5.d4.setTexture(domek);
	archi_5.d1.setPosition(Vector2f(270, 130));
	archi_5.d2.setPosition(Vector2f(250, 130));
	archi_5.d3.setPosition(Vector2f(270, 150));
	archi_5.d4.setPosition(Vector2f(250, 150));
	archi_5.d1.setRotation(0);
	archi_5.d2.setRotation(0);
	archi_5.d3.setRotation(0);
	archi_5.d4.setRotation(0);
	arch_archiwnetrz_s.setTexture(arch_archiwnetrz);
	arch_archiwnetrz_s.setPosition(Vector2f(351, 0));
	arch_archiwnetrz_s.setRotation(0);
	archiw_5.kolor.setTexture(color);
	archiw_5.kolor.setPosition(Vector2f(351, 80));
	archiw_5.kolor.setRotation(0);
	archiw_5.d1.setTexture(domek);
	archiw_5.d2.setTexture(domek);
	archiw_5.d3.setTexture(domek);
	archiw_5.d4.setTexture(domek);
	archiw_5.d1.setPosition(Vector2f(390, 130));
	archiw_5.d2.setPosition(Vector2f(370, 130));
	archiw_5.d3.setPosition(Vector2f(390, 150));
	archiw_5.d4.setPosition(Vector2f(370, 150));
	archiw_5.d1.setRotation(0);
	archiw_5.d2.setRotation(0);
	archiw_5.d3.setRotation(0);
	archiw_5.d4.setRotation(0);
	trans_logistyka_s.setTexture(trans_logistyka);
	trans_logistyka_s.setPosition(Vector2f(411, 0));
	trans_logistyka_s.setRotation(0);
	logi_6.kolor.setTexture(color);
	logi_6.kolor.setPosition(Vector2f(411, 80));
	logi_6.kolor.setRotation(0);
	logi_6.d1.setTexture(domek);
	logi_6.d2.setTexture(domek);
	logi_6.d3.setTexture(domek);
	logi_6.d4.setTexture(domek);
	logi_6.d1.setPosition(Vector2f(450, 130));
	logi_6.d2.setPosition(Vector2f(430, 130));
	logi_6.d3.setPosition(Vector2f(450, 150));
	logi_6.d4.setPosition(Vector2f(430, 150));
	logi_6.d1.setRotation(0);
	logi_6.d2.setRotation(0);
	logi_6.d3.setRotation(0);
	logi_6.d4.setRotation(0);
	trans_transprzemyslowy_s.setTexture(trans_transprzemyslowy);
	trans_transprzemyslowy_s.setPosition(Vector2f(531, 0));
	trans_transprzemyslowy_s.setRotation(0);
	trans_6.kolor.setTexture(color);
	trans_6.kolor.setPosition(Vector2f(531, 80));
	trans_6.kolor.setRotation(0);
	trans_6.d1.setTexture(domek);
	trans_6.d2.setTexture(domek);
	trans_6.d3.setTexture(domek);
	trans_6.d4.setTexture(domek);
	trans_6.d1.setPosition(Vector2f(570, 130));
	trans_6.d2.setPosition(Vector2f(550, 130));
	trans_6.d3.setPosition(Vector2f(570, 150));
	trans_6.d4.setPosition(Vector2f(550, 150));
	trans_6.d1.setRotation(0);
	trans_6.d2.setRotation(0);
	trans_6.d3.setRotation(0);
	trans_6.d4.setRotation(0);
	gorn_gornigeo_s.setTexture(gorn_gornigeo);
	gorn_gornigeo_s.setPosition(Vector2f(591, 0));
	gorn_gornigeo_s.setRotation(0);
	gig_7.kolor.setTexture(color);
	gig_7.kolor.setPosition(Vector2f(591, 80));
	gig_7.kolor.setRotation(0);
	gig_7.d1.setTexture(domek);
	gig_7.d2.setTexture(domek);
	gig_7.d3.setTexture(domek);
	gig_7.d4.setTexture(domek);
	gig_7.d1.setPosition(Vector2f(630, 130));
	gig_7.d2.setPosition(Vector2f(610, 130));
	gig_7.d3.setPosition(Vector2f(630, 150));
	gig_7.d4.setPosition(Vector2f(610, 150));
	gig_7.d1.setRotation(0);
	gig_7.d2.setRotation(0);
	gig_7.d3.setRotation(0);
	gig_7.d4.setRotation(0);
	gorn_inzbezp_s.setTexture(gorn_inzbezp);
	gorn_inzbezp_s.setPosition(Vector2f(711, 0));
	gorn_inzbezp_s.setRotation(0);
	inzb_7.kolor.setTexture(color);
	inzb_7.kolor.setPosition(Vector2f(711, 80));
	inzb_7.kolor.setRotation(0);
	inzb_7.d1.setTexture(domek);
	inzb_7.d2.setTexture(domek);
	inzb_7.d3.setTexture(domek);
	inzb_7.d4.setTexture(domek);
	inzb_7.d1.setPosition(Vector2f(750, 150));
	inzb_7.d2.setPosition(Vector2f(730, 150));
	inzb_7.d3.setPosition(Vector2f(750, 130));
	inzb_7.d4.setPosition(Vector2f(730, 130));
	inzb_7.d1.setRotation(0);
	inzb_7.d2.setRotation(0);
	inzb_7.d3.setRotation(0);
	inzb_7.d4.setRotation(0);
	chem_chemia_s.setTexture(chem_chemia);
	chem_chemia_s.setPosition(Vector2f(771, 190));
	chem_chemia_s.setRotation(-90);
	chem_8.kolor.setTexture(color);
	chem_8.kolor.setPosition(Vector2f(900, 190));
	chem_8.kolor.setRotation(-90);
	chem_8.d1.setTexture(domek);
	chem_8.d2.setTexture(domek);
	chem_8.d3.setTexture(domek);
	chem_8.d4.setTexture(domek);
	chem_8.d1.setPosition(Vector2f(920, 150));
	chem_8.d2.setPosition(Vector2f(940, 150));
	chem_8.d3.setPosition(Vector2f(920, 170));
	chem_8.d4.setPosition(Vector2f(940, 170));
	chem_8.d1.setRotation(-90);
	chem_8.d2.setRotation(-90);
	chem_8.d3.setRotation(-90);
	chem_8.d4.setRotation(-90);
	chem_biotech_s.setTexture(chem_biotech);
	chem_biotech_s.setPosition(Vector2f(771, 250));
	chem_biotech_s.setRotation(-90);
	biotech_8.kolor.setTexture(color);
	biotech_8.kolor.setPosition(Vector2f(900, 250));
	biotech_8.kolor.setRotation(-90);
	biotech_8.d1.setTexture(domek);
	biotech_8.d2.setTexture(domek);
	biotech_8.d3.setTexture(domek);
	biotech_8.d4.setTexture(domek);
	biotech_8.d1.setPosition(Vector2f(920, 210));
	biotech_8.d2.setPosition(Vector2f(940, 210));
	biotech_8.d3.setPosition(Vector2f(920, 230));
	biotech_8.d4.setPosition(Vector2f(940, 230));
	biotech_8.d1.setRotation(-90);
	biotech_8.d2.setRotation(-90);
	biotech_8.d3.setRotation(-90);
	biotech_8.d4.setRotation(-90);
	chem_techchem_s.setTexture(chem_techchem);
	chem_techchem_s.setPosition(Vector2f(771, 370));
	chem_techchem_s.setRotation(-90);
	tech_8.kolor.setTexture(color);
	tech_8.kolor.setPosition(Vector2f(900, 370));
	tech_8.kolor.setRotation(-90);
	tech_8.d1.setTexture(domek);
	tech_8.d2.setTexture(domek);
	tech_8.d3.setTexture(domek);
	tech_8.d4.setTexture(domek);
	tech_8.d1.setPosition(Vector2f(920, 330));
	tech_8.d2.setPosition(Vector2f(940, 330));
	tech_8.d3.setPosition(Vector2f(920, 350));
	tech_8.d4.setPosition(Vector2f(940, 350));
	tech_8.d1.setRotation(-90);
	tech_8.d2.setRotation(-90);
	tech_8.d3.setRotation(-90);
	tech_8.d4.setRotation(-90);

	piast_s.setTexture(piast);
	piast_s.setPosition(Vector2f(471, 671));
	piast_s.setRotation(0);
	pi.kolor.setTexture(color);
	pi.kolor.setPosition(Vector2f(471, 800));
	pi.kolor.setRotation(0);
	karlik_s.setTexture(karlik);
	karlik_s.setPosition(Vector2f(229, 371));
	karlik_s.setRotation(90);
	ka.kolor.setTexture(color);
	ka.kolor.setPosition(Vector2f(100, 371));
	ka.kolor.setRotation(90);
	solaris_s.setTexture(solaris);
	solaris_s.setPosition(Vector2f(471, 0));
	solaris_s.setRotation(0);
	so.kolor.setTexture(color);
	so.kolor.setPosition(Vector2f(471, 100));
	so.kolor.setRotation(0);
	elektron_s.setTexture(elektron);
	elektron_s.setPosition(Vector2f(771, 430));
	elektron_s.setRotation(-90);
	el.kolor.setTexture(color);
	el.kolor.setPosition(Vector2f(900, 430));
	el.kolor.setRotation(-90);

	impreza_s.setTexture(impreza);
	impreza_s.setPosition(Vector2f(531, 671));
	impreza_s.setRotation(0);
	afterek_s.setTexture(afterek);
	afterek_s.setPosition(Vector2f(771, 610));
	afterek_s.setRotation(-90);

	alo_rybnik_s.setTexture(alo_rybnik);
	alo_rybnik_s.setPosition(Vector2f(229, 551));
	alo_rybnik_s.setRotation(90);
	ry.kolor.setTexture(color);
	ry.kolor.setPosition(Vector2f(100, 551));
	ry.kolor.setRotation(90);
	alo_gliwice_s.setTexture(alo_gliwice);
	alo_gliwice_s.setPosition(Vector2f(651, 0));
	alo_gliwice_s.setRotation(0);
	gl.kolor.setTexture(color);
	gl.kolor.setPosition(Vector2f(651, 80));
	gl.kolor.setRotation(0);

	dzien_rektorski_1_s.setTexture(dzien_rektorski);
	dzien_rektorski_1_s.setPosition(Vector2f(651, 671));
	dzien_rektorski_1_s.setRotation(0);
	dzien_rektorski_2_s.setTexture(dzien_rektorski);
	dzien_rektorski_2_s.setPosition(Vector2f(351, 671));
	dzien_rektorski_2_s.setRotation(0);
	dzien_rektorski_3_s.setTexture(dzien_rektorski);
	dzien_rektorski_3_s.setPosition(Vector2f(229, 251));
	dzien_rektorski_3_s.setRotation(90);
	dzien_rektorski_4_s.setTexture(dzien_rektorski);
	dzien_rektorski_4_s.setPosition(Vector2f(291, 0));
	dzien_rektorski_4_s.setRotation(0);
	dzien_rektorski_5_s.setTexture(dzien_rektorski);
	dzien_rektorski_5_s.setPosition(Vector2f(771, 310));
	dzien_rektorski_5_s.setRotation(-90);
	dzien_rektorski_6_s.setTexture(dzien_rektorski);
	dzien_rektorski_6_s.setPosition(Vector2f(771, 490));
	dzien_rektorski_6_s.setRotation(-90);

	koniec_tury_s.setTexture(koniec_tury);
	koniec_tury_s.setPosition(Vector2f(850, 900));
	gracz1.g_s.setTexture(g1);
	gracz1.g_s.setPosition(Vector2f(850, 750));
	gracz2.g_s.setTexture(g2);
	gracz2.g_s.setPosition(Vector2f(800, 750));
	gracz2.opcje_s.setPosition(Vector2f(800, 900));

	while (monopoly_w.isOpen()) {
		Event event;
		monopoly_w.clear(Color::Black);
		monopoly_w.draw(plansza_s);

		monopoly_w.draw(bos_s);
		monopoly_w.draw(strefastudenta_s);
		monopoly_w.draw(start_s);
		monopoly_w.draw(wezwanie_s);

		monopoly_w.draw(ms_inf_s);
		monopoly_w.draw(ms_mat_s);
		monopoly_w.draw(aei_air_s);
		monopoly_w.draw(aei_inf_s);
		monopoly_w.draw(e_mech_s);
		monopoly_w.draw(e_energetyka_s);
		monopoly_w.draw(e_inf_s);
		monopoly_w.draw(mt_mechibud_s);
		monopoly_w.draw(mt_zarziinzprod_s);
		monopoly_w.draw(mt_inzmat_s);
		monopoly_w.draw(budo_budownictwo_s);
		monopoly_w.draw(budo_budopodz_s);
		monopoly_w.draw(budo_zarziinzprod_s);
		monopoly_w.draw(arch_architektura_s);
		monopoly_w.draw(arch_archiwnetrz_s);
		monopoly_w.draw(trans_logistyka_s);
		monopoly_w.draw(trans_transprzemyslowy_s);
		monopoly_w.draw(gorn_gornigeo_s);
		monopoly_w.draw(gorn_inzbezp_s);
		monopoly_w.draw(chem_chemia_s);
		monopoly_w.draw(chem_biotech_s);
		monopoly_w.draw(chem_techchem_s);

		monopoly_w.draw(air_1.kolor);
		monopoly_w.draw(inf_1.kolor);
		monopoly_w.draw(mech_2.kolor);
		monopoly_w.draw(energ_2.kolor);
		monopoly_w.draw(inf_2.kolor);
		monopoly_w.draw(mech_3.kolor);
		monopoly_w.draw(zarz_3.kolor);
		monopoly_w.draw(inz_3.kolor);
		monopoly_w.draw(budo_4.kolor);
		monopoly_w.draw(budop_4.kolor);
		monopoly_w.draw(zarz_4.kolor);
		monopoly_w.draw(archi_5.kolor);
		monopoly_w.draw(archiw_5.kolor);
		monopoly_w.draw(logi_6.kolor);
		monopoly_w.draw(trans_6.kolor);
		monopoly_w.draw(gig_7.kolor);
		monopoly_w.draw(inzb_7.kolor);
		monopoly_w.draw(chem_8.kolor);
		monopoly_w.draw(biotech_8.kolor);
		monopoly_w.draw(tech_8.kolor);
		monopoly_w.draw(mat_9.kolor);
		monopoly_w.draw(inf_9.kolor);

		monopoly_w.draw(air_1.d1);
		monopoly_w.draw(air_1.d2);
		monopoly_w.draw(air_1.d3);
		monopoly_w.draw(air_1.d4);
		monopoly_w.draw(inf_1.d1);
		monopoly_w.draw(inf_1.d2);
		monopoly_w.draw(inf_1.d3);
		monopoly_w.draw(inf_1.d4);
		monopoly_w.draw(mech_2.d1);
		monopoly_w.draw(mech_2.d2);
		monopoly_w.draw(mech_2.d3);
		monopoly_w.draw(mech_2.d4);
		monopoly_w.draw(energ_2.d1);
		monopoly_w.draw(energ_2.d2);
		monopoly_w.draw(energ_2.d3);
		monopoly_w.draw(energ_2.d4);
		monopoly_w.draw(inf_2.d1);
		monopoly_w.draw(inf_2.d2);
		monopoly_w.draw(inf_2.d3);
		monopoly_w.draw(inf_2.d4);
		monopoly_w.draw(mech_3.d1);
		monopoly_w.draw(mech_3.d2);
		monopoly_w.draw(mech_3.d3);
		monopoly_w.draw(mech_3.d4);
		monopoly_w.draw(zarz_3.d1);
		monopoly_w.draw(zarz_3.d2);
		monopoly_w.draw(zarz_3.d3);
		monopoly_w.draw(zarz_3.d4);
		monopoly_w.draw(inz_3.d1);
		monopoly_w.draw(inz_3.d2);
		monopoly_w.draw(inz_3.d3);
		monopoly_w.draw(inz_3.d4);
		monopoly_w.draw(budo_4.d1);
		monopoly_w.draw(budo_4.d2);
		monopoly_w.draw(budo_4.d3);
		monopoly_w.draw(budo_4.d4);
		monopoly_w.draw(zarz_4.d1);
		monopoly_w.draw(zarz_4.d2);
		monopoly_w.draw(zarz_4.d3);
		monopoly_w.draw(zarz_4.d4);
		monopoly_w.draw(budop_4.d1);
		monopoly_w.draw(budop_4.d2);
		monopoly_w.draw(budop_4.d3);
		monopoly_w.draw(budop_4.d4);
		monopoly_w.draw(archi_5.d1);
		monopoly_w.draw(archi_5.d2);
		monopoly_w.draw(archi_5.d3);
		monopoly_w.draw(archi_5.d4);
		monopoly_w.draw(archiw_5.d1);
		monopoly_w.draw(archiw_5.d2);
		monopoly_w.draw(archiw_5.d3);
		monopoly_w.draw(archiw_5.d4);
		monopoly_w.draw(logi_6.d1);
		monopoly_w.draw(logi_6.d2);
		monopoly_w.draw(logi_6.d3);
		monopoly_w.draw(logi_6.d4);
		monopoly_w.draw(trans_6.d1);
		monopoly_w.draw(trans_6.d2);
		monopoly_w.draw(trans_6.d3);
		monopoly_w.draw(trans_6.d4);
		monopoly_w.draw(gig_7.d1);
		monopoly_w.draw(gig_7.d2);
		monopoly_w.draw(gig_7.d3);
		monopoly_w.draw(gig_7.d4);
		monopoly_w.draw(inzb_7.d1);
		monopoly_w.draw(inzb_7.d2);
		monopoly_w.draw(inzb_7.d3);
		monopoly_w.draw(inzb_7.d4);
		monopoly_w.draw(chem_8.d1);
		monopoly_w.draw(chem_8.d2);
		monopoly_w.draw(chem_8.d3);
		monopoly_w.draw(chem_8.d4);
		monopoly_w.draw(biotech_8.d1);
		monopoly_w.draw(biotech_8.d2);
		monopoly_w.draw(biotech_8.d3);
		monopoly_w.draw(biotech_8.d4);
		monopoly_w.draw(tech_8.d1);
		monopoly_w.draw(tech_8.d2);
		monopoly_w.draw(tech_8.d3);
		monopoly_w.draw(tech_8.d4);
		monopoly_w.draw(inf_9.d1);
		monopoly_w.draw(inf_9.d2);
		monopoly_w.draw(inf_9.d3);
		monopoly_w.draw(inf_9.d4);
		monopoly_w.draw(mat_9.d1);
		monopoly_w.draw(mat_9.d2);
		monopoly_w.draw(mat_9.d3);
		monopoly_w.draw(mat_9.d4);

		monopoly_w.draw(piast_s);
		monopoly_w.draw(karlik_s);
		monopoly_w.draw(solaris_s);
		monopoly_w.draw(elektron_s);

		monopoly_w.draw(pi.kolor);
		monopoly_w.draw(ka.kolor);
		monopoly_w.draw(so.kolor);
		monopoly_w.draw(el.kolor);

		monopoly_w.draw(impreza_s);
		monopoly_w.draw(afterek_s);

		monopoly_w.draw(alo_rybnik_s);
		monopoly_w.draw(alo_gliwice_s);

		monopoly_w.draw(ry.kolor);
		monopoly_w.draw(gl.kolor);

		monopoly_w.draw(dzien_rektorski_1_s);
		monopoly_w.draw(dzien_rektorski_2_s);
		monopoly_w.draw(dzien_rektorski_3_s);
		monopoly_w.draw(dzien_rektorski_4_s);
		monopoly_w.draw(dzien_rektorski_5_s);
		monopoly_w.draw(dzien_rektorski_6_s);

		while (monopoly_w.pollEvent(event)) {
			if (event.type == Event::Closed) {
				monopoly_w.close();
			}
			if (koniec_tury_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					liczniktur += 1;
					if (liczniktur % 2 == 0) {
						tura_t.setString(gracz2.nick);
						kasa_t.setString(to_string(gracz2.Hajs));
						gracz2 = ruch(gracz2, gracz1, monopoly_w); //przemieszczanie gracza
					}
					else {
						tura_t.setString(gracz1.nick);
						kasa_t.setString(to_string(gracz1.Hajs));
						gracz1 = ruch(gracz1, gracz2, monopoly_w);
					}
					
				}
			}
		}
		monopoly_w.draw(tura_t);
		monopoly_w.draw(kasa_t);
		monopoly_w.draw(koniec_tury_s);
		monopoly_w.draw(gracz1.g_s);
		monopoly_w.draw(gracz2.g_s);
		monopoly_w.display();
		if (liczniktur % 2 == 0) {
			monopoly_w.draw(gracz2.kart_s);
			if (gracz2.n == 0&& bot == 3) {
				akcja(&gracz2, &gracz1); //akcja gracza
				bankrut(&gracz1, &gracz2); //sprawdzanie czy bankrut
				gracz2.n = 1;
			}
			else if (gracz2.n==0&&bot != 3) {
				ruchbot(&gracz2, &gracz1, bot);
				bankrut(&gracz1, &gracz2);
				gracz2.n = 1;
			}
		}
		else {
			monopoly_w.draw(gracz1.kart_s);
			if (gracz1.n == 0) {
				akcja(&gracz1, &gracz2);
				bankrut(&gracz2, &gracz1);
				gracz1.n = 1;
			}
		}
	}
}
void wbot() {
	RenderWindow wbot_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Ustawienia - Wybor Bota", Style::Default);
	Texture ustawienia, doktorant, prodziekan, rektor;
	ustawienia.loadFromFile("Ustawienia.jpg");
	doktorant.loadFromFile("Doktorant.jpg");
	prodziekan.loadFromFile("Prodziekan.jpg");
	rektor.loadFromFile("Rektor.jpg");
	Sprite ustawienia_s, doktorant_s, prodziekan_s, rektor_s;
	ustawienia_s.setTexture(ustawienia);
	doktorant_s.setTexture(doktorant);
	doktorant_s.setPosition(Vector2f(375, 300));
	prodziekan_s.setTexture(prodziekan);
	prodziekan_s.setPosition(Vector2f(375, 500));
	rektor_s.setTexture(rektor);
	rektor_s.setPosition(Vector2f(375, 700));
	while (wbot_w.isOpen()) {
		Event event;
		wbot_w.clear(Color::Black);
		wbot_w.draw(ustawienia_s);
		wbot_w.draw(doktorant_s);
		wbot_w.draw(prodziekan_s);
		wbot_w.draw(rektor_s);
		wbot_w.display();
		while (wbot_w.pollEvent(event)) {
			if (event.type == Event::Closed) {
				wbot_w.close();
			}
			if (doktorant_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					wbot_w.close();
					gracz2.nick = "DOKTORANT";
					bot = 0;
					nazwy();
				}
			}
			if (prodziekan_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					wbot_w.close();
					gracz2.nick = "PRODZIEKAN";
					bot = 1;
					nazwy();
				}
			}
			if (rektor_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					wbot_w.close();
					gracz2.nick = "REKTOR";
					bot = 2;
					nazwy();
				}
			}
		}
	}
}
void nazwy() {
	int zmiana = 0;
	RenderWindow whotseat_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Ustawienia - Wybor Nicków", Style::Default);
	Texture ustawienia, dalej;
	ustawienia.loadFromFile("Ustawienia.jpg");
	dalej.loadFromFile("dalej.jpg");

	Font nick_f, napis;
	nick_f.loadFromFile("BITCBLKAD.ttf");
	napis.loadFromFile("Cooper Black Regular.ttf");

	Sprite ustawienia_s, dalej_s;
	ustawienia_s.setTexture(ustawienia);
	dalej_s.setTexture(dalej);
	dalej_s.setPosition(Vector2f(600, 600));

	Text nick1_t, nick2_t, nick_1_s, nick_2_s;
	nick1_t.setFont(nick_f);
	nick1_t.setFillColor(Color::Blue);
	nick1_t.setPosition(Vector2f(100, 350));
	nick2_t.setFont(nick_f);
	nick2_t.setFillColor(Color::Blue);
	nick2_t.setPosition(Vector2f(100, 450));
	nick_1_s.setFont(napis);
	nick_1_s.setFillColor(Color::Blue);
	nick_1_s.setPosition(Vector2f(100, 300));
	nick_1_s.setString("Nick 1:");
	nick_2_s.setFont(napis);
	nick_2_s.setFillColor(Color::Blue);
	nick_2_s.setPosition(Vector2f(100, 400));
	nick_2_s.setString("Nick 2:");

	while (whotseat_w.isOpen()) {
		Event event;
		whotseat_w.clear(Color::Black);
		whotseat_w.draw(nick_1_s);
		whotseat_w.draw(nick_2_s);
		whotseat_w.draw(ustawienia_s);
		whotseat_w.draw(dalej_s);
		while (whotseat_w.pollEvent(event)) {
			if (event.type == Event::Closed) {
				whotseat_w.close();
			}
			if (event.type == Event::KeyPressed && zmiana == 0) {
				if (event.key.code == sf::Keyboard::Return) {
					zmiana = 1;
					continue;
				}
				if (event.key.code == sf::Keyboard::LShift) {
					continue;
				}
				if (event.key.code == sf::Keyboard::BackSpace && gracz1.nick.length() != 0) {
					gracz1.nick.erase(gracz1.nick.length()-1,gracz1.nick.length());
					continue;
				}
				gracz1.nick += char(event.key.code + 65);
				
			}
			if (event.type == Event::KeyPressed && zmiana == 1) {
				if (event.key.code == sf::Keyboard::LShift) {
					continue;
				}
				if (event.key.code == sf::Keyboard::BackSpace && gracz2.nick.length() != 0) {
					gracz2.nick.erase(gracz2.nick.length() - 1, gracz2.nick.length());
					continue;
				}
				if (event.key.code == sf::Keyboard::Return) {
					zmiana = 2;
					continue;
				}
				gracz2.nick += char(event.key.code + 65);
			}
			if (dalej_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && zmiana == 2) {
				whotseat_w.close();
				gra();
			}
		}
		nick1_t.setString(gracz1.nick);
		nick2_t.setString(gracz2.nick);
		whotseat_w.draw(nick1_t);
		whotseat_w.draw(nick2_t);
		whotseat_w.display();
	}
}
void ustawienia() {
	RenderWindow ustawienia_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Ustawienia", Style::Default);
	Texture ustawienia, hotseat, bot;
	ustawienia.loadFromFile("Ustawienia.jpg");
	hotseat.loadFromFile("Hot-Seat.jpg");
	bot.loadFromFile("Bot.jpg");
	Sprite ustawienia_s, hotseat_s, bot_s;
	ustawienia_s.setTexture(ustawienia);
	hotseat_s.setTexture(hotseat);
	hotseat_s.setPosition(Vector2f(375, 300));
	bot_s.setTexture(bot);
	bot_s.setPosition(Vector2f(375, 600));
	while (ustawienia_w.isOpen()) {
		Event event;
		ustawienia_w.clear(Color::Black);
		ustawienia_w.draw(ustawienia_s);
		ustawienia_w.draw(hotseat_s);
		ustawienia_w.draw(bot_s);
		ustawienia_w.display();
		while (ustawienia_w.pollEvent(event)) {
			if (event.type == Event::Closed) {
				ustawienia_w.close();
			}
			if (hotseat_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					ustawienia_w.close();
					nazwy();
				}
			}
			if (bot_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					ustawienia_w.close();
					wbot();
				}
			}
		}
	}
}
void polozenie(Gracz* g, Gracz* p) {
	if (g->Akty_Wlasnosci[0]==2 && g->Polozenie == p->Polozenie) { //umiejêtnoœæ specjalna aei
		g->Hajs += 20;
		p->Hajs -= 20;
	}
	if (g->Polozenie == 1) {
		g->g_s.setPosition(Vector2f(start.x, start.y)); //odpowiednie ustawienie sprita grcza
	}
	if (g->Polozenie == 2) {
		g->g_s.setPosition(Vector2f(aei_1.x, aei_1.y));
	}
	if (g->Polozenie == 3) {
		g->g_s.setPosition(Vector2f(dr_1.x, dr_1.y));
	}
	if (g->Polozenie == 4) {
		g->g_s.setPosition(Vector2f(aei_2.x, aei_2.y));
	}
	if (g->Polozenie == 5) {
		g->g_s.setPosition(Vector2f(impreza.x, impreza.y));
	}
	if (g->Polozenie == 6) {
		g->g_s.setPosition(Vector2f(piast.x, piast.y));
	}
	if (g->Polozenie == 7) {
		g->g_s.setPosition(Vector2f(e_1.x, e_1.y));
	}
	if (g->Polozenie == 8) {
		g->g_s.setPosition(Vector2f(dr_2.x, dr_2.y));
	}
	if (g->Polozenie == 9) {
		g->g_s.setPosition(Vector2f(e_2.x, e_2.y));
	}
	if (g->Polozenie == 10) {
		g->g_s.setPosition(Vector2f(e_3.x, e_3.y));
	}
	if (g->Polozenie == 11) {
		g->g_s.setPosition(Vector2f(bos.x, bos.y));
	}
	if (g->Polozenie == 12) {
		g->g_s.setPosition(Vector2f(mt_1.x, mt_1.y));
	}
	if (g->Polozenie == 13) {
		g->g_s.setPosition(Vector2f(alo_r.x, alo_r.y));
	}
	if (g->Polozenie == 14) {
		g->g_s.setPosition(Vector2f(mt_2.x, mt_2.y));
	}
	if (g->Polozenie == 15) {
		g->g_s.setPosition(Vector2f(mt_3.x, mt_3.y));
	}
	if (g->Polozenie == 16) {
		g->g_s.setPosition(Vector2f(karlik.x, karlik.y));
	}
	if (g->Polozenie == 17) {
		g->g_s.setPosition(Vector2f(budo_1.x, budo_1.y));
	}
	if (g->Polozenie == 18) {
		g->g_s.setPosition(Vector2f(dr_3.x, dr_3.y));
	}
	if (g->Polozenie == 19) {
		g->g_s.setPosition(Vector2f(budo_2.x, budo_2.y));
	}
	if (g->Polozenie == 20) {
		g->g_s.setPosition(Vector2f(budo_3.x, budo_3.y));
	}
	if (g->Polozenie == 21) {
		g->g_s.setPosition(Vector2f(strefa.x, strefa.y));
	}
	if (g->Polozenie == 22) {
		g->g_s.setPosition(Vector2f(arch_1.x, arch_1.y));
	}
	if (g->Polozenie == 23) {
		g->g_s.setPosition(Vector2f(dr_4.x, dr_4.y));
	}
	if (g->Polozenie == 24) {
		g->g_s.setPosition(Vector2f(arch_2.x, arch_2.y));
	}
	if (g->Polozenie == 25) {
		g->g_s.setPosition(Vector2f(trans_1.x, trans_1.y));
	}
	if (g->Polozenie == 26) {
		g->g_s.setPosition(Vector2f(solaris.x, solaris.y));
	}
	if (g->Polozenie == 27) {
		g->g_s.setPosition(Vector2f(trans_2.x, trans_2.y));
	}
	if (g->Polozenie == 28) {
		g->g_s.setPosition(Vector2f(gorn_1.x, gorn_1.y));
	}
	if (g->Polozenie == 29) {
		g->g_s.setPosition(Vector2f(alo_g.x, alo_g.y));
	}
	if (g->Polozenie == 30) {
		g->g_s.setPosition(Vector2f(gorn_2.x, gorn_2.y));
	}
	if (g->Polozenie == 31) {
		g->g_s.setPosition(Vector2f(wezwanie.x, wezwanie.y));
		if (g->Akty_Wlasnosci[7] == 3)
			g->wiêzienie = 2;
		else
			g->wiêzienie = 3;
		g->g_s.setPosition(Vector2f(bos.x - 80, bos.y));
	}
	if (g->Polozenie == 32) {
		g->g_s.setPosition(Vector2f(chem_1.x, chem_1.y));
	}
	if (g->Polozenie == 33) {
		g->g_s.setPosition(Vector2f(chem_2.x, chem_2.y));
	}
	if (g->Polozenie == 34) {
		g->g_s.setPosition(Vector2f(dr_5.x, dr_5.y));
	}
	if (g->Polozenie == 35) {
		g->g_s.setPosition(Vector2f(chem_3.x, chem_3.y));
	}
	if (g->Polozenie == 36) {
		g->g_s.setPosition(Vector2f(elektron.x, elektron.y));
	}
	if (g->Polozenie == 37) {
		g->g_s.setPosition(Vector2f(dr_6.x, dr_6.y));
	}
	if (g->Polozenie == 38) {
		g->g_s.setPosition(Vector2f(ms_1.x, ms_1.y));
	}
	if (g->Polozenie == 39) {
		g->g_s.setPosition(Vector2f(afterek.x, afterek.y));
	}
	if (g->Polozenie == 40) {
		g->g_s.setPosition(Vector2f(ms_2.x, ms_2.y));
	}
}
void akcja(Gracz* g, Gracz* p) {
	if (g->Polozenie == 2) { //sprawdza jakie pole
		if (air_1.GraczID == p->ID)
			zaplata(g, p, &air_1); // automatyczna op³ata
		else
			akcja_kierunek(g, p, &air_1); //inne opcje
	}
	if (g->Polozenie == 3) {
		loskarty(g, p);
	}
	if (g->Polozenie == 4) {
		if (inf_1.GraczID == p->ID)
			zaplata(g, p, &inf_1);
		else
			akcja_kierunek(g, p, &inf_1);
	}
	if (g->Polozenie == 5) {
		g->Hajs -= 200;
	}
	if (g->Polozenie == 6) {
		if (pi.IDGracz == p->ID) {
			zaplata_akademiki(g, p, &pi);
		}
		else {
			akcja_akademik(g, &pi);
		}
	}
	if (g->Polozenie == 7) {
		if (mech_2.GraczID == p->ID)
			zaplata(g, p, &mech_2);
		else
			akcja_kierunek(g, p, &mech_2);
	}
	if (g->Polozenie == 8) {
		loskarty(g, p);
	}
	if (g->Polozenie == 9) {
		if (energ_2.GraczID == p->ID)
			zaplata(g, p, &energ_2);
		else
			akcja_kierunek(g, p, &energ_2);
	}
	if (g->Polozenie == 10) {
		if (inf_2.GraczID == p->ID)
			zaplata(g, p, &inf_2);
		else
			akcja_kierunek(g, p, &inf_2);
	}
	if (g->Polozenie == 12) {
		if (mech_3.GraczID == p->ID)
			zaplata(g, p, &mech_3);
		else
			akcja_kierunek(g, p, &mech_3);
	}
	if (g->Polozenie == 13) {
		if (ry.IDGracz == p->ID) {
			zaplata_ALO(g, p, &ry);
		}
		else {
			akcja_alo(g, &ry);
		}
	}
	if (g->Polozenie == 14) {
		if (inz_3.GraczID == p->ID)
			zaplata(g, p, &inz_3);
		else
			akcja_kierunek(g, p, &inz_3);
	}
	if (g->Polozenie == 15) {
		if (zarz_3.GraczID == p->ID)
			zaplata(g, p, &zarz_3);
		else
			akcja_kierunek(g, p, &zarz_3);
	}
	if (g->Polozenie == 16) {
		if (ka.IDGracz == p->ID) {
			zaplata_akademiki(g, p, &ka);
		}
		else {
			akcja_akademik(g, &ka);
		}
	}
	if (g->Polozenie == 17) {
		if (budo_4.GraczID == p->ID)
			zaplata(g, p, &budo_4);
		else
			akcja_kierunek(g, p, &budo_4);
	}
	if (g->Polozenie == 18) {
		loskarty(g, p);
	}
	if (g->Polozenie == 19) {
		if (budop_4.GraczID == p->ID)
			zaplata(g, p, &budop_4);
		else
			akcja_kierunek(g, p, &budop_4);
	}
	if (g->Polozenie == 20) {
		if (zarz_4.GraczID == p->ID)
			zaplata(g, p, &zarz_4);
		else
			akcja_kierunek(g, p, &zarz_4);
	}
	if (g->Polozenie == 22) {
		if (archi_5.GraczID == p->ID)
			zaplata(g, p, &archi_5);
		else
			akcja_kierunek(g, p, &archi_5);
	}
	if (g->Polozenie == 23) {
		loskarty(g, p);
	}
	if (g->Polozenie == 24) {
		if (archiw_5.GraczID == p->ID)
			zaplata(g, p, &archiw_5);
		else
			akcja_kierunek(g, p, &archiw_5);
	}
	if (g->Polozenie == 25) {
		if (logi_6.GraczID == p->ID)
			zaplata(g, p, &logi_6);
		else
			akcja_kierunek(g, p, &logi_6);
	}
	if (g->Polozenie == 26) {
		if (so.IDGracz == p->ID) {
			zaplata_akademiki(g, p, &so);
		}
		else {
			akcja_akademik(g, &so);
		}
	}
	if (g->Polozenie == 27) {
		if (trans_6.GraczID == p->ID)
			zaplata(g, p, &trans_6);
		else
			akcja_kierunek(g, p, &trans_6);
	}
	if (g->Polozenie == 28) {
		if (gig_7.GraczID == p->ID)
			zaplata(g, p, &gig_7);
		else
			akcja_kierunek(g, p, &gig_7);
	}
	if (g->Polozenie == 29) {
		if (gl.IDGracz == p->ID) {
			zaplata_ALO(g, p, &gl);
		}
		else {
			akcja_alo(g, &gl);
		}
	}
	if (g->Polozenie == 30) {
		if (inzb_7.GraczID == p->ID)
			zaplata(g, p, &inzb_7);
		else
			akcja_kierunek(g, p, &inzb_7);
	}
	if (g->Polozenie == 32) {
		if (chem_8.GraczID == p->ID)
			zaplata(g, p, &chem_8);
		else
			akcja_kierunek(g, p, &chem_8);
	}
	if (g->Polozenie == 33) {
		if (biotech_8.GraczID == p->ID)
			zaplata(g, p, &biotech_8);
		else
			akcja_kierunek(g, p, &biotech_8);
	}
	if (g->Polozenie == 34) {
		loskarty(g, p);
	}
	if (g->Polozenie == 35) {
		if (tech_8.GraczID == p->ID)
			zaplata(g, p, &tech_8);
		else
			akcja_kierunek(g, p, &tech_8);
	}
	if (g->Polozenie == 36) {
		if (el.IDGracz == p->ID) {
			zaplata_akademiki(g, p, &el);
		}
		else {
			akcja_akademik(g, &el);
		}
	}
	if (g->Polozenie == 37) {
		loskarty(g, p);
	}
	if (g->Polozenie == 38) {
		if (mat_9.GraczID == p->ID)
			zaplata(g, p, &mat_9);
		else
			akcja_kierunek(g, p, &mat_9);
	}
	if (g->Polozenie == 39) {
		g->Hajs -= 100;
	}
	if (g->Polozenie == 40) {
		if (inf_9.GraczID == p->ID)
			zaplata(g, p, &inf_9);
		else
			akcja_kierunek(g, p, &inf_9);
	}
}
void akcja_kierunek(Gracz* X, Gracz* Y, Kierunek* K)
{
	RenderWindow opcje(VideoMode(600, 300), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	Texture domki, kup;
	Font czcionka;
	czcionka.loadFromFile("Cooper Black Regular.ttf");
	Text wiadomosc, odpowiedz;
	wiadomosc.setFont(czcionka);
	wiadomosc.setFillColor(Color::Blue);
	odpowiedz.setFont(czcionka);
	odpowiedz.setFillColor(Color::Blue);
	odpowiedz.setPosition(Vector2f(0, 50));
	Sprite kup_s, domki_s;
	kup.loadFromFile("kup.jpg");
	domki.loadFromFile("kup_domki.jpg");
	domki_s.setScale(Vector2f(0, 0));
	kup_s.setScale(Vector2f(0, 0));
	while (opcje.isOpen()) {
		Event event;
		kup_s.setTexture(kup);
		kup_s.setPosition(Vector2f(150, 80));
		domki_s.setTexture(domki);
		domki_s.setPosition(Vector2f(150, 80));
		odpowiedz.setPosition(Vector2f(0, 40));
		opcje.draw(kup_s);
		opcje.draw(domki_s);
		opcje.draw(wiadomosc);
		opcje.draw(odpowiedz);
		opcje.display();
		while (opcje.pollEvent(event)) {
			if (event.type == Event::Closed)
				opcje.close();
			if (K->GraczID == 0)
			{
				kup_s.setScale(Vector2f(1, 1));
				wiadomosc.setString("Czy chcesz kupic Kierunek?");
				if ((X->Hajs >= K->Koszt_zakupu) || (X->Akty_Wlasnosci[6] == 2 && X->Hajs >= K->Koszt_zakupu * 0.8)) //sprawdza czy gracz mo¿e kupiæ kierunek
				{
					if (kup_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
						zakup_kierunku(X, K);
						odpowiedz.setString("Zakup udany");
						opcje.close();
						akcja_kierunek(X, Y, K);
					}
				}
				else
				{
					odpowiedz.setString("Nie stac Cie na zakup Kierunku.");
				}
			}
			else
				if (K->GraczID == X->ID && X->Akty_Wlasnosci[K->Wydzial-1] == K->LKW) //sprawdza czy mo¿na zakupiæ katedrê lub instytut
				{
					domki_s.setScale(Vector2f(1, 1));
					wiadomosc.setString("Czy chcesz kupiæ Katedre?");
					if (domki_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed)
					{
						if (X->Hajs >= K->Koszt_Budowy)
							if (K->LiczbaBudynkow + 1 > 5)
							{
								odpowiedz.setString("Brak miejsca na tyle Katedr. Masz ju¿ Instytut");
							}
							else
							{
								zakup_budynek(X, Y, K, 1);
								odpowiedz.setString("Zakup udany");
								opcje.close();
								akcja_kierunek(X, Y, K);
							}
					}
				}
				else {
					opcje.close();
				}
		}
	}
}
void akcja_akademik(Gracz* X, Akademik* K) {
	RenderWindow opcje(VideoMode(600, 300), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	Texture kup;
	Font czcionka;
	czcionka.loadFromFile("Cooper Black Regular.ttf");
	Text wiadomosc, odpowiedz;
	wiadomosc.setFont(czcionka);
	wiadomosc.setFillColor(Color::Blue);
	odpowiedz.setFont(czcionka);
	odpowiedz.setFillColor(Color::Blue);
	odpowiedz.setPosition(Vector2f(0, 50));
	Sprite kup_s;
	kup.loadFromFile("kup.jpg");
	kup_s.setScale(Vector2f(0, 0));
	while (opcje.isOpen()) {
		Event event;
		kup_s.setTexture(kup);
		kup_s.setPosition(Vector2f(150, 80));
		odpowiedz.setPosition(Vector2f(0, 40));
		opcje.draw(kup_s);
		opcje.draw(wiadomosc);
		opcje.draw(odpowiedz);
		opcje.display();
		while (opcje.pollEvent(event)) {
			if (event.type == Event::Closed)
				opcje.close();
			if (K->IDGracz == 0)
			{
				kup_s.setScale(Vector2f(1, 1));
				wiadomosc.setString("Czy chcesz kupic Akademik?");
				if ((X->Hajs >= K->KosztZakupu))
				{
					if (kup_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
						zakup_akademika(X, K);
						odpowiedz.setString("Zakup udany");
						opcje.close();
						akcja_akademik(X, K);
					}
				}
				else
				{
					odpowiedz.setString("Nie stac Cie na zakup Akademika.");
				}

			}
			else {
				opcje.close();
			}
		}
	}
}
void akcja_alo(Gracz* X, ALO* K) {
	RenderWindow opcje(VideoMode(600, 300), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	Texture kup;
	Font czcionka;
	czcionka.loadFromFile("Cooper Black Regular.ttf");
	Text wiadomosc, odpowiedz;
	wiadomosc.setFont(czcionka);
	wiadomosc.setFillColor(Color::Blue);
	odpowiedz.setFont(czcionka);
	odpowiedz.setFillColor(Color::Blue);
	odpowiedz.setPosition(Vector2f(0, 50));
	Sprite kup_s;
	kup.loadFromFile("kup.jpg");
	kup_s.setScale(Vector2f(0, 0));
	while (opcje.isOpen()) {
		Event event;
		kup_s.setTexture(kup);
		kup_s.setPosition(Vector2f(150, 80));
		odpowiedz.setPosition(Vector2f(0, 40));
		opcje.draw(kup_s);
		opcje.draw(wiadomosc);
		opcje.draw(odpowiedz);
		opcje.display();
		while (opcje.pollEvent(event)) {
			if (event.type == Event::Closed)
				opcje.close();
			if (K->IDGracz == 0)
			{
				kup_s.setScale(Vector2f(1, 1));
				wiadomosc.setString("Czy chcesz kupic ALO?");
				if ((X->Hajs >= K->KosztZakupu))
				{
					if (kup_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
						zakup_alo(X, K);
						odpowiedz.setString("Zakup udany");
						opcje.close();
						akcja_alo(X, K);
					}

				}
				else
				{
					odpowiedz.setString("Nie stac Cie na zakup ALO.");
				}

			}
			else {
				opcje.close();
			}
		}
	}
}
void akcja_start(Gracz* X)
{
	if (X->Akty_Wlasnosci[2] == 3)
	{
		X->Hajs += 100;
	}
	X->Hajs += 200;
}
Gracz ruch(Gracz g, Gracz p, RenderWindow & monopoly) {
	int n;
	if (g.wiêzienie != 0)
		g.wiêzienie -= 1;
	else {
		 n = RNG(2, 12);
		 n = przerzut(&g, n);
		 g.Polozenie += n;
		if (g.Polozenie > 40) {
			g.Polozenie -= 40;
			g.p = 0;
			akcja_start(&g);
		}
		g.n = 0;
		polozenie(&g, &p);
	}
	return g;
}
void loskarty(Gracz* g, Gracz* p) {
	RenderWindow losk(VideoMode(468, 750), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	int x = RNG(1, 24);
	Texture k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24, k25, p1, p2, p3, p4;
	k1.loadFromFile("1.jpg");
	k2.loadFromFile("2.jpg");
	k3.loadFromFile("25.jpg");
	k4.loadFromFile("4.jpg");
	k5.loadFromFile("5.jpg");
	k6.loadFromFile("6.jpg");
	k7.loadFromFile("7.jpg");
	k8.loadFromFile("8.jpg");
	k9.loadFromFile("9.jpg");
	k10.loadFromFile("10.jpg");
	k11.loadFromFile("11.jpg");
	k12.loadFromFile("12.jpg");
	k13.loadFromFile("13.jpg");
	k14.loadFromFile("14.jpg");
	k15.loadFromFile("15.jpg");
	k16.loadFromFile("16.jpg");
	k17.loadFromFile("17.jpg");
	k18.loadFromFile("18.jpg");
	k19.loadFromFile("19.jpg");
	k20.loadFromFile("20.jpg");
	k21.loadFromFile("21.jpg");
	k22.loadFromFile("22.jpg");
	k23.loadFromFile("23.jpg");
	k24.loadFromFile("24.jpg");
	k25.loadFromFile("3.jpg");
	p1.loadFromFile("ka.jpg");
	p2.loadFromFile("el.jpg");
	p3.loadFromFile("pi.jpg");
	p4.loadFromFile("so.jpg");
	Sprite p1_s, p2_s, p3_s, p4_s;
	p1_s.setTexture(p1);
	p2_s.setTexture(p2);
	p3_s.setTexture(p3);
	p4_s.setTexture(p4);
	p1_s.setPosition(Vector2f(20, 500));
	p2_s.setPosition(Vector2f(150, 500));
	p3_s.setPosition(Vector2f(20, 600));
	p4_s.setPosition(Vector2f(150, 600));
	g->kart_s.setScale(Vector2f(1, 1));
		switch (x) {
		case 1:
			g->kart_s.setTexture(k1);
			if (g->Akty_Wlasnosci[3] == 3)
			{
				g->Hajs -= (g->ilosc_domkow * 20 + g->ilosc_hoteli * 90);
			}
			else
				g->Hajs -= (g->ilosc_domkow * 25 + g->ilosc_hoteli * 100);
			break;
		case 2:
			g->kart_s.setTexture(k2);
			if (g->Akty_Wlasnosci[3] == 3)
			{
				g->Hajs -= (g->ilosc_domkow * 35 + g->ilosc_hoteli * 105);
			}
			else
				g->Hajs -= (g->ilosc_domkow * 40 + g->ilosc_hoteli * 115);
			break;
		case 3:
			g->kart_s.setTexture(k25);
			if (g->Akty_Wlasnosci[6] == 2) //zgubila ci sie legitymacja studencka
			{
				p->Polozenie = 31;
			}
			g->Polozenie = 31;
			break;
		case 4:
			g->kart_s.setTexture(k4);
			g->Hajs += 200;
			if (g->Akty_Wlasnosci[7] == 3) //panie dziekanie to na cele naukowe...
			{
				g->Hajs += 150;
			}
			break;
		case 5:
			g->kart_s.setTexture(k5);
			g->Hajs += 10;
			if (g->Akty_Wlasnosci[4] == 2) //dorabiasz sobie w maku
			{
				g->Hajs += 5 * (g->ilosc_domkow + g->ilosc_hoteli);
			}
			break;
		case 6:
			g->kart_s.setTexture(k6);
			if (g->Akty_Wlasnosci[5] == 2) //czyzby kac po imprezie
			{
				p1.loadFromFile("+3.jpg");
				p2.loadFromFile("-3.jpg");
				p1_s.setScale(Vector2f(1, 1));
				p2_s.setScale(Vector2f(1, 1));
			}
			else
			{
				g->Polozenie -= 3;
				akcja(g, p);
			}
			break;
		case 7:
			g->kart_s.setTexture(k7);
			if (g->Akty_Wlasnosci[1] == 3) //szykuje sie impreza w akademiku
			{
				p1.loadFromFile("ka.jpg");
				p2.loadFromFile("el.jpg");
				p3.loadFromFile("pi.jpg");
				p4.loadFromFile("so.jpg");
				p1_s.setScale(Vector2f(1, 1));
				p2_s.setScale(Vector2f(1, 1));
				p3_s.setScale(Vector2f(1, 1));
				p4_s.setScale(Vector2f(1, 1));
			}
			else
			{
				g->Polozenie = 26;
			}

			break;
		case 8:
			g->kart_s.setTexture(k8);
			g->Polozenie = 22;
			if (g->Akty_Wlasnosci[4] == 2) //twoj artystyczny fragment duszy potrzebuje poogladac sobie sztuke
			{
				archi_5.Koszt_Budowy = 0;
				zakup_budynek(g, p, &archi_5, 1);
				archi_5.Koszt_Budowy = 150;
			}
			break;
		case 9:
			g->kart_s.setTexture(k9);
			g->Polozenie = 2;
			if (g->Akty_Wlasnosci[0] == 2) //potrzebujesz porady magow
			{
				air_1.Koszt_Budowy = 0;
				zakup_budynek(g, p, &air_1, 1);
				air_1.Koszt_Budowy = 50;
			}
			break;
		case 10:
			g->kart_s.setTexture(k10);
			g->Polozenie = 40;
			if (g->Akty_Wlasnosci[8] == 2) //musisz isc do biblioteki
			{
				inf_9.Koszt_Budowy = 0;
				zakup_budynek(g, p, &inf_9, 1);
				inf_9.Koszt_Budowy = 200;
			}
			break;
		case 11:
			g->kart_s.setTexture(k11);
			if (g->Akty_Wlasnosci[2] == 3) //organizujesz domowke
			{
				g->Polozenie = 14;
				p->Polozenie = 14;
			}
			else
			{
				p->Hajs -= 10;
				g->Hajs += 10;
			}
			break;
		case 12:
			g->kart_s.setTexture(k12);
			g->Hajs += 100;
			if (g->Akty_Wlasnosci[1] == 3) //czyzby to juz poczatek miesiaca?
			{
				g->Hajs += 30 * g->ilosc_hoteli;
			}
			break;
		case 13:
			g->kart_s.setTexture(k13);
			if (g->Akty_Wlasnosci[7] == 3) //znowu idziesz z ziomeczkami na piwo
			{
				p->Hajs -= 15;
			}
			else {
				g->Hajs -= 15;
			}
			break;
		case 14:
			g->kart_s.setTexture(k14);
			if (g->Akty_Wlasnosci[0] == 2) //udzielasz korkow z infy znajomemu z liceum
			{
				g->Hajs += 10 * (air_1.LiczbaBudynkow + air_1.Hotel + inf_1.LiczbaBudynkow + inf_1.Hotel);
			}
			else
				g->Hajs += 25;
			break;
		case 15:
			g->kart_s.setTexture(k15);
			g->Polozenie = 1;
			g->Hajs += 200;
			if (g->Akty_Wlasnosci[5] == 2)
			{
				liczniktur -= 1;
			}
			break;
		case 16:
			g->kart_s.setTexture(k16);
			g->Hajs += 50;
			if (g->Akty_Wlasnosci[2] == 3) //babcia jest dumna ze udalo ci sie zaliczyc kolosa z ...
			{
				g->Polozenie = 21;
				p->Polozenie = 21;
				g->Hajs += 10;
				p->Hajs -= 10;
			}
			break;
		case 17:
			g->kart_s.setTexture(k17);
			g->Hajs += 150;
			if (g->Akty_Wlasnosci[7] == 3) //znajomy oddal ci hajs za piwo
			{
				p->Hajs -= 20;
				g->Hajs += 20;
			}
			break;
		case 18:
			g->kart_s.setTexture(k18);
			g->wyjscie = 1;
			break;
		case 19:
			g->kart_s.setTexture(k19);
			g->Hajs += 20;
			if (g->Akty_Wlasnosci[2] == 3) //oszczedzasz na jedzeniu
			{
				g->Hajs += 60 * g->akademiki;
			}
			break;
		case 20:
			g->kart_s.setTexture(k20);
			g->Polozenie = 25;
			if (g->Akty_Wlasnosci[5] == 2) //organizujesz wyjazd w gory
			{
				logi_6.Koszt_Budowy = 0;
				zakup_budynek(g, p, &logi_6, 1);
				logi_6.Koszt_Budowy = 150;
			}
			break;
		case 21:
			g->kart_s.setTexture(k21);
			if (g->Akty_Wlasnosci[8] == 2) //ida igry, musisz zaopatrzec sie w plyny
			{
				p1.loadFromFile("-150.jpg");
				p2.loadFromFile("-tura.jpg");
				p1_s.setScale(Vector2f(1, 1));
				p2_s.setScale(Vector2f(1, 1));
			}
			else
			{
				g->Hajs -= 150;
			}

			break;
		case 22:
			g->kart_s.setTexture(k22);
			g->Hajs -= 50;
			if (g->Akty_Wlasnosci[3] == 3) //prosisz ziomka zeby zrobil ci prace magisterska
			{
				g->s += 0.1;
			}
			break;
		case 23:
			g->kart_s.setTexture(k23);
			g->Hajs -= 20;
			if (g->Akty_Wlasnosci[6] == 2) //impreza w spirali
			{
				p->Polozenie = 5;
				p->Hajs -= 200;

			}
			break;
		case 24:
			g->kart_s.setTexture(k24);
			if (g->Akty_Wlasnosci[2] == 3) //kupujesz piwo na zawody we flany
			{
				p->Hajs -= 150;
			}
			else
			{
				g->Hajs -= 150;
			}

			break;

		}
		while (losk.isOpen()) {
			p1_s.setScale(Vector2f(0, 0));
			p2_s.setScale(Vector2f(0, 0));
			p3_s.setScale(Vector2f(0, 0));
			p4_s.setScale(Vector2f(0, 0));
			Event event;
			while (losk.pollEvent(event)) {
			if (event.type == Event::Closed) {
				losk.close();
			}
			if (x == 6 && g->Akty_Wlasnosci[5] == 2) {
				if (p1_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
					g->Polozenie += 3;
				}
				if (p2_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
					g->Polozenie -= 3;
				}
			}
			if (x == 7 && g->Akty_Wlasnosci[1] == 3) {
				if (p1_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
					g->Polozenie = 16;
				}
				if (p2_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
					g->Polozenie = 36;
				}
				if (p1_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
					g->Polozenie = 6;
				}
				if (p1_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
					g->Polozenie = 26;
				}
			}
			if (x == 21 && g->Akty_Wlasnosci[8] == 2) {
				if (p1_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
					g->Hajs -= 150;
				}
				if (p2_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
					g->wiêzienie += 1;
				}
			}
		}
		losk.draw(g->kart_s);
		losk.draw(p1_s);
		losk.draw(p2_s);
		losk.draw(p3_s);
		losk.draw(p4_s);
		losk.display();
	}
	polozenie(g, p);
}
void bankrut(Gracz* g, Gracz* p) {
	if (g->Hajs <= 0) {
		RenderWindow koniec(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Koniec Gry", Style::Default);
		Font k;
		k.loadFromFile("Cooper Black Regular.ttf");
		Text b;
		b.setFillColor(Color::Blue);
		b.setFont(k);
		b.setString("Wygrywa gracz " + p->nick + "!");
		b.setPosition(Vector2f(400, 300));
		Event event;
		while (koniec.isOpen()) {
			koniec.draw(b);
			while (koniec.pollEvent(event)) {
				if (event.type == Event::Closed) {
					koniec.close();
				}
			}
			koniec.display();
		}
	}
}
int przerzut(Gracz* g, int n) {
	if (g->Akty_Wlasnosci[6] == 2 && g->p == 0) {
		RenderWindow p(VideoMode(600, 300), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
		Texture opcja;
		opcja.loadFromFile("przerzut.jpg");
		Font czcionka;
		czcionka.loadFromFile("Cooper Black Regular.ttf");
		Text wiadomosc;
		wiadomosc.setFont(czcionka);
		wiadomosc.setFillColor(Color::Blue);
		wiadomosc.setString(char(n) + " Przerzucasz?");
		Sprite opcja_s;
		opcja_s.setTexture(opcja);
		opcja_s.setPosition(Vector2f(150, 80));
		while (p.isOpen()) {
			Event event;
			p.draw(opcja_s);
			p.draw(wiadomosc);
			while (p.pollEvent(event)) {
				if (event.type == Event::Closed)
					p.close();
				if (opcja_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y) && event.type == Event::MouseButtonPressed) {
					n = RNG(2, 12);
					g->p = 1;
				}
			}
		}
	}
	return n;
}
void ruchbot(Gracz* X, Gracz* Y, int IQ)
{
	int pomoc = 1;
	for (int i = 0; i <= 21; i++)
	{
		if (i == 4 || i == 7 || i == 10 || i == 13 || i == 15 || i == 18 || i == 21)
		{
			pomoc += 1;
		}
		else if (i == 2 || i == 20)
		{
			pomoc += 3;
		}
		else
			pomoc += 2;
		if (X->Polozenie - pomoc - 1 == 0)
		{
			pomoc = i;
			break;
		}
	}
	if (X->wyjscie == 0)
	{
		if (X->Polozenie == 2) { //sprawdza jakie pole
			if (air_1.GraczID == Y->ID)
				zaplata(X, Y, &air_1); // automatyczna op³ata
			else {
				if (air_1.GraczID == 0 && (X->Hajs >= air_1.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - air_1.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - air_1.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &air_1);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * air_1.Koszt_Budowy > X->Hajs)) || (IQ == 1 && air_1.LiczbaBudynkow + i == 5) || (IQ == 2 && i * air_1.Koszt_Budowy > X->Hajs + 100) && air_1.Hotel == false)
						{
							zakup_budynek(X, Y, &air_1, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && air_1.LiczbaBudynkow + i == 5) && air_1.Hotel == false) || (IQ == 1 && air_1.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &air_1, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 3) {
			loskarty(X, Y);
		}
		if (X->Polozenie == 4) {
			if (inf_1.GraczID == Y->ID)
				zaplata(X, Y, &inf_1); // automatyczna op³ata
			else {
				if (inf_1.GraczID == 0 && (X->Hajs >= inf_1.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - inf_1.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - inf_1.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &inf_1);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * inf_1.Koszt_Budowy > X->Hajs)) || (IQ == 1 && inf_1.LiczbaBudynkow + i == 5) || (IQ == 2 && i * inf_1.Koszt_Budowy > X->Hajs + 100) && inf_1.Hotel == false)
						{
							zakup_budynek(X, Y, &inf_1, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && inf_1.LiczbaBudynkow + i == 5) && inf_1.Hotel == false) || (IQ == 1 && inf_1.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &inf_1, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 5) {
			X->Hajs -= 200;
		}
		if (X->Polozenie == 6) {
			if (pi.IDGracz == Y->ID) {
				zaplata_akademiki(X, Y, &pi);
			}
			else {
				if (pi.IDGracz == 0)
				{
					if (pi.KosztZakupu <= X->Hajs)
					{
						zakup_akademika(X, &pi);
					}
				}
				else
				{
					zaplata_akademiki(X, Y, &pi);
				}
			}
		}
		if (X->Polozenie == 7) {
			if (mech_2.GraczID == Y->ID)
				zaplata(X, Y, &mech_2); // automatyczna op³ata
			else {
				if (mech_2.GraczID == 0 && (X->Hajs >= mech_2.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - mech_2.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - mech_2.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &mech_2);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * mech_2.Koszt_Budowy > X->Hajs)) || (IQ == 1 && mech_2.LiczbaBudynkow + i == 5) || (IQ == 2 && i * mech_2.Koszt_Budowy > X->Hajs + 100) && mech_2.Hotel == false)
						{
							zakup_budynek(X, Y, &mech_2, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && mech_2.LiczbaBudynkow + i == 5) && mech_2.Hotel == false) || (IQ == 1 && mech_2.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &mech_2, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 8) {
			loskarty(X, Y);
		}
		if (X->Polozenie == 9) {
			if (energ_2.GraczID == Y->ID)
				zaplata(X, Y, &energ_2); // automatyczna op³ata
			else {
				if (energ_2.GraczID == 0 && (X->Hajs >= energ_2.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - energ_2.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - energ_2.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &energ_2);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * energ_2.Koszt_Budowy > X->Hajs)) || (IQ == 1 && energ_2.LiczbaBudynkow + i == 5) || (IQ == 2 && i * energ_2.Koszt_Budowy > X->Hajs + 100) && energ_2.Hotel == false)
						{
							zakup_budynek(X, Y, &energ_2, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && energ_2.LiczbaBudynkow + i == 5) && energ_2.Hotel == false) || (IQ == 1 && energ_2.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &energ_2, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 10) {
			if (inf_2.GraczID == Y->ID)
				zaplata(X, Y, &inf_2); // automatyczna op³ata
			else {
				if (inf_2.GraczID == 0 && (X->Hajs >= inf_2.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - inf_2.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - inf_2.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &inf_2);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * inf_2.Koszt_Budowy > X->Hajs)) || (IQ == 1 && inf_2.LiczbaBudynkow + i == 5) || (IQ == 2 && i * inf_2.Koszt_Budowy > X->Hajs + 100) && inf_2.Hotel == false)
						{
							zakup_budynek(X, Y, &inf_2, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && inf_2.LiczbaBudynkow + i == 5) && inf_2.Hotel == false) || (IQ == 1 && inf_2.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &inf_2, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 12) {
			if (mech_3.GraczID == Y->ID)
				zaplata(X, Y, &mech_3); // automatyczna op³ata
			else {
				if (mech_3.GraczID == 0 && (X->Hajs >= mech_3.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - mech_3.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - mech_3.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &mech_3);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * mech_3.Koszt_Budowy > X->Hajs)) || (IQ == 1 && mech_3.LiczbaBudynkow + i == 5) || (IQ == 2 && i * mech_3.Koszt_Budowy > X->Hajs + 100) && mech_3.Hotel == false)
						{
							zakup_budynek(X, Y, &mech_3, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && mech_3.LiczbaBudynkow + i == 5) && mech_3.Hotel == false) || (IQ == 1 && mech_3.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &mech_3, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 13) {
			if (ry.IDGracz == Y->ID) {
				zaplata_ALO(X, Y, &ry);
			}
			else {
				if (ry.IDGracz == 0)
				{
					if ((ry.KosztZakupu < X->Hajs && IQ == 2) || (ry.KosztZakupu * 2 < X->Hajs && IQ == 1))
					{
						zakup_alo(X, &ry);
					}
				}
			}
		}
		if (X->Polozenie == 14) {
			if (inz_3.GraczID == Y->ID)
				zaplata(X, Y, &inz_3); // automatyczna op³ata
			else {
				if (inz_3.GraczID == 0 && (X->Hajs >= inz_3.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - inz_3.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - inz_3.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &inz_3);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * inz_3.Koszt_Budowy > X->Hajs)) || (IQ == 1 && inz_3.LiczbaBudynkow + i == 5) || (IQ == 2 && i * inz_3.Koszt_Budowy > X->Hajs + 100) && inz_3.Hotel == false)
						{
							zakup_budynek(X, Y, &inz_3, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && inz_3.LiczbaBudynkow + i == 5) && inz_3.Hotel == false) || (IQ == 1 && inz_3.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &inz_3, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 15) {
			if (zarz_3.GraczID == Y->ID)
				zaplata(X, Y, &zarz_3); // automatyczna op³ata
			else {
				if (zarz_3.GraczID == 0 && (X->Hajs >= zarz_3.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - zarz_3.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - zarz_3.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &zarz_3);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * zarz_3.Koszt_Budowy > X->Hajs)) || (IQ == 1 && zarz_3.LiczbaBudynkow + i == 5) || (IQ == 2 && i * zarz_3.Koszt_Budowy > X->Hajs + 100) && zarz_3.Hotel == false)
						{
							zakup_budynek(X, Y, &zarz_3, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && zarz_3.LiczbaBudynkow + i == 5) && zarz_3.Hotel == false) || (IQ == 1 && zarz_3.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &zarz_3, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 16) {
			if (ka.IDGracz == Y->ID) {
				zaplata_akademiki(X, Y, &ka);
			}
			else {
				if (ka.IDGracz == 0)
				{
					if (ka.KosztZakupu <= X->Hajs)
					{
						zakup_akademika(X, &ka);
					}
				}
				else
				{
					zaplata_akademiki(X, Y, &ka);
				}
			}
		}
		if (X->Polozenie == 17) {
			if (budo_4.GraczID == Y->ID)
				zaplata(X, Y, &budo_4); // automatyczna op³ata
			else {
				if (budo_4.GraczID == 0 && (X->Hajs >= budo_4.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - budo_4.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - budo_4.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &budo_4);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * budo_4.Koszt_Budowy > X->Hajs)) || (IQ == 1 && budo_4.LiczbaBudynkow + i == 5) || (IQ == 2 && i * budo_4.Koszt_Budowy > X->Hajs + 100) && budo_4.Hotel == false)
						{
							zakup_budynek(X, Y, &budo_4, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && budo_4.LiczbaBudynkow + i == 5) && budo_4.Hotel == false) || (IQ == 1 && budo_4.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &budo_4, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 18) {
			loskarty(X, Y);
		}
		if (X->Polozenie == 19) {
			if (budop_4.GraczID == Y->ID)
				zaplata(X, Y, &budop_4); // automatyczna op³ata
			else {
				if (budop_4.GraczID == 0 && (X->Hajs >= budop_4.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - budop_4.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - budop_4.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &budop_4);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * budop_4.Koszt_Budowy > X->Hajs)) || (IQ == 1 && budop_4.LiczbaBudynkow + i == 5) || (IQ == 2 && i * budop_4.Koszt_Budowy > X->Hajs + 100) && budop_4.Hotel == false)
						{
							zakup_budynek(X, Y, &budop_4, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && budop_4.LiczbaBudynkow + i == 5) && budop_4.Hotel == false) || (IQ == 1 && budop_4.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &budop_4, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 20) {
			if (zarz_4.GraczID == Y->ID)
				zaplata(X, Y, &zarz_4); // automatyczna op³ata
			else {
				if (zarz_4.GraczID == 0 && (X->Hajs >= zarz_4.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - zarz_4.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - zarz_4.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &zarz_4);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * zarz_4.Koszt_Budowy > X->Hajs)) || (IQ == 1 && zarz_4.LiczbaBudynkow + i == 5) || (IQ == 2 && i * zarz_4.Koszt_Budowy > X->Hajs + 100) && zarz_4.Hotel == false)
						{
							zakup_budynek(X, Y, &zarz_4, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && zarz_4.LiczbaBudynkow + i == 5) && zarz_4.Hotel == false) || (IQ == 1 && zarz_4.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &zarz_4, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 22) {
			if (archi_5.GraczID == Y->ID)
				zaplata(X, Y, &archi_5); // automatyczna op³ata
			else {
				if (archi_5.GraczID == 0 && (X->Hajs >= archi_5.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - archi_5.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - archi_5.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &archi_5);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * archi_5.Koszt_Budowy > X->Hajs)) || (IQ == 1 && archi_5.LiczbaBudynkow + i == 5) || (IQ == 2 && i * archi_5.Koszt_Budowy > X->Hajs + 100) && archi_5.Hotel == false)
						{
							zakup_budynek(X, Y, &archi_5, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && archi_5.LiczbaBudynkow + i == 5) && archi_5.Hotel == false) || (IQ == 1 && archi_5.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &archi_5, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 23) {
			loskarty(X, Y);
		}
		if (X->Polozenie == 24) {
			if (archiw_5.GraczID == Y->ID)
				zaplata(X, Y, &archiw_5); // automatyczna op³ata
			else {
				if (archiw_5.GraczID == 0 && (X->Hajs >= archiw_5.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - archiw_5.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - archiw_5.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &archiw_5);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * archiw_5.Koszt_Budowy > X->Hajs)) || (IQ == 1 && archiw_5.LiczbaBudynkow + i == 5) || (IQ == 2 && i * archiw_5.Koszt_Budowy > X->Hajs + 100) && archiw_5.Hotel == false)
						{
							zakup_budynek(X, Y, &archiw_5, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && archiw_5.LiczbaBudynkow + i == 5) && archiw_5.Hotel == false) || (IQ == 1 && archiw_5.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &archiw_5, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 25) {
			if (logi_6.GraczID == Y->ID)
				zaplata(X, Y, &logi_6); // automatyczna op³ata
			else {
				if (logi_6.GraczID == 0 && (X->Hajs >= logi_6.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - logi_6.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - logi_6.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &logi_6);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * logi_6.Koszt_Budowy > X->Hajs)) || (IQ == 1 && logi_6.LiczbaBudynkow + i == 5) || (IQ == 2 && i * logi_6.Koszt_Budowy > X->Hajs + 100) && logi_6.Hotel == false)
						{
							zakup_budynek(X, Y, &logi_6, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && logi_6.LiczbaBudynkow + i == 5) && logi_6.Hotel == false) || (IQ == 1 && logi_6.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &logi_6, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 26) {
			if (so.IDGracz == Y->ID) {
				zaplata_akademiki(X, Y, &so);
			}
			else {
				if (so.IDGracz == 0)
				{
					if (so.KosztZakupu <= X->Hajs)
					{
						zakup_akademika(X, &so);
					}
				}
				else
				{
					zaplata_akademiki(X, Y, &so);
				}
			}
		}
		if (X->Polozenie == 27) {
			if (trans_6.GraczID == Y->ID)
				zaplata(X, Y, &trans_6); // automatyczna op³ata
			else {
				if (trans_6.GraczID == 0 && (X->Hajs >= trans_6.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - trans_6.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - trans_6.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &trans_6);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * trans_6.Koszt_Budowy > X->Hajs)) || (IQ == 1 && trans_6.LiczbaBudynkow + i == 5) || (IQ == 2 && i * trans_6.Koszt_Budowy > X->Hajs + 100) && trans_6.Hotel == false)
						{
							zakup_budynek(X, Y, &trans_6, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && trans_6.LiczbaBudynkow + i == 5) && trans_6.Hotel == false) || (IQ == 1 && trans_6.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &trans_6, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 28) {
			if (gig_7.GraczID == Y->ID)
				zaplata(X, Y, &gig_7); // automatyczna op³ata
			else {
				if (gig_7.GraczID == 0 && (X->Hajs >= gig_7.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - gig_7.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - gig_7.Koszt_zakupu > 200)))) {
					zakup_kierunku(X, &gig_7);
				}
				else {
					for (int i = 1; i <= 5; i++)
					{
						if ((IQ == 0 && (i * gig_7.Koszt_Budowy > X->Hajs)) || (IQ == 1 && gig_7.LiczbaBudynkow + i == 5) || (IQ == 2 && i * gig_7.Koszt_Budowy > X->Hajs + 100) && gig_7.Hotel == false)
						{
							zakup_budynek(X, Y, &gig_7, i - 1);
						}
						if ((((IQ == 0 || IQ == 2) && gig_7.LiczbaBudynkow + i == 5) && gig_7.Hotel == false) || (IQ == 1 && gig_7.LiczbaBudynkow == 4 && i == 1))
						{
							zakup_budynek(X, Y, &gig_7, i);
						}
					}
				}

			}
		}
		if (X->Polozenie == 29) {
			if (gl.IDGracz == Y->ID) {
				zaplata_ALO(X, Y, &gl);
			}
			else {
				if (gl.IDGracz == 0)
				{
					if ((gl.KosztZakupu < X->Hajs && IQ == 2) || (gl.KosztZakupu * 2 < X->Hajs && IQ == 1))
					{
						zakup_alo(X, &gl);
					}
				}

				if (X->Polozenie == 30) {
					if (inzb_7.GraczID == Y->ID)
						zaplata(X, Y, &inzb_7); // automatyczna op³ata
					else {
						if (inzb_7.GraczID == 0 && (X->Hajs >= inzb_7.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - inzb_7.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - inzb_7.Koszt_zakupu > 200)))) {
							zakup_kierunku(X, &inzb_7);
						}
						else {
							for (int i = 1; i <= 5; i++)
							{
								if ((IQ == 0 && (i * inzb_7.Koszt_Budowy > X->Hajs)) || (IQ == 1 && inzb_7.LiczbaBudynkow + i == 5) || (IQ == 2 && i * inzb_7.Koszt_Budowy > X->Hajs + 100) && inzb_7.Hotel == false)
								{
									zakup_budynek(X, Y, &inzb_7, i - 1);
								}
								if ((((IQ == 0 || IQ == 2) && inzb_7.LiczbaBudynkow + i == 5) && inzb_7.Hotel == false) || (IQ == 1 && inzb_7.LiczbaBudynkow == 4 && i == 1))
								{
									zakup_budynek(X, Y, &inzb_7, i);
								}
							}
						}

					}
				}
				if (X->Polozenie == 32) {
					if (chem_8.GraczID == Y->ID)
						zaplata(X, Y, &chem_8); // automatyczna op³ata
					else {
						if (chem_8.GraczID == 0 && (X->Hajs >= chem_8.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - chem_8.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - chem_8.Koszt_zakupu > 200)))) {
							zakup_kierunku(X, &chem_8);
						}
						else {
							for (int i = 1; i <= 5; i++)
							{
								if ((IQ == 0 && (i * chem_8.Koszt_Budowy > X->Hajs)) || (IQ == 1 && chem_8.LiczbaBudynkow + i == 5) || (IQ == 2 && i * chem_8.Koszt_Budowy > X->Hajs + 100) && chem_8.Hotel == false)
								{
									zakup_budynek(X, Y, &chem_8, i - 1);
								}
								if ((((IQ == 0 || IQ == 2) && chem_8.LiczbaBudynkow + i == 5) && chem_8.Hotel == false) || (IQ == 1 && chem_8.LiczbaBudynkow == 4 && i == 1))
								{
									zakup_budynek(X, Y, &chem_8, i);
								}
							}
						}

					}
				}
				if (X->Polozenie == 33) {
					if (biotech_8.GraczID == Y->ID)
						zaplata(X, Y, &biotech_8); // automatyczna op³ata
					else {
						if (biotech_8.GraczID == 0 && (X->Hajs >= biotech_8.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - biotech_8.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - biotech_8.Koszt_zakupu > 200)))) {
							zakup_kierunku(X, &biotech_8);
						}
						else {
							for (int i = 1; i <= 5; i++)
							{
								if ((IQ == 0 && (i * biotech_8.Koszt_Budowy > X->Hajs)) || (IQ == 1 && biotech_8.LiczbaBudynkow + i == 5) || (IQ == 2 && i * biotech_8.Koszt_Budowy > X->Hajs + 100) && biotech_8.Hotel == false)
								{
									zakup_budynek(X, Y, &biotech_8, i - 1);
								}
								if ((((IQ == 0 || IQ == 2) && biotech_8.LiczbaBudynkow + i == 5) && biotech_8.Hotel == false) || (IQ == 1 && biotech_8.LiczbaBudynkow == 4 && i == 1))
								{
									zakup_budynek(X, Y, &biotech_8, i);
								}
							}
						}

					}
				}
				if (X->Polozenie == 34) {
					loskarty(X, Y);
				}
				if (X->Polozenie == 35) {
					if (tech_8.GraczID == Y->ID)
						zaplata(X, Y, &tech_8); // automatyczna op³ata
					else {
						if (tech_8.GraczID == 0 && (X->Hajs >= tech_8.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - tech_8.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - tech_8.Koszt_zakupu > 200)))) {
							zakup_kierunku(X, &tech_8);
						}
						else {
							for (int i = 1; i <= 5; i++)
							{
								if ((IQ == 0 && (i * tech_8.Koszt_Budowy > X->Hajs)) || (IQ == 1 && tech_8.LiczbaBudynkow + i == 5) || (IQ == 2 && i * tech_8.Koszt_Budowy > X->Hajs + 100) && tech_8.Hotel == false)
								{
									zakup_budynek(X, Y, &tech_8, i - 1);
								}
								if ((((IQ == 0 || IQ == 2) && tech_8.LiczbaBudynkow + i == 5) && tech_8.Hotel == false) || (IQ == 1 && tech_8.LiczbaBudynkow == 4 && i == 1))
								{
									zakup_budynek(X, Y, &tech_8, i);
								}
							}
						}

					}
				}
				if (X->Polozenie == 36) {
					if (el.IDGracz == Y->ID) {
						zaplata_akademiki(X, Y, &el);
					}
					else {
						if (el.IDGracz == 0)
						{
							if (el.KosztZakupu <= X->Hajs)
							{
								zakup_akademika(X, &el);
							}
						}
						else
						{
							zaplata_akademiki(X, Y, &el);
						}
					}
				}
				if (X->Polozenie == 37) {
					loskarty(X, Y);
				}
				if (X->Polozenie == 38) {
					if (mat_9.GraczID == Y->ID)
						zaplata(X, Y, &mat_9); // automatyczna op³ata
					else {
						if (mat_9.GraczID == 0 && (X->Hajs >= mat_9.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - mat_9.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - mat_9.Koszt_zakupu > 200)))) {
							zakup_kierunku(X, &mat_9);
						}
						else {
							for (int i = 1; i <= 5; i++)
							{
								if ((IQ == 0 && (i * mat_9.Koszt_Budowy > X->Hajs)) || (IQ == 1 && mat_9.LiczbaBudynkow + i == 5) || (IQ == 2 && i * mat_9.Koszt_Budowy > X->Hajs + 100) && mat_9.Hotel == false)
								{
									zakup_budynek(X, Y, &mat_9, i - 1);
								}
								if ((((IQ == 0 || IQ == 2) && mat_9.LiczbaBudynkow + i == 5) && mat_9.Hotel == false) || (IQ == 1 && mat_9.LiczbaBudynkow == 4 && i == 1))
								{
									zakup_budynek(X, Y, &mat_9, i);
								}
							}
						}

					}
				}
				if (X->Polozenie == 39) {
					X->Hajs -= 100;
				}
				if (X->Polozenie == 40) {
					if (inf_9.GraczID == Y->ID)
						zaplata(X, Y, &inf_9); // automatyczna op³ata
					else {
						if (inf_9.GraczID == 0 && (X->Hajs >= inf_9.Koszt_zakupu) && ((IQ == 0) || (IQ == 1 && X->Hajs - inf_9.Koszt_zakupu > 100) || (IQ == 2 && (pomoc > 12 || X->Hajs - inf_9.Koszt_zakupu > 200)))) {
							zakup_kierunku(X, &inf_9);
						}
						else {
							for (int i = 1; i <= 5; i++)
							{
								if ((IQ == 0 && (i * inf_9.Koszt_Budowy > X->Hajs)) || (IQ == 1 && inf_9.LiczbaBudynkow + i == 5) || (IQ == 2 && i * inf_9.Koszt_Budowy > X->Hajs + 100) && inf_9.Hotel == false)
								{
									zakup_budynek(X, Y, &inf_9, i - 1);
								}
								if ((((IQ == 0 || IQ == 2) && inf_9.LiczbaBudynkow + i == 5) && inf_9.Hotel == false) || (IQ == 1 && inf_9.LiczbaBudynkow == 4 && i == 1))
								{
									zakup_budynek(X, Y, &inf_9, i);
								}
							}
						}

					}
				}
			}
		}
	}
}
int main() {
	RenderWindow menustart_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika",Style::Default);
	menustart_w.setFramerateLimit(60);
	Texture tytul, nowagra;
	tytul.loadFromFile("Nazwa.jpg");
	nowagra.loadFromFile("NowaGra.jpg");
	Sprite tytul_s, nowagra_s;
	tytul_s.setTexture(tytul);
	nowagra_s.setTexture(nowagra);
	nowagra_s.setPosition(Vector2f(375, 300));
	while (menustart_w.isOpen()) {
		Event event;
		menustart_w.clear(Color::Black);
		menustart_w.draw(tytul_s);
		menustart_w.draw(nowagra_s);
		menustart_w.display();
		while (menustart_w.pollEvent(event)) {
			if (event.type == Event::Closed) {
				menustart_w.close();
			}
			if (nowagra_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					menustart_w.close();
					ustawienia();
				}
			}
		}
	}
	return 0;
}
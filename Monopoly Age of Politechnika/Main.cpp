#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <conio.h>
#include "Nag³ówek.h"

using namespace sf;
Gracz gracz1;
Gracz gracz2;
Pole start(1, 850, 750), aei_1(2, 790, 750), dr_1(3, 730, 750), aei_2(4, 670, 750), impreza(5, 610, 750), piast(6, 550, 750), e_1(7, 490, 750), dr_2(8, 430, 750), e_2(9, 370, 750), e_3(10, 310, 750), bos(11, 150, 780), mt_1(12, 150, 620), alo_r(13, 150, 560), mt_2(14, 150, 500), mt_3(15, 150, 440), karlik(16, 150, 380), budo_1(17, 150, 320), dr_3(18, 150, 260), budo_2(19, 150, 200), budo_3(20, 150, 140), strefa(21, 150, 40), arch_1(22, 310, 40), dr_4(23, 370, 40), arch_2(24, 430, 40), trans_1(25, 490, 40), solaris(26, 550, 40), trans_2(27, 610, 40), gorn_1(28, 670, 40), alo_g(29, 730, 40), gorn_2(30, 790, 40), wezwanie(31, 850, 40), chem_1(32, 850, 150), chem_2(33, 850, 210), dr_5(34, 850, 270), chem_3(35, 850, 330), elektron(36, 850, 390), dr_6(37, 850, 450), ms_1(38, 850, 510), afterek(39, 850, 570), ms_2(40, 850, 630);
Kierunek air_1(2, "AiR", 1, 60, 50, 2), inf_1(4, "Informatyka", 1, 60, 50, 4), mech_2(7, "Mech", 2, 100, 50, 6), energ_2(9, "Energetyka", 2, 100, 50, 6), inf_2(10, "Informatyka", 2, 120, 50, 8), mech_3(12,"Mechanika i budowa maszyn", 3, 140, 100, 10), inz_3(14,"In¿. Mat", 3, 140, 100, 10), zarz_3(15, "Zarz¹dz. i In¿. Prod.", 3, 160, 100, 12), budo_4(17, "Budownictwo", 4, 180, 100, 14), budop_4(19, "Budo. Podziemne", 4, 180, 100, 14), zarz_4(20, "Zarz¹dz. i In¿. Prod.", 4, 200, 100, 16), archi_5(22, "Architektura", 5, 220, 150, 18), archiw_5(24, "Archi. Wnêtrz", 5, 220, 150, 20), logi_6(25, "Logistyka Transportu", 6, 240, 150, 20), trans_6(27, "Trans. Przemys³owy", 6, 240, 150, 22), gig_7(28, "Górnictwo i Geologia", 7, 260, 150, 22), inzb_7(30,"In¿. Bezp.", 7, 280, 150, 24), chem_8(32, "Chemia", 8, 300, 200, 26), biotech_8(33, "Biotechnologia", 8, 300, 200, 26), tech_8(35, "Tech. Chem.", 8, 320, 200, 28), mat_9(38, "Matematyka", 9, 350, 200, 35), inf_9(40, "Informatyka", 9, 400, 200, 50);
void nazwy();
Gracz ruch(Gracz g, Gracz p, RenderWindow & monopoly);
Gracz turagracza(Gracz g, Gracz p, RenderWindow& monopoly);
void gra() {
	int liczniktur = 1;
	RenderWindow monopoly_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	monopoly_w.setFramerateLimit(60);

	Font tura, kasa;
	tura.loadFromFile("Cooper Black Regular.ttf");
	kasa.loadFromFile("Cooper Black Regular.ttf");

	Text tura_t, kasa_t;
	tura_t.setFont(tura);
	tura_t.setFillColor(Color::Blue);
	tura_t.setPosition(Vector2f(100, 825));
	kasa_t.setFont(kasa);
	kasa_t.setFillColor(Color::Blue);
	kasa_t.setPosition(Vector2f(800, 850));

	Texture plansza, bos, strefastudenta, start, wezwanie, ms_inf, ms_mat, aei_air, aei_inf, e_mech, e_energetyka, e_inf, mt_mechibud, mt_inzmat, mt_zarziinzprod, budo_budownictwo, budo_budopodz, budo_zarziinzprod, arch_architektura, arch_archiwnetrz, trans_logistyka, trans_transprzemyslowy, gorn_gornigeo, gorn_inzbezp, chem_chemia, chem_biotech, chem_techchem, piast, karlik, solaris, elektron, impreza, afterek, alo_rybnik, alo_gliwice, dzien_rektorski, koniec_tury, g1, g2;
	plansza.loadFromFile("plansza.jpg");

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

	Sprite plansza_s, bos_s, strefastudenta_s, start_s, wezwanie_s, ms_inf_s, ms_mat_s, aei_air_s, aei_inf_s, e_mech_s, e_energetyka_s, e_inf_s, mt_mechibud_s, mt_inzmat_s, mt_zarziinzprod_s, budo_budownictwo_s, budo_budopodz_s, budo_zarziinzprod_s, arch_architektura_s, arch_archiwnetrz_s, trans_logistyka_s, trans_transprzemyslowy_s, gorn_gornigeo_s, gorn_inzbezp_s, chem_chemia_s, chem_biotech_s, chem_techchem_s, piast_s, karlik_s, solaris_s, elektron_s, impreza_s, afterek_s, alo_rybnik_s, alo_gliwice_s, dzien_rektorski_1_s, dzien_rektorski_2_s, dzien_rektorski_3_s, dzien_rektorski_4_s, dzien_rektorski_5_s, dzien_rektorski_6_s, koniec_tury_s;
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
	ms_mat_s.setTexture(ms_mat);
	ms_mat_s.setPosition(Vector2f(771, 550));
	ms_mat_s.setRotation(-90);
	aei_air_s.setTexture(aei_air);
	aei_air_s.setPosition(Vector2f(711, 671));
	aei_air_s.setRotation(0);
	aei_inf_s.setTexture(aei_inf);
	aei_inf_s.setPosition(Vector2f(591, 671));
	aei_inf_s.setRotation(0);
	e_mech_s.setTexture(e_mech);
	e_mech_s.setPosition(Vector2f(411, 671));
	e_mech_s.setRotation(0);
	e_energetyka_s.setTexture(e_energetyka);
	e_energetyka_s.setPosition(Vector2f(291, 671));
	e_energetyka_s.setRotation(0);
	e_inf_s.setTexture(e_inf);
	e_inf_s.setPosition(Vector2f(230, 671));
	e_inf_s.setRotation(0);
	mt_mechibud_s.setTexture(mt_mechibud);
	mt_mechibud_s.setPosition(Vector2f(229, 611));
	mt_mechibud_s.setRotation(90);
	mt_inzmat_s.setTexture(mt_inzmat);
	mt_inzmat_s.setPosition(Vector2f(229, 491));
	mt_inzmat_s.setRotation(90);
	mt_zarziinzprod_s.setTexture(mt_zarziinzprod);
	mt_zarziinzprod_s.setPosition(Vector2f(229, 431));
	mt_zarziinzprod_s.setRotation(90);
	budo_budownictwo_s.setTexture(budo_budownictwo);
	budo_budownictwo_s.setPosition(Vector2f(229, 311));
	budo_budownictwo_s.setRotation(90);
	budo_budopodz_s.setTexture(budo_budopodz);
	budo_budopodz_s.setPosition(Vector2f(229, 191));
	budo_budopodz_s.setRotation(90);
	budo_zarziinzprod_s.setTexture(budo_zarziinzprod);
	budo_zarziinzprod_s.setPosition(Vector2f(229, 130));
	budo_zarziinzprod_s.setRotation(90);
	arch_architektura_s.setTexture(arch_architektura);
	arch_architektura_s.setPosition(Vector2f(230, 0));
	arch_architektura_s.setRotation(0);
	arch_archiwnetrz_s.setTexture(arch_archiwnetrz);
	arch_archiwnetrz_s.setPosition(Vector2f(351, 0));
	arch_archiwnetrz_s.setRotation(0);
	trans_logistyka_s.setTexture(trans_logistyka);
	trans_logistyka_s.setPosition(Vector2f(411, 0));
	trans_logistyka_s.setRotation(0);
	trans_transprzemyslowy_s.setTexture(trans_transprzemyslowy);
	trans_transprzemyslowy_s.setPosition(Vector2f(531, 0));
	trans_transprzemyslowy_s.setRotation(0);
	gorn_gornigeo_s.setTexture(gorn_gornigeo);
	gorn_gornigeo_s.setPosition(Vector2f(591, 0));
	gorn_gornigeo_s.setRotation(0);
	gorn_inzbezp_s.setTexture(gorn_inzbezp);
	gorn_inzbezp_s.setPosition(Vector2f(711, 0));
	gorn_inzbezp_s.setRotation(0);
	chem_chemia_s.setTexture(chem_chemia);
	chem_chemia_s.setPosition(Vector2f(771, 190));
	chem_chemia_s.setRotation(-90);
	chem_biotech_s.setTexture(chem_biotech);
	chem_biotech_s.setPosition(Vector2f(771, 250));
	chem_biotech_s.setRotation(-90);
	chem_techchem_s.setTexture(chem_techchem);
	chem_techchem_s.setPosition(Vector2f(771, 370));
	chem_techchem_s.setRotation(-90);

	piast_s.setTexture(piast);
	piast_s.setPosition(Vector2f(471, 671));
	piast_s.setRotation(0);
	karlik_s.setTexture(karlik);
	karlik_s.setPosition(Vector2f(229, 371));
	karlik_s.setRotation(90);
	solaris_s.setTexture(solaris);
	solaris_s.setPosition(Vector2f(471, 0));
	solaris_s.setRotation(0);
	elektron_s.setTexture(elektron);
	elektron_s.setPosition(Vector2f(771, 430));
	elektron_s.setRotation(-90);

	impreza_s.setTexture(impreza);
	impreza_s.setPosition(Vector2f(531, 671));
	impreza_s.setRotation(0);
	afterek_s.setTexture(afterek);
	afterek_s.setPosition(Vector2f(771, 610));
	afterek_s.setRotation(-90);

	alo_rybnik_s.setTexture(alo_rybnik);
	alo_rybnik_s.setPosition(Vector2f(229, 551));
	alo_rybnik_s.setRotation(90);
	alo_gliwice_s.setTexture(alo_gliwice);
	alo_gliwice_s.setPosition(Vector2f(651, 0));
	alo_gliwice_s.setRotation(0);

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

		monopoly_w.draw(piast_s);
		monopoly_w.draw(karlik_s);
		monopoly_w.draw(solaris_s);
		monopoly_w.draw(elektron_s);

		monopoly_w.draw(impreza_s);
		monopoly_w.draw(afterek_s);

		monopoly_w.draw(alo_rybnik_s);
		monopoly_w.draw(alo_gliwice_s);

		monopoly_w.draw(dzien_rektorski_1_s);
		monopoly_w.draw(dzien_rektorski_2_s);
		monopoly_w.draw(dzien_rektorski_3_s);
		monopoly_w.draw(dzien_rektorski_4_s);
		monopoly_w.draw(dzien_rektorski_5_s);
		monopoly_w.draw(dzien_rektorski_6_s);

		monopoly_w.draw(tura_t);
		monopoly_w.draw(kasa_t);
		monopoly_w.draw(koniec_tury_s);
		monopoly_w.draw(gracz1.g_s);
		monopoly_w.draw(gracz2.g_s);

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
						gracz2 = turagracza(gracz2, gracz1, monopoly_w);
					}
					else {
						tura_t.setString(gracz1.nick);
						kasa_t.setString(to_string(gracz1.Hajs));
						gracz1 = turagracza(gracz1, gracz2, monopoly_w);
					}
				}
			}
		}
		monopoly_w.display();
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
					nazwy();
				}
			}
			if (prodziekan_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					wbot_w.close();
					gracz2.nick = "PRODZIEKAN";
					nazwy();
				}
			}
			if (rektor_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					wbot_w.close();
					gracz2.nick = "REKTOR";
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
Gracz ruch(Gracz g, Gracz p, RenderWindow & monopoly) {
	g.Polozenie+=RNG(2, 12);
	if (g.Polozenie > 40) {
		g.Polozenie -= 40;
		g.Hajs += 200;
	}
	if (g.Polozenie == 1) {
		g.g_s.setPosition(Vector2f(start.x, start.y));
	}
	if (g.Polozenie == 2) {
		g.g_s.setPosition(Vector2f(aei_1.x, aei_1.y));
		if (air_1.GraczID == 0) {
			zakup_kierunku(&g, &air_1);
		}
		else {
			zaplata(&p, &g, &air_1);
		}
	}
	if (g.Polozenie == 3) {
		g.g_s.setPosition(Vector2f(dr_1.x, dr_1.y));
	}
	if (g.Polozenie == 4) {
		g.g_s.setPosition(Vector2f(aei_2.x, aei_2.y));
		if (inf_1.GraczID == 0) {
			zakup_kierunku(&g, &inf_1);
		}
		else {
			zaplata(&p, &g, &inf_1);
		}
	}
	if (g.Polozenie == 5) {
		g.g_s.setPosition(Vector2f(impreza.x, impreza.y));
	}
	if (g.Polozenie == 6) {
		g.g_s.setPosition(Vector2f(piast.x, piast.y));
	}
	if (g.Polozenie == 7) {
		g.g_s.setPosition(Vector2f(e_1.x, e_1.y));
		if (mech_2.GraczID == 0) {
			zakup_kierunku(&g, &mech_2);
		}
		else {
			zaplata(&p, &g, &mech_2);
		}
	}
	if (g.Polozenie == 8) {
		g.g_s.setPosition(Vector2f(dr_2.x, dr_2.y));
	}
	if (g.Polozenie == 9) {
		g.g_s.setPosition(Vector2f(e_2.x, e_2.y));
		if (energ_2.GraczID == 0) {
			zakup_kierunku(&g, &energ_2);
		}
		else {
			zaplata(&p, &g, &energ_2);
		}
	}
	if (g.Polozenie == 10) {
		g.g_s.setPosition(Vector2f(e_3.x, e_3.y));
		if (inf_2.GraczID == 0) {
			zakup_kierunku(&g, &inf_2);
		}
		else {
			zaplata(&p, &g, &inf_2);
		}
	}
	if (g.Polozenie == 11) {
		g.g_s.setPosition(Vector2f(bos.x, bos.y));
	}
	if (g.Polozenie == 12) {
		g.g_s.setPosition(Vector2f(mt_1.x, mt_1.y));
		if (mech_3.GraczID == 0) {
			zakup_kierunku(&g, &mech_3);
		}
		else {
			zaplata(&p, &g, &mech_3);
		}
	}
	if (g.Polozenie == 13) {
		g.g_s.setPosition(Vector2f(alo_r.x, alo_r.y));
	}
	if (g.Polozenie == 14) {
		g.g_s.setPosition(Vector2f(mt_2.x, mt_2.y));
		if (inz_3.GraczID == 0) {
			zakup_kierunku(&g, &inz_3);
		}
		else {
			zaplata(&p, &g, &inz_3);
		}
	}
	if (g.Polozenie == 15) {
		g.g_s.setPosition(Vector2f(mt_3.x, mt_3.y));
		if (zarz_3.GraczID == 0) {
			zakup_kierunku(&g, &zarz_3);
		}
		else {
			zaplata(&p, &g, &zarz_3);
		}
	}
	if (g.Polozenie == 16) {
		g.g_s.setPosition(Vector2f(karlik.x, karlik.y));
	}
	if (g.Polozenie == 17) {
		g.g_s.setPosition(Vector2f(budo_1.x, budo_1.y));
		if (budo_4.GraczID == 0) {
			zakup_kierunku(&g, &budo_4);
		}
		else {
			zaplata(&p, &g, &budo_4);
		}
	}
	if (g.Polozenie == 18) {
		g.g_s.setPosition(Vector2f(dr_3.x, dr_3.y));
	}
	if (g.Polozenie == 19) {
		g.g_s.setPosition(Vector2f(budo_2.x, budo_2.y));
		if (budop_4.GraczID == 0) {
			zakup_kierunku(&g, &budop_4);
		}
		else {
			zaplata(&p, &g, &budop_4);
		}
	}
	if (g.Polozenie == 20) {
		g.g_s.setPosition(Vector2f(budo_3.x, budo_3.y));
		if (zarz_4.GraczID == 0) {
			zakup_kierunku(&g, &zarz_4);
		}
		else {
			zaplata(&p, &g, &zarz_4);
		}
	}
	if (g.Polozenie == 21) {
		g.g_s.setPosition(Vector2f(strefa.x, strefa.y));
	}
	if (g.Polozenie == 22) {
		g.g_s.setPosition(Vector2f(arch_1.x, arch_1.y));
		if (archi_5.GraczID == 0) {
			zakup_kierunku(&g, &archi_5);
		}
		else {
			zaplata(&p, &g, &archi_5);
		}
	}
	if (g.Polozenie == 23) {
		g.g_s.setPosition(Vector2f(dr_4.x, dr_4.y));
	}
	if (g.Polozenie == 24) {
		g.g_s.setPosition(Vector2f(arch_2.x, arch_2.y));
		if (archiw_5.GraczID == 0) {
			zakup_kierunku(&g, &archiw_5);
		}
		else {
			zaplata(&p, &g, &archiw_5);
		}
	}
	if (g.Polozenie == 25) {
		g.g_s.setPosition(Vector2f(trans_1.x, trans_1.y));
		if (logi_6.GraczID == 0) {
			zakup_kierunku(&g, &logi_6);
		}
		else {
			zaplata(&p, &g, &logi_6);
		}
	}
	if (g.Polozenie == 26) {
		g.g_s.setPosition(Vector2f(solaris.x, solaris.y));
	}
	if (g.Polozenie == 27) {
		g.g_s.setPosition(Vector2f(trans_2.x, trans_2.y));
		if (trans_6.GraczID == 0) {
			zakup_kierunku(&g, &trans_6);
		}
		else {
			zaplata(&p, &g, &trans_6);
		}
	}
	if (g.Polozenie == 28) {
		g.g_s.setPosition(Vector2f(gorn_1.x, gorn_1.y));
		if (gig_7.GraczID == 0) {
			zakup_kierunku(&g, &gig_7);
		}
		else {
			zaplata(&p, &g, &gig_7);
		}
	}
	if (g.Polozenie == 29) {
		g.g_s.setPosition(Vector2f(alo_g.x, alo_g.y));
	}
	if (g.Polozenie == 30) {
		g.g_s.setPosition(Vector2f(gorn_2.x, gorn_2.y));
		if (inzb_7.GraczID == 0) {
			zakup_kierunku(&g, &inzb_7);
		}
		else {
			zaplata(&p, &g, &inzb_7);
		}
	}
	if (g.Polozenie == 31) {
		g.g_s.setPosition(Vector2f(wezwanie.x, wezwanie.y));
	}
	if (g.Polozenie == 32) {
		g.g_s.setPosition(Vector2f(chem_1.x, chem_1.y));
		if (chem_8.GraczID == 0) {
			zakup_kierunku(&g, &chem_8);
		}
		else {
			zaplata(&p, &g, &chem_8);
		}
	}
	if (g.Polozenie == 33) {
		g.g_s.setPosition(Vector2f(chem_2.x, chem_2.y));
		if (biotech_8.GraczID == 0) {
			zakup_kierunku(&g, &biotech_8);
		}
		else {
			zaplata(&p, &g, &biotech_8);
		}
	}
	if (g.Polozenie == 34) {
		g.g_s.setPosition(Vector2f(dr_5.x, dr_5.y));
	}
	if (g.Polozenie == 35) {
		g.g_s.setPosition(Vector2f(chem_3.x, chem_3.y));
		if (tech_8.GraczID == 0) {
			zakup_kierunku(&g, &tech_8);
		}
		else {
			zaplata(&p, &g, &tech_8);
		}
	}
	if (g.Polozenie == 36) {
		g.g_s.setPosition(Vector2f(elektron.x, elektron.y));
	}
	if (g.Polozenie == 37) {
		g.g_s.setPosition(Vector2f(dr_6.x, dr_6.y));
	}
	if (g.Polozenie == 38) {
		g.g_s.setPosition(Vector2f(ms_1.x, ms_1.y));
		if (mat_9.GraczID == 0) {
			zakup_kierunku(&g, &mat_9);
		}
		else {
			zaplata(&p, &g, &mat_9);
		}
	}
	if (g.Polozenie == 39) {
		g.g_s.setPosition(Vector2f(afterek.x, afterek.y));
	}
	if (g.Polozenie == 40) {
		g.g_s.setPosition(Vector2f(ms_2.x, ms_2.y));
		if (inf_9.GraczID == 0) {
			zakup_kierunku(&g, &inf_9);
		}
		else {
			zaplata(&p, &g, &inf_9);
		}
	}
	return g;
}
Gracz turagracza(Gracz g, Gracz p, RenderWindow& monopoly) {
	g = ruch(g, p, monopoly);
	return g;
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
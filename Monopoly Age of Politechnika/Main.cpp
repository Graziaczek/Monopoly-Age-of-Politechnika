#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Nag³ówek.h"

using namespace sf;
using namespace std;
//Gracz g1;
//Gracz g2;
void gra() {
	RenderWindow monopoly_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	monopoly_w.setFramerateLimit(60);

	Texture plansza, bos, strefastudenta, start, wezwanie, ms_inf, ms_mat, aei_air, aei_inf, e_mech, e_energetyka, e_inf, mt_mechibud, mt_inzmat, mt_zarziinzprod, budo_budownictwo, budo_budopodz, budo_zarziinzprod, arch_architektura, arch_archiwnetrz, trans_logistyka, trans_transprzemyslowy, gorn_gornigeo, gorn_inzbezp, chem_chemia, chem_biotech, chem_techchem, piast, karlik, solaris, elektron, impreza, afterek, alo_rybnik, alo_gliwice, dzien_rektorski;
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

	Sprite plansza_s, bos_s, strefastudenta_s, start_s, wezwanie_s, ms_inf_s, ms_mat_s, aei_air_s, aei_inf_s, e_mech_s, e_energetyka_s, e_inf_s, mt_mechibud_s, mt_inzmat_s, mt_zarziinzprod_s, budo_budownictwo_s, budo_budopodz_s, budo_zarziinzprod_s, arch_architektura_s, arch_archiwnetrz_s, trans_logistyka_s, trans_transprzemyslowy_s, gorn_gornigeo_s, gorn_inzbezp_s, chem_chemia_s, chem_biotech_s, chem_techchem_s, piast_s, karlik_s, solaris_s, elektron_s, impreza_s, afterek_s, alo_rybnik_s, alo_gliwice_s, dzien_rektorski_1_s, dzien_rektorski_2_s, dzien_rektorski_3_s, dzien_rektorski_4_s, dzien_rektorski_5_s, dzien_rektorski_6_s;
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

		monopoly_w.display();
		while (monopoly_w.pollEvent(event)) {
			if (event.type == Event::Closed) {
				monopoly_w.close();
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
					gra();
				}
			}
			if (prodziekan_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					wbot_w.close();
					gra();
				}
			}
			if (rektor_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					wbot_w.close();
					gra();
				}
			}
		}
	}
}
void whotseat() {
	RenderWindow whotseat_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Ustawienia - Wybor Nicków", Style::Default);
	Texture ustawienia;
	ustawienia.loadFromFile("Ustawienia.jpg");
	Sprite ustawienia_s;
	ustawienia_s.setTexture(ustawienia);
	while (whotseat_w.isOpen()) {
		Event event;
		whotseat_w.clear(Color::Black);
		whotseat_w.draw(ustawienia_s);
		whotseat_w.display();
		while (whotseat_w.pollEvent(event)) {
			if (event.type == Event::Closed) {
				whotseat_w.close();
			}
			if (event.type == Event::KeyPressed) {
				//g1->nick=getch();
			}
		}
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
					gra();
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
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;
void gra() {
	RenderWindow monopoly_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	monopoly_w.setFramerateLimit(60);
	Texture plansza, bos, strefastudenta, start, wezwanie, ms_inf, ms_mat, aei_air, aei_inf, e_mech, e_energetyka, e_inf, alo_rybnik, alo_gliwice;
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
	alo_rybnik.loadFromFile("alo_rybnik.jpg");
	alo_gliwice.loadFromFile("alo_gliwice.jpg");

	Sprite plansza_s, bos_s, strefastudenta_s, start_s, wezwanie_s, ms_inf_s, ms_mat_s, aei_air_s, aei_inf_s, e_mech_s, e_energetyka_s, e_inf_s, alo_rybnik_s, alo_gliwice_s;
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
	alo_rybnik_s.setTexture(alo_rybnik);
	alo_rybnik_s.setPosition(Vector2f(229, 551));
	alo_rybnik_s.setRotation(90);
	alo_gliwice_s.setTexture(alo_gliwice);
	alo_gliwice_s.setPosition(Vector2f(710, 129));
	alo_gliwice_s.setRotation(180);

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
		monopoly_w.draw(alo_rybnik_s);
		monopoly_w.draw(alo_gliwice_s);

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
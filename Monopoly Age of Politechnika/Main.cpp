#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;
void gra() {
	RenderWindow monopoly_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	monopoly_w.setFramerateLimit(60);
	Texture plansza, bos, strefastudenta, start;
	plansza.loadFromFile("plansza.jpg");
	bos.loadFromFile("bos.jpg");
	strefastudenta.loadFromFile("strefa_studenta.jpg");
	start.loadFromFile("start.jpg");
	Sprite plansza_s, bos_s, strefastudenta_s, start_s;
	plansza_s.setTexture(plansza);
	bos_s.setTexture(bos);
	bos_s.setPosition(Vector2f(100, 671));
	strefastudenta_s.setTexture(strefastudenta);
	strefastudenta_s.setPosition(Vector2f(100, 0));
	start_s.setTexture(start);
	start_s.setPosition(Vector2f(771, 671));
	while (monopoly_w.isOpen()) {
		Event event;
		monopoly_w.clear(Color::Black);
		monopoly_w.draw(plansza_s);
		monopoly_w.draw(bos_s);
		monopoly_w.draw(strefastudenta_s);
		monopoly_w.draw(start_s);
		monopoly_w.display();
		while (monopoly_w.pollEvent(event)) {
			if (event.type == Event::Closed) {
				monopoly_w.close();
			}
		}
	}
}
void ustawienia() {
	RenderWindow ustawienia_w(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Ustawienia", Style::Default);
	Texture ustawienia, hotseat, bot, doktorant, prodziekan, rektor;
	ustawienia.loadFromFile("Ustawienia.jpg");
	hotseat.loadFromFile("Hot-Seat.jpg");
	bot.loadFromFile("Bot.jpg");
	doktorant.loadFromFile("Doktorant.jpg");
	prodziekan.loadFromFile("Prodziekan.jpg");
	rektor.loadFromFile("Rektor.jpg");
	Sprite ustawienia_s, hotseat_s, bot_s, doktorant_s, prodziekan_s, rektor_s;
	ustawienia_s.setTexture(ustawienia);
	hotseat_s.setTexture(hotseat);
	hotseat_s.setPosition(Vector2f(375, 300));
	bot_s.setTexture(bot);
	bot_s.setPosition(Vector2f(375, 600));
	doktorant_s.setTexture(doktorant);
	prodziekan_s.setTexture(prodziekan);
	rektor_s.setTexture(rektor);
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
					gra();
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
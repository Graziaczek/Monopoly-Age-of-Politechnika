#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;
void gra() {
	RenderWindow monopoly(VideoMode(1000, 1000), "Monopoly: Age of Politechnika - Nowa Gra", Style::Default);
	monopoly.setFramerateLimit(60);
	while (monopoly.isOpen()) {
		Event event;
		monopoly.clear(Color::Black);
		monopoly.display();
		while (monopoly.pollEvent(event)) {
			if (event.type == Event::Closed) {
				monopoly.close();
			}
		}
	}
}
int main() {
	RenderWindow window(VideoMode(1000, 1000), "Monopoly: Age of Politechnika",Style::Default);
	window.setFramerateLimit(60);
	Texture tytul;
	Texture nowagra;
	tytul.loadFromFile("Nazwa.jpg");
	nowagra.loadFromFile("NowaGra.jpg");
	Sprite tytul_s;
	Sprite nowagra_s;
	tytul_s.setTexture(tytul);
	nowagra_s.setTexture(nowagra);
	nowagra_s.setPosition(Vector2f(375, 300));
	while (window.isOpen()) {
		Event event;
		window.clear(Color::Black);
		window.draw(tytul_s);
		window.draw(nowagra_s);
		window.display();
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (nowagra_s.getGlobalBounds().Rect::contains(event.mouseButton.x, event.mouseButton.y)) {
				if (event.type == Event::MouseButtonPressed) {
					window.close();
					gra();
				}
			}
		}
	}
	return 0;
}
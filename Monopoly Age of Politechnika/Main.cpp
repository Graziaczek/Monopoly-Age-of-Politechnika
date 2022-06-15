#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;
int main() {
	RenderWindow window(VideoMode(1000, 800), "Monopoly: Age of Politechnika",Style::Default);
	window.setFramerateLimit(60);
	Texture tytul;
	Texture nowagra;
	tytul.loadFromFile("Nazwa.jpg");
	nowagra.loadFromFile("NowaGra.jpg");
	Sprite tytul_s;
	Sprite nowagra_s;
	tytul_s.setTexture(tytul);
	tytul_s.setPosition(Vector2f(300,100));
	nowagra_s.setTexture(nowagra);
	nowagra_s.setPosition(Vector2f(375, 300));
	nowagra_s.setScale(0.5,0.5);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		window.clear(Color::Black);
		window.draw(tytul_s);
		window.draw(nowagra_s);
		if ();
		window.display();
	}
	return 0;
}
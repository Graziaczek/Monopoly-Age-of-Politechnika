#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
	sf::Window window(sf::VideoMode(1200, 800), "Monopoly: Age of Politechnika",sf::Style::Default);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
	return 0;
}
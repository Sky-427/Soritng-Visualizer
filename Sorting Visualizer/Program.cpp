#include "Program.h"

void Program::run() {
	sf::RenderWindow window(sf::VideoMode(900, 700), "Sorting Visualizer", sf::Style::Close);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		sf::Event evt;
		while (window.pollEvent(evt)) {
			switch (evt.type) {
				case sf::Event::Closed: {
					window.close();
				}
			}
		}
		window.clear();
		window.display();
	}
}
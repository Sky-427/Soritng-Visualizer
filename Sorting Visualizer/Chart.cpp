#include "Chart.h"
#include <iostream>

void Chart::make() {
	if (part == 1) {
		for (int i = 0; i < 960; ++i) {
			float randomh = 1 + rand() % 600;
			float index = i;
			rect.setPosition({ index,630 }); rect.setSize({6.0,randomh});
			rect.setFillColor(sf::Color::Yellow); rect.setRotation(180);
			lines.push_back(rect);
			if (i == 959)
				part = 2;
		}
	}
}

void Chart::drawTo(sf::RenderWindow& window) {
	for (auto& it : lines) {
		window.draw(it);
	}
}

void Chart::randomize() {
	for (int i = 0; i < 960; ++i) {
		int index = 0 + rand() % (959 + 1);
		sf::RectangleShape temp;
		temp.setSize(lines[index].getSize());
		lines[index].setSize(lines[i].getSize());
		lines[i].setSize(temp.getSize());
	}
}
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Chart{
public:
	void make();
	void drawTo(sf::RenderWindow&);
	void randomize();

private:
	std::vector<sf::RectangleShape> lines; int part = 1;
	float posx; float height; sf::RectangleShape rect;
};
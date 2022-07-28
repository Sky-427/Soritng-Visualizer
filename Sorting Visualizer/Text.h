#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Text{
public:
	Text() {
		font.loadFromFile("C:/Users/tarun/source/repos/Sorting Visualizer/resource/Yaahowu Bold.ttf");
		text.setFont(font); text.setCharacterSize(14); text.setPosition({0,670});
	}
	void setString(std::string);
	void setPosition_(sf::Vector2f);
	void setPosition(Text, float, float);
	void drawTo(sf::RenderWindow&);
	sf::Vector2f getPosition();
	float size();
	std::string getString();
	sf::Font getFont();
	void setFont(sf::Font);
	friend class Program;
	friend class bubbleSort;
private:
	sf::Text text; sf::Font font;
};
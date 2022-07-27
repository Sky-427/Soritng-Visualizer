#pragma once
#include <SFML/Graphics.hpp>
class Text{
public:
	Text() {
		font.loadFromFile("C:/Users/tarun/source/repos/Sorting Visualizer/resource/Yaahowu Bold.ttf");
		text.setFont(font); text.setCharacterSize(14);
	}
	void setString(std::string);
	void setPosition_(sf::Vector2f);
	void setPosition(Text, float, float);
	void drawTo(sf::RenderWindow&);
	sf::Vector2f getPosition();
	float size();
private:
	sf::Text text; sf::Font font;
};


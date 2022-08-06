#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
#include <vector>

class Chart{
public:
	int isCalled = 0;
	int compareCounter = 0, readCounter = 0, swapCounter = 0;
	bool working = 0, sorted = 0;
	std::vector<sf::RectangleShape> lines;
	void make();
	void drawTo(sf::RenderWindow&);
	void randomize();
	void textTest(int*,int*,int*,bool*,bool*);
	Text* getArray();
	void up(int*);

private:
	int part = 1;
	float posx; float height; sf::RectangleShape rect;
	Text arr[12];
};
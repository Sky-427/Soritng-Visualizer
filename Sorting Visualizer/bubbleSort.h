#pragma once
#include "Chart.h"
#include "Text.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class bubbleSort{
public:
	void sort(Chart,sf::RenderWindow&);
private:
	std::vector<Text> arr;
};
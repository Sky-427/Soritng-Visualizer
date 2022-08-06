#pragma once
#include "Text.h"
#include "Chart.h"
#include <iostream>
#include <SFML/System.hpp>

class quickSort{
public:
	void recurse(Chart, int, int, sf::RenderWindow&);
	void sort(Chart, int, int, sf::RenderWindow&);
	void partition(Chart, int, int, sf::RenderWindow&);
private:
	std::vector<Text> arr; int a = 0;
};


#pragma once
#include "Text.h"
#include "Chart.h"
#include <iostream>

class insertionSort:private Text{
public:
	void sort(Chart, sf::RenderWindow&);
private:
	std::vector<Text> arr;
};


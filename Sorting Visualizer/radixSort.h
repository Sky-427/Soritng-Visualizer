#pragma once
#include "Chart.h"

class radixSort{
public:
	void radixsort(Chart*, sf::RenderWindow&);
	void countSort(Chart*, int, int, sf::RenderWindow&);
	int getMax(Chart*, int n);
private:
	Chart ching;
};


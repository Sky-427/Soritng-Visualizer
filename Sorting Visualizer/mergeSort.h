#pragma once
#include "Chart.h"

class mergeSort{
public:
	void mergesort(Chart*,int,int,sf::RenderWindow&);
	void merge(Chart*, int, int, int, sf::RenderWindow&);
private:
	Chart ching;
};
#pragma once
#include <SFML/Graphics.hpp>

class Program{
public:
	void run();
private:
	long compareCounter = 0, readCounter = 0, swapCounter = 0;
	bool working = 0, sorted = 0; int count = 0;
};


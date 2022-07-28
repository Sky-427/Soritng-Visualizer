#pragma once
#include <SFML/Graphics.hpp>
class bubbleSort;
class Program{
public:
	void run();
	friend class bubbleSort;
private:
	long compareCounter = 0, readCounter = 0, swapCounter = 0;
	bool working = 0, sorted = 0; int count = 0;
};


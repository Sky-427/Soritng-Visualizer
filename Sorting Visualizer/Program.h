#pragma once
#include <SFML/Graphics.hpp>
class bubbleSort;
class Program{
public:
	void run();
	friend class bubbleSort;
private:
	bool working = 0, sorted = 0; int count = 0;
	bool reset = false;
};


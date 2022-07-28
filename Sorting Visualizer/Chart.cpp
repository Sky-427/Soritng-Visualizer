#include "Chart.h"
#include <iostream>

void Chart::make() {
	if (part == 1) {
		for (int i = 0; i < 900; ++i) {
			float randomh = 1 + rand() % 600;
			float index = i+30;
			rect.setPosition({ index,630 }); rect.setSize({6.0,randomh});
			rect.setFillColor(sf::Color::Yellow); rect.setRotation(180);
			lines.push_back(rect);
			if (i == 899)
				part = 2;
		}
	}
}

void Chart::drawTo(sf::RenderWindow& window) {
	for (auto& it : lines) {
		window.draw(it);
	}
}

void Chart::randomize() {
	for (int i = 0; i < 900; ++i) {
		int index = 0 + rand() % (899 + 1);
		sf::RectangleShape temp;
		temp.setSize(lines[index].getSize());
		lines[index].setSize(lines[i].getSize());
		lines[i].setSize(temp.getSize());
	}
}

void Chart::textTest(int compareCounter, int readCounter, int swapCounter, bool working, bool sorted) {
	arr[0].setString("Select Algo : "); arr[0].setPosition_({ 10,670 });
	if (isCalled == 0) {
		arr[1].setString("Bubble Sort  | ");
		isCalled++;
	}
	arr[1].setPosition(arr[0], 6, arr[0].size());
	arr[2].setString(" Compare count : "); arr[2].setPosition(arr[1], 6, arr[1].size());
	arr[3].setString(std::to_string(compareCounter) + "  | "); arr[3].setPosition(arr[2], 7, arr[2].size());
	arr[4].setString("Read count : "); arr[4].setPosition(arr[3], 7, arr[3].size());
	arr[5].setString(std::to_string(readCounter) + "  | "); arr[5].setPosition(arr[4], 7, arr[4].size());
	arr[6].setString("Swap count : "); arr[6].setPosition(arr[5], 7, arr[5].size());
	arr[7].setString(std::to_string(swapCounter) + "  | "); arr[7].setPosition(arr[6], 7, arr[6].size());
	arr[8].setString(" Working : "); arr[8].setPosition(arr[7], 7, arr[7].size());
	if (working == 1) {
		arr[9].setString("Yes  | "); arr[9].setPosition(arr[8], 7, arr[8].size());
	}
	else {
		arr[9].setString("No  | "); arr[9].setPosition(arr[8], 7, arr[8].size());
	}
	arr[10].setString("Sorted : "); arr[10].setPosition(arr[9], 7, arr[9].size());
	if (sorted == 1) {
		arr[11].setString("Yes  | "); arr[11].setPosition(arr[10], 7, arr[10].size());
	}
	else {
		arr[11].setString("No  | "); arr[11].setPosition(arr[10], 7, arr[10].size());
	}
}

Text* Chart::getArray() {
	return arr;
}

void Chart::up(int *counter) {
	switch (*counter){
		case 0: {
			arr[1].setString("Bubble Sort  | ");
			break;
		}
		case 1: {
			arr[1].setString("Selection Sort  | ");
			break;
		}
		case 2: {
			arr[1].setString("Insertion Sort  | ");
			break;
		}
		case 3: {
			arr[1].setString("Merge Sort  | ");
			break;
		}
		case 4: {
			arr[1].setString("Quick Sort  | ");
			break;
		}
		case 5: {
			arr[1].setString("Radix Sort  | ");
			break;
		}
		default: {
			if (*counter > 5) {
				*counter = 5;
			}
			if (*counter < 0) {
				*counter = 0;
			}
		}
	}
}
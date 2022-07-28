#include "insertionSort.h"

void insertionSort::sort(Chart ch, sf::RenderWindow& window) {
	int size = ch.lines.size(); float key;
	Text* temp_arr = ch.getArray();
	for (int i = 1; i < size; ++i) {
		++ch.readCounter; ++ch.compareCounter;
		key = ch.lines[i].getSize().y;
		int j = i - 1;
		while (j >= 0 && ch.lines[j].getSize().y > key) {
			++ch.readCounter; ++ch.swapCounter;
			ch.lines[j + 1].setSize({6.0,ch.lines[j].getSize().y});
			--j;
		}
		ch.lines[j + 1].setSize({6.0,key});
		window.clear();
		ch.textTest(ch.compareCounter, ch.readCounter, ch.swapCounter, ch.working, ch.sorted);
		for (int i = 0; i < 12; ++i) {
			temp_arr[i].drawTo(window);
		}
		ch.drawTo(window);
		window.display();
	}
	ch.working = 0; ch.sorted = 1;
}
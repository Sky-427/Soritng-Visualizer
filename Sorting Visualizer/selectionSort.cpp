#include "selectionSort.h"

void selectionSort::sort(Chart ch, sf::RenderWindow& window) {
	Text temp;
	int size = ch.lines.size(); int min_;
	Text* temp_arr = ch.getArray();
	for (int i = 0; i < size - 1; ++i) {
		++ch.readCounter;
		min_ = i;
		for (int j = i + 1; j < size; ++j) {
			++ch.readCounter;
			if (ch.lines[j].getSize().y < ch.lines[min_].getSize().y) {
				min_ = j;
				++ch.compareCounter; ++ch.swapCounter;
			}
		}
		float pos = ch.lines[i].getSize().y; ch.swapCounter++;
		ch.lines[i].setSize({ 6.0,ch.lines[min_].getSize().y });
		ch.lines[min_].setSize({ 6.0,pos });
		window.clear();
		ch.textTest(ch.compareCounter, ch.readCounter, ch.swapCounter, ch.working, ch.sorted);
		for (int i = 0; i < 12; ++i) {
			temp_arr[i].drawTo(window);
		}
		ch.drawTo(window);
		window.display();
	}
}
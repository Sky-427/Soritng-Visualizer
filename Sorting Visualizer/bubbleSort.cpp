#include "bubbleSort.h"

Text temp;
void bubbleSort::sort(Chart ch, sf::RenderWindow& window) {
	int size = ch.lines.size();
	Text* temp_arr = ch.getArray();
	while (size--) {
		for (int i = 0; i < size - 1; ++i) {
			if (ch.lines[i].getSize().y > ch.lines[i + 1].getSize().y) {
				float pos = ch.lines[i].getSize().y;
				ch.lines[i].setSize({ 6.0,ch.lines[i + 1].getSize().y });
				ch.lines[i + 1].setSize({ 6.0,pos });
				ch.compareCounter++; ch.readCounter++; ch.swapCounter++;
			}
			ch.compareCounter++;
		}
		ch.compareCounter++;
		window.clear();
		ch.textTest(&ch.compareCounter, &ch.readCounter, &ch.swapCounter, &ch.working, &ch.sorted);
		for (int i = 0; i < 12; ++i) {
			temp_arr[i].drawTo(window);
		}
		ch.drawTo(window);
		window.display();
	}
	ch.working = 0; ch.sorted = 1;
}
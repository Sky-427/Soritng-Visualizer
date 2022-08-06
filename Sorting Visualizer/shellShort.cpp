#include "shellShort.h"

void shellShort::sort(Chart ch, sf::RenderWindow& window) {
	Text* temp_arr = ch.getArray();
	int n = ch.lines.size();
	for (int i = n / 2; i > 0; i=i/2) {
		++ch.readCounter;
		for (int j = i; j < n; j += 1) {
			++ch.readCounter;
			float temp = ch.lines[j].getSize().y; ++ch.compareCounter;
			int k;
			for (k = j; k >= i && ch.lines[k - i].getSize().y > temp; k -= i) {
				ch.lines[k].setSize({ 6.0,ch.lines[k - i].getSize().y });
				++ch.swapCounter;
			}
			ch.lines[k].setSize({ 6.0,temp }); ++ch.swapCounter;
			window.clear();
			ch.textTest(&ch.compareCounter, &ch.readCounter, &ch.swapCounter, &ch.working, &ch.sorted);
			for (int i = 0; i < 12; ++i) {
				temp_arr[i].drawTo(window);
			}
			ch.lines[k].setFillColor(sf::Color::Red);
			ch.drawTo(window);
			ch.lines[k].setFillColor(sf::Color::Yellow);
			window.display();
		}
	}
}
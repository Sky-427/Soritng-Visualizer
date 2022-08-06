#include "quickSort.h"

void quickSort::sort(Chart ch, int left, int right, sf::RenderWindow& window) {
	ch.working = 1;
	if (left < right) {
		++ch.compareCounter;
		partition(ch, left, right, window);
		quickSort::sort(ch, left,a-1,window);
		quickSort::sort(ch,a+1,right,window);
	}
}

void quickSort::partition(Chart ch, int left, int right, sf::RenderWindow&window) {
	Text* temp_arr = ch.getArray();
	float piv = ch.lines[right].getSize().y; int i = left - 1;
	for( int j = left; j <= right-1; ++j) {
		if (ch.lines[j].getSize().y < piv) {
			++i; float temp = ch.lines[i].getSize().y;
			ch.lines[i].setSize({6.0,ch.lines[j].getSize().y});
			ch.lines[j].setSize({ 6.0,temp }); ++ch.compareCounter; ++ch.readCounter;
		}
	}
	float temp = ch.lines[i + 1].getSize().y;
	ch.lines[i + 1].setSize({6.0,ch.lines[right].getSize().y});
	ch.lines[right].setSize({ 6.0,temp }); ++ch.swapCounter;
	a = i + 1; ++ch.readCounter;
}

void quickSort::recurse(Chart ch, int left, int right, sf::RenderWindow& window) {
	Text* temp_arr = ch.getArray();
	quickSort::sort(ch, left, right, window);
	window.clear();
	ch.textTest(&ch.compareCounter, &ch.readCounter, &ch.swapCounter, &ch.working, &ch.sorted);
	quickSort::partition(ch,left,right,window);
	for (int i = 0; i < 12; ++i) {
		temp_arr[i].drawTo(window);
	}
	ch.drawTo(window);
	window.display();
}
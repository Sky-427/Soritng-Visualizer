#include "radixSort.h"

void radixSort::sort(Chart ch, sf::RenderWindow& window) {
	Text* temp_arr = ch.getArray();
	float m=ch.lines[0].getSize().y;
	for (int i = 1; i < ch.lines.size(); ++i) {
		if (ch.lines[i].getSize().y > m) {
			m = ch.lines[i].getSize().y;
		}
	}
	window.clear();
	ch.textTest(&ch.compareCounter, &ch.readCounter, &ch.swapCounter, &ch.working, &ch.sorted);
	for (int i = 0; i < 12; ++i) {
		temp_arr[i].drawTo(window);
	}
	for (int i = 1; m / i > 0; i *= 3) {
		const int size = ch.lines.size();
		float* arr = new float[size];
		int j; float* arr1 = new float[3]{0};

		for (int j = 0; j < size; ++j) {
			arr1[(int)(ch.lines[j].getSize().y / i) % 3]++;
		}
		for (int j = 1; j < 3; ++j) {
			arr1[j] += arr1[j - 1];
		}
		for (j = size - 1; j >= 0; --j) {
			arr[(int)arr1[(int)(ch.lines[j].getSize().y / i) % 3] - 1] = ch.lines[j].getSize().y;
			arr1[(int)(arr[j] / i) % 3]--;
		}

		for (int j = 0; j < size; ++i) {
			ch.lines[j].setSize({6.0,arr1[j]});
			++ch.compareCounter; ++ch.swapCounter;
		}

		delete[]arr, arr1;
		ch.drawTo(window);
		window.display();
	}
}
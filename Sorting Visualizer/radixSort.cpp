#include "radixSort.h"

void radixSort::countSort(Chart* ch, int n, int a, sf::RenderWindow& window) {
	Text* temp_arr = (*ch).getArray();
	float *output = new float[n];
	int i; float count[3] = { 0,0,0 };

	for (int i = 0; i < n; ++i) {
		count[(int)((*ch).lines[i].getSize().y / a) % 3]++;
	}

	for (int i = 1; i < 3; ++i) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; --i) {
		output[(int)count[(int)((*ch).lines[i].getSize().y / a) % 3] - 1] = (*ch).lines[i].getSize().y;
		count[(int)((*ch).lines[i].getSize().y / a) % 3]--;
		++ching.swapCounter;
	}

	for (int i = 0; i < n; ++i) {
		(*ch).lines[i].setSize({ 6.0,output[i] });
		window.clear();
		(*ch).textTest(&ching.compareCounter, &ching.readCounter, &ching.swapCounter, &ching.working, &ching.sorted);
		for (int i = 0; i < 12; ++i) {
			temp_arr[i].drawTo(window);
			++ching.readCounter;
		}
		++ching.swapCounter;
		(*ch).drawTo(window);
		window.display();
	}
	delete[] output;
}

void radixSort::radixsort(Chart* ch, sf::RenderWindow& window) {
	ching.working = true;
	int m = getMax(ch,900);
	for (int a = 1; m / a > 0; a *= 3) {
		radixSort::countSort(ch,900,a, window);
		++ching.compareCounter;
	}
	ching.sorted = true;
}

int  radixSort::getMax(Chart* ch, int n) {
	float mx = (*ch).lines[0].getSize().y;
	n = (*ch).lines.size();
	for (int i = 1; i < n; ++i) {
		if ((*ch).lines[i].getSize().y > mx) {
			mx = (*ch).lines[i].getSize().y;
		}
		++ching.compareCounter;
	}
	return mx;
}
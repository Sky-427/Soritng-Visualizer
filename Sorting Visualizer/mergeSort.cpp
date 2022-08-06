#include "mergeSort.h"

void mergeSort::mergesort(Chart* cht, int left, int right, sf::RenderWindow& window) {
	int mid; ching.working = true;
	if (left < right) {
		mid = left + (right - left) / 2;
		mergeSort::mergesort(cht,left,mid,window);
		mergeSort::mergesort(cht,mid+1,right,window);
		mergeSort::merge(cht,left,mid,right,window);
	}
}
	
void mergeSort::merge(Chart* cht, int left, int mid, int right, sf::RenderWindow& window) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	float* a = new float[n1], * b = new float[n2];
	
	for (int i = 0; i < n1; ++i) {
		a[i] =  (*cht).lines[left + i].getSize().y;
	}
	for (int i = 0; i < n2; ++i) {
		b[i] = (*cht).lines[mid + 1 + i].getSize().y;
	}
	
	Text* temp_arr = (*cht).getArray();
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (a[i] <= b[j]) {
			(*cht).lines[k].setSize({ 6.0,a[i] });
			++k; ++i;
		}
		else {
			(*cht).lines[k].setSize({ 6.0,b[j] });
			++k; ++j;
		}
		++ching.compareCounter; ++ching.swapCounter;
		++ching.readCounter;
	}
	while (i < n1) {
		(*cht).lines[k].setSize({ 6.0,a[i] });
		++k; ++i;
		++ching.compareCounter; ++ching.swapCounter;
	}
	while (j < n2) {
		(*cht).lines[k].setSize({ 6.0,b[j] });
		++k; ++j;
		++ching.compareCounter; ++ching.swapCounter;
	}
	delete[]a; delete[]b;
	
	window.clear();
	(*cht).textTest(&ching.compareCounter, &ching.readCounter, &ching.swapCounter, &ching.working, &ching.sorted);
	for (int i = 0; i < 12; ++i) {
		temp_arr[i].drawTo(window);
	}
	(*cht).drawTo(window);
	window.display();
}
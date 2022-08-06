#pragma once
#include "Program.h"
#include "Text.h"
#include "Chart.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "shellShort.h"
#include "radixSort.h"

void Program::run() {

	Program pg; Chart ch_; Text text_;
	ch_.make();
	sf::RenderWindow window(sf::VideoMode(960, 700), "Sorting Visualizer", sf::Style::Close);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		
		//@adding text elements here
		ch_.textTest(&ch_.compareCounter,&ch_.readCounter,&ch_.swapCounter,&ch_.working,&ch_.sorted);

		//@events takes place here
		sf::Event evt;
		while (window.pollEvent(evt)) {
			switch (evt.type) {
				case sf::Event::Closed: {
					window.close();
				}
				case ::sf::Event::KeyPressed: {
					if (evt.key.code == sf::Keyboard::Up) {
						++pg.count; ch_.randomize();
					}
					if (evt.key.code == sf::Keyboard::Down) {
						--pg.count; ch_.randomize();
					}
					if (evt.key.code == sf::Keyboard::Enter) {
						switch (pg.count) {
							case 0: {
								ch_.working = 1;						
								bubbleSort bb; bb.sort(ch_, window);
								break;
							}
							case 1: {
								ch_.working = 1;
								selectionSort ss; ss.sort(ch_,window);
								break;
							}
							case 2: {
								ch_.working = 1;
								insertionSort is; is.sort(ch_,window);
								break;
							}
							case 3: {
								ch_.working = 1;
								mergeSort mg; mg.mergesort(&ch_,0,899,window);
								break;
							}
							case 4: {
								ch_.working = 1;
								shellShort ss; ss.sort(ch_,window);
								break;
							}
							case 5: {
								ch_.working = 1;
								radixSort rs; rs.sort(ch_,window);
								break;
							}
							default: {
								if (pg.count > 5) {
									pg.count = 5;
								}
								if (pg.count < 0) {
									pg.count = 0;
								}
							}
						}
					}
				}
				case::sf::Event::KeyReleased: {
					if (evt.key.code == sf::Keyboard::Up || evt.key.code==sf::Keyboard::Down) {
						ch_.up(&pg.count);
					}
				}
			}
		}
		Text* program_array = ch_.getArray();
		window.clear();
		for (int i = 0; i < 12; ++i) {
			program_array[i].drawTo(window);
		}
		ch_.drawTo(window);
		window.display();
	}
}
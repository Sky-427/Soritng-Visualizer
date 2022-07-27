#include "Program.h"
#include "Text.h"

void Program::run() {

	Text text, text1, text2, text3, text4, text5, text6, text7, text8, text9, text10, text11; Program pg;
	text.setString("Select Algo : "); text.setPosition_({10,670});
	text1.setString("Bubble Sort  | "); text1.setPosition(text,6,text.size());

	sf::RenderWindow window(sf::VideoMode(900, 700), "Sorting Visualizer", sf::Style::Close);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		
		//@adding text elements here
		text2.setString(" Compare count : "); text2.setPosition(text1,6,text1.size());
		text3.setString(std::to_string(pg.compareCounter)+"  | "); text3.setPosition(text2, 7, text2.size());
		text4.setString("Read count : "); text4.setPosition(text3, 6, text3.size());
		text5.setString(std::to_string(pg.readCounter) + "  | "); text5.setPosition(text4, 7, text4.size());
		text6.setString("Swap count : "); text6.setPosition(text5, 6, text5.size());
		text7.setString(std::to_string(pg.swapCounter) + "  | "); text7.setPosition(text6, 7, text6.size());
		text8.setString("Working : "); text8.setPosition(text7, 6, text7.size());
		if (pg.working == 1) {
			text9.setString("YES  | "); text9.setPosition(text8, 7, text8.size());
		}
		else {
			text9.setString("NO  | "); text9.setPosition(text8, 7, text8.size());
		}
		text10.setString("Sorted : "); text10.setPosition(text9, 6, text9.size());
		if (pg.sorted == 1) {
			text11.setString("YES  | "); text11.setPosition(text10, 7, text10.size());
		}
		else {
			text11.setString("NO  | "); text11.setPosition(text10, 7, text10.size());
		}

		//@events takes place here

		sf::Event evt;
		while (window.pollEvent(evt)) {
			switch (evt.type) {
				case sf::Event::Closed: {
					window.close();
				}
				case ::sf::Event::KeyPressed: {
					if (evt.key.code == sf::Keyboard::Up) {
						++pg.count;
					}
					if (evt.key.code == sf::Keyboard::Down) {
						--pg.count;
					}
				}
				case::sf::Event::KeyReleased: {
					if (evt.key.code == sf::Keyboard::Up || evt.key.code==sf::Keyboard::Down) {
						switch (pg.count) {
							case 0: {
								text1.setString("Bubble Sort  | ");
								break;
							}
							case 1: {
								text1.setString("Selection Sort  | ");
								break;
							}
							case 2: {
								text1.setString("Insertion Sort  | ");
								break;
							}
							case 3: {
								text1.setString("Merge Sort  | ");
								break;
							}
							case 4: {
								text1.setString("Quick Sort  | ");
								break;
							}
							case 5: {
								text1.setString("Radix Sort  | ");
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
			}
		}
		window.clear();
		text.drawTo(window);
		text1.drawTo(window);
		text2.drawTo(window);
		text3.drawTo(window);
		text4.drawTo(window);
		text5.drawTo(window);
		text6.drawTo(window);
		text7.drawTo(window);
		text8.drawTo(window);
		text9.drawTo(window);
		text10.drawTo(window);
		text11.drawTo(window);
		window.display();
	}
}
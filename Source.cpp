#include "Render.h"
#include "Pole.h"

int main() {
	Pole tales;
	Render window;
	sf::RenderWindow okno(sf::VideoMode(1000, 500), "Volba");
	sf::RectangleShape rect[3];
	sf::Font font;
	font.loadFromFile("ARIAL.TTF");
	sf::Text text[3];
	rect[0].setFillColor(sf::Color::Green);
	rect[0].setSize(sf::Vector2f(200, 50));
	rect[0].setOrigin(sf::Vector2f(rect[0].getGlobalBounds().width / 2, rect[0].getGlobalBounds().height));
	rect[0].setPosition(sf::Vector2f(250, 250));
	text[0].setCharacterSize(40);
	text[0].setFillColor(sf::Color::Black);
	text[0].setOrigin(sf::Vector2f(text[0].getGlobalBounds().width / 2, text[0].getGlobalBounds().height));
	text[0].setFont(font);
	text[0].setPosition(sf::Vector2f(200, 200));
	text[0].setString("EASY");
	rect[1].setFillColor(sf::Color::Yellow);
	rect[1].setSize(sf::Vector2f(200, 50));
	rect[1].setOrigin(sf::Vector2f(rect[1].getGlobalBounds().width / 2, rect[1].getGlobalBounds().height));
	rect[1].setPosition(sf::Vector2f(500, 250));
	text[1].setCharacterSize(40);
	text[1].setFillColor(sf::Color::Black);
	text[1].setOrigin(sf::Vector2f(text[1].getGlobalBounds().width / 2, text[1].getGlobalBounds().height));
	text[1].setFont(font);
	text[1].setPosition(sf::Vector2f(420, 200));
	text[1].setString("MEDIUM");
	rect[2].setFillColor(sf::Color::Red);
	rect[2].setSize(sf::Vector2f(200, 50));
	rect[2].setOrigin(sf::Vector2f(rect[2].getGlobalBounds().width / 2, rect[2].getGlobalBounds().height));
	rect[2].setPosition(sf::Vector2f(750, 250));
	text[2].setCharacterSize(40);
	text[2].setFillColor(sf::Color::Black);
	text[2].setOrigin(sf::Vector2f(text[2].getGlobalBounds().width / 2, text[2].getGlobalBounds().height));
	text[2].setFont(font);
	text[2].setPosition(sf::Vector2f(695, 200));
	text[2].setString("HARD");
	while (okno.isOpen()) {
        sf::Event event;
        while (okno.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                okno.close();
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (rect[0].getGlobalBounds().contains(okno.mapPixelToCoords(sf::Mouse::getPosition(okno)))) {
						window.HEIGHT = 364.f;
						window.LENGHT = 364.f;
						tales.HEIGHT = 364.f;
						tales.LENGHT = 364.f;
						window.pocetMin = 20;
						window.column = 8;
						window.row = 8;
						tales.column = 8;
						tales.row = 8;
						okno.close();
					}
					else if (rect[1].getGlobalBounds().contains(okno.mapPixelToCoords(sf::Mouse::getPosition(okno)))) {
						window.HEIGHT = 727.f;
						window.LENGHT = 727.f;
						tales.HEIGHT = 727.f;
						tales.LENGHT = 727.f;
						window.pocetMin = 40;
						window.column = 16;
						window.row = 16;
						tales.column = 16;
						tales.row = 16;
						okno.close();
					}
					else if (rect[2].getGlobalBounds().contains(okno.mapPixelToCoords(sf::Mouse::getPosition(okno)))) {
						window.HEIGHT = 1000.f;
						window.LENGHT = 1000.f;
						tales.HEIGHT = 1000.f;
						tales.LENGHT = 1000.f;
						window.pocetMin = 99;
						window.column = 22;
						window.row = 22;
						tales.column = 22;
						tales.row = 22;
						okno.close();
					}
				}
			}
		}
        okno.clear();
		okno.draw(rect[0]);
		okno.draw(text[0]);
		okno.draw(rect[1]);
		okno.draw(text[1]);
		okno.draw(rect[2]);
		okno.draw(text[2]);
        okno.display();
    }
	window.cellPos = tales.talesPos;
	window.cell = tales.tales;
	//funkce, ketrá v podstatě spouští Render.cpp
	window.rend();

	return 0;
}

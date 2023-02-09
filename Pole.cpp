#include "Pole.h"



Pole::Pole()
{
	for (int i = 0; i < this->line; i++) {
		std::vector<sf::Vector2f> vec;
		for (int j = 0; j < this->line; j++) {
			sf::Vector2f x;
			x.x = j * LENGHT / this->line + OUTLINE;
			x.y = i * HIGHT / this->line + OUTLINE;
			vec.push_back(x);
		}
		this->talesPos.push_back(vec);
	}
	for (int i = 0; i < this->line; i++) {
		std::vector<sf::RectangleShape> vec;
		for (int j = 0; j < this->line; j++) {
			sf::RectangleShape x;
			x.setFillColor(sf::Color::White);
			x.setSize(sf::Vector2f(HIGHT / this->line - OUTLINE, LENGHT / this->line - OUTLINE));
			x.setPosition(this->talesPos[i][j]);
			vec.push_back(x);
		}
		this->tales.push_back(vec);
	}
}

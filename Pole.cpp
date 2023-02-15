#include "Pole.h"

Pole::Pole()
{
	Pole::setPos();
	Pole::setTiles();
}

void Pole::setPos()
{
	for (int i = 0; i < this->row+ 1; i++) {
		std::vector<sf::Vector2f> vec;
		for (int j = 0; j < this->column+ 1; j++) {
			sf::Vector2f x;
			x.x = j * LENGHT / this->row+ OUTLINE;
			x.y = i * HEIGHT / this->column + OUTLINE;
			vec.push_back(x);
		}
		this->talesPos.push_back(vec);
	}
}

void Pole::setTiles()
{
	for (int i = 0; i < this->row + 1; i++) {
		std::vector<sf::RectangleShape> vec;
		for (int j = 0; j < this->column + 1; j++) {
			sf::RectangleShape x;
			x.setSize(sf::Vector2f(LENGHT / this->row - OUTLINE, HEIGHT / this->column - OUTLINE));
			x.setPosition(this->talesPos[i][j]);
			sf::Color gray(128, 128, 128);
			x.setFillColor(gray);
			
			vec.push_back(x);
		}
		this->tales.push_back(vec);
	}
}

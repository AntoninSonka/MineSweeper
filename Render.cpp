#include "Render.h"


//rendrování a kreslení na okno

void Render::rend()
{
	while (this->window.isOpen()) {
		Render::update();
		this->window.clear(sf::Color::Black);
		for (int i = 0; i < this->line; i++) {
			for (int j = 0; j < this->line; j++) {
				this->window.draw(cell[i][j]);
			}
		}
		this->window.display();
	}
}

//Eventy a inputová logika

void Render::update()
{
	while (this->window.pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window.close();
		}
		if (this->event.type == sf::Event::MouseButtonReleased) {
			if (this->event.mouseButton.button == sf::Mouse::Left) {
				for (int i = 0; i < this->line; i++) {
					for (int j = 0; j < this->line; j++) {
						if (this->cell[i][j].getGlobalBounds().contains(this->window.mapPixelToCoords(sf::Mouse::getPosition(this->window)))) {
							if(this->isMine[i][j])
								this->cell[i][j].setFillColor(sf::Color::Red);
							else
								this->cell[i][j].setFillColor(sf::Color::Green);
						}
					}
				}
			}
		}
	}
}

void Render::zaminovat()
{
	srand(time(NULL));
	for (int i = 0; i < this->pocetMin; i++) {
		int x = rand() % line;
		int y = rand() % line;
		if (this->isMine[x][y] == false) {
			this->isMine[x][y] = true;
		}
		else {
			i--;
		}
	}
	int count = 0;
	for (int i = 0; i < this->line; i++) {
		for (int j = 0; j < this->line; j++) {
			std::cout << this->isMine[i][j] << ' ';
			if (this->isMine[i][j])
				count++;
		}
	}
	std::cout << count << std::endl;
}

//constructor

Render::Render()
{
	//vytvoøení okna
	this->window.create(sf::VideoMode(HIGHT + OUTLINE, LENGHT + OUTLINE), "MineSweeper");
	//vkládání prázdných elementù do vectorù
	for (int i = 0; i < this->line; i++) {
		std::vector<sf::Vector2f> vec;
		for (int j = 0; j < this->line; j++) {
			sf::Vector2f x;
			x.x = j * LENGHT / this->line;
			x.y = i * HIGHT / this->line;
			vec.push_back(x);
		}
		this->cellPos.push_back(vec);
	}
	for (int i = 0; i < this->line; i++) {
		std::vector<sf::RectangleShape> vec;
		for (int j = 0; j < this->line; j++) {
			sf::RectangleShape x;
			vec.push_back(x);
		}
		this->cell.push_back(vec);
	}
	for (int i = 0; i < this->line; i++) {
		std::vector<bool> vec;
		for (int j = 0; j < this->line; j++) {
			bool x = false;
			vec.push_back(x);
		}
		this->isMine.push_back(vec);
	}
	int count = 0;
	for (int i = 0; i < this->line; i++) {
		for (int j = 0; j < this->line; j++) {
			std::cout << this->isMine[i][j] << ' ';
			if (this->isMine[i][j])
				count++;
		}
	}
	std::cout << count << std::endl;
	Render::zaminovat();
}



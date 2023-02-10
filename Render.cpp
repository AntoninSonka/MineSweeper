#include "Render.h"


//rendrování a kreslení na okno

void Render::rend()
{ 
	sf::Texture texture;
    if (!texture.loadFromFile("TextureTest.png")) {
        std::cerr << "Failed to load texture" << std::endl;
        return;
    }

	while (this->window.isOpen()) {
		this->window.clear(sf::Color::Black);
		Render::update();

		for (int i = 0; i < this->line; i++) {
			for (int j = 0; j < this->line; j++) {
				this->window.draw(this->cell[i][j]);
				if (this->isOpend[i][j]) {
					texture = setCisla(i, j);
					sf::Sprite sprite(texture);
					sprite.setTextureRect(sf::IntRect(0, 0, this->cell[i][j].getSize().x, this->cell[i][j].getSize().y));
					sprite.setPosition(cell[i][j].getPosition());
					this->window.draw(sprite);
				}
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
							if (!this->isOpend[i][j]) {
								std::cout << " (" << this->cell[i][j].getSize().x << ", " << this->cell[i][j].getSize().y << ") ";
								if (this->isMine[i][j]) {
									this->cell[i][j].setFillColor(sf::Color::Red);
								} else {
									this->cell[i][j].setFillColor(sf::Color::Green);
								}
							}
							this->isOpend[i][j] = true;
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
		int x = rand() % this->line;
		int y = rand() % this->line;
		if (this->isMine[x][y] == false) {
			this->isMine[x][y] = true;
		}
		else {
			i--;
		}
	}
}

sf::Texture Render::setCisla(int x, int y)
{
	
	int count = 0;
	if (x > 0) {
		if (this->isMine[x - 1][y]) {
			count++;
		}
	}
	if (x < this->line) {
		if (this->isMine[x + 1][y]) {
			count++;
		}
	}
	if (y > 0) {
		if (this->isMine[x][y - 1]) {
			count++;
		}
	}
	if (y < this->line + 1) {
		if (this->isMine[x][y + 1]) {
			count++;
		}
	}
	if (x > 0 && y > 0) {
		if (this->isMine[x - 1][y - 1]) {
			count++;
		}
	}
	if (x < this->line && y < this->line) {
		if (this->isMine[x + 1][y + 1]) {
			count++;
		}
	}
	if (y > 0 && x < this->line) {
		if (this->isMine[x + 1][y - 1]) {
			count++;
		}
	}
	if (y < this->line + 1 && x > 0) {
		if (this->isMine[x - 1][y + 1]) {
			count++;
		}
	}
	sf::Texture texture;
	switch (count) {
	case 1:
		if (!texture.loadFromFile("TextureTest.png"))
			std::cerr << "Failed to load texture" << std::endl;
		break;
	case 2:
		if (!texture.loadFromFile("TextureTest.png"))
			std::cerr << "Failed to load texture" << std::endl;
		break;
	case 3:
		if (!texture.loadFromFile("TextureTest.png"))
			std::cerr << "Failed to load texture" << std::endl;
		break;
	case 4:
		if (!texture.loadFromFile("TextureTest.png"))
			std::cerr << "Failed to load texture" << std::endl;
		break;
	case 5:
		if (!texture.loadFromFile("TextureTest.png"))
			std::cerr << "Failed to load texture" << std::endl;
		break;
	case 6:
		if (!texture.loadFromFile("TextureTest.png"))
			std::cerr << "Failed to load texture" << std::endl;
		break;
	case 7:
		if (!texture.loadFromFile("TextureTest.png")) {
			std::cerr << "Failed to load texture" << std::endl;
			break;
	case 8:
		if (!texture.loadFromFile("TextureTest.png"))
			std::cerr << "Failed to load texture" << std::endl;
		break;
	default:
		break;
		}
	}
	return texture;
}

//constructor

Render::Render()
{
	//vytvoření okna
	this->window.create(sf::VideoMode(HIGHT + OUTLINE, LENGHT + OUTLINE), "MineSweeper");
	//vkládání prázdných elementů do vectorů
	for (int i = 0; i < this->line; i++) {
		std::vector<sf::Vector2f> vec1;
		std::vector<sf::RectangleShape> vec2;
		std::vector<bool> vec3;
		for (int j = 0; j < this->line; j++) {
			sf::Vector2f x;
			x.x = j * LENGHT / this->line + OUTLINE;
			x.y = i * HIGHT / this->line + OUTLINE;
			vec1.push_back(x);
			sf::RectangleShape y;
			vec2.push_back(y);
			bool z = false;
			vec3.push_back(z);
		}
		this->cellPos.push_back(vec1);
		this->cell.push_back(vec2);
		this->isMine.push_back(vec3);
		this->isOpend.push_back(vec3);
	}
	Render::zaminovat();
}



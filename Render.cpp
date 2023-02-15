#include "Render.h"


//rendrování a kreslení na okno

void Render::rend()
{
	//vytvoření okna
	this->window.create(sf::VideoMode(LENGHT + OUTLINE, HEIGHT + OUTLINE), "MineSweeper");
	sf::Texture texture;
	while (this->window.isOpen()) {
		int count = 0;
		this->window.clear(sf::Color::Black);
		Render::update();
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->column; j++) {
				this->window.draw(this->cell[i][j]);
				if (this->isOpend[i][j]) {
					if (!this->isMine[i][j]) {
						this->cell[i][j].setFillColor(sf::Color::White);
						count++;
						if (count == this->row * this->column - this->pocetMin)
							this->win = true;
					}
					texture = setCisla(i, j);
					sf::Sprite sprite(texture);
					sprite.setOrigin(cell[i][j].getGlobalBounds().width / 2, cell[i][j].getGlobalBounds().height / 2);
					sprite.setTextureRect(sf::IntRect(0, 0, this->cell[i][j].getSize().x, this->cell[i][j].getSize().y));
					sprite.setPosition(cell[i][j].getPosition().x + cell[i][j].getGlobalBounds().width / 2, cell[i][j].getPosition().y + cell[i][j].getGlobalBounds().height / 2);
					this->window.draw(sprite);
				}
				else if (this->flag[i][j]) {
					if (!texture.loadFromFile("flag.png")) {
						std::cout << "Failed to load texture" << std::endl;
					}
					sf::Sprite sprite(texture);
					sprite.setOrigin(cell[i][j].getGlobalBounds().width / 2, cell[i][j].getGlobalBounds().height / 2);
					sprite.setTextureRect(sf::IntRect(0, 0, this->cell[i][j].getSize().x, this->cell[i][j].getSize().y));
					sprite.setPosition(cell[i][j].getPosition().x + cell[i][j].getGlobalBounds().width / 2, cell[i][j].getPosition().y + cell[i][j].getGlobalBounds().height / 2);
					this->window.draw(sprite);
				}
				else {
					if (!texture.loadFromFile("Blank.png")) {
						std::cout << "Failed to load texture" << std::endl;
					}
					sf::Sprite sprite(texture);
					sprite.setTextureRect(sf::IntRect(0, 0, this->cell[i][j].getSize().x, this->cell[i][j].getSize().y));
					sprite.setPosition(cell[i][j].getPosition());
					this->window.draw(sprite);
				}
			}
		}
		if (this->isGameOver || this->win) {
			sf::Font font;
			font.loadFromFile("ARIAL.TTF");
			sf::Text text;
			text.setFont(font);
			text.setCharacterSize(HEIGHT / 10);
			text.setStyle(sf::Text::Bold);
			if (this->isGameOver) {
				text.setFillColor(sf::Color::Red);
				text.setString("GAME OVER!");
			}
			else if (this->win) {
				sf::Color darkGreen(0, 153, 0);
				text.setFillColor(darkGreen);
				text.setString("YOU HAVE\nSURVIVED!");
			}
			text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
			text.setPosition(LENGHT / 2, HEIGHT / 2 - 50);
			this->window.draw(text);
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
				for (int i = 0; i < this->row + 1; i++) {
					for (int j = 0; j < this->column + 1; j++) {
						if (this->cell[i][j].getGlobalBounds().contains(this->window.mapPixelToCoords(sf::Mouse::getPosition(this->window)))) {
							this->isOpend[i][j] = true;
						}
					}
				}
			}
			else if (this->event.mouseButton.button == sf::Mouse::Right) {
				for (int i = 0; i < this->row + 1; i++) {
					for (int j = 0; j < this->column + 1; j++) {
						if (this->cell[i][j].getGlobalBounds().contains(this->window.mapPixelToCoords(sf::Mouse::getPosition(this->window)))) {
							if (!this->isOpend[i][j]) {
								if (!this->flag[i][j])
									this->flag[i][j] = true;
								else
									this->flag[i][j] = false;
							}
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
		int x = rand() % this->row;
		int y = rand() % this->column;
		if (!this->isOpend[x][y]) {
			if (this->isMine[x][y] == false) {
				this->isMine[x][y] = true;
			}
			else {
				i--;
			}
		}
		else {
			i--;
		}
	}
}

sf::Texture Render::setCisla(int x, int y)
{
	this->howManyOpen++;
	int count = 0;
	if (!this->isMine[x][y]) {
		if (x > 0) {
			if (this->isMine[x - 1][y]) {
				count++;
			}
		}
		if (x < this->row) {
			if (this->isMine[x + 1][y]) {
				count++;
			}
		}
		if (y > 0) {
			if (this->isMine[x][y - 1]) {
				count++;
			}
		}
		if (y < this->column + 1) {
			if (this->isMine[x][y + 1]) {
				count++;
			}
		}
		if (x > 0 && y > 0) {
			if (this->isMine[x - 1][y - 1]) {
				count++;
			}
		}
		if (x < this->row && y < this->column) {
			if (this->isMine[x + 1][y + 1]) {
				count++;
			}
		}
		if (y > 0 && x < this->row) {
			if (this->isMine[x + 1][y - 1]) {
				count++;
			}
		}
		if (y < this->column + 1 && x > 0) {
			if (this->isMine[x - 1][y + 1]) {
				count++;
			}
		}
	}
	else {
		count += 9;
		this->isGameOver = true;
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->column; j++) {
				if (this->isMine[i][j] == true) {
					this->isOpend[i][j] = true;
				}
			}
		}
	}
	sf::Texture texture;
	switch (count) {
	case 0: {
		if (x > 0) {
			this->isOpend[x - 1][y] = true;
		}
		if (x < this->row) {
			this->isOpend[x + 1][y] = true;
		}
		if (y > 0) {
			this->isOpend[x][y - 1] = true;
		}
		if (y < this->column+ 1) {
			this->isOpend[x][y + 1] = true;
		}
		if (x > 0 && y > 0) {
			this->isOpend[x - 1][y - 1] = true;
		}
		if (x < this->row && y < this->column) {
			this->isOpend[x + 1][y + 1] = true;
		}
		if (y > 0 && x < this->row) {
			this->isOpend[x + 1][y - 1] = true;
		}
		if (y < this->column + 1 && x > 0) {
			this->isOpend[x - 1][y + 1] = true;
		}
		if (this->howManyOpen == 1) {
			this->zaminovat();
		}
		break; 
	}
	case 1:
		if (!texture.loadFromFile("1.png"))
			std::cout << "Failed to load texture" << std::endl;
		break;
	case 2:
		if (!texture.loadFromFile("2.png"))
			std::cout << "Failed to load texture" << std::endl;
		break;
	case 3:
		if (!texture.loadFromFile("3.png"))
			std::cout << "Failed to load texture" << std::endl;
		break;
	case 4:
		if (!texture.loadFromFile("4.png"))
			std::cout << "Failed to load texture" << std::endl;
		break;
	case 5:
		if (!texture.loadFromFile("5.png"))
			std::cout << "Failed to load texture" << std::endl;
		break;
	case 6:
		if (!texture.loadFromFile("6.png"))
			std::cout << "Failed to load texture" << std::endl;
		break;
	case 7:
		if (!texture.loadFromFile("7.png")) {
			std::cout << "Failed to load texture" << std::endl;
			break;
	case 8:
		if (!texture.loadFromFile("8.png"))
			std::cout << "Failed to load texture" << std::endl;
		break;
	case 9:
		if (!texture.loadFromFile("mine.png"))
			std::cout << "Failed to load texture" << std::endl;
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
	this->window.setFramerateLimit(30);
	//vkládání prázdných elementů do vectorů
	for (int i = 0; i < this->row+ 1; i++) {
		std::vector<sf::Vector2f> vec1;
		std::vector<sf::RectangleShape> vec2;
		std::vector<bool> vec3;
		for (int j = 0; j < this->column+ 1; j++) {
			sf::Vector2f x;
			x.x = j * LENGHT / this->row+ OUTLINE;
			x.y = i * HEIGHT / this->column+ OUTLINE;
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
		this->flag.push_back(vec3);
	}
	//Render::zaminovat();
}

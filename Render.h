#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


//!musí se počítat s tim, že k výšce a šířce se přičte ještě OUTLINE. To je kvůli 

class Render
{
private:
	sf::RenderWindow window;
	//Počet buněk na jednom řádku
	//Deklarace okna a eventů
	sf::Event event;
	bool isGameOver = false;
	bool win = false;
	int howManyOpen = 0;
public:
	Render();
	int row = 22;
	int column = 22;
	int pocetMin = 99;
	float HEIGHT = 1000.f;	//výška obrazovky
	float LENGHT = 1000.f;	//dýlka obrazovky
	float OUTLINE = 3.f;		//mezery okolo jednotlivejch buněk
	void rend();	//v update se volají všechny eventy. viz. update()
	void update();	//Pozice buněk na obrazovce. deklaruje se pomocí Pole.h a Pole.cpp
	void zaminovat();
	sf::Texture setCisla(int x, int y);
	std::vector<std::vector<sf::Vector2f>> cellPos;
	std::vector<std::vector<sf::RectangleShape>> cell;	//Obsahuje informace o konkrétních buňkách. např. velikost, barva a potom i pozice
	std::vector<std::vector<bool>> isMine;
	std::vector<std::vector<bool>> isOpend;
	std::vector<std::vector<bool>> flag;
};

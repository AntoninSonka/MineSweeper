#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#define HEIGHT 750.f	//výška obrazovky
#define LENGHT 750.f	//dýlka obrazovky
#define OUTLINE 5.f		//mezery okolo jednotlivejch buněk

//!musí se počítat s tim, že k výšce a šířce se přičte ještě OUTLINE. To je kvůli 

class Render
{
private:
	sf::RenderWindow window;
	//Počet buněk na jednom řádku
	int line = 16;
	//Deklarace okna a eventů
	sf::Event event;
	int pocetMin = 40;
	bool isGameOver = false;
	int howManyOpen = 0;
public:
	//Constructor
	Render();	//rend je funkce která se volá main funkcí v source. před zavolání je potřeba deklarovat přesně cellPos a cell pomocí klásy Pole.h a Pole.cpp. viz main()
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

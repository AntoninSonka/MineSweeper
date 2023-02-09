#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#define HIGHT 1000.f	//výška obrazovky
#define LENGHT 1000.f	//dýlka obrazovky
#define OUTLINE 5.f		//mezery okolo jednotlivejch bunìk

//!musí se poèítat s tim, že k výšce a šíøce se pøiète ještì OUTLINE. To je kvùli 

class Render
{
private:
	//Poèet bunìk na jednom øádku
	int line = 16;
	//Deklarace okna a eventù
	sf::RenderWindow window;
	sf::Event event;
public:
	//Constructor
	Render();	//rend je funkce která se volá main funkcí v source. pøed zavolání je potøeba deklarovat pøesnì cellPos a cell pomocí klásy Pole.h a Pole.cpp. viz main()
	void rend();	//v update se volají všechny eventy. viz. update()
	void update();	//Pozice bunìk na obrazovce. deklaruje se pomocí Pole.h a Pole.cpp
	void zaminovat();
	std::vector<std::vector<sf::Vector2f>> cellPos;
	std::vector<std::vector<sf::RectangleShape>> cell;	//Obsahuje informace o konkrétních buòkách. napø. velikost, barva a potom i pozice
	std::vector<std::vector<bool>> isMine;
	int pocetMin = 40;
};

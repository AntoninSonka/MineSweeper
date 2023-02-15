#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

//viz Render.h

class Pole
{
private:
	//viz Render.h
public:
	int row = 22;
	int column = 22;
	int pocetMin = 99;
	float HEIGHT = 1000.f;	//výška obrazovky
	float LENGHT = 1000.f;	//dýlka obrazovky
	float OUTLINE = 3.f;		//mezery okolo jednotlivejch bunìk
	//tahle classa používá pouze constructor
	Pole();
	void setPos();
	void setTiles();
	//vektor s informací o pozici každý buòky. Pak se dává do Render.h skrz main()
	std::vector<std::vector<sf::Vector2f>> talesPos;
	//vektor s informacemo o každý buòce, jako barva, velikost, atd. to samý, co s tim prvnim
	std::vector<std::vector<sf::RectangleShape>> tales;
};

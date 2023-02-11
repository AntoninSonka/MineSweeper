#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

//viz Render.h

#define HEIGHT 750.f
#define LENGHT 750.f
#define OUTLINE 5.f

class Pole
{
private:
	//viz Render.h
	int line = 16;
public:
	//tahle classa používá pouze constructor
	Pole();
	void setPos();
	void setTiles();
	//vektor s informací o pozici každý buňky. Pak se dává do Render.h skrz main()
	std::vector<std::vector<sf::Vector2f>> talesPos;
	//vektor s informacemo o každý buňce, jako barva, velikost, atd. to samý, co s tim prvnim
	std::vector<std::vector<sf::RectangleShape>> tales;
};

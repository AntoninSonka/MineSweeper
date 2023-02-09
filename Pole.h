#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

//viz Render.h

#define HIGHT 1000.f
#define LENGHT 1000.f
#define OUTLINE 5.f

class Pole
{
public:
	//viz Render.h
	int line = 16;
	//tahle classa používá pouze constructor
	Pole();
	//vektor s informací o pozici každý buòky. Pak se dává do Render.h skrz main()
	std::vector<std::vector<sf::Vector2f>> talesPos;
	//vektor s informacemo o každý buòce, jako barva, velikost, atd. to samý, co s tim prvnim
	std::vector<std::vector<sf::RectangleShape>> tales;
};

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
	//tahle classa pou��v� pouze constructor
	Pole();
	//vektor s informac� o pozici ka�d� bu�ky. Pak se d�v� do Render.h skrz main()
	std::vector<std::vector<sf::Vector2f>> talesPos;
	//vektor s informacemo o ka�d� bu�ce, jako barva, velikost, atd. to sam�, co s tim prvnim
	std::vector<std::vector<sf::RectangleShape>> tales;
};

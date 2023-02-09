#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#define HIGHT 1000.f	//v��ka obrazovky
#define LENGHT 1000.f	//d�lka obrazovky
#define OUTLINE 5.f		//mezery okolo jednotlivejch bun�k

//!mus� se po��tat s tim, �e k v��ce a ���ce se p�i�te je�t� OUTLINE. To je kv�li 

class Render
{
private:
	//Po�et bun�k na jednom ��dku
	int line = 16;
	//Deklarace okna a event�
	sf::RenderWindow window;
	sf::Event event;
public:
	//Constructor
	Render();	//rend je funkce kter� se vol� main funkc� v source. p�ed zavol�n� je pot�eba deklarovat p�esn� cellPos a cell pomoc� kl�sy Pole.h a Pole.cpp. viz main()
	void rend();	//v update se volaj� v�echny eventy. viz. update()
	void update();	//Pozice bun�k na obrazovce. deklaruje se pomoc� Pole.h a Pole.cpp
	void zaminovat();
	std::vector<std::vector<sf::Vector2f>> cellPos;
	std::vector<std::vector<sf::RectangleShape>> cell;	//Obsahuje informace o konkr�tn�ch bu�k�ch. nap�. velikost, barva a potom i pozice
	std::vector<std::vector<bool>> isMine;
	int pocetMin = 40;
};

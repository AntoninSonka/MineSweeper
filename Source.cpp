#include "Render.h"
#include "Pole.h"

int main() {
	//vytvo�en� objekt�, p�i�em� se spust� constructory
	Pole tales;
	Render window;
	
	//tady se p�ed� obsah vektor� z Pole.h do Redner.h
	//Redner te� m� pot�ebn� informace k chodu
	window.cellPos = tales.talesPos;
	window.cell = tales.tales;
	//funkce, ketr� v podstat� spou�t� Render.cpp
	window.rend();

	return 0;
}

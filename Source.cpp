#include "Render.h"
#include "Pole.h"

int main() {
	//vytvoření objektů, přičemž se spustí constructory
	Pole tales;
	Render window;
	//tady se předá obsah vektorů z Pole.h do Redner.h
	//Redner teď má potřebný informace k chodu
	window.cellPos = tales.talesPos;
	window.cell = tales.tales;
	//funkce, ketrá v podstatě spouští Render.cpp
	window.rend();

	return 0;
}

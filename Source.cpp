#include "Render.h"
#include "Pole.h"

int main() {
	//vytvoøení objektù, pøièemž se spustí constructory
	Pole tales;
	Render window;
	
	//tady se pøedá obsah vektorù z Pole.h do Redner.h
	//Redner teï má potøebný informace k chodu
	window.cellPos = tales.talesPos;
	window.cell = tales.tales;
	//funkce, ketrá v podstatì spouští Render.cpp
	window.rend();

	return 0;
}

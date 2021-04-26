#include "Caja.h"
#include "freeglut.h"

Caja::Caja() {
	suelo.SetColor(0, 100, 0);
	techo.SetColor(0, 100, 0);
	pared_dcha.SetColor(0, 150, 0);
	pared_izq.SetColor(0, 150, 0);
}

void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
}

void Caja::Inicializa() {
	suelo.SetColor(150, 250, 0);
	techo.SetColor(150, 250, 0);
	pared_dcha.SetColor(0, 150, 0);
	pared_izq.SetColor(0, 150, 0);

	suelo.SetPos(10.0f, 0.0f, -10.0f, 0.0f);//x1,y1,x2,y2
	techo.SetPos(10.0f, 15.0f, -10.0f, 15.0f);
	pared_dcha.SetPos(10.0f, 15.0f, 10.0f, 0.0f);
	pared_izq.SetPos(-10.0f, 15.0, -10.0f, 0.0f);
}
#include "Caja.h"
#include "freeglut.h"

Caja::Caja() {
	techo.setColor(0, 100, 0);
	techo.setLims(200.0f, 20.0f, -30.0f, 20.0f);
	pared_dcha.setColor(0, 250, 0);
	pared_dcha.setLims(200.0f, 20.0f, 200.0f, 0.0f);
	pared_izq.setColor(0, 250, 0);
	pared_izq.setLims(-10.0f, 0.005f, -10.0f, 0.0f);
	suelo.setColor(0, 100, 0);
	suelo.setLims(200.0f, -10.0f, -30.0f, -10.0f);

}

void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
}

void Caja::Inicializa() 
{

}
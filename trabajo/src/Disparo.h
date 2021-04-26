#pragma once
#include "Vector2D.h"
#include "Estela.h"
class Disparo
{
public:
	Disparo();
	float radio;
	float origen = posicion.x;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
	Estela estela1, estela2, estela3, estela4;
	Estela* pestela1 = &estela1, * pestela2 = &estela2, * pestela3 = &estela3, * pestela4 = &estela4;
	void dibuja();
	void mueve(float);
	int ini = 0;
};


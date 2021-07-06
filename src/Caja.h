#pragma once
#include "Solidos.h"
#include "ColorRGB.h"
class Caja
{
	Pared suelo, techo, pared_izq, pared_dcha;
public:
	Caja();
	void dibuja(int i);
	void Inicializa();
	friend class Interaccion;
};




#pragma once
#include "Pared.h"
#include "ColorRGB.h"
class Caja
{
	Pared suelo, techo, pared_izq, pared_dcha;

public:
	Caja();
	void dibuja();
	void Inicializa();

	friend class Interaccion;
};



#pragma once
#include "Pared.h"
#include "ColorRGB.h"
class Caja
{
	Pared suelo1, techo, pared_izq, pared_dcha;
	Pared suelo2, suelo3, suelo4, suelo5;
	Pared pozo1_dcha, pozo1_izq, pozo2_dcha, pozo2_izq, pozo3_dcha, pozo3_izq, pozo4_dcha, pozo4_izq;
public:
	Caja();
	void dibuja();
	void Inicializa();
	friend class Interaccion;
};




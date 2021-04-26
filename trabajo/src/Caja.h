#pragma once
#include "Pared.h"
class Caja
{
public:
	Caja();
	Pared suelo, techo, pared_izq, pared_dcha;
	void dibuja();
	void Inicializa();
};

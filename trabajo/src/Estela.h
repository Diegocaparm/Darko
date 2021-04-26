#pragma once
#include "Vector2D.h"

class Estela
{
public:
	float radio1 = 0.1;
	float radio2 = 0.2;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
	Estela();
	void dibuja(float);
	void mueve(float);
};


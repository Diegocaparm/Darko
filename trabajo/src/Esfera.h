#pragma once
#include "Vector2D.h"
class Esfera
{
	float radio;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
public:
	Esfera();
	void dibuja();
	void mueve(float);
	void setColor(unsigned char, unsigned char, unsigned char);
	void setRadio(float);
	void setPos(float, float);
};


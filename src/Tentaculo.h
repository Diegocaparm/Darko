#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Tentaculo
{
	float longitud = 5.0f;
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;

public:
	Tentaculo();
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setPos(float, float);
	friend class Interaccion;
	friend class Mundo;
	friend class Nivel1;

	float a;		//angulo de giro
	int px;			//posicion relativa al personaje principal
};
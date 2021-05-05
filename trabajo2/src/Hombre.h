#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Hombre
{
	ColorRGB color;
	Vector2D posicion{ -4,2 }, velocidad, aceleracion;

public:
	Hombre();
	float altura;
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setVel(float, float);

	friend class Interaccion;



	bool mov;
	int salto = 1, sentido = 0, zona = 0;
};


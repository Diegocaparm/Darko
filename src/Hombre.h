#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Hombre
{
	ColorRGB color;
	Vector2D posicion{ -4,11 }, velocidad, aceleracion;

public:
	Hombre();
	float altura;
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setVelx(float);		//antes era void setVel(float, float);
	Vector2D getPos();

	friend class Interaccion;
	friend class Mundo;
	friend class Nivel1;
	friend class Interfaz;
	friend class Vida;

	bool mov;
	int salto = 1, sentido = 0, zona = 0, flag = 0;
};


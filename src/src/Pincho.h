#pragma once
#include "Vector2D.h"
#include "freeglut.h"
#include "Hitbox.h"

class Pincho
{
	Vector2D posicion;
	float altura;
	Hitbox hitbox;
public:
	Pincho();
	Pincho(float px, float py);
	void dibuja();
	void setPos(float x, float y);
	friend class Mundo;
	friend class Nivel1;

	friend class Interaccion;
};


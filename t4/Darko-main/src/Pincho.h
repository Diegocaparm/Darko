#pragma once
#include "Vector2D.h"
#include "freeglut.h"

class Pincho
{
	Vector2D posicion;
	float altura;
public:
	Pincho();
	void dibuja();
	void setPos(float x, float y);
	friend class Mundo;
	friend class Nivel1;
};


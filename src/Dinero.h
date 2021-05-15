#pragma once
#include <Vector2D.h>
#include <ETSIDI.h>
using ETSIDI::SpriteSequence;

class Dinero
{
public:
	int actual;
	Vector2D posicion;
	SpriteSequence sprite{ "imagenes/moneda.png", 7 };

public:
	Dinero();
	void dibuja();
	void setPos(float x, float y);
	int getCantidad();
	void mueve();

};


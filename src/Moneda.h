#pragma once
#include <Vector2D.h>
#include <ETSIDI.h>
using ETSIDI::SpriteSequence;

class Moneda
{
public:
	float radio;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	SpriteSequence sprite{ "imagenes/moneda.png", 7 };

public:
	Moneda();
	Moneda(float x, float y);
	void dibuja();
	void setPos(float x, float y);
	void mueve(float t);
};


#pragma once
#include <Vector2D.h>
#include <ETSIDI.h>
using ETSIDI::SpriteSequence;

class Dinero
{
public:
	int contador;
	Vector2D posicion;
	SpriteSequence sprite{ "imagenes/moneda.png", 4 };

public:
	Dinero();
	void dibuja();

};


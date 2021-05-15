#pragma once
#include "Vidas.h"
#include "Dinero.h"

class Interfaz
{
public:
	Vidas corazon;
	Dinero moneda;

public:
	void dibuja(Vector2D h);
	void mueve(float t);
};


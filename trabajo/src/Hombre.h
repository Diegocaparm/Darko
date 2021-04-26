#pragma once
#include "Vector2D.h"
class Hombre
{
public:
	Hombre();
	float altura;
	unsigned char rojo, verde, azul;
	Vector2D posicion, velocidad, aceleracion;
	void dibuja();
	void mueve(float);
	void tecla(unsigned char);
	
	bool mov;
	int salto = 1, sentido = 0;
};


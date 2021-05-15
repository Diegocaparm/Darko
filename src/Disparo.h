#pragma once
#include "Vector2D.h"
//#include "Estela.h"
#include "ColorRGB.h"
class Disparo
{
	ColorRGB color;
public:
	Disparo();
	Vector2D posicion, velocidad, aceleracion;

	float radio;
	float origen = posicion.x;
	//Estela estela1, estela2, estela3, estela4;
	//Estela* pestela1 = &estela1, * pestela2 = &estela2, * pestela3 = &estela3, * pestela4 = &estela4;

	void dibuja();
	void mueve(float);
	void setPos(float, float);
	void setColor(Byte, Byte, Byte);



	int ini = 0;
};


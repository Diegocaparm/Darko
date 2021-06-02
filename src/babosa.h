#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Babosa
{
	float longitud = 1.5f;
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;

public:
	Babosa();
	Babosa(float px, float py);
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setVelx(float);		//antes era void setVel(float, float);
	void setPos(float, float);
	friend class Interaccion;
	friend class Mundo;
	friend class Nivel1;

	int prx, pry;			//posicion relativa al personaje principal
	int cerca=0;		//=1 si esta a menos de 5m, cambia el movimiento
};


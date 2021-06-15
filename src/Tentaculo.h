#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "Hitbox.h"
class Tentaculo
{
	float longitud = 5.0f;
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;
	Hitbox hitbox[3];
	int tempdmg = 0, flagdmg = 0, flagesp = 0, vida = 19;	////////////////////////////////////

public:
	Tentaculo();
	Tentaculo(float px, float py);
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setPos(float, float);
	friend class Interaccion;
	friend class Mundo;
	friend class Nivel1;

	float a;		//angulo de giro
	int prx, flag;			//posicion relativa al personaje principal, direccion de oscilacion
};
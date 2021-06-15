#pragma once
#include <ETSIDI.h>
#include "EnemigoDisp.h"
#include "Hitbox.h"
#include "ColorRGB.h"

class BolaFuego: public EnemigoDisp
{
protected:
	float radio;
	Vector2D posicion;
	Vector2D origen;
	Vector2D velocidad;
	Vector2D aceleracion;
	Hitbox hitbox;

	ColorRGB color;
public:

	BolaFuego();
	void setPos(float, float);
	void dibuja();
	void mueve(float t);
	float getRadio();//
	Vector2D getPos();//
	void setColor(Byte, Byte, Byte);

	friend class Interaccion;

};




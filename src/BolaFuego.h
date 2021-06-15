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
	Vector2D limitesy;
	Hitbox hitbox;
	ColorRGB color;
public:
	BolaFuego();
	BolaFuego(float posx, float posy, float limtop, float limbot);
	void setPos(float, float);
	void dibuja();
	void mueve(float t);
	void setColor(Byte, Byte, Byte);
	float getRadio();//
	Vector2D getPos();//

	friend class Interaccion;

};




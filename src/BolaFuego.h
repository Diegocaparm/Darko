#pragma once
#include <ETSIDI.h>
#include "EnemigoDisp.h"
#include "Hitbox.h"


class BolaFuego: public EnemigoDisp
{
protected:
	float radio;
	Vector2D posicion;
	Vector2D origen;
	Vector2D velocidad;
	Vector2D limitesy;
	Hitbox hitbox;
public:
	BolaFuego();
	BolaFuego(float posx, float posy, float limtop, float limbot);
	void setPos(float, float);
	void dibuja();
	void mueve(float t);
	float getRadio();//
	Vector2D getPos();//

	friend class Interaccion;

};




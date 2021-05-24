#pragma once
#include "Vector2D.h"
#include "Pared.h"

class Hitbox
{
public:
	Vector2D esquina1, esquina2, esquina3, esquina4;
	Pared arriba;
	Pared abajo;
	Pared derecha;
	Pared izquierda;
public:
	Hitbox();
	Hitbox(float x, float y);
	void setPared();
	void setPos(Vector2D e1, Vector2D e2, Vector2D e3, Vector2D e4);
};


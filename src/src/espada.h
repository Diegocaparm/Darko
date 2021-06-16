#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"
class espada
{
	float longitud = 1.5;
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;
	float angulo = 0;
	int flag = 0;
public:
	espada();
	espada(float px, float py);
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setPos(float px, float py);
	void setVel(float vx, float vy);
	Vector2D getPos();
	int getFlag();
	void setFlag(int);
	float getLong();
};


#include "PlatMovil.h"

PlatMovil::PlatMovil(float lim1x, float lim1y, float lim2x, float lim2y, float vx, float vy, float ex1x, float ex1y, float ex2x, float ex2y, Byte r, Byte g, Byte b)
{
	setColor(r, g, b);
	setPos(lim1x, lim1y, lim2x, lim2y);
	vel = { vx,vy };
	extremo1 = { ex1x,ex1y };
	extremo2 = { ex2x,ex2y };
}

void PlatMovil::mueve(float t)
{
	limite1 = limite1 + vel * t; //Movemos el limite 1 con la velocidad indicada
	limite2 = limite2 + vel * t; //Movemos el limite 2 con la velocidad indicada
	Vector2D puntomedio = { ((limite1.x + limite2.x) / 2),((limite1.y + limite2.y) / 2) };
	if (puntomedio.x <= extremo1.x) //Si llegamos a un extremo, invertimos la velocidad
	{ 
		vel.x = -vel.x;
		vel.y = -vel.y;
	}
	else if (puntomedio.x >= extremo2.x) //Si llegamos al otro extremo, invertimos la velocidad nuevamente
	{
		vel.x = -vel.x;
		vel.y = -vel.y;
	}
}

#pragma once
#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "DispTank.h"

class Tank
{
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;

public:
	Tank();
	float altura;
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setVelx(float);		//antes era void setVel(float, float);
	void setPos(float x, float y);
	friend class Interaccion;
	friend class Mundo;
	friend class Nivel1;

	int zonaV = 0, zonaH = 0;	//zonaV=0 abajo =1 arriba		zonaH=-1 izq =0 dentro =1 dcha
	int temp = 0, sentido = 1;	//temp contador para disparar	sentido=0 izq =1 dcha
	DispTank dispTank1, dispTank2, dispTank3, dispTank4, dispTank5;

};


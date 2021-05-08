#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "DispEnem.h"

class EnemigoDisp
{
	ColorRGB color;
	Vector2D posicion{ 4,8 }, velocidad, aceleracion;

public:
	EnemigoDisp();
	float altura;
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setVelx(float);		//antes era void setVel(float, float);

	friend class Interaccion;
	friend class Mundo;

	int zonaV = 0, zonaH = 0;	//zonaV=0 abajo =1 arriba		zonaH=-1 izq =0 dentro =1 dcha
	int temp = 0, sentido = 1;	//temp contador para disparar	sentido=0 izq =1 dcha
	DispEnem dispEnem1;

};


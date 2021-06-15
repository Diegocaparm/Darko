#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "disparosEnemigos.h"
#include "Hitbox.h"

class EnemigoDisp
{
	ColorRGB color;
	Vector2D posicion; 
	Vector2D velocidad;
	Vector2D aceleracion;
	Hitbox hitbox;
	int tempdmg = 0, flagdmg = 0, flagesp = 0, vida = 4;	////////////////////////////////////

public:
	EnemigoDisp();
	EnemigoDisp(float px, float py);
	float altura;
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setVelx(float);		//antes era void setVel(float, float);
	void setPos(float x, float y);

	friend class Interaccion;
	friend class Mundo;
	friend class Nivel1;

	int zonaV = 0, zonaH = 0;	//zonaV=0 abajo =1 arriba		zonaH =-1 izq = 0 dentro = 1 dcha
	int temp = 0, sentido = 1;	//temp contador para disparar	sentido=0 izq =1 dcha
	DisparosEnemigos * dispEnem1=new DisparosEnemigos();
};


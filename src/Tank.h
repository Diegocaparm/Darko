#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "disparosEnemigos.h"
#include "Hitbox.h"
class Tank
{
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;
	Hitbox hitbox;
	int tempdmg = 0, flagdmg = 0, flagesp = 0, vida = 9;	////////////////////////////////////

public:
	Tank();
	Tank(float px, float py);
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
	DisparosEnemigos* dispTank1 = new DisparosEnemigos(),
		* dispTank2 = new DisparosEnemigos(),
		* dispTank3 = new DisparosEnemigos(),
		* dispTank4 = new DisparosEnemigos(),
		* dispTank5 = new DisparosEnemigos();

};


#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "Hitbox.h"

class bomber
{
private:
	float radio;
	ColorRGB color;
	Hitbox hitbox;

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	bomber();									//Constructor
	bomber(float x, float y);					//Constructor que define posicion
	void setPos(float x, float y);				//Posici�n de vida
	Vector2D getPos();							//retorna la posicion de bomber	
	void setColor(Byte, Byte, Byte);
	void setVelx(float vx);
	void dibuja();								//Dibuja bomber
	void mueve(float t);						//Movimiento del bomber
	int zonaV = 0, zonaH = 0;					//zonaV=0 abajo =1 arriba		zonaH =-1 izq = 0 dentro = 1 dcha
	int sentido = 1;							//sentido=0 izq =1 dcha


	//friend class Interfaz;
	friend class Interaccion;
};

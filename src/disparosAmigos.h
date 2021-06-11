#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class disparosAmigos
{
	//atributos
	Vector2D posicion, velocidad, aceleracion;
	ColorRGB color;
	float radio;
	int temp = 0;	//temporizador para cambiar el color

public:
	//funciones
	disparosAmigos();
	disparosAmigos(float px, float py, float vx, float vy);
	void dibuja();
	void mueve(float);
	void setPos(float, float);
	void setVel(float, float);
	void setAc(float, float);
	void setColor(Byte, Byte, Byte);
	float getRadio();
	Vector2D getPos();

	friend class Hombre;


	float vel = 3.0;
	int flagdibujar = 1;	//flagdibujar=1 si dibuja	=0 no dibuja
	int zonaV = 0, zonaH = 0;// , sentido;	//inicializar
	//zonaV=0 abajo =1 arriba		zonaH =-1 izq = 0 dentro = 1 dcha
};

#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "Hitbox.h"
#include "disparosAmigos.h"

class Hombre
{
public:
	ColorRGB color;
	Vector2D posicion{ -4,11 };
	Vector2D velocidad;
	Vector2D aceleracion;
	Hitbox hitbox;
	float altura = 1.8f;
	bool mov;
	int salto = 1, sentido = 0, zonaV = 0, zonaH = 0, flag = 0, flagH = 0;
	//flagH=-1 izquierda	=0	quieto	   =1 derecha
public:
	Hombre();
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setVelx(float);		//antes era void setVel(float, float);
	Vector2D getPos();

	friend class Interaccion;
	friend class Mundo;
	friend class Nivel1;
	friend class Interfaz;
	friend class Vida;

	
};


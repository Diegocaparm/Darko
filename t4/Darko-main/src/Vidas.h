#pragma once
#include <freeglut.h>
#include <Vector2D.h>

class Vidas
{
public:
	int actual;
	int maximo;
	int aumento;
	int desviacion;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	Vidas();
	void setPos(float x, float y);
	void dibuja(float posx, float posy);
	void mueve(float t);
	void daño();
	int getCantidad();
	friend class Interfaz;

};


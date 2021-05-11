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

public:
	Vidas();
	void setPos(float x, float y);
	void dibuja(int posicion);
	int getCantidad();
	friend class Interfaz;

};


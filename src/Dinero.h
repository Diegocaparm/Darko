#pragma once
#include <Vector2D.h>
#include <Moneda.h>
#include <freeglut.h>
#include <Caja.h>
#include <Hombre.h>
#define MAX_MONEDAS 50

class Dinero
{
protected:
	Moneda* lista[MAX_MONEDAS];
	int numero;

public:
	Dinero();							//Constructor
	bool agregar(Moneda* d);			//Agrega Moneda
	void dibuja();						//Dibuja Moneda	
	void mueve(float t);				//Movimiento Moneda
	void rebote(Pared pared);
	void rebote(Caja caja);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Moneda* d);
	Moneda* colision(Hombre h);
	Moneda* operator [] (int i);

};


#pragma once
#include <freeglut.h>
#include <Vector2D.h>
#include <Corazon.h>
#include <Caja.h>
#include <Hombre.h>

#define MAX_VIDAS 10

class Vidas
{
public:
	Corazon* lista[MAX_VIDAS];
	int numero;

public:
	Vidas();							//Constructor
	bool agregar(Corazon* c);			//Agrega Un Corazon
	void dibuja();						//Dibuja Corazon	
	void mueve(float t);
	void rebote(Pared pared);
	void rebote(Caja caja);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Corazon* e);
	Corazon* colision(Hombre h);
	Corazon* operator [] (int i);
	

	friend class Interfaz;
};

#pragma once
#include "Caja.h"
#include "babosa.h"
#include "listaPlat.h"
#include "Hombre.h"

#define MAX_BABOSAS 100
class listaBabosas
{
	Babosa* lista[MAX_BABOSAS];
	int numero;
public:
	listaBabosas();
	void dibuja();
	void mueve(float t);
	bool agregar(Babosa* ene);
	void mov(Hombre);
	//void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Babosa* ene);

	//Esfera* operator[](int i);
	int getNumero() { return numero; }

	friend class Interaccion;
};
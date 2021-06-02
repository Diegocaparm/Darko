#pragma once
#include "bomber.h"
#include "Caja.h"
#include "listaPlat.h"

#define MAX_BOMBER 100
class listabomber 
{
	bomber* lista[MAX_BOMBER];
	int numero;
public:
	listabomber();
	void dibuja();
	void mueve(float t);
	bool agregar(bomber* ene);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote(listaPlat lp);
	//void rebote();
	void destruirContenido();
	void eliminar(int index);
	//void eliminar(bomber* ene);

	//Esfera* operator[](int i);
	int getNumero() { return numero; }

	friend class Interaccion;
};


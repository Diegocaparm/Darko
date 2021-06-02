#pragma once
#include "Caja.h"
#include "Tank.h"
#include "listaPlat.h"
#include "Hombre.h"

#define MAX_TANK 100
class listaTank
{
	Tank* lista[MAX_TANK];
	int numero;
public:
	listaTank();
	void dibuja();
	void mueve(float t);
	bool agregar(Tank* ene);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote(listaPlat lp);
	//void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Tank* ene);

	//Esfera* operator[](int i);
	int getNumero() { return numero; }

	friend class Interaccion;
};

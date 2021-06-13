#pragma once
#include "Tentaculo.h"
#include "Caja.h"
#include "listaPlat.h"
#include "Hombre.h"

#define MAX_TENTACULO 100
class listaTentaculo
{
	Tentaculo* lista[MAX_TENTACULO];
	int numero;
public:
	listaTentaculo();
	void dibuja();
	void mueve(float t);
	bool agregar(Tentaculo* ene);
	/*void rebote(Caja caja);
	void rebote(Pared p);
	void rebote(listaPlat lp);*/
	//void rebote();
	void colision(Hombre& h);
	void destruirContenido();
	void eliminar(int index);
	//void eliminar(bomber* ene);

	//Esfera* operator[](int i);
	int getNumero() { return numero; }

	friend class Interaccion;
};

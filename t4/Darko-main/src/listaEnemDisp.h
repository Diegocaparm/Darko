#pragma once
#include "Caja.h"
#include "EnemigoDisp.h"
#include "listaPlat.h"

#define MAX_ENEMDISP 100
class listaEnemDisp
{
	EnemigoDisp* lista[MAX_ENEMDISP];
	int numero;
public:
	listaEnemDisp();
	void dibuja();
	void mueve(float t);
	bool agregar(EnemigoDisp* ene);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote(listaPlat lp);
	void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(EnemigoDisp* ene);
	//EnemigoDisp* colision(Hombre& h);

	//Esfera* operator[](int i);
	int getNumero() { return numero; }
};


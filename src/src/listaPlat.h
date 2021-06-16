#pragma once
#include "Pared.h"
#include "PlatMovil.h"
#define MAX_PAREDES 100

class listaPlat
{
	Pared *lista[MAX_PAREDES];
	PlatMovil* listamov[MAX_PAREDES];
	int numero;
	int numv;
public:
	listaPlat();
	void dibuja();
	bool agregar(Pared* p);
	bool agregar(PlatMovil* p);
	void mueve(float);

	friend class Interaccion;
	friend class listaEnemDisp;
	friend class listaTank;
	friend class listabomber;
	friend class listaDispEnem;
	friend class listaDispAmig;
	friend class listamisiles;
};


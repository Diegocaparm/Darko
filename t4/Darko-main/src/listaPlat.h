#pragma once
#include "Pared.h"
#define MAX_PAREDES 100
class listaPlat
{
	Pared *lista[MAX_PAREDES];
	int numero;
public:
	listaPlat();
	void dibuja();
	bool agregar(Pared* p);

	friend class Interaccion;
	friend class listaEnemDisp;
};


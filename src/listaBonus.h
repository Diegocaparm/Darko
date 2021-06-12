#pragma once
#include "Bonus.h"
#include "Hombre.h"
#include "Interaccion.h"
#define MAX_BONUS 100
class listaBonus
{
	Bonus* lista[MAX_BONUS];
	int numero;
public:
	listaBonus();
	void dibuja();
	bool agregar(Bonus* p);
	void rebote(Hombre& h);
	friend class Interaccion;
};


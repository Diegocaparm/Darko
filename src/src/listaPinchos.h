#pragma once
#include "Pincho.h"
#include "Hombre.h"
#include "Interaccion.h"
#include "VidasRec.h"

#define MAX_PINCHOS 100
class listaPinchos
{
	Pincho* lista[MAX_PINCHOS];
	int numero;
public:
	listaPinchos();
	void dibuja();
	bool agregar(Pincho* p);
	void rebote(Hombre& h, VidasRec& v);
	friend class Interaccion;
};


#pragma once
#include "Solidos.h"
#include "Personaje.h"
#include "Recolectable.h"
#include "Enemigo.h"
#define MAX_SOLIDOS 50

class ListaSolidos
{
private:
	Solidos* lista[MAX_SOLIDOS];
	int numero;
public:
	ListaSolidos();
	bool agregar(Solidos* s);
	void dibuja(int i);
	void mueve(float t);
	void rebote(Personaje& pj, VidasRecolectadas& v);
	void destruirContenido();
	friend class Interaccion;
};


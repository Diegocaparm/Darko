#pragma once
#include "Enemigo.h"
#include "Personaje.h"
#include "Recolectable.h"
#include "Disparos.h"
#define MAX_DISP 250

class ListaDisparos
{
private:
	Disparos* lista[MAX_DISP];
	int numero;
public:
	ListaDisparos();
	bool agregar(Disparos* d);
	bool agregar(Disparos* d, Enemigo e);
	void dibuja();
	void mueve(float t);
	void colision(Personaje& pj, VidasRecolectadas& v);
	friend class Interaccion;
};


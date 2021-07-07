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
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Disparos* e);
	Disparos* operator [] (int i);
	friend class Interaccion;
};


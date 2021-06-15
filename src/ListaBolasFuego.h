#pragma once
#include "BolaFuego.h"
#include "Interaccion.h"
#include "Caja.h"
#include "Hombre.h"

#define NBOLAS 20
class ListaBolasFuego
{
	BolaFuego* lista[NBOLAS];
	int num;
public:
	ListaBolasFuego();
	void dibuja();
	void mueve(float t);
	bool agregar(BolaFuego* bola);
	void rebote(Hombre& h);
	void destruirContenido();
	void eliminar(int index);
	friend class Interaccion;
};


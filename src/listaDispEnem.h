#pragma once
#include "Caja.h"
#include "DisparosEnemigos.h"
#include "listaPlat.h"
#include "Hombre.h"

#define MAX_DISPENEM 100
class listaDispEnem
{
	DisparosEnemigos* lista[MAX_DISPENEM];
	int numero;
public:
	listaDispEnem();
	void dibuja();
	void mueve(float t);
	void setPos(float px, float py);
	void setColor(Byte r, Byte g, Byte b);
	bool agregar(DisparosEnemigos* disp);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote(listaPlat lp);
	void rebote(Hombre h);
	//void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(DisparosEnemigos* DE);

	//Esfera* operator[](int i);
	int getNumeroDE() { return numero; }

	friend class Interaccion;
};


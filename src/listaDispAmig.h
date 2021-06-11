#pragma once
#include "Caja.h"
#include "DisparosAmigos.h"
#include "listaPlat.h"
#include "Hombre.h"

#define MAX_DISPAMIG 100
class listaDispAmig
{
	disparosAmigos* lista[MAX_DISPAMIG];
	int numero;
public:
	listaDispAmig();
	void dibuja();
	void mueve(float t);
	void setPos(float px, float py);
	void setColor(Byte r, Byte g, Byte b);
	bool agregar(disparosAmigos* disp);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote(listaPlat lp);
	//void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(disparosAmigos* DE);

	//Esfera* operator[](int i);
	int getNumeroDE() { return numero; }

	friend class Interaccion;

};


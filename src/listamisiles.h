#pragma once
#include "Caja.h"
#include "misil.h"
#include "listaPlat.h"
#include "Hombre.h"
#include "VidasRec.h"

#define MAX_MISIL 100
class listamisiles
{
	misil* lista[MAX_MISIL];
	int numero;
public:
	listamisiles();
	void dibuja();
	void mueve(float t);
	void setPos(float px, float py);
	void setColor(Byte r, Byte g, Byte b);
	bool agregar(misil* disp);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote(listaPlat lp);
	void rebote(Hombre h, VidasRec& v);
	//void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(misil* DE);

	//Esfera* operator[](int i);
	int getNumeroDE() { return numero; }

	friend class Interaccion;
};


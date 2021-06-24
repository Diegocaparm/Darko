#pragma once
#include "Disparos.h"
#include "Enemigo.h"
#include "Solidos.h"

#define MAX_NUM 1000
#define MAX_DISP 100
#define MAX_ENEM 100
class listas
{
	ObjetoMovil* lista[MAX_NUM];
	int numero;
public:
	listas();
	void dibuja();
	void mueve(float t);
	void setPos(float px, float py);
	void setColor(Byte r, Byte g, Byte b);
	bool agregar(ObjetoMovil* disp);
	//void rebote(Caja caja);
	void rebote(Pared p);
	//void rebote(listaPlat lp);

	//void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(ObjetoMovil* DE);

	//Esfera* operator[](int i);
	int getNumeroDE() { return numero; }

	friend class Interaccion;
};

class listaDisparos :public listas
{
	Disparos* lista[MAX_DISP];
};

class listasEnemigos :public listas
{
	Enemigo* lista[MAX_ENEM];
};

class listaDisparosAmigos :public listaDisparos
{
	disparosAmigos* lista[MAX_DISP];
};
class listaDisparosEnemigos :public listaDisparos
{
	disparosEnemigos* lista[MAX_DISP];
};
class listaMisiles :public listaDisparos
{
	misiles* lista[MAX_DISP];
};


class listaEnemDisp :public Enemigo
{
	EnemigoDisp* lista[MAX_ENEM];
};
class listaTank :public Enemigo
{
	Tank* lista[MAX_ENEM];	//solo hay un boss asi que no deberia hacer falta lista
};
class listaBabosa :public Enemigo
{
	babosa* lista[MAX_ENEM];
};
class listaBomber :public Enemigo
{
	bomber* lista[MAX_ENEM];
};
class listaTentaculo :public Enemigo
{
	Tentaculo* lista[MAX_ENEM];
};

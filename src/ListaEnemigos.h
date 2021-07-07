#pragma once
#include "Disparos.h"
#include "Enemigo.h"
#include "ListaSolidos.h"

#define MAX_NUM 1000
#define MAX_DISP 100
#define MAX_ENEM 100

class ListaEnemigos
{
private:
	Enemigo* lista[MAX_ENEM];
	int numero;
public:
	ListaEnemigos();
	bool agregar(Enemigo* e);
	void dibuja();
	void mueve(float t);
	void eliminar(Enemigo* e);
	friend class Interaccion;
};














//objeto movil
/*
class listaObjetoMovil
{
protected:
	ObjetoMovil* lista[MAX_NUM];
	int numero;
public:
	listaObjetoMovil();
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
	void eliminarindex(int index);
	void eliminar(ObjetoMovil* DE);

	//Esfera* operator[](int i);
	int getNumeroDE() { return numero; }

	friend class Interaccion;
};
//generales disparos y enemigos
class listaDisparos :public listaObjetoMovil
{
protected:
	Disparos* lista[MAX_DISP];
public:
	bool agregar(Disparos* disp);
	void eliminar(Disparos* DE);
};
class listasEnemigos :public listaObjetoMovil
{
protected:
	Enemigo* lista[MAX_ENEM];
public:
	bool agregar(Enemigo* disp);
	void eliminar(Enemigo* DE);
};

//especificas disparos
class listaDisparosAmigos :public listaDisparos
{
	disparosAmigos* lista[MAX_DISP];
public:
	bool agregar(disparosAmigos* disp);
	void eliminar(disparosAmigos* DE);
};
class listaDisparosEnemigos :public listaDisparos
{
	disparosEnemigos* lista[MAX_DISP];
public:
	bool agregar(disparosEnemigos* disp);
	void eliminar(disparosEnemigos* DE);
};
class listaMisiles :public listaDisparos
{
	misiles* lista[MAX_DISP];
public:
	bool agregar(misiles* disp);
	void eliminar(misiles* DE);
};


/*

//especificas enemigos
class listaEnemDisp :public listasEnemigos
{
	EnemigoDisp* lista[MAX_ENEM];
public:
	bool agregar(EnemigoDisp* disp);
	void eliminar(EnemigoDisp* DE);
};
class listaTank :public listasEnemigos
{
	Tank* lista[MAX_ENEM];	//solo hay un boss asi que no deberia hacer falta lista
public:
	bool agregar(Tank* disp);
	void eliminar(Tank* DE);

};
class listaBabosa :public listasEnemigos
{
	babosa* lista[MAX_ENEM];
public:
	bool agregar(babosa* disp);
	void eliminar(babosa* DE);
};
class listaBomber :public listasEnemigos
{
	bomber* lista[MAX_ENEM];
public:
	bool agregar(bomber* disp);
	void eliminar(bomber* DE);
};
class listaTentaculo :public listasEnemigos
{
	Tentaculo* lista[MAX_ENEM];
public:
	bool agregar(Tentaculo* disp);
	void eliminar(Tentaculo* DE);
};
*/
#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "Caja.h"
//#include "Personaje.h"
#define MAX_VIDAS 5
#define MAX_MONEDAS 50

//Declaracion directa
class Personaje;

using ETSIDI::SpriteSequence;

class Recolectable
{
protected:
	Vector2D posicion;
	float radio;
public:
	Recolectable();
	Recolectable(float x, float y);
	virtual void setPos(float x, float y);				//Set Posicion
	virtual Vector2D getPos();							//retorna Posicion
	friend class Interaccion;

};
//Corazon herencia de Recolectable
class Corazon :public Recolectable
{
private:
	SpriteSequence sprite{"bin/imagenes/corazon.png",1 };
public:
	Corazon();
	Corazon(float x, float y);
	void dibuja();
	void mueve(float t);
	friend class Interaccion;
};
//Moneda herencia de Recolectable
class Moneda : public Recolectable
{
private:
	SpriteSequence sprite{ "bin/imagenes/moneda.png", 7 };
public:
	Moneda();
	Moneda(float x, float y);
	void dibuja();
	void mueve(float t);
	friend class Interaccion;
};

//Lista de vidas
class Vidas
{
protected:
	Corazon* lista[MAX_VIDAS];
	int numero;
public:
	Vidas();							//Constructor
	bool agregar(Corazon* c);			//Agrega Un Corazon
	void dibuja();						//Dibuja Corazon	
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Corazon* e);
	Corazon* recoleccion(Personaje h);
	Corazon* operator [] (int i);
	friend class Interaccion;
};
//Vidas recolectadas herencia de Vidas
class VidasRecolectadas : public Vidas
{
private:
	int vida_inicial = 3;
	int contador_vidas = -1;
public:
	
	bool agregar(Corazon* c);			//Agrega Un Corazon Recolectado
	void eliminar(int i);
	void mueve(float t, float posx);
	int getVidas();
	int getVidasInicial();
	void reduceVida();
	bool FinVida();
	friend class Interaccion;
};

//Lista de monedas
class Dinero
{
protected:
	Moneda* lista[MAX_MONEDAS];
	int numero;

public:
	Dinero();							//Constructor
	bool agregar(Moneda* d);			//Agrega Moneda
	void dibuja();						//Dibuja Moneda	
	void mueve(float t);				//Movimiento Moneda
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Moneda* d);
	Moneda* recoleccion(Personaje h);
	Moneda* operator [] (int i);
	friend class Interaccion;
};
//DineroRecolectado herencia de Dinero
class DineroRecolectados : public Dinero
{
private:
	int dinero_actual = 0;
	SpriteSequence nUnidad{ "bin/imagenes/numero.png",10 };
	SpriteSequence nDecena{ "bin/imagenes/numero.png",10 };
	Vector2D pos;

public:
	DineroRecolectados();
	void mueve(float t, Vector2D v);
	void aumentaDinero();
	void dibujaContador();
	void getVida(VidasRecolectadas *v); //Si coge 100 monedas, se le a?ade 2 vidas
	friend class Interaccion;
};
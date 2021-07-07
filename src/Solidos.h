#pragma once
#include "Hitbox.h"
#include "ColorRGB.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
class Solidos
{
protected:
	Vector2D posicion;
	ColorRGB color;
	int cosa=0;	//1 pared, 2 plat movil, 3 suelo, 4 final, 5 pincho, 6 bola
public:
	Solidos();
	//~Solidos();
	virtual void setPos(float px, float py);
	virtual void setColor(Byte r, Byte g, Byte b);
	virtual void dibuja();
	virtual void mueve(float t);
	void setCosa(int);
	int getCosa();
	friend class Interaccion;

};
//Pared herencia de SOLIDO
class Pared : public Solidos
{
protected:
	Vector2D limite1, limite2;
public:
	Pared();
	Pared(float x1, float y1, float x2, float y2, Byte r, Byte g, Byte b); //Constructor automático
	virtual void setLims(float x1, float y1, float x2, float y2); //Establece los dos limites de la plataforma
	virtual void dibuja();
	virtual float distancia(Vector2D punto, Vector2D* direccion = 0);
	bool operator ==(Pared);
	friend class Interaccion;
};
//Plataforma móvil herencia de PARED
class PlatMovil : public Pared 
{
private:
	Vector2D vel;
	Vector2D extremo1, extremo2;
public:
	PlatMovil(float, float, float, float, float, float, float, float, float, float, Byte, Byte, Byte); //Constructor completo
	void mueve(float);
	friend class Interaccion;
};
//Suelo herencia de PARED
class Suelo : public Pared 
{
private:
	Vector2D bajo1, bajo2;
public:
	Suelo(float limx1, float altura, float limx2, float bajo); //Constructor con anchura y altura
	void dibuja();
	friend class Interaccion;
};
//Final herencia de PARED
class Final : public Pared
{
public:
	Final(float x1, float y1, float x2, float y2); //Constructor propio
	friend class Interaccion;
};
//Pincho herencia de SOLIDO
class Pincho : public Solidos
{
protected:
	Hitbox hitbox;
	SpriteSequence sprite{ "bin/imagenes/pinchos.png", 1 };
public:
	Pincho();
	Pincho(float px, float py);
	void dibuja();
	friend class Interaccion;
};
//BolaFuego herencia de PINCHO
class BolaFuego : public Pincho
{
private:
	Vector2D vel, borde;
public:
	BolaFuego(float px, float py, float limtop, float limbot);
	void dibuja();
	void mueve(float t);
	friend class Interaccion;
	SpriteSequence fireball;
};



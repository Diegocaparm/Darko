#pragma once
#include "Hitbox.h"
#include "Vector2D.h"
#include "ColorRGB.h"

class Solidos
{
protected:
	Vector2D posicion;
	ColorRGB color;
public:
	Solidos();
	//~Solidos();
	virtual void setPos(float px, float py);
	virtual void setColor(Byte r, Byte g, Byte b);

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
	float distancia(Vector2D punto, Vector2D* direccion = 0);
	bool operator ==(Pared);
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
	Suelo(float limx1, float limy1, float limx2, float limy2); //Constructor con anchura y altura
	void dibuja();
};
//Pincho herencia de SOLIDO
class Pincho : public Solidos
{
private:
	//float altura = 2.5f;
	Hitbox hitbox;
public:
	Pincho(float px, float py);
	void dibuja();
};
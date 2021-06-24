#pragma once
#include "ObjetoMovil.h"
class Enemigo :
    public ObjetoMovil
{
protected:
    int tempdmg = 0, flagdmg = 0, flagesp = 0, vida = 0;	////////////////////////////////////
    float altura = 0.5;   //altura, radio, longitud
    int zonaV = 0, zonaH = 0;	//zonaV=0 abajo =1 arriba		zonaH =-1 izq = 0 dentro = 1 dcha
    int temp = 0, sentido = 1;	//temp contador para disparar	sentido=0 izq =1 dcha

public:
    Enemigo();
};

class EnemigoDisp :
    public Enemigo
{

public:
    EnemigoDisp(float px, float py);
    void dibuja();
    void mueve(float t);
};

class Tank :
    public Enemigo
{

public:
    Tank();
    Tank(float px, float py);
    void dibuja();
    void mueve(float t);

};

class babosa :
    public Enemigo
{
    int prx =1, pry = 1;		//px=1 derecha   py=1 arriba
    int cerca = 0;		//=1 si esta a menos de 5m, cambia el movimiento

public:
    babosa(float px, float py);
    void dibuja();
    void mueve(float t);

};

class bomber :
    public Enemigo
{

public:
    bomber(float px, float py);
    void dibuja();
    void mueve(float t);

};

class Tentaculo :
    public Enemigo
{
    int flag = 0;       //direccion de oscilacion
    float angulo = 0;   //angulo de giro
public:
    Tentaculo(float px, float py);
    void dibuja();
    void mueve(float t);

};

class BossFinal :
    public Tank
{

public:
    BossFinal(float px, float py);
    void dibuja();
    void mueve(float t);

};

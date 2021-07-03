#pragma once
#include "ObjetoMovil.h"
#include "Disparos.h"

//Enemigo herencia de OBJETOMOVIL
class Enemigo : public ObjetoMovil
{
protected:
    int tempdmg = 0, flagdmg = 0, flagesp = 0, vida = 0;	////////////////////////////////////
    float altura = 0.5;   //altura, radio, longitud
    int temp = 0, sentido = 1;	//temp contador para disparar	sentido=0 izq =1 dcha
public:
    Enemigo();
    virtual void dibuja();
    virtual void mueve(float t);
    friend class Interaccion;
};
//EnemigoDisp herencia de ENEMIGO
class EnemigoDisp : public Enemigo
{
public:
    EnemigoDisp(float px, float py);
    void dibuja();
    void mueve(float t);
    DisparosEnemigos* dispEnem1 = new DisparosEnemigos(posicion.x, posicion.y);
    friend class Interaccion;
};
//Babosa herencia de ENEMIGO
class Babosa : public Enemigo
{
private:
    int prx =1, pry = 1;		//px=1 derecha   py=1 arriba
    int cerca = 0;		//=1 si esta a menos de 5m, cambia el movimiento
public:
    Babosa(float px, float py);
    void dibuja();
    void mueve(float t);
    friend class Interaccion;
};
//Bomber herencia de ENEMIGO
class Bomber : public Enemigo
{
    int flag = 0;
public:
    Bomber(float px, float py);
    void dibuja();
    void mueve(float t);

    friend class Interaccion;
};
//Tentáculo herencia de ENEMIGO
class Tentaculo : public Enemigo
{
private:
    int flag = 0;       //direccion de oscilacion
    float angulo = 0;   //angulo de giro
public:
    Tentaculo(float px, float py);
    void dibuja();
    void mueve(float t);
    friend class Interaccion;
};
//Tank herencia de ENEMIGO
class Tank : public Enemigo
{
public:
    Tank();
    Tank(float px, float py);
    void dibuja();
    void mueve(float t);
    DisparosEnemigos* dispTank1 = new DisparosEnemigos(posicion.x,posicion.y),
        * dispTank2 = new DisparosEnemigos(posicion.x, posicion.y),
        * dispTank3 = new DisparosEnemigos(posicion.x, posicion.y),
        * dispTank4 = new DisparosEnemigos(posicion.x, posicion.y),
        * dispTank5 = new DisparosEnemigos(posicion.x, posicion.y);
    friend class Interaccion;
};
//BossFinal herencia de TANK
class BossFinal : public Tank
{
public:
    BossFinal(float px, float py);
    void dibuja();
    void mueve(float t);
    Misiles* misil1 = new Misiles(posicion.x, posicion.y + altura / 2),
        * misil2 = new Misiles(posicion.x, posicion.y + altura / 2),
        * misil3 = new Misiles(posicion.x, posicion.y + altura / 2),
        * misil4 = new Misiles(posicion.x, posicion.y + altura / 2),
        * misil5 = new Misiles(posicion.x, posicion.y + altura / 2),
        * misil6 = new Misiles(posicion.x, posicion.y + altura / 2),
        * misil7 = new Misiles(posicion.x, posicion.y + altura / 2),
        * misil8 = new Misiles(posicion.x, posicion.y + altura / 2),
        * misil9 = new Misiles(posicion.x, posicion.y + altura / 2),
        * misil10 = new Misiles(posicion.x, posicion.y + altura / 2);
    friend class Interaccion;
};

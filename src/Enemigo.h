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
    disparosEnemigos* dispEnem1 = new disparosEnemigos();
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
};
//Tank herencia de ENEMIGO
class Tank : public Enemigo
{
public:
    Tank();
    Tank(float px, float py);
    void dibuja();
    void mueve(float t);
    disparosEnemigos* dispTank1 = new disparosEnemigos(),
        * dispTank2 = new disparosEnemigos(),
        * dispTank3 = new disparosEnemigos(),
        * dispTank4 = new disparosEnemigos(),
        * dispTank5 = new disparosEnemigos();
};
//BossFinal herencia de TANK
class BossFinal : public Tank
{
public:
    BossFinal(float px, float py);
    void dibuja();
    void mueve(float t);
};

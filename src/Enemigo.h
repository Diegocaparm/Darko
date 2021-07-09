#pragma once
#include "ObjetoMovil.h"
#include "Disparos.h"
#include <math.h>
#define pi 3.14159265359
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

//Enemigo herencia de OBJETOMOVIL
class Enemigo : public ObjetoMovil
{
protected:
    int cosa = 0;   //1 disp, 2 tank, 3 babosa, 4 bomber, 5 tent, 6 boss
    int tempdmg = 0, flagdmg = 0, flagesp = 0, vida = 1;	////////////////////////////////////
    float altura = 0.5;   //altura, radio, longitud
    int temp = 40, sentido = 1;	//temp contador para disparar	sentido=0 izq =1 dcha
    int var=0; //variable para cambiar de sprite cada seg
public:
    Enemigo();
    virtual void dibuja();
    virtual void mueve(float t);
    virtual int getVida(){ return vida; };
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
    SpriteSequence sprite{ "bin/imagenes/frankfvect.png", 2 };
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
    SpriteSequence sprite{ "bin/imagenes/babfvect.png", 2 };
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
    SpriteSequence sprite{ "bin/imagenes/bomberfvect.png", 2 };
};
//Tentáculo herencia de ENEMIGO
class Tentaculo : public Enemigo
{
private:
    int flag = 0;       //direccion de oscilacion
    float angulo = 0;   //angulo de giro
    Hitbox hitbox[3];
public:
    Tentaculo(float px, float py);
    void dibuja();
    void mueve(float t);
    friend class Interaccion;
   SpriteSequence sprite{ "bin/imagenes/tentfvect1.png", 4 };
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
    SpriteSequence sprite{ "bin/imagenes/tanquefvect.png", 1 };
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
    SpriteSequence sprite{ "bin/imagenes/megatanquefvect.png", 1 };
};

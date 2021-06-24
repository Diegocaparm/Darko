#pragma once
#include "ObjetoMovil.h"
class Disparos :
    public ObjetoMovil
{
protected:
    float radio;
    float temp = 0;
    float vel = 3;      //velocidad inicial
public:
    Disparos();
    Disparos(float px, float py);
    virtual void dibuja();
    virtual void mueve(float);
    virtual void setPos(float, float);
    virtual void setVel(float, float);
    virtual void setAc(float, float);
    virtual void setColor(Byte, Byte, Byte);
    virtual float getRadio();
    
};

class disparosAmigos :
    public Disparos
{
public:
    disparosAmigos(float px, float py);
};

class disparosEnemigos :
    public Disparos
{
public:
    disparosEnemigos(float px, float py);

};

class misiles :
    public Disparos
{
    int prx=0, pry=0;		//posicion relativa al personaje principal
    int cerca = 0;		//=1 si esta a menos de 5m, cambia el movimiento
public:
    misiles(float px, float py);
    void mueve(float);
    
};


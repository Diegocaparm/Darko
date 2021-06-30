#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"

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
    float getVelDef() { return vel; }

    friend class Interaccion;
};
//DisparosAmigos herencia de DISPAROS
class DisparosAmigos : public Disparos
{
public:
    DisparosAmigos(float px, float py);
};
//Espada herencia de DISPAROS
class Espada : public Disparos
{
    int flag = 0;
    float angulo = 0;
public:
    Espada(float px, float py);
    void mueve(float t);
    int getFlag();
    void setFlag(int);
    float getLong();
};
//DisparosEnemigos herencia de DISPAROS
class DisparosEnemigos : public Disparos
{
public:
    DisparosEnemigos(float px, float py);
};
//Misiles herencia de DISPAROS
class Misiles : public Disparos
{
    int prx=0, pry=0;		//posicion relativa al personaje principal
    int cerca = 0;		//=1 si esta a menos de 5m, cambia el movimiento
public:
    Misiles(float px, float py);
    void mueve(float);
    
    friend class Interaccion;
};

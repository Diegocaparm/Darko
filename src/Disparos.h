#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"

class Disparos :
    public ObjetoMovil
{
protected:
    float radio=0.15;
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
    DisparosAmigos(float px, float py, float vx, float vy);
    friend class Interaccion;
};
//Espada herencia de DISPAROS
class Espada : public Disparos
{
    int flag = 0;
    float angulo = 0;
public:
    Espada();
    Espada(float px, float py);
    void dibuja();
    void mueve(float t);
    int getFlag();
    void setFlag(int);
    float getLong();
    friend class Interaccion;
};
//DisparosEnemigos herencia de DISPAROS
class DisparosEnemigos : public Disparos
{
public:
    DisparosEnemigos();
    DisparosEnemigos(float px, float py);
    friend class Interaccion;
};
//Misiles herencia de DISPAROSENEMIGOS
class Misiles : public DisparosEnemigos
{
    int prx=0, pry=0;		//posicion relativa al personaje principal
    int cerca = 0;		//=1 si esta a menos de 5m, cambia el movimiento
public:
    Misiles(float px, float py);
    void mueve(float);
    
    friend class Interaccion;
};


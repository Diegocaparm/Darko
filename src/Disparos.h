#pragma once
#include "ObjetoMovil.h"
#include "ColorRGB.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Disparos : public ObjetoMovil
{
protected:
    int cosa;
    float radio=0.15f;
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
    SpriteSequence sprite{ "bin/imagenes/disparo.png", 4 };
};
//DisparosAmigos herencia de DISPAROS
class DisparosAmigos : public Disparos
{
public:
    DisparosAmigos();
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
    SpriteSequence sprite{ "bin/imagenes/espada.png", 1 };
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
    Misiles();
    Misiles(float px, float py);
    void mueve(float);
    void dibuja();
    
    friend class Interaccion;
    SpriteSequence misil{ "bin/imagenes/misil.png", 4,1 };
};


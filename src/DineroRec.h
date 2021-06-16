#pragma once
#include "Dinero.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class DineroRec :
    public Dinero
{
private:
    int dinero_actual=0;
    SpriteSequence nUnidad{ "imagenes/numero.png",10 };
    SpriteSequence nDecena{ "imagenes/numero.png",10 };
    Vector2D pos;
public:
    DineroRec();
    void mueve(float t,Vector2D v);
    void aumentaDinero();
    void dibujaContador();
    
};


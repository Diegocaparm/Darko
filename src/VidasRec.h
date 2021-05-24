#pragma once
#include "Vidas.h"
#include "Hombre.h"
class VidasRec :
    public Vidas
{
private:
    int vida_inicial= 3;
public:
    void mueve(float t,float posx);
    int getVidas();
    void reduceVida();
};


#pragma once
#include "Dinero.h"
class DineroRec :
    public Dinero
{
private:
    int dinero_actual=0;
public:
    void mueve(float t, float posx);
    void aumentaDinero();
    void dibujaContador(float posx);
};


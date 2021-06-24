#pragma once
#include "ObjetoMovil.h"
class Personaje :
    public ObjetoMovil
{
    float altura = 1.8f;
    int salto = 1, sentido = 0, zonaV = 0, zonaH = 0, flag = 0, flagH = 0;
    //flagH=-1 izquierda	=0	quieto	   =1 derecha
public:
    Personaje();
    void dibuja();
    void mueve(float t);
};


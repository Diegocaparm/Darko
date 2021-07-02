#pragma once
#include "Disparos.h"
#include "ListaDisparos.h"
class Personaje : public ObjetoMovil
{
private:
    float altura = 1.8f;
    int salto = 1, sentido = 0, flag = 0, flagH = 0, disparo = 0;
    //flagH=-1 izquierda	=0	quieto	   =1 derecha

public:
    Personaje();
    void dibuja();
    void mueve(float t);
    //void dispara();
    DisparosAmigos* bala = new DisparosAmigos(posicion.x, posicion.y);

    friend class Interaccion;
    friend class Nivel;
};


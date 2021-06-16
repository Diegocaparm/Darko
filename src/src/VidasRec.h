#pragma once
#include "Vidas.h"
#include "Hombre.h"
#include "EnemigoDisp.h"


class VidasRec :
    public Vidas
{
private:
    int vida_inicial= 3;
    int contador_vidas = -1;
   
public:
    bool agregar(Corazon* c);			//Agrega Un Corazon
    void eliminar(int i);
   //void eliminar(Corazon* e);
    void mueve(float t,float posx);
    int getVidas();
    int getVidasInicial();
    void reduceVida();
   // Corazon* colisionEnemigoDisp(EnemigoDisp e);
};


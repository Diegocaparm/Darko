#pragma once
#include "Disparos.h"
#include "ListaDisparos.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;// para usar el sprite del hombre
class Personaje : public ObjetoMovil
{
private:
    float altura = 2.5f;
    int salto = 1;
    int sentido = 0;
    int flag = 0;
    int flagH = 0; //-1 izquierda   =0 quieto   =1 derecha
    int disparo = 0; //Flag para que el hombre dispare
    int flagnivel = 7, nivelaux = 0; //Indica el nivel donde estamos, aumenta al llegar al final
    int tempdmg = 0;
    int guardapersonaje; //Sin inicializar porque se ha de elegir
    SpriteSequence sprite_darko, sprite_humano;
    SpriteSequence* puntero;
public:
    Personaje();
    void dibuja();
    void mueve(float t);
    int getNivel();
    //DisparosAmigos* bala = new DisparosAmigos(posicion.x, posicion.y);
    //SpriteSequence sprite{ "bin/imagenes/darkoespfvect.png", 2 };

    int setPersonaje(unsigned char key);
    int getguardapersonaje() { return guardapersonaje; }
    void setDarko() { puntero = &sprite_darko; }
    void setHumano() { puntero = &sprite_humano; }

    friend class Interaccion;
    friend class Nivel;
    friend class Solidos;
    friend class Pared;
    //friend class Vida;
};


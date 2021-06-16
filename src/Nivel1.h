#pragma once
#include "Caja.h"
#include "listaPlat.h"
#include "listaPinchos.h"
#include "Disparo.h"
#include "Hombre.h"
#include "listaDispAmig.h"
#include "Interaccion.h"
#include "listaEnemDisp.h"
#include "listaTank.h"
#include "listaDispEnem.h"
#include "babosa.h"		
#include "listaBabosas.h"
#include "Tentaculo.h"
#include "listaTent.h"
#include "listabomber.h"
#include "bossFinal.h"
#include "listamisiles.h"
#include "VidasRec.h"
#include "DineroRec.h"
#include "espada.h"
#include "ListaBolasFuego.h"

class Nivel1
{
//Atributos
public:
	//Interfaz intz;
	float x_ojo;
	float y_ojo;
	float z_ojo;

	int nivel; //Será lo que usemos para identificar en que nivel estamos
	//Estructura del nivel
	Caja caja;
	listaPlat plataformas;
	listaPinchos listPinchos;
	ListaBolasFuego listaFuego;

	//Pj
	Hombre hombre;
	listaDispAmig dispAmig;
	espada espada;

	//Enemigos
	listaEnemDisp enemigosDisp;
	listaTank Tanks;
	listaBabosas babosas;
	listaTentaculo tentaculos;
	listabomber bombers;
	listaDispEnem disparos;
	bossFinal boss;
	listamisiles misiles;

	//Listas para vidas
	Vidas vidas;							//Vidas del entorno (Recolectables)
	VidasRec vidasR;						//Vidas del Pj (Recogidas)

	//Listas para Dinero
	Dinero dineros;							//Monedas del entorno (Recolectables)
	DineroRec dinerosR;						//Dinero del Pj (Recogidas)

public://Métodos
	void teclaUp(unsigned char key);
	void teclaDown(unsigned char key);

	void teclaEspecial(unsigned char key);
	void mueve();
	void dibuja();
	void inicializa();
	bool cargarnivel();
	//void teclaEspecialUp(unsigned char key);
};


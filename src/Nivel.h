#pragma once
/*#include "Caja.h"
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
#include "ListaBolasFuego.h"*/

#include "listas.h"
#include "ListaSolidos.h"
#include "Recolectable.h"
#include "Interaccion.h"
#include "ListaEnemigos.h"

class Nivel
{
	//Atributos
public:
	//Interfaz intz;
	float x_ojo;
	float y_ojo;
	float z_ojo;

	int nivel; //Ser� lo que usemos para identificar en que nivel estamos
	//Estructura del nivel
	Caja caja;
	ListaSolidos solidos;	//esto equivale a lo siguiente creo
	/*
	listaPlat plataformas;
	listaPinchos listPinchos;
	ListaBolasFuego listaFuego;

	listaMovil movil;*/

	//Pj
	Personaje hombre;
	listaDisparosAmigos dispAmig;
	espada espada;

	//Enemigos
	listaObjetoMovil moviles;
	ListaEnemigos enemigos;
	/*listaEnemDisp enemigosDisp;
	listaDisparosEnemigos disparos;
	listaMisiles misiles;*/

	//Listas para vidas
	Vidas vidas;							//Vidas del entorno (Recolectables)
	VidasRecolectadas vidasR;				//Vidas del Pj (Recogidas)

	//Listas para Dinero
	Dinero dineros;							//Monedas del entorno (Recolectables)
	DineroRecolectados dinerosR;			//Dinero del Pj (Recogidas)

public://M�todos
	void teclaUp(unsigned char key);
	void teclaDown(unsigned char key);

	void teclaEspecial(unsigned char key);
	void mueve();
	void dibuja();
	void inicializa();
	bool cargarnivel();
	//void teclaEspecialUp(unsigned char key);
};

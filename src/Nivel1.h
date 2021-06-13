#pragma once
#include "Bonus.h"
#include "listaBonus.h"
#include "Caja.h"
#include "listaPlat.h"
#include "Pincho.h"
#include "listaPinchos.h"
#include "Disparo.h"
#include "Estela.h"
#include "Hombre.h"
#include "listaDispAmig.h"
#include "Interaccion.h"
#include "EnemigoDisp.h"
#include "listaEnemDisp.h"
#include "Tank.h"
#include "listaTank.h"
#include "listaDispEnem.h"
#include "babosa.h"		
#include "listaBabosas.h"
#include "Tentaculo.h"
#include "listaTent.h"
#include "bomber.h"
#include "listabomber.h"
#include "Interfaz.h"
#include "VidasRec.h"
#include "DineroRec.h"

class Nivel1
{
//Atributos
public:
	//Interfaz intz;
	float x_ojo;
	float y_ojo;
	float z_ojo;

	//Estructura del nivel
	Caja caja;
	listaPlat plataformas;
	
	listaPinchos listPinchos;
	//listaBonus listBonus;

	//Pj
	Hombre hombre;
	listaDispAmig dispAmig;

	//Enemigos
	listaEnemDisp enemigosDisp;
	listaTank Tanks;
	listaBabosas babosas;
	//listaTentaculo tentaculos;
	//listabomber bombers;
	listaDispEnem disparos;

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
	//void teclaEspecialUp(unsigned char key);
};


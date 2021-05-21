#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Estela.h"
#include "Interaccion.h"
#include "EnemigoDisp.h"			
#include "Tank.h"
#include "Interfaz.h"
#include "Pincho.h"
#include "babosa.h"				
#include "Tentaculo.h"
#include "listaEnemDisp.h"
#include "listaPlat.h"
#include "Bonus.h"

class Nivel1
{
//Atributos
public:
	Interfaz intz;
	float x_ojo;
	float y_ojo;
	float z_ojo;

	//Estructura del nivel
	Caja caja;
	Pared plataforma1, plataforma2, plataforma3, plataforma4, 
		plataforma5, plataforma6, plataforma7, plataforma8, plataforma9;

	Pincho pincho1, pincho2, pincho3;
	Bonus bonus1, bonus2, bonus3, bonus4;
	Hombre hombre;
	Disparo disparo;
	EnemigoDisp eneDisp1, eneDisp2, eneDisp3, eneDisp4, eneDisp5, 
		eneDisp6, eneDisp7, eneDisp8, eneDisp9; //Enemigos simples
	Tank tank;									//Enemigos chetos
	Babosa babosa;							
	Tentaculo tentaculo;
	listaEnemDisp enemigosDisp;
	listaPlat plataformas;
	//Bonus bonus, * pbonus = &bonus;
	//Esfera esfera, * pesfera = &esfera,
		//esfera2, * pesfera2 = &esfera2;
	//añadir los atributos que son los objetos del escenario

	//Métodos
public:
	void teclaUp(unsigned char key);
	void teclaDown(unsigned char key);

	void teclaEspecial(unsigned char key);
	void mueve();
	void dibuja();
	void inicializa();
	//void teclaEspecialUp(unsigned char key);
	//void rotarOjo(); (Creo que no hace ni falta)
};


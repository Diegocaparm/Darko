#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Estela.h"
#include "Interaccion.h"
#include "DispEnem.h"			
#include "Tank.h"
#include "Interfaz.h"
#include "Pincho.h"

class Nivel1
{
//Atributos
public:
	Interfaz intz;
	float x_ojo;
	float y_ojo;
	float z_ojo;

	//Estructura del nivel
	Caja caja, * pcaja = &caja;
	Pared plataforma1, * pplataforma1 = &plataforma1,
		plataforma2, * pplataforma2 = &plataforma2,
		plataforma3, * pplataforma3 = &plataforma3,
		plataforma4, * pplataforma4 = &plataforma4,
		plataforma5, * pplataforma5 = &plataforma5,
		plataforma6, * pplataforma6 = &plataforma6,
		plataforma7, * pplataforma7 = &plataforma7,
		plataforma8, * pplataforma8 = &plataforma8,
		plataforma9, * pplataforma9 = &plataforma9;
	Pincho pincho1, pincho2, pincho3;

	Hombre hombre, * phombre = &hombre;
	Disparo disparo, * pdisparo = &disparo;
	EnemigoDisp eneDisp1, eneDisp2, eneDisp3, eneDisp4, eneDisp5, 
		eneDisp6, eneDisp7, eneDisp8, eneDisp9;	//Enemigos simples		
	Tank tank;									//Enemigos chetos
	

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


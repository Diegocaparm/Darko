#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Estela.h"
#include "Interaccion.h"

#include "DispEnem.h"			//eeeeeeeeeeeeeeeeeeeeeeee
#include "Tank.h"
//#include "Pared.h"
//#include "Vector2D.h"

class Mundo
{
public: 
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	//void teclaEspecialUp(unsigned char key);

	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Bonus bonus, * pbonus = &bonus;
	Caja caja, * pcaja = &caja;
	Disparo disparo, * pdisparo = &disparo;

	Esfera esfera, * pesfera = &esfera, 
		   esfera2, * pesfera2 = &esfera2;
	Hombre hombre, * phombre = &hombre;
	Pared plataforma1, * pplataforma1 = &plataforma1, 
		  plataforma2, * pplataforma2 = &plataforma2;

	
	EnemigoDisp eneDisp1;			//eeeeeeeeeeeeeeeeeeeeeeeeeeeeee
	Tank tank;
	//añadir los atributos que son los objetos del escenario
};

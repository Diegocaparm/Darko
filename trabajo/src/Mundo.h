#pragma once
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "Estela.h"
//#include "Pared.h"
//#include "Vector2D.h"

class Mundo
{
public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
	Bonus bonus, *pbonus = &bonus;
	Caja caja, *pcaja = &caja;
	Disparo disparo, *pdisparo = &disparo;
	
	Esfera esfera, *pesfera = &esfera;
	Hombre hombre, *phombre = &hombre;
	Pared plataforma, *pplataforma = &plataforma;
	//añadir los atributos que son los objetos del escenario
};

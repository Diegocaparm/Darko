#pragma once
#include "ListaDisparos.h"
#include "ListaSolidos.h"
#include "Recolectable.h"
#include "Interaccion.h"
#include "ListaEnemigos.h"
#include "Caja.h"

class Nivel
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
	ListaSolidos solidos;

	//Pj
	Personaje hombre;
	Espada espada;

	//Enemigos
	ListaEnemigos enemigos;

	//Disparos del PJ y los enemigos
	ListaDisparos disparos;

	//Listas para vidas
	Vidas vidas;							//Vidas del entorno (Recolectables)
	VidasRecolectadas vidasR;				//Vidas del Pj (Recogidas)

	//Listas para Dinero
	Dinero dineros;							//Monedas del entorno (Recolectables)
	DineroRecolectados dinerosR;			//Dinero del Pj (Recogidas)

public://Métodos
	void teclaUp(unsigned char key);
	void teclaDown(unsigned char key);
	void teclaEspecial(unsigned char key);
	void mueve();
	void dibuja(); //Aquí le podemos meter como parámetro un int con el mundo en el que estamos
	void inicializa();
	bool cargarnivel();
	bool borrarnivel();
	//void teclaEspecialUp(unsigned char key);
	void setDarko() { hombre.setDarko(); }
	void setHumano() { hombre.setHumano(); }
};

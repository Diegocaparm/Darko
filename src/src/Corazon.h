#pragma once
#include "Vector2D.h"

class Corazon
{
private:
	float radio;

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	Corazon();									//Constructor
	Corazon(float x, float y);					//Constructor que define posicion
	void setPos(float x, float y);				//Posición de vida
	Vector2D getPos();							//retorna la posicion de vida	
	void dibuja();								//Dibuja Corazon
	void mueve(float t);						//Movimiento del Corazón
	//void mueve(float x, float y);		//Movimiento del Corazón 
	//void daño();								//Reduce la vida en 1, si se acaba salta a la pantalla de GameOver
	//void aumento();								//Aumenta la vida
	//int getCantidad();							//Retorna la cantidad de vidas actuales
	//void setRecogido(bool a);
	//bool getRecogido();

	friend class Interfaz;
	friend class Interaccion;
};


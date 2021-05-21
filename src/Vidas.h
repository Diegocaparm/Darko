#pragma once
#include <freeglut.h>
#include <Vector2D.h>

class Vidas
{
private:
	int actual;
	int maximo;
	bool recoger;

	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	Vidas();									//Constructor
	void setPos(float x, float y);				//Posición de vida
	Vector2D getPos();							//retorna la posicion de vida	
	void dibuja(float posx, float posy, bool r); //Dibuja Corazon
	void mueve(float t);						//Movimiento del Corazón
	void daño();								//Reduce la vida en 1, si se acaba salta a la pantalla de GameOver
	void aumento();								//Aumenta la vida
	int getCantidad();							//Retorna la cantidad de vidas actuales
	void setRecogido(bool a);
	bool getRecogido();

	friend class Interfaz;

};

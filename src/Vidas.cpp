#include "Vidas.h"
#include "freeglut.h"
#include "Hombre.h"
#include "ETSIDI.h"
#include "Menu.h"
#include "Interaccion.h"

Vidas::Vidas()
{
	numero = 0;
	for (int i = 0; i < MAX_VIDAS; i++)
		lista[i] = 0;

}

bool Vidas::agregar(Corazon* c)
{
	for (int i = 0; i < numero; i++) //Evitar que se añada una vida ya existente
		if (lista[i] == c)
			return false;

	if (numero < MAX_VIDAS)
		lista[numero++] = c; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}


void Vidas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}



void Vidas::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void Vidas::rebote(Pared pared)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), pared);
}

void Vidas::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void Vidas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de corazones contenidos
		delete lista[i];

	numero = 0; // inicializa lista
}

void Vidas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void Vidas::eliminar(Corazon* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}


Corazon* Vidas::colision(Hombre h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::recoleccion(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisión
}

Corazon* Vidas::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}


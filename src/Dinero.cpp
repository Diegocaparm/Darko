#include "Dinero.h"
#include "freeglut.h"
#include "Hombre.h"
#include "ETSIDI.h"
#include "Menu.h"
#include "Interaccion.h"

Dinero::Dinero()
{
	numero = 0;
	for (int i = 0; i < MAX_MONEDAS; i++)
		lista[i] = 0;

}

bool Dinero::agregar(Moneda* d)
{
	//for (int i = 0; i < numero; i++) //Evitar que se añada una moneda ya existente
	//	if (lista[i] == d)
	//		return false;

	if (numero < MAX_MONEDAS)
		lista[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void Dinero::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void Dinero::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void Dinero::rebote(Pared pared)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), pared);
}

void Dinero::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void Dinero::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de dinero contenido
		delete lista[i];

	numero = 0; // inicializa lista
}

void Dinero::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void Dinero::eliminar(Moneda* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

Moneda* Dinero::colision(Hombre h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::recoleccion(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisión
}

Moneda* Dinero::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}


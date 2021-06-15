#include "ListaBolasFuego.h"

ListaBolasFuego::ListaBolasFuego()
{
	num = 0;
	for (int i = 0; i < NBOLAS; i++)
		lista[i] = 0;
}

bool ListaBolasFuego::agregar(BolaFuego* bola)
{
	bool aux = true;
	for (int i = 0; i < num; i++) {
		if (bola == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (num < NBOLAS)
			lista[num++] = bola; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void ListaBolasFuego::dibuja()
{
	for (int i = 0; i < num; i++)
		lista[i]->dibuja();
}

void ListaBolasFuego::mueve(float t)
{
	for (int i = 0; i < num; i++)
		lista[i]->mueve(t);
}

void ListaBolasFuego::rebote(Hombre& h) {
	for (int i = 0; i < num; i++)
		Interaccion::colision(h, *(lista[i]));
}

void ListaBolasFuego::destruirContenido()
{
	for (int i = 0; i < num; i++) // destrucción de esferas contenidas
		delete lista[i];
	num = 0; // inicializa lista
}

void ListaBolasFuego::eliminar(int index)
{
	if ((index < 0) || (index >= num))
		return;
	delete lista[index];
	num--;
	for (int i = index; i < num; i++)
		lista[i] = lista[i + 1];
}

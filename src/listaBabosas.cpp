#include "listaBabosas.h"
#include "Interaccion.h"

listaBabosas::listaBabosas() {
	numero = 0;
	for (int i = 0; i < MAX_ENEMDISP; i++)
		lista[i] = 0;
}

bool listaBabosas::agregar(Babosa* ene)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_BABOSAS)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void listaBabosas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listaBabosas::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void listaBabosas::mov(Hombre h) {
	for (int i = 0; i < numero; i++)
		Interaccion::mov(*(lista[i]), h);
}

/*void listaBabosas::rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j)
				Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}*/

void listaBabosas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listaBabosas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void listaBabosas::eliminar(Babosa* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
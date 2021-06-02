#include "listaTank.h"
#include "Interaccion.h"

listaTank::listaTank() {
	numero = 0;
	for (int i = 0; i < MAX_TANK; i++)
		lista[i] = 0;
}

bool listaTank::agregar(Tank* ene)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_ENEMDISP)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void listaTank::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listaTank::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void listaTank::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void listaTank::rebote(Pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}

void listaTank::rebote(listaPlat lp) {
	for (int i = 0; i < lp.numero; i++)
		rebote(*lp.lista[i]);
}

/*void listaTank::rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j)
				Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}*/

void listaTank::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listaTank::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void listaTank::eliminar(Tank* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
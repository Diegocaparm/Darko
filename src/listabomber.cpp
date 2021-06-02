#include "listabomber.h"
#include "Interaccion.h"

listabomber::listabomber() {
	numero = 0;
	for (int i = 0; i < MAX_BOMBER; i++)
		lista[i] = 0;
}

bool listabomber::agregar(bomber* ene)
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

void listabomber::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listabomber::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void listabomber::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void listabomber::rebote(Pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}

void listabomber::rebote(listaPlat lp) {
	for (int i = 0; i < lp.numero; i++)
		rebote(*lp.lista[i]);
}

/*void listabomber::rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j)
				Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}*/

void listabomber::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listabomber::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

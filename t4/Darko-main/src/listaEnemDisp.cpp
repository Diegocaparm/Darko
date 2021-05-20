#include "listaEnemDisp.h"
#include "Interaccion.h"

listaEnemDisp::listaEnemDisp() {
	numero = 0;
	for (int i = 0; i < MAX_ENEMDISP; i++)
		lista[i] = 0;
}

bool listaEnemDisp::agregar(EnemigoDisp* ene)
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

void listaEnemDisp::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listaEnemDisp::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void listaEnemDisp::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void listaEnemDisp::rebote(Pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}
void listaEnemDisp::rebote(listaPlat lp) {
	for (int i = 0; i < lp.numero; i++)
		rebote(*lp.lista[i]);
}

void listaEnemDisp::rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j)
				Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}

void listaEnemDisp::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listaEnemDisp::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void listaEnemDisp::eliminar(EnemigoDisp* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

/*EnemigoDisp* listaEnemDisp::colision(Hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisión
}*/
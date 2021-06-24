#include "listas.h"
//#include "Interaccion.h"

listas::listas() {
	numero = 0;
	for (int i = 0; i < MAX_NUM; i++)
		lista[i] = 0;
}

bool listas::agregar(ObjetoMovil* ene)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_NUM)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void listas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listas::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void listas::setPos(float px, float py)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setPos(px, py);
}

void listas::setColor(Byte r, Byte g, Byte b)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setColor(r, g, b);
}

/*void listas::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}*/

void listas::rebote(Pared p)
{
	for (int i = 0; i < numero; i++) {}
		//Interaccion::rebote(*(lista[i]), p);
}

/*void listas::rebote(listaPlat lp) {
	for (int i = 0; i < lp.numero; i++)
		rebote(*lp.lista[i]);
}*/

/*void listaDispEnem::rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j)
				Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}*/

void listas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void listas::eliminar(ObjetoMovil* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
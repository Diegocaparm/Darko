#include "listaDispEnem.h"
#include "Interaccion.h"

listaDispEnem::listaDispEnem() {
	numero = 0;
	for (int i = 0; i < MAX_DISPENEM; i++)
		lista[i] = 0;
}

bool listaDispEnem::agregar(DisparosEnemigos* ene)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_DISPENEM)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void listaDispEnem::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listaDispEnem::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void listaDispEnem::setPos(float px, float py)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setPos(px, py);
}

void listaDispEnem::setColor(Byte r, Byte g, Byte b)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setColor(r, g, b);
}

void listaDispEnem::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void listaDispEnem::rebote(Pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}

void listaDispEnem::rebote(listaPlat lp) {
	for (int i = 0; i < lp.numero; i++)
		rebote(*lp.lista[i]);
}

void listaDispEnem::rebote(Hombre h, VidasRec& v) {
	for (int i = 0; i < numero; i++)
		Interaccion::colision(h, *(lista[i]),v);
}
/*void listaDispEnem::rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j)
				Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}*/

void listaDispEnem::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listaDispEnem::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void listaDispEnem::eliminar(DisparosEnemigos* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

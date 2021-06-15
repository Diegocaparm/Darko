#include "listamisiles.h"
#include "Interaccion.h"

listamisiles::listamisiles() {
	numero = 0;
	for (int i = 0; i < MAX_MISIL; i++)
		lista[i] = 0;
}

bool listamisiles::agregar(misil* ene)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_MISIL)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void listamisiles::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listamisiles::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void listamisiles::setPos(float px, float py)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setPos(px, py);
}

void listamisiles::setColor(Byte r, Byte g, Byte b)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setColor(r, g, b);
}

void listamisiles::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void listamisiles::rebote(Pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}

void listamisiles::rebote(listaPlat lp) {
	for (int i = 0; i < lp.numero; i++)
		rebote(*lp.lista[i]);
}

void listamisiles::rebote(Hombre h) {
	for (int i = 0; i < numero; i++) {
		Interaccion::colision(h, *(lista[i]));
		Interaccion::mov(h, *(lista[i]));
	}
}
/*void listamisiles::rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j)
				Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}*/

void listamisiles::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listamisiles::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void listamisiles::eliminar(misil* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

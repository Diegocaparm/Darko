#include "listaDispAmig.h"
#include "Interaccion.h"

listaDispAmig::listaDispAmig() {
	numero = 0;
	for (int i = 0; i < MAX_DISPAMIG; i++)
		lista[i] = 0;
}

bool listaDispAmig::agregar(disparosAmigos* ene)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_DISPAMIG)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void listaDispAmig::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listaDispAmig::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void listaDispAmig::setPos(float px, float py)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setPos(px, py);
}

void listaDispAmig::setColor(Byte r, Byte g, Byte b)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setColor(r, g, b);
}

void listaDispAmig::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void listaDispAmig::rebote(Pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}

void listaDispAmig::rebote(listaPlat lp) {
	for (int i = 0; i < lp.numero; i++)
		rebote(*lp.lista[i]);
}

/*void listaDispEnem::rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j)
				Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}*/

void listaDispAmig::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listaDispAmig::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void listaDispAmig::eliminar(disparosAmigos* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

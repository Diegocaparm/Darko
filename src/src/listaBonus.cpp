#include "listaBonus.h"

listaBonus::listaBonus() {
	numero = 0;
	for (int i = 0; i < MAX_BONUS; i++)
		lista[i] = 0;
}

void listaBonus::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

bool listaBonus::agregar(Bonus* p)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (p == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_BONUS)
			lista[numero++] = p; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void listaBonus::rebote(Hombre& h) {
	for (int i = 0; i < numero; i++)
		Interaccion::colision(h, *(lista[i]));
}
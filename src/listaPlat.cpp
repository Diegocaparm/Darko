#include "listaPlat.h"

listaPlat::listaPlat() {
	numero = 0;
	for (int i = 0; i < MAX_PAREDES; i++)
		lista[i] = 0;
}

void listaPlat::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

bool listaPlat::agregar(Pared* p)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (p == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_PAREDES)
			lista[numero++] = p; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}


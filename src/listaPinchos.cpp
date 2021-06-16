#include "listaPinchos.h"

listaPinchos::listaPinchos() {
	numero = 0;
	for (int i = 0; i < MAX_PINCHOS; i++)
		lista[i] = 0;
}

void listaPinchos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

bool listaPinchos::agregar(Pincho* p)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (p == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_PINCHOS)
			lista[numero++] = p; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void listaPinchos::rebote(Hombre& h, VidasRec& v) {
	for (int i = 0; i < numero; i++)
		Interaccion::colision(h, *(lista[i]),v);
}
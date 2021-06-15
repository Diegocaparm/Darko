#include "listaPlat.h"

listaPlat::listaPlat() {
	numero = 0;
	for (int i = 0; i < MAX_PAREDES; i++)
		lista[i] = 0;
	numv = 0;
	for (int i = 0; i < MAX_PAREDES; i++)
		listamov[i] = 0;
}

void listaPlat::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
	for (int i = 0; i < numv; i++)
		listamov[i]->dibuja();
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
			lista[numero++] = p; // �ltimo puesto sin rellenar
		else
			return false; // capacidad m�xima alcanzada
		return true;
	}
}

bool listaPlat::agregar(PlatMovil* p)
{
	bool aux = true;
	for (int i = 0; i < numv; i++) {
		if (p == listamov[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numv < MAX_PAREDES)
			listamov[numv++] = p; // �ltimo puesto sin rellenar
		else
			return false; // capacidad m�xima alcanzada
		return true;
	}
}

void listaPlat::mueve(float t)
{
	for (int i = 0; i < numv; i++)
		listamov[i]->mueve(t);
}
#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISP; i++)
		lista[i] = 0;
}
bool ListaDisparos::agregar(Disparos* d)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
			return false;
	if (numero < MAX_DISP)
		lista[numero++] = d;
	else
		return false; //Capacidad máxima alcanzada
	return true;
}
void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}
void ListaDisparos::colision(Personaje& pj, VidasRecolectadas& v)
{
	for (int i = 0;i < MAX_DISP;i++)
		Interaccion::colision(pj, *lista[i], v);
}

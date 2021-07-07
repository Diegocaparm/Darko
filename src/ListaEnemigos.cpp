#include "ListaEnemigos.h"
//#include "Interaccion.h"

//Métodos de la lista de enemigos
ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0;i < MAX_ENEM;i++)
		lista[i] = 0;
}
bool ListaEnemigos::agregar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
			return false;
	//Una vez comprobado que no existe ese mismo enemigo
	if (numero < MAX_ENEM)
		lista[numero++] = e;
	else
		return false; //Capacidad máxima alcanzada
	return true;
}
void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void ListaEnemigos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaEnemigos::eliminar(Enemigo* e)
{
}
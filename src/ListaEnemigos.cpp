#include "ListaEnemigos.h"
#include "Interaccion.h"

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
void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de corazones contenidos
		delete lista[i];

	numero = 0; // inicializa lista
}
void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaEnemigos::eliminar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
Enemigo* ListaEnemigos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

Enemigo* ListaEnemigos::colision(Espada esp)
{
	{
		for (int i = 0; i < numero; i++)
		{
			if (Interaccion::colision(esp, lista[i]))
				return lista[i];
		}
		return 0;
	}
}

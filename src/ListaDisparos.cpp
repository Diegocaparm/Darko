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
void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de corazones contenidos
		delete lista[i];
	numero = 0; // inicializa lista
}
void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaDisparos::eliminar(Disparos* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
Disparos* ListaDisparos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

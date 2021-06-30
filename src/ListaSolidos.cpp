#include "solidos.h"
#include "Interaccion.h"

//Métodos de la lista de sólidos
ListaSolidos::ListaSolidos()
{
	numero = 0;
	for (int i = 0; i < MAX_SOLIDOS; i++)
		lista[i] = 0;
}
bool ListaSolidos::agregar(Solidos* s)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == s)
			return false;

	if (numero < MAX_SOLIDOS)
		lista[numero++] = s; 
	else
		return false; //Capacidad máxima alcanzada
	return true;
}
void ListaSolidos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void ListaSolidos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}
void ListaSolidos::rebote(Personaje& pj, VidasRecolectadas& v)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(pj, *lista[i], v);
}
#include "listas.h"
//#include "Interaccion.h"

listaObjetoMovil::listaObjetoMovil() {
	numero = 0;
	for (int i = 0; i < MAX_NUM; i++)
		lista[i] = 0;
}

bool listaObjetoMovil::agregar(ObjetoMovil* ene)
{
	bool aux = true;
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_NUM)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}

void listaObjetoMovil::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listaObjetoMovil::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void listaObjetoMovil::setPos(float px, float py)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setPos(px, py);
}

void listaObjetoMovil::setColor(Byte r, Byte g, Byte b)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setColor(r, g, b);
}

/*void listaObjetoMovil::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}

void listaObjetoMovil::rebote(Pared p)
{
	for (int i = 0; i < numero; i++) {}
		//Interaccion::rebote(*(lista[i]), p);
}*/

/*void listaObjetoMovil::rebote(listaPlat lp) {
	for (int i = 0; i < lp.numero; i++)
		rebote(*lp.lista[i]);
}*/

/*void listaObjetoMovil::rebote() {
	for (int i = 0; i < numero; i++) {
		for (int j = 0; j < numero; j++) {
			if (i != j)
				Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}*/

void listaObjetoMovil::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listaObjetoMovil::eliminarindex(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void listaObjetoMovil::eliminar(ObjetoMovil* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminarindex(i);
			return;
		}
}

//disparos
bool listaDisparos::agregar(Disparos* ene)
{
	bool aux = true;
	listaObjetoMovil::agregar(ene);		//meter en lista objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_DISP) 
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listaDisparos::eliminar(Disparos* e)
{
	listaObjetoMovil::eliminar(e);				//eliminar de lista objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista disparos
		{
			eliminarindex(i);
			return;
		}
	}
}

//enemigos
bool listasEnemigos::agregar(Enemigo* ene)
{
	bool aux = true;
	listaObjetoMovil::agregar(ene);		//meter en lista objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_DISP)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listasEnemigos::eliminar(Enemigo* e)
{
	listaObjetoMovil::eliminar(e);				//eliminar de lista objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista enemigos
		{
			eliminarindex(i);
			return;
		}
	}
}


//disparos amigos
bool listaDisparosAmigos::agregar(disparosAmigos* ene)
{
	bool aux = true;
	listaDisparos::agregar(ene);		//meter en lista disparos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_DISP)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listaDisparosAmigos::eliminar(disparosAmigos* e)
{
	listaDisparos::eliminar(e);				//eliminar de lista disparos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista disparos
		{
			eliminarindex(i);
			return;
		}
	}
}
//disparos enemigos
bool listaDisparosEnemigos::agregar(disparosEnemigos* ene)
{
	bool aux = true;
	listaDisparos::agregar(ene);		//meter en lista disparos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_DISP)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listaDisparosEnemigos::eliminar(disparosEnemigos* e)
{
	listaDisparos::eliminar(e);				//eliminar de lista disparos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista disparos
		{
			eliminarindex(i);
			return;
		}
	}
}
//misiles
bool listaMisiles::agregar(misiles* ene)
{
	bool aux = true;
	listaDisparos::agregar(ene);		//meter en lista disparos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_DISP)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listaMisiles::eliminar(misiles* e)
{
	listaDisparos::eliminar(e);				//eliminar de lista disparos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista disparos
		{
			eliminarindex(i);
			return;
		}
	}
}


//enemigo disp
bool listaEnemDisp::agregar(EnemigoDisp* ene)
{
	bool aux = true;
	listasEnemigos::agregar(ene);		//meter en lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_ENEM)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listaEnemDisp::eliminar(EnemigoDisp* e)
{
	listasEnemigos::eliminar(e);				//eliminar de lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista disparos
		{
			eliminarindex(i);
			return;
		}
	}
}
//tank
bool listaTank::agregar(Tank* ene)
{
	bool aux = true;
	listasEnemigos::agregar(ene);		//meter en lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_ENEM)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listaTank::eliminar(Tank* e)
{
	listasEnemigos::eliminar(e);				//eliminar de lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista disparos
		{
			eliminarindex(i);
			return;
		}
	}
}
//babosa
bool listaBabosa::agregar(Babosa* ene)
{
	bool aux = true;
	listasEnemigos::agregar(ene);		//meter en lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_ENEM)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listaBabosa::eliminar(Babosa* e)
{
	listasEnemigos::eliminar(e);				//eliminar de lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista disparos
		{
			eliminarindex(i);
			return;
		}
	}
}
//bomber
bool listaBomber::agregar(Bomber* ene)
{
	bool aux = true;
	listasEnemigos::agregar(ene);		//meter en lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_ENEM)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listaBomber::eliminar(Bomber* e)
{
	listasEnemigos::eliminar(e);				//eliminar de lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista disparos
		{
			eliminarindex(i);
			return;
		}
	}
}
//tentaculo
bool listaTentaculo::agregar(Tentaculo* ene)
{
	bool aux = true;
	listasEnemigos::agregar(ene);		//meter en lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (ene == lista[i]) {
			aux = false;
		}
	}
	if (aux) {
		if (numero < MAX_ENEM)
			lista[numero++] = ene; // último puesto sin rellenar
		else
			return false; // capacidad máxima alcanzada
		return true;
	}
}
void listaTentaculo::eliminar(Tentaculo* e)
{
	listasEnemigos::eliminar(e);				//eliminar de lista enemigos y objeto movil
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)				//eliminar de la lista disparos
		{
			eliminarindex(i);
			return;
		}
	}
}


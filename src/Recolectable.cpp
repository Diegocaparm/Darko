#include "Recolectable.h"
#include "freeglut.h"
#include "Interaccion.h"
#include "stdio.h"
using ETSIDI::SpriteSequence;

//Constructores de los distintos recolectables y sus listas
Recolectable::Recolectable()
{
	radio = 1.5;
	setPos(0, 0);
}
Recolectable::Recolectable(float x, float y)
{
	radio = 1.5;
	setPos(x, y);
}
Corazon::Corazon()
{
	radio = 1.5;
	setPos(0, 0);
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
}
Corazon::Corazon(float x, float y)
{
	radio = 1.5;
	setPos(x, y);
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
}
Moneda::Moneda()
{
	radio = 1.5;
	setPos(0, 0);
}
Moneda::Moneda(float x, float y)
{
	radio = 1.5;
	setPos(x, y);
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
}
Vidas::Vidas()
{
	numero = 0;
	for (int i = 0; i < MAX_VIDAS; i++)
		lista[i] = 0;
}
Dinero::Dinero()
{
	numero = 0;
	for (int i = 0; i < MAX_MONEDAS; i++)
		lista[i] = 0;
}
DineroRecolectados::DineroRecolectados()
{
	nUnidad.setCenter(0, 0);
	nUnidad.setSize(2, 2);

	nDecena.setCenter(0, 0);
	nDecena.setSize(2, 2);
}

//M?todos virtuales de Recolectable
void Recolectable::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
Vector2D Recolectable::getPos()
{
	Vector2D get;
	get.x = posicion.x;
	get.y = posicion.y;
	return get;
}

//M?todos propios de Corazon
void Corazon::dibuja()
{
	//Pendiente a editar

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(radio, 20, 20);
	sprite.setState(1, true);
	sprite.draw();
	glPopMatrix();
}
void Corazon::mueve(float t)
{
	sprite.loop();
}

//Metodos propios de Moneda
void Moneda::dibuja()
{
	//Pendiente
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	if (sprite.getState() == 0) {
		sprite.setState(1, false);
	}
	sprite.draw();
	glPopMatrix();
}
void Moneda::mueve(float t)
{
	sprite.loop();
}

//M?todos de la lista de Vidas
bool Vidas::agregar(Corazon* c)
{
	for (int i = 0; i < numero; i++) //Evitar que se a?ada una vida ya existente
		if (lista[i] == c)
			return false;

	if (numero < MAX_VIDAS)
		lista[numero++] = c; // ?ltimo puesto sin rellenar
	else
		return false; // capacidad m?xima alcanzada
	return true;
}
void Vidas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void Vidas::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}
void Vidas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucci?n de corazones contenidos
		delete lista[i];

	numero = 0; // inicializa lista
}
void Vidas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void Vidas::eliminar(Corazon* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
Corazon* Vidas::recoleccion(Personaje h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::recoleccion(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisi?n
}
Corazon* Vidas::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

//M?todos de la lista de Vidas Recolectadas
bool VidasRecolectadas::agregar(Corazon* c)
{
	for (int i = 0; i < numero; i++) //Evitar que se a?ada una vida ya existente
		if (lista[i] == c)
			return false;

	if (numero < MAX_VIDAS) {
		lista[numero++] = c; // ?ltimo puesto sin rellenar
		contador_vidas++;
		printf("%d\n", contador_vidas);
	}
	else
		return false; // capacidad m?xima alcanzada
	return true;
}
void VidasRecolectadas::eliminar(int i)
{
	Vidas::eliminar(i);
	contador_vidas--;
	if (contador_vidas < -1) {
		contador_vidas = -1;
	}
}
void VidasRecolectadas::mueve(float t, float posx)
{
	for (int i = 0; i < numero; i++) {
		lista[i]->setPos(posx + 12 - i * 2, 16);
		lista[i]->mueve(t);
	}
}
int VidasRecolectadas::getVidas()
{
	printf("%d", contador_vidas);
	return contador_vidas;
}
int VidasRecolectadas::getVidasInicial()
{
	return vida_inicial;
}
void VidasRecolectadas::reduceVida()
{
	eliminar(contador_vidas);
}

bool VidasRecolectadas::FinVida()
{
	if (contador_vidas < 0) {
		return true;
	}
	return false;
}

//M?todos de la lista de Dinero
bool Dinero::agregar(Moneda* d)
{
	//for (int i = 0; i < numero; i++) //Evitar que se a?ada una moneda ya existente
	//	if (lista[i] == d)
	//		return false;

	if (numero < MAX_MONEDAS)
		lista[numero++] = d; // ?ltimo puesto sin rellenar
	else
		return false; // capacidad m?xima alcanzada
	return true;
}
void Dinero::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void Dinero::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}
void Dinero::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucci?n de dinero contenido
		delete lista[i];

	numero = 0; // inicializa lista
}
void Dinero::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void Dinero::eliminar(Moneda* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
Moneda* Dinero::recoleccion(Personaje h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::recoleccion(*lista[i], h))
			return lista[i];
	}
	return 0; //no hay colisi?n
}
Moneda* Dinero::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

//M?todos de la lista de DineroRecolectado
void DineroRecolectados::mueve(float t, Vector2D v)
{
	pos.x = v.x;
	for (int i = 0; i < numero; i++) {
		lista[i]->setPos(v.x + 12 + i * 2, 14);
		lista[i]->mueve(t);
	}
}
void DineroRecolectados::aumentaDinero()
{
	dinero_actual += 1;
}
void DineroRecolectados::dibujaContador()
{

	glPushMatrix();
	glTranslatef(pos.x + 8.5, 13.5, 1);

	//glutSolidSphere(0.2, 20, 20);

	for (int i = 0; i < 10; i++) {
		if (i == dinero_actual) {
			nUnidad.setState(i, true);
		}
		else {
			for (int j = 0; j < 10; j++) {
				int unidad;
				if (dinero_actual >= j * 10) {
					unidad = dinero_actual - j * 10;
					nUnidad.setState(unidad, true);
					nDecena.setState(j, true);
					if (unidad == 0) {
						nDecena.setState(j, true);
					}
				}

			}
		}

	}

	nUnidad.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(pos.x + 6.5, 13.5, 1);
	nDecena.draw();
	glPopMatrix();
}

void DineroRecolectados::getVida(VidasRecolectadas *v)
{
	if (dinero_actual > 99) {
		dinero_actual = dinero_actual - 99;
		v->agregar(new Corazon());
		v->agregar(new Corazon());
	}
}

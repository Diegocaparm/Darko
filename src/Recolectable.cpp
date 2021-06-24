#include "Recolectable.h"
#include "freeglut.h"
//#include "interaccion"
using ETSIDI::SpriteSequence;

//Constructores de los distintos recolectables y sus listas
Recolectable::Recolectable()
{
}
Recolectable::Recolectable(float x, float y)
{
	setPos(x, y);
}
Corazon::Corazon()
{

}
Corazon::Corazon(float x, float y)
{
	setPos(x, y);
}
Moneda::Moneda()
{
}
Moneda::Moneda(float x, float y)
{
	setPos(x, y);
	//Recolectable(x, y);
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
}
Vidas::Vidas()
{
	numero = 0;
	for (int i = 0; i < MAX_VIDAS; i++)
		lista[i] = 0;
}
VidasRecolectadas::VidasRecolectadas()
{

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

//Métodos virtuales de Recolectable
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

//Métodos propios de Corazon
void Corazon::dibuja()
{
	//Pendiente a editar

	/*glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(radio, 20, 20);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/corazon.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0, 0);
	glTexCoord2d(1, 1); glVertex2f(1.5, 0);
	glTexCoord2d(1, 0); glVertex2f(1.5, 1.5);
	glTexCoord2d(0, 0); glVertex2f(0, 1.5);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();*/
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

//Métodos de la lista de Vidas
bool Vidas::agregar(Corazon* c)
{
	for (int i = 0; i < numero; i++) //Evitar que se añada una vida ya existente
		if (lista[i] == c)
			return false;

	if (numero < MAX_VIDAS)
		lista[numero++] = c; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
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
void Vidas::rebote(Pared pared)
{
	//for (int i = 0; i < numero; i++)
		//Interaccion::rebote(*(lista[i]), pared);
}
void Vidas::rebote(Caja caja)
{
	//for (int i = 0; i < numero; i++)
		//Interaccion::rebote(*(lista[i]), caja);
}
void Vidas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de corazones contenidos
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
/*Corazon* Vidas::colision(Hombre h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::recoleccion(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisión
}*/
Corazon* Vidas::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
//Métodos de la lista de Vidas Recolectadas
bool VidasRecolectadas::agregar(Corazon* c)
{
	for (int i = 0; i < numero; i++) //Evitar que se añada una vida ya existente
		if (lista[i] == c)
			return false;

	if (numero < MAX_VIDAS) {
		lista[numero++] = c; // último puesto sin rellenar
		contador_vidas++;
	}
	else
		return false; // capacidad máxima alcanzada
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

//Métodos de la lista de Dinero
bool Dinero::agregar(Moneda* d)
{
	//for (int i = 0; i < numero; i++) //Evitar que se añada una moneda ya existente
	//	if (lista[i] == d)
	//		return false;

	if (numero < MAX_MONEDAS)
		lista[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
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
void Dinero::rebote(Pared pared)
{
	//for (int i = 0; i < numero; i++)
		//Interaccion::rebote(*(lista[i]), pared);
}
void Dinero::rebote(Caja caja)
{
	//for (int i = 0; i < numero; i++)
		//Interaccion::rebote(*(lista[i]), caja);
}
void Dinero::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de dinero contenido
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
/*
Moneda* Dinero::colision(Hombre h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::recoleccion(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisión
}*/
Moneda* Dinero::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}
//Métodos de la lista de DineroRecolectado
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
	glTranslatef(pos.x + 10, 12, 1);

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
	glTranslatef(pos.x + 8, 12, 1);
	nDecena.draw();
	glPopMatrix();
}

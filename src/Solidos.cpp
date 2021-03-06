#include "Solidos.h"
#include "freeglut.h"

//Constructores de los s?lidos varios
Solidos::Solidos()
{

}
Pared::Pared()
{
	//Necesario para las herencias y que se llame desde caja sin tener que especificar posiciones
}
Pared::Pared(float x1, float y1, float x2, float y2) 
{
	setCosa(1);
	setLims(x1, y1, x2, y2);
}
PlatMovil::PlatMovil(float lim1x, float lim1y, float lim2x, float lim2y, float vx, float vy, float ex1x, float ex1y, float ex2x, float ex2y)
{
	setCosa(2);
	setLims(lim1x, lim1y, lim2x, lim2y);
	vel = { vx,vy };
	extremo1 = { ex1x,ex1y };
	extremo2 = { ex2x,ex2y };
}
Suelo::Suelo(float limx1, float altura, float limx2, float bajo)
{
	setCosa(3);
	limite1.x = bajo1.x = limx1;
	limite2.x = bajo2.x = limx2;

	limite1.y = limite2.y = altura;
	bajo1.y = bajo2.y = bajo;
}
Final::Final(float x1, float y1, float x2, float y2)
{
	setCosa(4);
	setLims(x1, y1, x2, y2);
}
Pincho::Pincho() {
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
};
Pincho::Pincho(float px, float py) {
	sprite.setCenter(2.5, 1.5);
	sprite.setSize(5, 5);
	setCosa(5);
	//Situamos los pinchos
	setPos(px, py);
	//Situamos las esquimnas de su hitbox
	hitbox.bot_l.x = posicion.x - 1.3f;	hitbox.bot_l.y = posicion.y;
	hitbox.bot_r.x = posicion.x + 1.3f;	hitbox.bot_r.y = posicion.y;
	hitbox.top_l.x = posicion.x - 1.3f;	hitbox.top_l.y = posicion.y + 2.5f;
	hitbox.top_r.x = posicion.x + 1.3f;	hitbox.top_r.y = posicion.y + 2.5f;
}
BolaFuego::BolaFuego(float px, float py, float limtop, float limbot) : fireball("bin/imagenes/fireball.png", 4, 3)
{
	//radio = 0.75f;
	setCosa(6);
	vel.x = 0.0f;
	vel.y = 10.0f;
	setPos(px, py);
	borde = { limbot, limtop };
}

//M?todos virtuales de Solidos
void Solidos::setPos(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
}
void Solidos::dibuja(int i) {} //Vacios para entrar en lista
void Solidos::mueve(float t) {} //El de arriba y este
void Solidos::setCosa(int i) {
	cosa = i;
}
int Solidos::getCosa() {
	return cosa;
}

//M?todos virtuales de Pared
void Pared::setLims(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
void Pared::dibuja(int i)
{
	if (i == 1)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/mundo1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0.4, 0.2);	glVertex2f(limite1.x + 0.5f, limite1.y - 1);
		glTexCoord2d(0.6, 0.2);	glVertex2f(limite2.x + 0.5f, limite2.y - 1);
		glTexCoord2d(0.6, 0.1);	glVertex2f(limite2.x - 0.5f, limite2.y + 0.5f);
		glTexCoord2d(0.4, 0.1);	glVertex2f(limite1.x - 0.5f, limite1.y + 0.5f);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else if (i == 2)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/mundo2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glTexCoord2d(0.15, 0.92);	glVertex2f(limite1.x + 0.5f, limite1.y - 1);
		glTexCoord2d(0.85, 0.92);	glVertex2f(limite2.x + 0.5f, limite2.y - 1);
		glTexCoord2d(0.85, 0.8);	glVertex2f(limite2.x - 0.5f, limite2.y + 0.5f);
		glTexCoord2d(0.15, 0.8);	glVertex2f(limite1.x - 0.5f, limite1.y + 0.5f);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Plat_Marte.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glTexCoord2d(0.15, 0.2);	glVertex2f(limite1.x + 0.5f, limite1.y - 1);
		glTexCoord2d(0.85, 0.2);	glVertex2f(limite2.x + 0.5f, limite2.y - 1);
		glTexCoord2d(0.85, 0.1);	glVertex2f(limite2.x - 0.5f, limite2.y + 0.5f);
		glTexCoord2d(0.15, 0.1);	glVertex2f(limite1.x - 0.5f, limite1.y + 0.5f);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
}
float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //Si nos dan un vector
		*direccion = dir.unitario();
	return distancia;
}

//M?todos propios de Pared
bool Pared::operator==(Pared p)
{
	if (limite1 == p.limite1 && limite2 == p.limite2) {
		return true;
	}
	return false;
}
//M?todos propios de PlatMovil
void PlatMovil::dibuja(int i)
{
	if (i == 1)
	{
		//Dimensiones del sprite
		platmovil1.setCenter((limite2.x - limite1.x) * 3/2,3);
		platmovil1.setSize((limite2.x-limite1.x)*3, 5);
		//Dibujo
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0.5);
		platmovil1.draw();
		glPopMatrix();

	}
	else if (i == 2)
	{
		//Dimensiones del sprite
		platmovil2.setCenter((limite2.x - limite1.x) * 3 / 2, 3);
		platmovil2.setSize((limite2.x - limite1.x) * 3, 5);
		//Dibujo
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0.5f);
		if (vel.x < -0.01)platmovil2.flip(true, false);
		if (vel.x > 0.01)platmovil2.flip(false, false);
		if ((vel.x < 0.01) && (vel.x > -0.01f))
			platmovil2.setState(0);
		platmovil2.draw();
		glPopMatrix();
	}
	else
	{
		//Dimensiones del sprite
		platmovil3.setCenter((limite2.x - limite1.x) * 3 / 2, 3);
		platmovil3.setSize((limite2.x - limite1.x) * 3, 5);
		//Dibujo
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0.5f);
		platmovil3.draw();
		glPopMatrix();
	}
}
void PlatMovil::mueve(float t)
{
	limite1 = limite1 + vel * t; //Movemos el limite 1 con la velocidad indicada
	limite2 = limite2 + vel * t; //Movemos el limite 2 con la velocidad indicada
	posicion = { ((limite1.x + limite2.x) / 2),((limite1.y + limite2.y) / 2) };
	if (posicion.x <= extremo1.x) //Si llegamos a un extremo, invertimos la velocidad
	{
		vel.x = -vel.x;
		vel.y = -vel.y;
	}
	else if (posicion.x >= extremo2.x) //Si llegamos al otro extremo, invertimos la velocidad nuevamente
	{
		vel.x = -vel.x;
		vel.y = -vel.y;
	}
}
//M?todos propios de Suelo
void Suelo::dibuja(int i)
{
	if (i == 1)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/mundo1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glTexCoord2d(0.1, 1);		glVertex2f(bajo1.x, bajo1.y);
		glTexCoord2d(0.95, 1);		glVertex2f(bajo2.x, bajo2.y);
		glTexCoord2d(0.95, 0.75);	glVertex2f(limite2.x, limite2.y);
		glTexCoord2d(0.1, 0.75);	glVertex2f(limite1.x, limite1.y);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else if (i == 2)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/mundo2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glTexCoord2d(0.15, 0.92);	glVertex2f(bajo1.x, bajo1.y);
		glTexCoord2d(0.85, 0.92);	glVertex2f(bajo2.x, bajo2.y);
		glTexCoord2d(0.85, 0.8);	glVertex2f(limite2.x, limite2.y);
		glTexCoord2d(0.15, 0.8);	glVertex2f(limite1.x, limite1.y);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/SueloMarte.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glTexCoord2d(0.15, 0.9);	glVertex2f(bajo1.x, bajo1.y);
		glTexCoord2d(0.85, 0.9);	glVertex2f(bajo2.x, bajo2.y);
		glTexCoord2d(0.85, 0.5);	glVertex2f(limite2.x, limite2.y);
		glTexCoord2d(0.15, 0.5);	glVertex2f(limite1.x, limite1.y);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
}
//M?todos propios de Final
void Final::dibuja(int i)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/final.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2d(0.4, 0.2);	glVertex2f(limite1.x + 0.5f, limite1.y - 1);
	glTexCoord2d(0.6, 0.2);	glVertex2f(limite2.x + 0.5f, limite2.y - 1);
	glTexCoord2d(0.6, 0.1);	glVertex2f(limite2.x - 0.5f, limite2.y + 0.5f);
	glTexCoord2d(0.4, 0.1);	glVertex2f(limite1.x - 0.5f, limite1.y + 0.5f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
//M?todos propios de Pinchos
void Pincho::dibuja(int i)
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.setState(1, true);
	sprite.draw();
	glPopMatrix();
}
//M?todos propios de BolaFuego
void BolaFuego::dibuja(int i)
{
	//Dimensiones del sprite
	fireball.setCenter(2, 2);
	fireball.setSize(4, 4);
	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	fireball.draw();
	fireball.loop();
	glPopMatrix();
}
void BolaFuego::mueve(float t)
{
	if (vel.y > 0.01)fireball.flip(true, false);
	if (vel.y < -0.01)fireball.flip(true, true);
	if ((vel.y < 0.01) && (vel.y > -0.01))
		fireball.setState(0);
	if ((posicion.y > borde.y) || (posicion.y < borde.x)) //Si superamos limtop o  bajamos de limbot
	{
		vel.y = -vel.y;
	}
	posicion.y = posicion.y + vel.y * t;
	//posicion hitbox
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - 0.75f;			e1.y = posicion.y + 0.75f;
	e2.x = posicion.x + 0.75f;			e2.y = posicion.y + 0.75f;
	e3.x = posicion.x - 0.75f;			e3.y = posicion.y - 0.75f;
	e4.x = posicion.x + 0.75f;			e4.y = posicion.y - 0.75f;
	hitbox.setPos(e1, e2, e3, e4);
}
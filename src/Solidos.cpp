#include "Solidos.h"
#include "freeglut.h"

//Constructores de los sólidos varios
Solidos::Solidos()
{

}
Pared::Pared()
{
	//Necesario para las herencias y que se llame desde caja sin tener que especificar posiciones
}
Pared::Pared(float x1, float y1, float x2, float y2, Byte r, Byte g, Byte b) 
{
	setCosa(1);
	setLims(x1, y1, x2, y2);
	setColor(r, g, b);
}
PlatMovil::PlatMovil(float lim1x, float lim1y, float lim2x, float lim2y, float vx, float vy, float ex1x, float ex1y, float ex2x, float ex2y, Byte r, Byte g, Byte b)
{
	setCosa(2);
	setColor(r, g, b);
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
Pincho::Pincho() {};
Pincho::Pincho(float px, float py) {
	setCosa(5);
	//Situamos los pinchos
	setPos(px, py);
	//Situamos las esquimnas de su hitbox
	hitbox.bot_l.x = posicion.x - 1.3;	hitbox.bot_l.y = posicion.y;
	hitbox.bot_r.x = posicion.x + 1.3;	hitbox.bot_r.y = posicion.y;
	hitbox.top_l.x = posicion.x - 1.3;	hitbox.top_l.y = posicion.y + 2.5f;
	hitbox.top_r.x = posicion.x + 1.3;	hitbox.top_r.y = posicion.y + 2.5f;
	/*Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - 1.3;		e1.y = posicion.y + 2.5;
	e2.x = posicion.x + 1.3;		e2.y = posicion.y + 2.5;
	e3.x = posicion.x - 1.3;		e3.y = posicion.y - 0;
	e4.x = posicion.x + 1.3;		e4.y = posicion.y - 0;
	hitbox.setPos(e1, e2, e3, e4);*/
}
BolaFuego::BolaFuego(float px, float py, float limtop, float limbot)
{
	//radio = 0.75f;
	setCosa(6);
	vel.x = 0.0f;
	vel.y = 10.0f;
	setPos(px, py);
	borde = { limbot, limtop };
	setColor(1, 0, 0);
}

//Métodos virtuales de Solidos
void Solidos::setColor(Byte r, Byte g, Byte b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}
void Solidos::setPos(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
}
void Solidos::dibuja() {} //Vacios para entrar en lista
void Solidos::mueve(float t) {} //El de arriba y este
void Solidos::setCosa(int i) {
	cosa = i;
}
int Solidos::getCosa() {
	return cosa;
}

//Métodos virtuales de Pared
void Pared::setLims(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
void Pared::dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
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

//Métodos propios de Pared
bool Pared::operator==(Pared p)
{
	if (limite1 == p.limite1 && limite2 == p.limite2) {
		return true;
	}
	return false;
}
//Métodos propios de PlatMovil
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
//Métodos propios de Suelo
void Suelo::dibuja()
{
	//Pintamos aquí el sprite que sea
}
//Métodos propios de Pinchos
void Pincho::dibuja()
{
	//Esto lo sustituiremos por el srpite que toque
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(posicion.x + 1, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.5f, 2.5f, 20, 10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.5f, 2.5f, 20, 10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(posicion.x - 1, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.5f, 2.5f, 20, 10);
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.top_l.x, hitbox.top_l.y, 0);
	glVertex3f(hitbox.top_r.x, hitbox.top_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.top_r.x, hitbox.top_r.y, 0);
	glVertex3f(hitbox.bot_r.x, hitbox.bot_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.bot_r.x, hitbox.bot_r.y, 0);
	glVertex3f(hitbox.bot_l.x, hitbox.bot_l.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.bot_l.x, hitbox.bot_l.y, 0);
	glVertex3f(hitbox.top_l.x, hitbox.top_l.y, 0);
	glEnd();
	glPopMatrix();
}
//Métodos propios de BolaFuego
void BolaFuego::dibuja()
{
	//Dibujo
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0.5);
	glutWireSphere(0.75f, 15, 15);
	glPopMatrix();
}
void BolaFuego::mueve(float t)
{
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
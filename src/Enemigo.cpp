#include "Enemigo.h"
#include "freeglut.h"

//Constructores de los enemigos varios
Enemigo::Enemigo() {

}
EnemigoDisp::EnemigoDisp(float px, float py) {
	altura = 2.0f; 
	vida = 4;
	setColor(1, 0, 0);
	setPos(px, py);
	setAc(0, -9.8f);
	dispEnem1->setPos(posicion.x, posicion.y + altura * 2 / 3);	//esta aqui para que este bien la posicion del disparo inicial

}
Babosa::Babosa(float px, float py) {
	altura = 1.5f;
	vida = 5;
	setColor(2, 0, 0);
	setPos(px, py);
}
Bomber::Bomber(float px, float py) {
	altura = 2.0f;
	vida = 2;
	setColor(200, 100, 0);
	setPos(px, py);
	setAc(0, -9.8f);
}
Tentaculo::Tentaculo(float px, float py) {
	altura = 5.0f;
	vida = 19;
	setColor(150, 0, 0);
	setPos(px, py);
}
Tank::Tank() {}
Tank::Tank(float px, float py) {
	altura = 7.0f;
	vida = 9;
	setColor(1, 1, 1);
	setPos(px, py);
	setAc(0, -9.8f);
	dispTank1->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank2->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank3->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank4->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank5->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank1->setVel(-dispTank1->getVelDef(), 0.0f);
	dispTank2->setVel(-dispTank1->getVelDef() * 0.707, dispTank1->getVelDef() * 0.707);
	dispTank3->setVel(0.0f, dispTank1->getVelDef());
	dispTank4->setVel(dispTank1->getVelDef() * 0.707, dispTank1->getVelDef() * 0.707);
	dispTank5->setVel(dispTank1->getVelDef(), 0.0f);
	dispTank1->setColor(10, 0, 0);
	dispTank2->setColor(10, 0, 0);
	dispTank3->setColor(10, 0, 0);
	dispTank4->setColor(10, 0, 0);
	dispTank5->setColor(10, 0, 0);
}
BossFinal::BossFinal(float px, float py) {
	altura = 14.0f;
	vida = 49;
	setColor(1, 1, 1);
	setPos(px, py);
	setAc(0, -9.8f);

	/*
	misil1->setVel(-misil1., 0.0f);
	misil2->setVel(-misil1->vel * 0.94, misil1->vel * 0.342);
	misil3->setVel(-misil1->vel * 0.766, misil1->vel * 0.643);
	misil4->setVel(-misil1->vel * 0.5, misil1->vel * 0.866);
	misil5->setVel(-misil1->vel * 0.174, misil1->vel * 0.985);

	misil6->setVel(-misil1->vel, -misil1->vel * 0.174);
	misil7->setVel(-misil1->vel * 0.94, -misil1->vel * 0.342);
	misil8->setVel(misil1->vel * 0.766, misil1->vel * 0.643);
	misil9->setVel(misil1->vel * 0.5, misil1->vel * 0.866);
	misil10->setVel(misil1->vel * 0.174, misil1->vel * 0.985);*/

	misil1->setColor(10, 0, 0);
	misil2->setColor(10, 0, 0);
	misil3->setColor(10, 0, 0);
	misil4->setColor(10, 0, 0);
	misil5->setColor(10, 0, 0);
	misil6->setColor(10, 0, 0);
	misil7->setColor(10, 0, 0);
	misil8->setColor(10, 0, 0);
	misil9->setColor(10, 0, 0);
	misil10->setColor(10, 0, 0);
}

//Método dibuja de cada enemigo
void Enemigo::dibuja()
{

}
void EnemigoDisp::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
	glRotatef(-90, 1, 0, 0);		//dibujar persona
	glTranslatef(-0.2, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(0.4, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(-0.2, 0, altura / 3);
	glutSolidCylinder(0.35, altura / 3, 30, 30);
	glTranslatef(0, 0, altura / 2);
	glRotatef(90, 1, 0, 0);
	//glutSolidTeapot(altura/6);
	glutSolidSphere(altura / 6, 30, 30);
	glTranslatef(0, 0, -altura * 5 / 6);
	//glRotatef(90, 1, 0, 0);
	glPopMatrix();

	//Añadido por Miguel (Dibuja los bordes de choque)
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
void Babosa::dibuja() {
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 0, 1, 0);
	glutSolidCylinder(altura / 3, altura, 30, 30);
	//glRotatef(90, 0, 1, 0);
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
void Bomber::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
	glutSolidSphere(altura, 30, 30);
	glPopMatrix();

	//Añadido por Miguel (Dibuja los bordes de choque)
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
void Tentaculo::dibuja() {
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(angulo, 0, 1, 0);
	glutSolidCylinder(altura / 6, altura, 30, 30);
	glutSolidSphere(altura / 6, 30, 30);

	glTranslatef(0, 0, altura);
	glRotatef(angulo, 0, 1, 0);
	glutSolidCylinder(altura / 7, altura, 30, 30);
	glutSolidSphere(altura / 7, 30, 30);

	glTranslatef(0, 0, altura);
	glRotatef(angulo, 0, 1, 0);
	glutSolidCylinder(altura / 8, altura, 30, 30);
	glutSolidSphere(altura / 8, 30, 30);
	glPopMatrix();

	/*glPushMatrix();
	//glTranslatef(posicion.x, posicion.y, 0);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[0].top_l.x, hitbox[0].top_l.y, 0);
	glVertex3f(hitbox[0].top_r.x, hitbox[0].top_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[0].top_r.x, hitbox[0].top_r.y, 0);
	glVertex3f(hitbox[0].bot_r.x, hitbox[0].bot_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[0].bot_r.x, hitbox[0].bot_r.y, 0);
	glVertex3f(hitbox[0].bot_l.x, hitbox[0].bot_l.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[0].bot_l.x, hitbox[0].bot_l.y, 0);
	glVertex3f(hitbox[0].top_l.x, hitbox[0].top_l.y, 0);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[1].top_l.x, hitbox[1].top_l.y, 0);
	glVertex3f(hitbox[1].top_r.x, hitbox[1].top_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[1].top_r.x, hitbox[1].top_r.y, 0);
	glVertex3f(hitbox[1].bot_r.x, hitbox[1].bot_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[1].bot_r.x, hitbox[1].bot_r.y, 0);
	glVertex3f(hitbox[1].bot_l.x, hitbox[1].bot_l.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[1].bot_l.x, hitbox[1].bot_l.y, 0);
	glVertex3f(hitbox[1].top_l.x, hitbox[1].top_l.y, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[2].top_l.x, hitbox[2].top_l.y, 0);
	glVertex3f(hitbox[2].top_r.x, hitbox[2].top_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[2].top_r.x, hitbox[2].top_r.y, 0);
	glVertex3f(hitbox[2].bot_r.x, hitbox[2].bot_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[2].bot_r.x, hitbox[2].bot_r.y, 0);
	glVertex3f(hitbox[2].bot_l.x, hitbox[2].bot_l.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[2].bot_l.x, hitbox[2].bot_l.y, 0);
	glVertex3f(hitbox[2].top_l.x, hitbox[2].top_l.y, 0);
	glEnd();
	glPopMatrix();*/
}
void Tank::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
	glRotatef(-90, 1, 0, 0);		//dibujar persona
	glutSolidCylinder(altura / 3, altura / 3, 30, 30);
	glTranslatef(0, 0, altura / 3);
	glutSolidSphere(altura / 3, 30, 30);
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
void BossFinal::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
	glRotatef(-90, 1, 0, 0);		//dibujar persona
	glutSolidCylinder(altura / 3, altura / 3, 30, 30);
	glTranslatef(0, 0, altura / 3);
	glutSolidSphere(altura / 3, 30, 30);
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

//Métodos mueve de cada enemigo
void Enemigo::mueve(float t)
{
}
void EnemigoDisp::mueve(float t)
{
	ObjetoMovil::mueve(t);

	//Disparo de los enemigos cada 3 segundos
	if (temp < 120) {		//40 para 1 seg
		temp++;
		if (temp == 120) {		//volver a disparar
			/*dispEnem1->setPos(posicion.x, posicion.y + altura * 2 / 3);
			dispEnem1->setVel(-dispEnem1->vel + velocidad.x, 0.0f);
			dispEnem1->flagdibujar = 1;*/
		}
	}
	else {
		//~DispEnem();
		temp = 0;
	}
	if (zonaH == 0) {
		if (sentido == 0) {
			velocidad.x = 1;
		}
		else
			velocidad.x = -1;
	}

	//Añadido por Miguel (crea las paredes de choque)
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - 0.3f;	e1.y = posicion.y + 2.0f;
	e2.x = posicion.x + 0.3f;	e2.y = posicion.y + 2.0f;
	e3.x = posicion.x - 0.3f;	e3.y = posicion.y - 0.0f;
	e4.x = posicion.x + 0.3f;	e4.y = posicion.y - 0.0f;
	hitbox.setPos(e1, e2, e3, e4);

	if (tempdmg) {
		tempdmg--;
		if (vida <= 0) {	//muerto
			setColor(1, 1, 1);
		}
	}
	else if (flagdmg) {
		vida -= 1 + flagesp;
		//destruir la vida de la interfaz
		flagdmg = 0;
		flagesp = 0;
	}
}
void Babosa::mueve(float t) {
	ObjetoMovil::mueve(t);

	if (cerca) {
		if (prx)
			aceleracion.x = -1;
		else
			aceleracion.x = 1;

		if (pry)
			aceleracion.y = -1;
		else
			aceleracion.y = 1;

		if (velocidad.x > 2)
			velocidad.x = 2;
		if (velocidad.y > 2)
			velocidad.y = 2;
	}
	else {
		if (prx)
			aceleracion.x = -1;
		else
			aceleracion.x = 1;

		if (pry)
			aceleracion.y = -1;
		else
			aceleracion.y = 1;
		if (velocidad.x > 3)
			velocidad.x = 3;
		if (velocidad.y > 3)
			velocidad.y = 3;
	}

	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - altura;		e1.y = posicion.y + altura / 3;
	e2.x = posicion.x + 0;			e2.y = posicion.y + altura / 3;
	e3.x = posicion.x - altura;		e3.y = posicion.y - altura / 3;
	e4.x = posicion.x + 0;			e4.y = posicion.y - altura / 3;
	hitbox.setPos(e1, e2, e3, e4);

	if (tempdmg) {
		tempdmg--;
		if (vida <= 0) {	//muerto
			setColor(1, 1, 1);
		}
	}
	else if (flagdmg) {
		vida -= 1 + flagesp;
		//destruir la vida de la interfaz
		flagdmg = 0;
		flagesp = 0;
	}
}
void Bomber::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;


	//if (zonaH == 0) {
	if (sentido == 0) {
		velocidad.x = 1;
	}
	else
		velocidad.x = -1;
	//}

	//Añadido por Miguel (crea las paredes de choque)
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - altura;		e1.y = posicion.y + altura;
	e2.x = posicion.x + altura;		e2.y = posicion.y + altura;
	e3.x = posicion.x - altura;		e3.y = posicion.y - altura;
	e4.x = posicion.x + altura;		e4.y = posicion.y - altura;
	hitbox.setPos(e1, e2, e3, e4);

	if (tempdmg) {
		tempdmg--;
		if (vida <= 0) {	//muerto
			setColor(1, 1, 1);
		}
	}
	else if (flagdmg) {
		vida -= 1 + flagesp;
		//destruir la vida de la interfaz
		flagdmg = 0;
		flagesp = 0;
	}
}
void Tentaculo::mueve(float t) {
	/*posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	velocidad.x = aceleracion.x = 0;*/      //creo que se puede quitar todo

	int lim = 15;
	if (angulo > lim)
		flag = 1;
	if (angulo < -lim)
		flag = 0;

	if (flag == 0)
		angulo += 0.2f;
	else
		angulo -= 0.2f;

	//Vector2D e1, e2, e3, e4;
	/*float h0 = sqrt(longitud * longitud + longitud * longitud / 36);
	float beta0 = atan(1 / 6);
	e1.x = h0 * sin((a) * pi / 180 - beta0);		e1.y = h0 * sin((a )*pi/180 - beta0);
	e2.x = h0* sin((a) * pi / 180 + beta0);			e2.y = h0 * cos((a ) * pi / 180 + beta0);
	e3.x = -(longitud / 6) * cos(a * pi / 180);		e3.y = (longitud / 6) * (sin(a * pi / 180));
	e4.x = (longitud / 6) * cos(a * pi / 180);		e4.y = -(longitud / 6) * (sin(a * pi / 180));*/

	/*e1.x = -(longitud / 6) + longitud * sin(a * pi / 180) + posicion.x;		e1.y = (longitud) * (cos(-a * pi / 180)) + posicion.y;
	e2.x = (longitud / 6) + longitud * sin(a * pi / 180) + posicion.x;			e2.y = (longitud) * (cos(-a * pi / 180)) + posicion.y;
	e3.x = -(longitud / 6) * cos(-a * pi / 180) + posicion.x;				e3.y = -(longitud / 6) * (sin(-a * pi / 180)) + posicion.y;
	e4.x = (longitud / 6) * cos(-a * pi / 180) + posicion.x;					e4.y = (longitud / 6) * (sin(-a * pi / 180)) + posicion.y;
	hitbox[0].setPos(e1, e2, e3, e4);


	Vector2D e11, e21, e31, e41;
	e11.x = -(longitud / 6) + longitud * sin(3 * a * pi / 180);		e11.y = (longitud) * (cos(3 * a * pi / 180)) + 2 * sin(a * pi / 180) * sin(a * pi / 180);
	e21.x = (longitud / 6) + longitud * sin(3 * a * pi / 180);		e21.y = (longitud) * (cos(3 * a * pi / 180)) + 2 * sin(a * pi / 180) * sin(a * pi / 180);
	e31.x = -(longitud / 6) + longitud * sin(a * pi / 180) + posicion.x;			e31.y = (longitud) * (cos(-a * pi / 180)) + posicion.y;
	e41.x = (longitud / 6) + longitud * sin(a * pi / 180) + posicion.x;			e41.y = (longitud) * (cos(-a * pi / 180)) + posicion.y;
	Vector2D e111 = { e11.x + posicion.x, e1.y + e11.y }, e211 = { e21.x + posicion.x, e2.y + e21.y };
	hitbox[1].setPos(e111, e211, e31, e41);

	Vector2D e12, e22, e32, e42;
	e12.x = -(longitud / 6) + longitud * 2 * sin(3.2 * a * pi / 180);		e12.y = (longitud) * (cos(a * pi / 180)) - 0.5 * (cos(a * pi / 180));
	e22.x = (longitud / 6) + longitud * 2 * sin(3.2 * a * pi / 180);		e22.y = (longitud) * (cos(a * pi / 180)) - 0.5 * (cos(a * pi / 180));
	e32.x = -(longitud / 6) + longitud * sin(3 * a * pi / 180);			e32.y = (longitud) * (cos(3 * a * pi / 180)) + 2 * sin(a * pi / 180) * sin(a * pi / 180);
	e42.x = (longitud / 6) + longitud * sin(3 * a * pi / 180);			e42.y = (longitud) * (cos(3 * a * pi / 180)) + 2 * sin(a * pi / 180) * sin(a * pi / 180);
	Vector2D e121 = { e12.x + posicion.x, e111.y + e12.y }, e221 = { e22.x + posicion.x, e211.y + e22.y };
	hitbox[2].setPos(e121, e221, e111, e211);*/

	if (tempdmg) {
		tempdmg--;
		if (vida <= 0) {	//muerto
			setColor(1, 1, 1);
		}
	}
	else if (flagdmg) {
		vida -= 1 + flagesp;
		//destruir la vida de la interfaz
		flagdmg = 0;
		flagesp = 0;
	}
}
void Tank::mueve(float t)
{
	ObjetoMovil::mueve(t);

	if (temp < 120) {		//40 para 1 seg
		temp++;
		//mueve?

		if (temp == 120) {
			/*dispTank1->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank2->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank3->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank4->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank5->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank1->setVel(-dispTank1->vel + velocidad.x, 0.0f);
			dispTank2->setVel(-dispTank1->vel * 0.707 + velocidad.x, dispTank1->vel * 0.707);
			dispTank3->setVel(0.0f + velocidad.x, dispTank1->vel);
			dispTank4->setVel(dispTank1->vel * 0.707 + velocidad.x, dispTank1->vel * 0.707);
			dispTank5->setVel(dispTank1->vel + velocidad.x, 0.0f);
			dispTank1->flagdibujar = 1;
			dispTank2->flagdibujar = 1;
			dispTank3->flagdibujar = 1;
			dispTank4->flagdibujar = 1;
			dispTank5->flagdibujar = 1;*/
		}

	}
	else {
		//~DispEnem();
		temp = 0;
	}

	if (zonaH == 0) {
		if (sentido == 0) {
			velocidad.x = -1;
		}
		else
			velocidad.x = 1;
	}

	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - altura / 3;		e1.y = posicion.y + altura * 2 / 3;
	e2.x = posicion.x + altura / 3;		e2.y = posicion.y + altura * 2 / 3;
	e3.x = posicion.x - altura / 3;		e3.y = posicion.y - 0;
	e4.x = posicion.x + altura / 3;		e4.y = posicion.y - 0;
	hitbox.setPos(e1, e2, e3, e4);

	if (tempdmg) {
		tempdmg--;
		if (vida <= 0) {	//muerto
			setColor(1, 1, 1);
		}
	}
	else if (flagdmg) {
		vida -= 1 + flagesp;
		//destruir la vida de la interfaz
		flagdmg = 0;
		flagesp = 0;
	}
}
void BossFinal::mueve(float t)
{
	ObjetoMovil::mueve(t);

	if (temp < 120) {		//40 para 1 seg
		temp++;
		//mueve?

		if (temp == 120) {
			/*misil1->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil2->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil3->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil4->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil5->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil6->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil7->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil8->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil9->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil10->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial

			misil1->setVel(-misil1->vel, 0.0f);
			misil2->setVel(-misil1->vel * 0.94, misil1->vel * 0.342);
			misil3->setVel(-misil1->vel * 0.766, misil1->vel * 0.643);
			misil4->setVel(-misil1->vel * 0.5, misil1->vel * 0.866);
			misil5->setVel(-misil1->vel * 0.174, misil1->vel * 0.985);
			misil6->setVel(-misil1->vel, -misil1->vel * 0.174);
			misil7->setVel(-misil1->vel * 0.94, -misil1->vel * 0.342);
			misil8->setVel(misil1->vel * 0.766, misil1->vel * 0.643);
			misil9->setVel(misil1->vel * 0.5, misil1->vel * 0.866);
			misil10->setVel(misil1->vel * 0.174, misil1->vel * 0.985);

			misil1->flagdibujar = 1;
			misil2->flagdibujar = 1;
			misil3->flagdibujar = 1;
			misil4->flagdibujar = 1;
			misil5->flagdibujar = 1;
			misil6->flagdibujar = 1;
			misil7->flagdibujar = 1;
			misil8->flagdibujar = 1;
			misil9->flagdibujar = 1;
			misil10->flagdibujar = 1;*/
		}

	}
	else {
		//~DispEnem();
		temp = 0;
	}

	if (zonaH == 0) {
		if (sentido == 0) {
			velocidad.x = -1;
		}
		else
			velocidad.x = 1;
	}

	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - altura / 3;		e1.y = posicion.y + altura * 2 / 3;
	e2.x = posicion.x + altura / 3;		e2.y = posicion.y + altura * 2 / 3;
	e3.x = posicion.x - altura / 3;		e3.y = posicion.y - 0;
	e4.x = posicion.x + altura / 3;		e4.y = posicion.y - 0;
	hitbox.setPos(e1, e2, e3, e4);

	if (tempdmg) {
		tempdmg--;
		if (vida <= 0) {	//muerto
			setColor(1, 1, 1);
		}
	}
	else if (flagdmg) {
		vida -= 1 + flagesp;
		//destruir la vida de la interfaz
		flagdmg = 0;
		flagesp = 0;
	}
}

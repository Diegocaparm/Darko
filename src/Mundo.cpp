#include "Mundo.h"
#include "freeglut.h"
#include <math.h>


void Mundo::rotarOjo()
{
	/*float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);*/
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo + 3, z_ojo,  // posicion del ojo
			0.0f, 7.5f, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
				
	caja.dibuja();
	esfera.dibuja();
	esfera2.dibuja();
	hombre.dibuja();
	disparo.dibuja();
	
	plataforma1.dibuja();
	plataforma2.dibuja();
	bonus.dibuja();

	eneDisp1.dibuja();			//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
	tank.dibuja();



	/*glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);
		glVertex3f(-5.0f, 0, -5.0f);
		glVertex3f(-5.0f, 0, 5.0f);
		glColor3ub(255, 255, 0);
		glVertex3f(5.0f, 0, 5.0f);
		glVertex3f(5.0f, 0, -5.0f);

		//caja.dibuja();

	glEnd();
	glEnable(GL_LIGHTING);
	*/
}

void Mundo::mueve()
{
	hombre.mueve(0.025f);
	esfera.mueve(0.025f);
	esfera2.mueve(0.025f);
	bonus.mueve(0.025f);
	disparo.mueve(0.025f);

	eneDisp1.mueve(0.025f);
	tank.mueve(0.025f);


	Interaccion::rebote(hombre, caja);

	Interaccion::rebote(hombre, plataforma1);
	Interaccion::rebote(hombre, plataforma2);

	Interaccion::rebote(esfera, plataforma1);
	Interaccion::rebote(esfera, plataforma2);

	Interaccion::rebote(esfera, caja);
	Interaccion::rebote(esfera2, caja);

	Interaccion::rebote(esfera2, plataforma1);
	Interaccion::rebote(esfera2, plataforma2);

	Interaccion::rebote(esfera, esfera2);

	Interaccion::rebote(eneDisp1, caja);	//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
	if(eneDisp1.posicion.y <10.2f&& eneDisp1.posicion.y > 9.8f)
		Interaccion::rebote(eneDisp1, plataforma1);
	if (eneDisp1.posicion.y < 5.2f && eneDisp1.posicion.y > 4.8f)
		Interaccion::rebote(eneDisp1, plataforma2);
	Interaccion::rebote(tank, caja);	//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
	if (tank.posicion.y < 10.2f && tank.posicion.y > 9.8f)
		Interaccion::rebote(tank, plataforma1);
	if (tank.posicion.y < 5.2f && tank.posicion.y > 4.8f)
		Interaccion::rebote(tank, plataforma2);
}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	esfera.setColor(0, 0, 255);
	esfera.setRadio(1.5f);
	esfera.setPos(2.0f, 4.0f);
	esfera.setVel(5, 15);

	esfera2.setRadio(2);
	esfera2.setPos(-2, 4);
	esfera2.setVel(-5, 15);

	bonus.setPos(5.0f, 5.0f);

	disparo.setPos(-5.0f, 0.0f);

	plataforma1.setPos(2.0f,10.0f, -5.0f, 10.0f);
	plataforma1.setColor(50, 150, 250);//color plataforma

	plataforma2.setPos(7.0f, 5.0f, -2.0f, 5.0f);
	plataforma2.setColor(150, 150, 50);
}

void Mundo::tecla(unsigned char key)
{
	if (key == ' ') {
		Interaccion::disparoInicializa(pdisparo, phombre);
		eneDisp1.velocidad.x = 2;
	}
	if (key == 'w') {
		//eneDisp1.posicion.y += 3;
		eneDisp1.velocidad.y = 3.0f;
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVelx(-5.0f);	//hombre.setVel(-5.0f,0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVelx(5.0f);
		break;
	case GLUT_KEY_UP:
		if (hombre.salto==1)
			hombre.salto = 0;
		break;
	default:
			hombre.setVelx(0.0f);
			hombre.salto = 1;
		break;
	}
}

/*void Mundo::teclaEspecialUp(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		hombre.salto = 1;
		break;
	}
}*/



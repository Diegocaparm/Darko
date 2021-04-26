#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void disparoInicializa(Disparo *, Hombre *);

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
				
	caja.dibuja();
	esfera.dibuja();
	hombre.dibuja();
	disparo.dibuja();
	
	plataforma.dibuja();
	bonus.dibuja();

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
	bonus.mueve(0.025f);
	disparo.mueve(0.025f);
}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	bonus.posicion.x = 5.0f;
	bonus.posicion.y = 5.0f;
	disparoInicializa(pdisparo, phombre);
	plataforma.SetPos(-5.0f, 9.0f, 5.0f, 9.0f);
	plataforma.SetColor(0, 150, 150);//color plataforma
	caja.Inicializa();
}

void Mundo::tecla(unsigned char key)
{
	hombre.tecla(key);

	if (key == ' ') {
		disparoInicializa(pdisparo, phombre);
		
	}
}


void disparoInicializa(Disparo* disparo, Hombre* hombre) {
	disparo->radio = 0.2f;
	disparo->posicion.x = hombre->posicion.x;
	disparo->posicion.y = hombre->posicion.y;
	disparo->ini = 0;
}

//void onSpecialKeyboardDown(int key);		//movimiento especial
//GLUT_KEY_RIGHT
//void onSpecialUpFunc();
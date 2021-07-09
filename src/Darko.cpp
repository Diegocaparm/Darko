//#include "Nivel.h"
#include "Menu.h"
#include "freeglut.h"

Menu menu;

//Llamadas a callbacks
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyDown(unsigned char key, int x, int y); //cuando se presione una tecla	
void OnKeyUp(unsigned char key, int x, int y);//Cuando se suelta una tecla
void onKeyboardDown(unsigned char key, int x, int y);


int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Gran juego de plataformas"); //Ya se cambiará el nombre

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyDown);
	glutKeyboardUpFunc(OnKeyUp);
	glutKeyboardFunc(onKeyboardDown);
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	menu.Dibuja(); //Dibujo el menú

	glutSwapBuffers();
}


void OnKeyDown(unsigned char key, int x_t, int y_t)
{
	menu.TeclaDown(key);
	glutPostRedisplay();
}

void OnKeyUp(unsigned char key, int x_t, int y_t)
{
	menu.TeclaUp(key);
	glutPostRedisplay();
}

void onKeyboardDown(unsigned char key, int x, int y)
{
	menu.Tecla(key);
	glutPostRedisplay();
}

void OnTimer(int value)
{
	menu.Mueve();
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
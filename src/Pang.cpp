#include "Nivel1.h"
#include "freeglut.h"
#include "Menu.h"

//Menu (Creo que deberíamos llamar todos los niveles como estados desde el menú e inicializarlos allí)
Menu menu;
Nivel1 nivel1;

//Llamadas a callbacks
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyDown(unsigned char key, int x, int y); //cuando se presione una tecla	
void OnKeyUp(unsigned char key, int x, int y);//Cuando se suelta una tecla
void onSpecialKeyboardDown(int key, int x, int y);
//void onSpecialKeyboardUp(int key, int x, int y);


int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Gran juego de plataformas"); //Ya se cambiará el nombre

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyDown);
	glutKeyboardUpFunc(OnKeyUp);
	glutSpecialFunc(onSpecialKeyboardDown); //gestion de los cursores
	//glutSpecialFunc(onSpecialKeyboardUp);

	//Inicializacion de la escena
	//Puede que deba existir un menu.inicializa()
	nivel1.inicializa();
		
	//pasarle el control a GLUT,que llamara a los callbacks
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
	nivel1.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}


void OnKeyDown(unsigned char key, int x_t, int y_t)
{
	menu.Tecla(key); //Creo que el código del teclado del nivel 1 también debería ir en el menú
	nivel1.teclaDown(key);

	glutPostRedisplay();
}

void OnKeyUp(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	nivel1.teclaUp(key);

	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
	menu.TeclaEspecial(key); //Creo que el código del teclado del nivel 1 también debería ir en el menú
	nivel1.teclaEspecial(key);
}

/*void onSpecialKeyboardUp(int key, int x, int y)
{
	mundo.teclaEspecialUp(key);
}*/


void OnTimer(int value)
{
	menu.Mueve(); //Lo mismo de antes
	nivel1.mueve();

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

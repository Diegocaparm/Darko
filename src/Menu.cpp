#include "Menu.h"
#include "freeglut.h"

Menu::Menu()  //Constructor
{
	estado = START;                                  //Comienza el juego en START
	ETSIDI::playMusica("bin/bso/intro.mp3", true);   //Se activa la m�sica del inicio
	camara = 0;
}

Menu::~Menu() //Destructor
{

}

void Menu::Dibuja()							 //Para dibujar en pantalla los distintos estados
{
	if (estado != NIVEL && estado != FIN)						 //Posici�n del men� si no estamos en el estado FIN
		gluLookAt(0.0, 4.5, 13,
			0.0, 4.5, 0.0,
			0.0, 1.0, 0.0);
	switch (estado)
	{
	case START:  //Estado de INICIO
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/start.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case MENU: //Menu princupal (comenzar, controles, salir)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/menu.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case CONTROLES:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/controles.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case ESCOGE_PERSONAJE: //Escoger el personaje con el que se quiere jugar
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/escoge_personaje.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case HISTORIA: //Presentacion de la historia
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/historia.png").id); //foto correo
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		break;

	case SUERTE: //Deseamos animo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/suerte.png").id); //foto animo
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case NIVEL: //Comenzamos el juego
		camara = nivel.hombre.getPos().x;   // recoge la posicion x del mu�eco en la variable ojo
		if (camara <= 0) camara = 0;
		gluLookAt(camara, 11.5, nivel.z_ojo,  // posicion del ojo  
			camara, 7.5f, 0.0,      // hacia que punto mira  (hombre.posicion.y + 8)
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    		
		
		nivel.dibuja();
		//vida1.GetMov(ojo);

		/*if (nivel1.SetVida() == 2)        // Vida en la convocatoria ordinaria
			vida1.Dibuja();

		if (nivel1.SetVida() == 1) {      // Vida en la convocatoria de julio
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/julio.mp3", true);
			guardanivel = 1;
			estado = JULIO;
		}*/

		if (nivel.hombre.getPos().x == nivel.hombre.getfin()) //Si el mu�eco llega al final del nivel pasa al siguiente
		{
			nivel.inicializa();
			switch (nivel.hombre.getguardapersonaje()) {         //Dibuja el personaje escogido
			case 0:
				nivel.hombre.setDarko();	//Cargo a Darko
				break;
			case 1:
				nivel.hombre.setHumano();	//Cargo Astronauta
				break;
			}
			if (nivel.nivel == 1)
				estado = NIVEL;
			else if (nivel.nivel == 2)	//CAMBIAR?? En alg�n punto hay que poner un nivel ++, quiz�s aqu� es buena opci�n
				estado = NIVEL;			//nivel.nivel++??????
			else if (nivel.nivel == 3)
				estado = NIVEL;
			else if (nivel.nivel == 4)
				estado = NIVEL;
			else if (nivel.nivel == 5)
				estado = NIVEL;
			else if (nivel.nivel == 6)
				estado = NIVEL;
			else if (nivel.nivel == 7)
				estado = NIVEL;
			else if (nivel.nivel == 8)
				estado = NIVEL;
			else if (nivel.nivel == 9)
				estado = VICTORIA;
			Musica();
		}

		break;

	case VICTORIA: //Has ganado
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/victoria.png").id); //foto victoria
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case GAMEOVER: //Has perdido
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/gameover.png").id); //foto derrrota
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case FIN: //Fin del juego

		gluLookAt(0.0, 8, 10,   // Posici�n del ojo si esta en el menu
			0.0, 4.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fin.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	}
}

void Menu::Tecla(unsigned char key)
{
	switch (estado)
	{
	case START:
		if (key == 27)              //Pulsa esc para salir
			exit(0);
		if (key == 13) {            //Pulsa el enter para continuar
			//nivel1.Inicializa();
			Musica();
			key = '0';
			estado = MENU;
		}
		break;

	case MENU:
		if (key == 27)              //Pulsa esc para salir
			exit(0);
		if (key == 'C' || key == 'c')
			estado = CONTROLES;
		if (key == 13)              //comenzar juego
			estado = ESCOGE_PERSONAJE;
		break;

	case CONTROLES:
		if (key == 27)              //Pulsa esc para volver al MENU
			estado = MENU;
		break;

	case ESCOGE_PERSONAJE:
		if (key == 27)              //Pulsa esc para volver al MENU
			estado = MENU;

		if (key == 80 || key == 112 || key == 72 || key == 104)
			estado = HISTORIA;

		Musica();					//Comenzar�a la m�sica de la historia 
		break;

	case HISTORIA:
		if (key == 27)              //Pulsa esc para volver al MENU
		{
			estado = MENU;
			Musica();				//Comenzar�a la m�sica del men�
		}
		if (key == 13)              //Pulsa enter para pasar a la siguiente pantalla
			estado = SUERTE;
		break;

	case SUERTE:
		if (key == 27)              //Pulsa esc para volver al MENU
			estado = MENU;

		if (key == 13)              //Pulsa enter para empezar a jugar
		{
			nivel.inicializa();
			estado = NIVEL;
			Musica();				//COMENZAR�A LA M�SICA QUE QUISI�RAMOS PONERLE AL NIVEL1
		}
		break;

	case NIVEL:

		nivel.teclaUp(key);
		nivel.teclaDown(key);

		if (key == 27)              //Pulsa esc para volver al MENU
			estado = MENU;

	case GAMEOVER:
		if (key == 27)              //Pulsa esc para salir del juego
		{
			exit(0);
			Musica();
		}
		if (key == 13)              //Pulsa enter para salir del juego
		{
			exit(0);
			Musica();
		}
		break;

	case VICTORIA:
		if (key == 27)              //Pulsa esc para ir al estado FIN
		{
			estado = FIN;
			Musica();
		}
		if (key == 13)              //Pulsa enter para ir al estado FIN
		{
			estado = FIN;
			Musica();
		}
		break;

	case FIN:						//Final de la historia
		if (key == 27)              //Pulsa esc para salir del juego
		{
			exit(0);
			Musica();
		}
		if (key == 13)              //Pulsa enter para salir del juego
		{
			exit(0);
			Musica();
		}
		break;
	}
}

void Menu::Musica()
{
	switch (estado)
	{
	case HISTORIA:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/historia.mp3", true);
		break;

	case MENU:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/intro.mp3", true);
		break;

	case NIVEL:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/nivel.mp3", true);
		break;

	case VICTORIA:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/victoria.mp3", true);
		break;

	case GAMEOVER:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/gameover.mp3", true);
		break;

	case FIN:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/fin.mp3", true);
		break;
	}

}

void Menu::TeclaDown(unsigned char key)
{
	nivel.teclaDown(key);
}

void Menu::TeclaUp(unsigned char key)
{
	nivel.teclaUp(key);
}

void Menu::TeclaEspecial(unsigned char key)
{
	nivel.teclaEspecial(key);
}

void Menu::Mueve()
{
	if (estado == NIVEL)       //El juego est� en el estado nivel
		nivel.mueve();         //Se llama a la funci�n mueve de espacio para controlar los distintos objetos que aparecen en pantalla
}


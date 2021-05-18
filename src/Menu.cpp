 #include "Menu.h"
#include "freeglut.h"

Menu::Menu()  //Constructor
{
	estado = START;                                  //Comienza el juego en START
	ETSIDI::playMusica("bso/intro.mp3", true);   //Se activa la música del inicio
}

Menu::~Menu() //Destructor
{

}

void Menu::Dibuja()							 //Para dibujar en pantalla los distintos estados
{
	if (estado != FIN)						 //Posición del menú si no estamos en el estado FIN
		gluLookAt(0.0, 4.5, 13,              
			0.0, 4.5, 0.0,
			0.0, 1.0, 0.0);
	switch (estado)
	{
	case START:  //Estado de INICIO
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/start.png").id);
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu.png").id);
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/controles.png").id);
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/escoge_personaje.png").id);
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/historia.png").id); //foto correo
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/suerte.png").id); //foto animo
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

	case VICTORIA: //Has ganado
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/victoria.png").id); //foto victoria
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

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/gameover.png").id); //foto derrrota
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

		gluLookAt(0.0, 8, 10,   // Posición del ojo si esta en el menu
			0.0, 4.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fin.png").id);
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
		/*else {
			if (nivel1.muñeco.SetSexo(key) == 1 && key != 13)        //Se escoge chico
				estado = HISTORIA;
			else if (nivel1.muñeco.SetSexo(key) == 0 && key != 13)   //Se escoge chica
				estado = HISTORIA;
		}*/
		Musica();					//Comenzaría la música de la historia 
		break;

	case HISTORIA:
		if (key == 27)              //Pulsa esc para volver al MENU
		{
			estado = MENU;
			Musica();				//Comenzaría la música del menú
		}
		if (key == 13)              //Pulsa enter para pasar a la siguiente pantalla
			estado = SUERTE;
		break;

	case SUERTE:
		if (key == 27)              //Pulsa esc para volver al MENU
			estado = MENU;

		/*if (key == 13)              //Pulsa enter para empezar a jugar
		{
			nivel1.Inicializa();
			estado = NIVEL1;
			Musica();				//COMENZARÍA LA MÚSICA QUE QUISIÉRAMOS PONERLE AL NIVEL1
		}*/
		break;

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
		ETSIDI::playMusica("bso/historia.mp3", true);
		break;

	case MENU:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bso/intro.mp3", true);
		break;

	/*case NIVEL1:

		if (nivel1.SetVida() == 2)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/nivel1.mp3", true);
		}
		break;*/

	case VICTORIA:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bso/victoria.mp3", true);
		break;

	case GAMEOVER:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bso/gameover.mp3", true);
		break;

	case FIN:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bso/fin.mp3", true);
		break;
	}

}

void Menu::TeclaEspecial(unsigned char key)
{
	//nivel1.TeclaEspecial(key);
}

void Menu::Mueve()
{
	/*if (estado == NIVEL1)       //El juego está en el primer nivel
	{
		nivel1.Mueve();         //Se llama a la función mueve de espacio para controlar los distintos objetos que aparecen en pantalla
	}*/
}


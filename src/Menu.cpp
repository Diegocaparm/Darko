#include "Menu.h"
#include "freeglut.h"
#include "stdio.h"

Menu::Menu()  //Constructor
{
	estado = START;                                  //Comienza el juego en START
	ETSIDI::playMusica("bin/musica/menu.ogg", true);   //Se activa la música del inicio
	camara = 0;
}

Menu::~Menu() //Destructor
{

}

void Menu::Dibuja()							 //Para dibujar en pantalla los distintos estados
{
	if (estado != NIVEL && estado != FIN)						 //Posición del menú si no estamos en el estado FIN
		gluLookAt(0.0f, 4.5f, 13.0f,
			0.0f, 4.5f, 0.0f,
			0.0f, 1.0f, 0.0f);
	switch (estado)
	{
	case START:  //Estado de INICIO
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/start.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 1);		glVertex3f(6.5, -0.25, -0.1f);
		glTexCoord2d(1, 0);		glVertex3f(6.5f, 9.25f, -0.1f);
		glTexCoord2d(0, 0);		glVertex3f(-6.5f, 9.25f, -0.1f);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case MENU: //Menu principal (comenzar, controles, salir)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/menu.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 1);		glVertex3f(6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 0);		glVertex3f(6.5f, 9.25f, -0.1f);
		glTexCoord2d(0, 0);		glVertex3f(-6.5f, 9.25f, -0.1f);
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
		glTexCoord2d(0, 1);		glVertex3f(-6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 1);		glVertex3f(6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 0);		glVertex3f(6.5f, 9.25f, -0.1f);
		glTexCoord2d(0, 0);		glVertex3f(-6.5f, 9.25f, -0.1f);
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
		glTexCoord2d(0, 1);		glVertex3f(-6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 1);		glVertex3f(6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 0);		glVertex3f(6.5f, 9.25f, -0.1f);
		glTexCoord2d(0, 0);		glVertex3f(-6.5f, 9.25f, -0.1f);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case HISTORIA: //Presentacion de la historia
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/historia.png").id); //foto correo
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 1);		glVertex3f(6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 0);		glVertex3f(6.5f, 9.25f, -0.1f);
		glTexCoord2d(0, 0);		glVertex3f(-6.5f, 9.25f, -0.1f);
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

		glTexCoord2d(0, 1);		glVertex3f(-6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 1);		glVertex3f(6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 0);		glVertex3f(6.5f, 9.25f, -0.1f);
		glTexCoord2d(0, 0);		glVertex3f(-6.5f, 9.25f, -0.1f);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case NIVEL: //Comenzamos el juego
		camara = nivel.hombre.getPos().x;   // recoge la posicion x del muñeco en la variable ojo
		gluLookAt(camara, 11.5, 30,  // posicion del ojo  
			camara, 7.5f, 0.0,      // hacia que punto mira  (hombre.posicion.y + 8)
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    		

		nivel.dibuja();
		nivel.inicializa();
		if (nivel.nivel == 1)
		{
			estado = NIVEL;
			Musica();
			aux++;
		}
		else if (nivel.nivel == 2)	//CAMBIAR?? En algún punto hay que poner un nivel ++, quizás aquí es buena opción
		{
			estado = NIVEL;
			Musica();
			aux1++;
		}
		else if (nivel.nivel == 3)
		{
			estado = NIVEL;
			Musica();
			aux2++;
		}
		else if (nivel.nivel == 4)
		{
			estado = NIVEL;
			Musica();
			aux3++;
		}
		else if (nivel.nivel == 5)
		{
			estado = NIVEL;
			Musica();
			aux4++;
		}
		else if (nivel.nivel == 6)
		{
			estado = NIVEL;
			Musica();
			aux5++;
		}
		else if (nivel.nivel == 7)
		{
			estado = NIVEL;
			Musica();
			aux6++;
		}
		else if (nivel.nivel == 8)
		{
			estado = NIVEL;
			Musica();
			aux7++;
		}
		else if (nivel.nivel == 9)
		{
			estado = NIVEL;
			Musica();
			aux8++;
		}
		else if (nivel.nivel > 9)
			estado = VICTORIA;
		//Musica();

		break;

	case VICTORIA: //Has ganado
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/victoria.png").id); //foto victoria
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 1);		glVertex3f(6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 0);		glVertex3f(6.5f, 9.25f, -0.1f);
		glTexCoord2d(0, 0);		glVertex3f(-6.5f, 9.25f, -0.1f);
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
		glTexCoord2d(0, 1);		glVertex3f(-6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 1);		glVertex3f(6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 0);		glVertex3f(6.5f, 9.25f, -0.1f);
		glTexCoord2d(0, 0);		glVertex3f(-6.5f, 9.25f, -0.1f);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case FIN: //Fin del juego

		gluLookAt(0.0, 8, 10,   // Posición del ojo si esta en el menu
			0.0, 4.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fin.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);		glVertex3f(-6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 1);		glVertex3f(6.5f, -0.25f, -0.1f);
		glTexCoord2d(1, 0);		glVertex3f(6.5f, 9.25f, -0.1f);
		glTexCoord2d(0, 0);		glVertex3f(-6.5f, 9.25f, -0.1f);
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
		if (nivel.hombre.setPersonaje(key))
			//if (key == 80 || key == 112 || key == 72 || key == 104)
			estado = HISTORIA;
		if (key == 13)
			estado = MENU;
		//Musica();					//Comenzaría la música de la historia 
		break;

	case HISTORIA:
		if (key == 27)              //Pulsa esc para volver al MENU
		{
			estado = MENU;
			//Musica();				//Comenzaría la música del menú
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
			Musica();				//COMENZARÍA LA MÚSICA QUE QUISIÉRAMOS PONERLE AL NIVEL1
		}
		break;

	case NIVEL:

		nivel.teclaUp(key);
		nivel.teclaDown(key);

		if (key == 27)              //Pulsa esc para volver al MENU
		{
			estado = MENU;
			Musica();				//Comenzaría la música del menú
		}

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
	/*case HISTORIA:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/historia.mp3", true);
		break;*/

	case MENU:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/musica/intro.ogg", true);
		break;

	case NIVEL:
		/*printf_s("No entro");
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/musica/mundo1.ogg", true);*/
		if (aux == 2)
		{
			printf_s("No entro");
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/musica/mundo1.ogg", true);
		}
		if (aux1 == 2)	//CAMBIAR?? En algún punto hay que poner un nivel ++, quizás aquí es buena opción
		{
			printf_s("No entro2");
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/musica/mundo2.ogg", true);
		}
		if (aux2 == 2)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/musica/mundo3o4.ogg", true);
		}
		if (aux3 == 2)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/musica/mundo4o3.ogg", true);
		}
		if (aux4 == 2)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/musica/mundo5.ogg", true);
		}
		if (aux5 == 2)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/musica/mundo6.ogg", true);
		}
		if (aux6 == 2)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/musica/mundo7.ogg", true);
		}
		if (aux7 == 2)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/musica/mundo8.ogg", true);
		}
		if (aux8 == 2)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/musica/mundo9.ogg", true);
		}

		break;

	case VICTORIA:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/musica/victoria.ogg", true);
		break;

	case GAMEOVER:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/musica/derrota.ogg", true);
		break;

	case FIN:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/musica/victoria.ogg", true);
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
	if (estado == NIVEL) {       //El juego está en el estado nivel
		nivel.mueve();         //Se llama a la función mueve de espacio para controlar los distintos objetos que aparecen en pantalla
		if (nivel.vidasR.FinVida()) {
			estado=GAMEOVER;
		}
	}
}

#pragma once
#include "Nivel.h"
#include "freeglut.h""
#include "ETSIDI.h"

class Menu
{
	enum Estado //Se crea una enumeraci�n con los posibles estados que va a adoptar la m�quina de estados
	{
		START, MENU, CONTROLES, ESCOGE_PERSONAJE, HISTORIA, SUERTE, NIVEL, VICTORIA, GAMEOVER, FIN
	};
	Estado estado; //Se define una variable del tipo de la enumeraci�n anterior
	int guardanivel;
	float camara;
	Nivel nivel;
public:
	Menu();
	~Menu();
	void TeclaUp(unsigned char key);
	void Tecla(unsigned char key);
	void TeclaDown(unsigned char key);
	void TeclaEspecial(unsigned char key);
	void Mueve();
	void Dibuja();
	void Musica();
};
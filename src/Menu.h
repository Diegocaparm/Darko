#pragma once
#include "ETSIDI.h"

class Menu
{
	enum Estado //Se crea una enumeraci�n con los posibles estados que va a adoptar la m�quina de estados
	{
		START, MENU, CONTROLES, ESCOGE_PERSONAJE, HISTORIA, SUERTE, NIVEL1, VICTORIA, GAMEOVER, FIN
	};

	Estado estado; //Se define una variable del tipo de la enumeraci�n anterior

public:

	Menu();
	~Menu();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
	void Musica();
};
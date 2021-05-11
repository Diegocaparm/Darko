#include "Nivel1.h"

void Nivel1::dibuja()
{	//Creamos la cámara
	gluLookAt(hombre.posicion.x, y_ojo + 3, z_ojo,  // posicion del ojo
		hombre.posicion.x, 7.5f, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	//Dibuja la estructura del nivel
	caja.dibuja();
	plataforma1.dibuja();
	plataforma2.dibuja();
	plataforma3.dibuja();
	plataforma4.dibuja();
	plataforma5.dibuja();
	plataforma6.dibuja();
	plataforma7.dibuja();
	plataforma8.dibuja();
	plataforma9.dibuja();

	//Dibujamos lo animado
	hombre.dibuja();
	eneDisp1.dibuja();
	eneDisp2.dibuja();
	eneDisp3.dibuja();
	eneDisp4.dibuja();
	eneDisp5.dibuja();
	eneDisp6.dibuja();
	eneDisp7.dibuja();
	eneDisp8.dibuja();
	eneDisp9.dibuja();
	tank.dibuja();
}

void Nivel1::mueve()
{
	//Movimientos personaje y disparo
	hombre.mueve(0.025f);
	disparo.mueve(0.025f);
	//Movimiento de los enemigos
	eneDisp1.mueve(0.025f);
	eneDisp2.mueve(0.025f);
	eneDisp3.mueve(0.025f);
	eneDisp4.mueve(0.025f);
	eneDisp5.mueve(0.025f);
	eneDisp6.mueve(0.025f);
	eneDisp7.mueve(0.025f);
	eneDisp8.mueve(0.025f);
	eneDisp9.mueve(0.025f);
	tank.mueve(0.025f);

	//Interacciones personaje con el entorno
	Interaccion::rebote(hombre, caja);
	Interaccion::rebote(hombre, plataforma1);
	Interaccion::rebote(hombre, plataforma2);
	Interaccion::rebote(hombre, plataforma3);
	Interaccion::rebote(hombre, plataforma4);
	Interaccion::rebote(hombre, plataforma5);
	Interaccion::rebote(hombre, plataforma6);
	Interaccion::rebote(hombre, plataforma7);
	Interaccion::rebote(hombre, plataforma8);
	Interaccion::rebote(hombre, plataforma9);
	
	//Interacciones enemigos con el entorno
	Interaccion::rebote(eneDisp1, caja);
	Interaccion::rebote(eneDisp2, caja);
	Interaccion::rebote(eneDisp2, plataforma2);
	Interaccion::rebote(eneDisp3, caja);
	Interaccion::rebote(eneDisp3, plataforma3);
	Interaccion::rebote(eneDisp4, caja);
	Interaccion::rebote(eneDisp5, caja);
	Interaccion::rebote(eneDisp6, caja);
	Interaccion::rebote(eneDisp6, plataforma6);
	Interaccion::rebote(eneDisp7, caja);
	Interaccion::rebote(eneDisp8, caja);
	Interaccion::rebote(eneDisp9, caja);
	Interaccion::rebote(tank, caja);	
	Interaccion::rebote(tank, plataforma9);
}

void Nivel1::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	//bonus.setPos(5.0f, 5.0f);
	//disparo.setPos(-5.0f, 0.0f);
	//Creacion de las plataformas
	plataforma1.setPos(2.0f, 10.0f, -5.0f, 10.0f);
	plataforma1.setColor(50, 150, 250);
	plataforma2.setPos(17.0f, 5.0f, 8.0f, 5.0f);
	plataforma2.setColor(150, 150, 50);
	plataforma3.setPos(25.0f, 10.0f, 16.0f, 10.0f);
	plataforma3.setColor(50, 150, 250);
	plataforma4.setPos(38.0f, 5.0f, 27.0f, 5.0f);
	plataforma4.setColor(150, 150, 50);
	plataforma5.setPos(50.0f, 10.0f, 42.0f, 10.0f);
	plataforma5.setColor(50, 150, 250);
	plataforma6.setPos(63.0f, 5.0f, 58.0f, 5.0f);
	plataforma6.setColor(150, 150, 50);
	plataforma7.setPos(75.0f, 10.0f, 65.0f, 10.0f);
	plataforma7.setColor(50, 150, 250);
	plataforma8.setPos(85.0f, 5.0f, 78.0f, 5.0f);
	plataforma8.setColor(150, 150, 50);
	plataforma9.setPos(97.0f, 5.0f, 89.0f, 5.0f);
	plataforma9.setColor(150, 150, 50);
	//Creacion de los enemigos
	eneDisp1.setPos(5.0f, 5.0f);
	eneDisp2.setPos(15.0f, 6.0f);
	eneDisp3.setPos(22.0f, 11.0f);
	eneDisp4.setPos(45.0f, 5.0f);
	eneDisp5.setPos(57.0f, 2.0f);
	eneDisp6.setPos(62.0f, 6.0f);
	eneDisp7.setPos(74.0f, 5.0f);
	eneDisp8.setPos(81.0f, 2.0f);
	eneDisp9.setPos(93.0f, 1.0f);
	tank.setPos(93.0f, 15.0f);
}

void Nivel1::tecla(unsigned char key)
{
	if (key == ' ') {
		Interaccion::disparoInicializa(pdisparo, phombre);
		//eneDisp1.velocidad.x = 2;
	}
	//if (key == 'w') { //???????????
		//eneDisp1.posicion.y += 3;
		//eneDisp1.velocidad.y = 0.0f;
	//}
}

void Nivel1::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVelx(-7.50f);	//hombre.setVel(-5.0f,0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVelx(7.50f);
		break;
	case GLUT_KEY_UP:
		if (hombre.salto == 1)
			hombre.salto = 0;
		break;
	default:
		hombre.setVelx(0.0f);
		hombre.salto = 1;
		break;
	}
}
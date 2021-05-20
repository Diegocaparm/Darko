#include "Caja.h"
#include "freeglut.h"

Caja::Caja() {
	//Superficies por donde se camina
	suelo1.setColor(0, 100, 0);
	suelo1.setPos(50.0f, 0.0f, -30.0f, 0.0f);
	suelo2.setColor(0, 100, 0);
	suelo2.setPos(80.0f, 0.0f, 55.0f, 0.0f);
	suelo3.setColor(0, 100, 0);
	suelo3.setPos(132.0f, 0.0f, 87.0f, 0.0f);
	suelo4.setColor(0, 100, 0);
	suelo4.setPos(150.0f, 0.0f, 139.0f, 0.0f);
	suelo5.setColor(0, 100, 0);
	suelo5.setPos(200.0f, 0.0f, 156.0f, 0.0f);
	/*Pared* suelo1 = new Pared(50.0f, 0.0f, -30.0f, 0.0f, 0, 100, 0),
		* suelo2 = new Pared(80.0f, 0.0f, 55.0f, 0.0f, 0, 100, 0),
		* suelo3 = new Pared(132.0f, 0.0f, 87.0f, 0.0f, 0, 100, 0),
		* suelo4 = new Pared(150.0f, 0.0f, 139.0f, 0.0f, 0, 100, 0),
		* suelo5 = new Pared(200.0f, 0.0f, 156.0f, 0.0f, 0, 100, 0);
	plataformas.agregar(suelo1);	
	plataformas.agregar(suelo2);
	plataformas.agregar(suelo3);
	plataformas.agregar(suelo4);
	plataformas.agregar(suelo5);
		*/
	//repetir lo de arriba para cada pared y techo y esas cosas de abajo
	//imagino que tambien hay que agregarlo, quizas haya que subir el limite de plataformas

	//Resto de paredes de la caja inicial
	techo.setColor(0, 100, 0);
	techo.setPos(200.0f, 20.0f, -30.0f, 20.0f);
	pared_dcha.setColor(0, 250, 0);
	pared_dcha.setPos(200.0f, 20.0f, 200.0f, 0.0f);
	pared_izq.setColor(0, 250, 0);
	pared_izq.setPos(-10.0f, 0.005f, -10.0f, 0.0f);

	//Paredes de los pozos
	pozo1_izq.setColor(0, 250, 0);
	pozo1_izq.setPos(50.0f, 0.0f, 50.0f, -25.0f);
	pozo1_dcha.setColor(0, 250, 0);
	pozo1_dcha.setPos(55.0f, 0.0f, 55.0f, -25.0f);
	pozo2_izq.setColor(0, 250, 0);
	pozo2_izq.setPos(80.0f, 0.0f, 80.0f, -25.0f);
	pozo2_dcha.setColor(0, 250, 0);
	pozo2_dcha.setPos(87.0f, 0.0f, 87.0f, -25.0f);
	pozo3_izq.setColor(0, 250, 0);
	pozo3_izq.setPos(132.0f, 0.0f, 132.0f, -25.0f);
	pozo3_dcha.setColor(0, 250, 0);
	pozo3_dcha.setPos(139.0f, 0.0f, 139.0f, -25.0f);
	pozo4_izq.setColor(0, 250, 0);
	pozo4_izq.setPos(150.0f, 0.0f, 150.0f, -25.0f);
	pozo4_dcha.setColor(0, 250, 0);
	pozo4_dcha.setPos(156.0f, 0.0f, 156.0f, -25.0f);
}

void Caja::dibuja()
{
	//Superficies por donde se camina
	suelo1.dibuja();
	suelo2.dibuja();
	suelo3.dibuja();
	suelo4.dibuja();
	suelo5.dibuja();
	//Resto de paredes de la caja inicial
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
	//Paredes de los pozos
	pozo1_izq.dibuja();
	pozo1_dcha.dibuja();
	pozo2_izq.dibuja();
	pozo2_dcha.dibuja();
	pozo3_izq.dibuja();
	pozo3_dcha.dibuja();
	pozo4_izq.dibuja();
	pozo4_dcha.dibuja();
}

void Caja::Inicializa() {
}
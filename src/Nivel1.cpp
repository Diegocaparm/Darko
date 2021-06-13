#include "Nivel1.h"

void Nivel1::dibuja()
{	//Creamos la cámara
	gluLookAt(hombre.posicion.x, 11.5, z_ojo,  // posicion del ojo  
		hombre.posicion.x, 7.5f, 0.0,      // hacia que punto mira  (hombre.posicion.y + 8)
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//Dibuja la estructura del nivel
	caja.dibuja();
	plataformas.dibuja();
	listPinchos.dibuja();
	//listBonus.dibuja();
	
	//Dibuja Vida y Monedas
	vidas.dibuja();			//Vidas del entorno
	vidasR.dibuja();		//Vidas Recogidas
	dineros.dibuja();		//Monedas del entorno
	dinerosR.dibuja();		//Debajo de Vidas Recogidas, el simbolo de moneda
	Vector2D pos = hombre.getPos(); //Hay que desimplementar la union dibuja-logica todavia
	dinerosR.dibujaContador(pos.x);	//Debajo de Vidas Recogidas, el numero de monedas

	//Dibujamos lo animado
	hombre.dibuja();
	enemigosDisp.dibuja();
	Tanks.dibuja();
	babosas.dibuja();			
	//tentaculos.dibuja();
	//bombers.dibuja();

	disparos.dibuja();
	dispAmig.dibuja();
	espada.dibuja();
}

void Nivel1::mueve()
{
	//Movimientos personaje y disparo
	hombre.mueve(0.025f);
	dispAmig.mueve(0.025f);
	espada.mueve(0.025f);
	Interaccion::mov(espada, hombre);

	//Movimiento de los enemigos
	enemigosDisp.mueve(0.025f);
	Tanks.mueve(0.025f);
	babosas.mueve(0.025f);
	//tentaculos.mueve(0.025f);
	//bombers.mueve(0.025f);
	disparos.mueve(0.025f);

	//Movimiento vidas y monedas
	vidas.mueve(0.025f);
	Vector2D pos=hombre.getPos();
	vidasR.mueve(0.025f,pos.x);
	dineros.mueve(0.025f);
	dinerosR.mueve(0.025f, pos.x);

	//Interacciones personaje con el entorno
	Interaccion::rebote(hombre, caja);
	Interaccion::rebote(hombre, plataformas);
	//listBonus.rebote(hombre);
	listPinchos.rebote(hombre);

	//Interacciones enemigos con el entorno
	enemigosDisp.rebote(caja);
	enemigosDisp.rebote(plataformas);
	Tanks.rebote(caja);	
	Tanks.rebote(plataformas);
	//bombers.rebote(caja);
	//bombers.rebote(plataformas);
	
	//Interacciones disparo con el entorno
	disparos.rebote(caja);
	disparos.rebote(plataformas);
	dispAmig.rebote(caja);
	dispAmig.rebote(plataformas);

	//Interacciones disparoEnemigo con hombre
	disparos.rebote(hombre);

	//Interacciones disparoAmigo con enemigos
	Interaccion::colision(enemigosDisp, dispAmig);
	Interaccion::colision(Tanks, dispAmig);
	Interaccion::colision(babosas, dispAmig);
	//Interaccion::colision(tentaculos, dispAmig);
	//Interaccion::colision(bombers, dispAmig);
	if (espada.getFlag()) {
		Interaccion::colision(enemigosDisp, espada);
		Interaccion::colision(Tanks, espada);
		Interaccion::colision(babosas, espada);
		//Interaccion::colision(tentaculos, espada);
		//Interaccion::colision(bombers, espada);
	}

	//Interaccion Pj con enemigo
	Interaccion::rebote(hombre, enemigosDisp,vidasR);
	//Interaccion::rebote(hombre, eneDisp1);
	//Interaccion::rebote(hombre, eneDisp2);
	//Interaccion::mov(babosas, hombre);
	babosas.mov(hombre);
	//bombers.rebote(hombre);
	 
	//Interaccion Pj con Vida y Monedas
	//Elimina Vida recogida
	Corazon* aux_c = vidas.colision(hombre);
	if (aux_c != 0) {				//si alguna Vida ha chocado
		vidas.eliminar(aux_c);
		vidasR.agregar(new Corazon());
	}
	//Elimina Monedas recogidas
	Moneda* aux_m = dineros.colision(hombre);
	if (aux_m != 0) {				//si alguna Moneda ha chocado
		dineros.eliminar(aux_m);
		dinerosR.aumentaDinero();
	}
}

void Nivel1::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	//Posicionamos el suelo y las paredes de los pozos
	Pared* suelo1 = new Pared(50.0f, 0.0f, -30.0f, 0.0f, 0, 100, 0),
		* suelo2 = new Pared(80.0f, 0.0f, 55.0f, 0.0f, 0, 100, 0),
		* suelo3 = new Pared(132.0f, 0.0f, 87.0f, 0.0f, 0, 100, 0),
		* suelo4 = new Pared(150.0f, 0.0f, 139.0f, 0.0f, 0, 100, 0),
		* suelo5 = new Pared(200.0f, 0.0f, 156.0f, 0.0f, 0, 100, 0),
		/*
		* pozo1_i = new Pared(50.0f, 0.0f, 50.0f, -10.0f, 0, 250, 0),
		* pozo1_d = new Pared(55.0f, 0.0f, 55.0f, -10.0f, 0, 250, 0),
		* pozo2_i = new Pared(80.0f, 0.0f, 80.0f, -10.0f, 0, 250, 0),
		* pozo2_d = new Pared(87.0f, 0.0f, 87.0f, -10.0f, 0, 250, 0), 
		* pozo3_i = new Pared(132.0f, 0.0f, 132.0f, -10.0f, 0, 250, 0),
		* pozo3_d = new Pared(139.0f, 0.0f, 139.0f, -10.0f, 0, 250, 0), 
		* pozo4_i = new Pared(150.0f, 0.0f, 150.0f, -10.0f, 0, 250, 0),
		* pozo4_d = new Pared(156.0f, 0.0f, 156.0f, -10.0f, 0, 250, 0), 
		*/
		//Posicionamos también las plataformas aéreas
		* plat1 = new Pared(2.0f, 10.0f, -5.0f, 10.0f, 50, 150, 250),
		* plat1_2 = new Pared(16.0f, 2.50f, 11.0f, 2.50f, 150, 150, 50), //plat añadida entre 1 y 2- sino no llega salto
		* plat2 = new Pared(27.0f, 5.0f, 18.0f, 5.0f, 150, 150, 50),
		* plat2_3 = new Pared(35.0f, 7.50f, 30.0f, 7.50f, 150, 150, 50), //plat añadida entre 2 y 3- sino no llega salto
		* plat3 = new Pared(45.0f, 10.0f, 36.0f, 10.0f, 50, 150, 250),
		* plat4 = new Pared(68.0f, 5.0f, 57.0f, 5.0f, 150, 150, 50),
		* plat5 = new Pared(90.0f, 8.0f, 70.0f, 8.0f, 50, 150, 250), //movida a la izq
		* plat5_6 = new Pared(102.0f, 7.50f, 98.0f, 7.50f, 150, 150, 50), //plat añadida entre 5 y 6- sino no llega salto
		* plat6 = new Pared(118.0f, 5.0f, 104.0f, 5.0f, 150, 150, 50), //movida a la izq
		* plat6_7 = new Pared(130.0f, 7.50f, 124.0f, 7.50f, 150, 150, 50), //plat añadida entre 6 y 7- sino no llega salto
		* plat7 = new Pared(145.0f, 10.0f, 135.0f, 10.0f, 50, 150, 250),
		* plat7_8 = new Pared(155.0f, 7.50f, 150.0f, 7.50f, 150, 150, 50), //plat añadida entre 7 y 8- sino no llega salto
		* plat8 = new Pared(175.0f, 5.0f, 158.0f, 5.0f, 150, 150, 50),
		* plat9 = new Pared(197.0f, 5.0f, 182.0f, 5.0f, 150, 150, 50); // alargamos para meterle una puerta y que pase de nivel?

	plataformas.agregar(plat1);
	plataformas.agregar(plat1_2);
	plataformas.agregar(plat2);
	plataformas.agregar(plat2_3);
	plataformas.agregar(plat3);
	plataformas.agregar(plat4);
	plataformas.agregar(plat5);
	plataformas.agregar(plat5_6);
	plataformas.agregar(plat6);
	plataformas.agregar(plat6_7);
	plataformas.agregar(plat7);
	plataformas.agregar(plat7_8);
	plataformas.agregar(plat8);
	plataformas.agregar(plat9);
	plataformas.agregar(suelo1);
	plataformas.agregar(suelo2);
	plataformas.agregar(suelo3);
	plataformas.agregar(suelo4);
	plataformas.agregar(suelo5);

	Pincho* pincho1 = new Pincho(25.0f, 0.0f),
		* pincho2 = new Pincho(40.0f, 10.0f),	//pincho en plataforma3
		* pincho3 = new Pincho(69.0f, 0.0f),
		* pincho4 = new Pincho(78.0f, 0.0f),	
		* pincho5 = new Pincho(108.0f, 5.0f), //en plat 6
		* pincho6 = new Pincho(115.0f, 5.0f), //en plat 6
		* pincho7 = new Pincho(148.0f, 0.0f),
		* pincho8 = new Pincho(165.0f, 5.0f); //pincho en plat 8
	listPinchos.agregar(pincho1);
	listPinchos.agregar(pincho2);
	listPinchos.agregar(pincho3);
	listPinchos.agregar(pincho4);
	listPinchos.agregar(pincho5);
	listPinchos.agregar(pincho6);
	listPinchos.agregar(pincho7);
	listPinchos.agregar(pincho8);

	/*Bonus* bonus1 = new Bonus(7.0f, 7.0f),
		* bonus2 = new Bonus(30.0f, 5.0f),
		* bonus3 = new Bonus(73.0f, 5.0f),
		* bonus4 = new Bonus(178.0f, 5.0f);
	listBonus.agregar(bonus1);
	listBonus.agregar(bonus2);
	listBonus.agregar(bonus3);
	listBonus.agregar(bonus4);*/


	//Creacion de los enemigos
	EnemigoDisp* ped1 = new EnemigoDisp(0.0f, 0.0f), //Enemigo plat1
		* ped2 = new EnemigoDisp(15.0f, 0.0f),
		* ped3 = new EnemigoDisp(22.0f, 0.0f),
		* ped4 = new EnemigoDisp(35.0f, 0.0f),
		* ped5 = new EnemigoDisp(62.0f, 7.0f), //Enemigo plat4
		* ped6 = new EnemigoDisp(87.0f, 0.0f),
		* ped7 = new EnemigoDisp(95.0f, 0.0f),
		* ped8 = new EnemigoDisp(120.0f, 0.0f),
		* ped9 = new EnemigoDisp(130.0f, 0.0f),
		* ped10 = new EnemigoDisp(174.0f, 0.0f),
		* ped11 = new EnemigoDisp(140.0f, 11.0f), //Enemigo plat7
		* ped12 = new EnemigoDisp(193.0f, 0.0f);
	Tank* Tank1 = new Tank(193.0f, 15.0f);
	Babosa* babosa1 = new Babosa(10.0f, 13.0f);
		//* babosa2 = new Babosa(-8.0f, 2.0f);
	//Tentaculo* tentaculo1 = new Tentaculo(10.0f, 0.0f);
	//bomber* bomber1 = new bomber(10.0f, 10.0f);

	//meter enemigos en sus listas
	enemigosDisp.agregar(ped1);
	enemigosDisp.agregar(ped2);
	enemigosDisp.agregar(ped3);
	enemigosDisp.agregar(ped4);
	enemigosDisp.agregar(ped5);
	enemigosDisp.agregar(ped6);
	enemigosDisp.agregar(ped7);
	enemigosDisp.agregar(ped8);
	enemigosDisp.agregar(ped9);
	enemigosDisp.agregar(ped10);
	enemigosDisp.agregar(ped11);
	enemigosDisp.agregar(ped12);
	Tanks.agregar(Tank1);
	babosas.agregar(babosa1);
	//babosas.agregar(babosa2);
	//tentaculos.agregar(tentaculo1);
	//bombers.agregar(bomber1);

	//meter disparos en lista
	disparos.agregar(ped1->dispEnem1);
	disparos.agregar(ped2->dispEnem1);
	disparos.agregar(ped3->dispEnem1);
	disparos.agregar(ped4->dispEnem1);
	disparos.agregar(ped5->dispEnem1);
	disparos.agregar(ped6->dispEnem1);
	disparos.agregar(ped7->dispEnem1);
	disparos.agregar(ped8->dispEnem1);
	disparos.agregar(ped9->dispEnem1);

	disparos.agregar(Tank1->dispTank1);
	disparos.agregar(Tank1->dispTank2);
	disparos.agregar(Tank1->dispTank3);
	disparos.agregar(Tank1->dispTank4);
	disparos.agregar(Tank1->dispTank5);

	//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
	vidas.agregar(new Corazon(32.5f, 8.0f)); //La vida a la que invita la casa
	vidas.agregar(new Corazon(111.5f, 5.5f)); //Vida entre los dos pinchos
	vidas.agregar(new Corazon(178.0f, 5.0f)); //Vida antes del jefe final

	//Creaccion de las Vidas del Pj
	for (int i = 0; i < vidasR.getVidas(); i++) 
		vidasR.agregar(new Corazon());
	
	//Creaccion de Monedas Recolectables
	dineros.agregar(new Moneda(19.0f, 5.5f));
	dineros.agregar(new Moneda(21.0f, 5.5f));
	dineros.agregar(new Moneda(23.0f, 5.5f));
	dineros.agregar(new Moneda(25.0f, 5.5f));

	dineros.agregar(new Moneda(36.0f, 0.5f));
	dineros.agregar(new Moneda(38.0f, 0.5f));
	dineros.agregar(new Moneda(40.0f, 0.5f));
	dineros.agregar(new Moneda(42.0f, 0.5f));
	dineros.agregar(new Moneda(44.0f, 0.5f));

	dineros.agregar(new Moneda(48.5f, 0.5f));
	dineros.agregar(new Moneda(50.5f, 1.75f));
	dineros.agregar(new Moneda(52.5f, 3.0f));
	dineros.agregar(new Moneda(54.5f, 1.75f));
	dineros.agregar(new Moneda(56.5f, 0.5f));

	dineros.agregar(new Moneda(72.0f, 8.5f));
	dineros.agregar(new Moneda(74.0f, 8.5f));
	dineros.agregar(new Moneda(76.0f, 8.5f));
	dineros.agregar(new Moneda(78.0f, 8.5f));
	dineros.agregar(new Moneda(80.0f, 8.5f));
	dineros.agregar(new Moneda(82.0f, 8.5f));
	dineros.agregar(new Moneda(84.0f, 8.5f));
	dineros.agregar(new Moneda(86.0f, 8.5f));
	dineros.agregar(new Moneda(88.0f, 8.5f));

	dineros.agregar(new Moneda(125.0f, 8.0f));
	dineros.agregar(new Moneda(127.0f, 8.0f));
	dineros.agregar(new Moneda(129.0f, 8.0f));

	dineros.agregar(new Moneda(150.5f, 8.0f));
	dineros.agregar(new Moneda(152.5f, 8.0f));
	dineros.agregar(new Moneda(154.5f, 8.0f));
	//Creaccion de Monedas del Pj
	dinerosR.agregar(new Moneda(8.0f,14.0f));
}

void Nivel1::teclaUp(unsigned char key)
{
	switch (key)
	{
	case 'a':
		//hombre.setVelx(0.0f);	//hombre.setVel(-5.0f,0.0f);
		hombre.flagH = 0;
		break;
	case 'd':
		//hombre.setVelx(0.0f);
		hombre.flagH = 0;
		break;
	case 'w':
		hombre.flag = 0;
		break;
	case ' ':
		break;
	default:
		//hombre.setVelx(0.0f);
		hombre.salto = 1;
		break;
	}
}

void Nivel1::teclaDown(unsigned char key)
{
	switch (key)
	{
	case 'a':
		//hombre.setVelx(-7.50f);	//hombre.setVel(-5.0f,0.0f);
		hombre.flagH = -1;
		break;
	case 'd':
		//hombre.setVelx(7.50f);
		hombre.flagH = 1;
		break;
	case 'w':
		hombre.flag = 1;
		break;
	case 'q':
		//cosas de espada
		espada.setFlag(1);
		break;
	case ' ':
		disparosAmigos * dispam = new disparosAmigos(hombre.posicion.x, hombre.posicion.y + hombre.altura * 2 / 3, hombre.velocidad.x, 0);
		if (dispAmig.agregar(dispam))
			hombre.setVelx(0);
		else delete dispam;
		break;
	/*default:
		hombre.setVelx(0.0f);
		hombre.salto = 1;
		break;*/
	}	
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
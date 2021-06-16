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
	listaFuego.dibuja();

	//Dibuja Vida y Monedas
	vidas.dibuja();			//Vidas del entorno
	vidasR.dibuja();		//Vidas Recogidas
	dineros.dibuja();		//Monedas del entorno
	dinerosR.dibuja();		//Debajo de Vidas Recogidas, el simbolo de moneda
	dinerosR.dibujaContador();	//Debajo de Vidas Recogidas, el numero de monedas

	//Dibujamos lo animado
	hombre.dibuja();
	enemigosDisp.dibuja();
	Tanks.dibuja();
	babosas.dibuja();			
	tentaculos.dibuja();
	bombers.dibuja();
	disparos.dibuja();
	dispAmig.dibuja();
	espada.dibuja();
	boss.dibuja();
	misiles.dibuja();
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
	tentaculos.mueve(0.025f);
	bombers.mueve(0.025f);
	disparos.mueve(0.025f);
	listaFuego.mueve(0.025f);
	boss.mueve(0.025f);
	misiles.mueve(0.025f);

	//Movimiento vidas y monedas
	vidas.mueve(0.025f);
	Vector2D pos=hombre.getPos();
	vidasR.mueve(0.025f,pos.x);
	dineros.mueve(0.025f);
	dinerosR.mueve(0.025f, pos);
	plataformas.mueve(0.025);

	//Interacciones personaje con el entorno
	Interaccion::rebote(hombre, caja);
	Interaccion::rebote(hombre, plataformas);

	listPinchos.rebote(hombre);
	listaFuego.rebote(hombre);

	//Interacciones enemigos con el entorno
	enemigosDisp.rebote(caja);
	enemigosDisp.rebote(plataformas);
	Tanks.rebote(caja);	
	Tanks.rebote(plataformas);
	bombers.rebote(caja);
	bombers.rebote(plataformas);
	Interaccion::rebote(boss, plataformas);
	
	//Interacciones disparo con el entorno
	disparos.rebote(caja);
	disparos.rebote(plataformas);
	dispAmig.rebote(caja);
	dispAmig.rebote(plataformas);

	//Interacciones disparoEnemigo con hombre
	disparos.rebote(hombre);
	misiles.rebote(hombre);

	//Interacciones disparoAmigo con enemigos
	Interaccion::colision(enemigosDisp, dispAmig);
	Interaccion::colision(Tanks, dispAmig);
	Interaccion::colision(babosas, dispAmig);
	Interaccion::colision(tentaculos, dispAmig);
	Interaccion::colision(bombers, dispAmig);
	Interaccion::colision(boss, dispAmig);
	if (espada.getFlag()) {
		Interaccion::colision(enemigosDisp, espada);
		Interaccion::colision(Tanks, espada);
		Interaccion::colision(babosas, espada);
		Interaccion::colision(tentaculos, espada);
		Interaccion::colision(bombers, espada);
		Interaccion::colision(boss, espada);
	}

	//Interaccion Pj con enemigo
	Interaccion::rebote(hombre, enemigosDisp,vidasR);
	babosas.mov(hombre);
	bombers.rebote(hombre);
	tentaculos.colision(hombre);
	 
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

	nivel = 5;
	cargarnivel();
}

bool Nivel1::cargarnivel()
{
	if (nivel == 1)
	{
		//Agregamos los suelos
		plataformas.agregar(new Pared(50.0f, 0.0f, -30.0f, 0.0f, 0, 100, 0));
		plataformas.agregar(new Pared(80.0f, 0.0f, 55.0f, 0.0f, 0, 100, 0));
		plataformas.agregar(new Pared(132.0f, 0.0f, 87.0f, 0.0f, 0, 100, 0));
		plataformas.agregar(new Pared(150.0f, 0.0f, 139.0f, 0.0f, 0, 100, 0));
		plataformas.agregar(new Pared(200.0f, 0.0f, 156.0f, 0.0f, 0, 100, 0));
		//Agregamos las paredes de los pozos
		plataformas.agregar(new Pared(50.0f, 0.0f, 50.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(55.0f, 0.0f, 55.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(80.0f, 0.0f, 80.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(87.0f, 0.0f, 87.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(132.0f, 0.0f, 132.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(139.0f, 0.0f, 139.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(150.0f, 0.0f, 150.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(156.0f, 0.0f, 156.0f, -10.0f, 0, 250, 0));
		//Agregamos las plataformas aéreas
		plataformas.agregar(new Pared(2.0f, 10.0f, -5.0f, 10.0f, 50, 150, 250));
		plataformas.agregar(new Pared(16.0f, 2.50f, 11.0f, 2.50f, 150, 150, 50));
		plataformas.agregar(new Pared(27.0f, 5.0f, 18.0f, 5.0f, 150, 150, 50));
		plataformas.agregar(new Pared(35.0f, 7.50f, 30.0f, 7.50f, 150, 150, 50));
		plataformas.agregar(new Pared(45.0f, 10.0f, 36.0f, 10.0f, 50, 150, 250));
		plataformas.agregar(new Pared(68.0f, 5.0f, 57.0f, 5.0f, 150, 150, 50));
		plataformas.agregar(new Pared(90.0f, 8.0f, 70.0f, 8.0f, 50, 150, 250));
		plataformas.agregar(new Pared(102.0f, 7.50f, 98.0f, 7.50f, 150, 150, 50));
		plataformas.agregar(new Pared(118.0f, 5.0f, 104.0f, 5.0f, 150, 150, 50));
		plataformas.agregar(new Pared(130.0f, 7.50f, 124.0f, 7.50f, 150, 150, 50));
		plataformas.agregar(new Pared(145.0f, 10.0f, 135.0f, 10.0f, 50, 150, 250));
		plataformas.agregar(new Pared(155.0f, 7.50f, 150.0f, 7.50f, 150, 150, 50));
		plataformas.agregar(new Pared(175.0f, 5.0f, 158.0f, 5.0f, 150, 150, 50));
		plataformas.agregar(new Pared(197.0f, 5.0f, 182.0f, 5.0f, 150, 150, 50));
		//Agregamos los pinchos
		listPinchos.agregar(new Pincho(25.0f, 0.0f));
		listPinchos.agregar(new Pincho(40.0f, 10.0f)); //Pincho en plat3
		listPinchos.agregar(new Pincho(69.0f, 0.0f));
		listPinchos.agregar(new Pincho(78.0f, 0.0f));
		listPinchos.agregar(new Pincho(108.0f, 5.0f)); //Pincho en plat6
		listPinchos.agregar(new Pincho(115.0f, 5.0f)); //Pincho en plat6
		listPinchos.agregar(new Pincho(148.0f, 0.0f));
		listPinchos.agregar(new Pincho(165.0f, 5.0f)); //Pincho en plat8

		//Creacion de los enemigos
		EnemigoDisp*ped1 = new EnemigoDisp(0.0f, 0.0f), //Enemigo plat1
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
		babosas.agregar(new Babosa(10.0f, 13.0f));
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
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 2)
	{
		//Agregamos el suelo
		plataformas.agregar(new Pared(37.0f, 0.0f, -10.0f, 0.0f, 50, 150, 250));
		plataformas.agregar(new Pared(125.0f, 0.0f, 112.0f, 0.0f, 50, 150, 250));
		plataformas.agregar(new Pared(135.0f, 0.0f, 130.0f, 0.0f, 50, 150, 250));
		plataformas.agregar(new Pared(167.0f, 0.0f, 147.0f, 0.0f, 50, 150, 250));
		plataformas.agregar(new Pared(186.0f, 0.0f, 172.0f, 0.0f, 50, 150, 250)); //suelo entre plataformas para meter monedas
		plataformas.agregar(new Pared(200.0f, 0.0f, 190.0f, 0.0f, 50, 150, 250));
		//Agregamos las paredes de los pozos
		plataformas.agregar(new Pared(37.0f, 0.0f, 37.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(112.0f, 0.0f, 112.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(125.0f, 0.0f, 125.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(130.0f, 0.0f, 130.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(135.0f, 0.0f, 135.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(147.0f, 0.0f, 147.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(167.0f, 0.0f, 167.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(172.0f, 0.0f, 172.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(186.0f, 0.0f, 186.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(190.0f, 0.0f, 190.0f, -10.0f, 0, 250, 0));
		//Agregamos las plataformas aéreas
		plataformas.agregar(new Pared(40.0f, 2.5f, 37.0f, 2.5f, 50, 150, 250));//plat entre medias
		plataformas.agregar(new Pared(45.0f, 5.0f, 41.0f, 5.0f, 50, 150, 250));
		plataformas.agregar(new Pared(63.0f, 5.0f, 48.0f, 5.0f, 50, 150, 250));
		plataformas.agregar(new Pared(69.0f, 7.0f, 65.0f, 7.0f, 50, 150, 250));
		plataformas.agregar(new Pared(75.0f, 9.0f, 71.0f, 9.0f, 50, 150, 250));
		plataformas.agregar(new Pared(82.0f, 10.5f, 78.0f, 10.50f, 50, 150, 250));//la siguiente plat es movil
		plataformas.agregar(new PlatMovil(86.0f, 8.0f, 92.0f, 8.0f, 3.0f, 0.0f, 86.0f, 8.0f, 120.0f, 8.0f, 50, 150, 250));//Plataforma móvil
		plataformas.agregar(new Pared(145.0f, 2.50f, 137.0f, 2.50f, 50, 150, 250));
		plataformas.agregar(new Pared(175.0f, 2.5f, 167.5f, 2.5f, 150, 150, 250));
		plataformas.agregar(new Pared(183.0f, 6.0f, 177.0f, 6.0f, 50, 150, 250));//plat movil en esta posicion
		plataformas.agregar(new Pared(190.0f, 7.5f, 185.0f, 7.50f, 50, 150, 250));
		plataformas.agregar(new Pared(200.0f, 12.0f, 197.0f, 12.0f, 250, 150, 250));
		plataformas.agregar(new Pared(200.0f, 10.0f, 197.0f, 10.0f, 250, 150, 250));
		plataformas.agregar(new Pared(200.0f, 8.0f, 197.0f, 8.0f, 250, 150, 250));
		plataformas.agregar(new Pared(200.0f, 2.0f, 197.0f, 2.0f, 250, 150, 250));
		//Agregamos los pinchos
		listPinchos.agregar(new Pincho(25.0f, 0.0f));//suelo1
		listPinchos.agregar(new Pincho(162.0f, 0.0f));//suelo4
		listPinchos.agregar(new Pincho(180.0f, 0.0f));//suelo5
		//Agregamos las bolas de fuego 
		listaFuego.agregar(new BolaFuego(87.0f, 0.0f, 16.0f, -5.0f));
		listaFuego.agregar(new BolaFuego(99.0f, -2.0f, 16.0f, -5.0f));
		listaFuego.agregar(new BolaFuego(110.0f, -4.0f, 16.0f, -5.0f));

		//Creacion de los enemigos
		tentaculos.agregar(new Tentaculo(192.0f, 0.0f));
		EnemigoDisp* ped1 = new EnemigoDisp(0.0f, 9.0f), //Enemigo en plat movil xd
			* ped2 = new EnemigoDisp(10.0f, 0.0f), //suelo1
			* ped3 = new EnemigoDisp(23.0f, 0.0f), //suelo1
			* ped4 = new EnemigoDisp(55.0f, 0.0f), //suelo1
			* ped5 = new EnemigoDisp(73.0f, 9.0f), //p5
			* ped6 = new EnemigoDisp(80.0f, 10.5f), //p6
			* ped7 = new EnemigoDisp(117.0f, 0.0f),  //Suelo2
			* ped8 = new EnemigoDisp(120.0f, 0.0f), //Suelo2
			* ped9 = new EnemigoDisp(132.0f, 0.0f), //suelo3
			* ped10 = new EnemigoDisp(140.0f, 2.5f), //p7
			* ped11 = new EnemigoDisp(172.0f, 2.5f), //p8
			* ped12 = new EnemigoDisp(178.0f, 0.0f),  // suelo intermedio
			* ped14 = new EnemigoDisp(198.0f, 12.5f), //Enemigos de apoyo al tentaculo
			* ped15 = new EnemigoDisp(199.0f, 10.5f), 
			* ped16 = new EnemigoDisp(198.0f, 8.5f); 
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
		enemigosDisp.agregar(ped14);
		enemigosDisp.agregar(ped15);
		enemigosDisp.agregar(ped16);
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
		disparos.agregar(ped10->dispEnem1);
		disparos.agregar(ped11->dispEnem1);
		disparos.agregar(ped12->dispEnem1);
		disparos.agregar(ped14->dispEnem1);
		disparos.agregar(ped15->dispEnem1);
		disparos.agregar(ped16->dispEnem1);

		//Agregamos las vidas recolectables
		vidas.agregar(new Corazon(67.0f, 7.5f)); //plat 4
		vidas.agregar(new Corazon(117.5f, 0.5f)); //suelo 2
		vidas.agregar(new Corazon(170.0f, 2.5f)); //plat 8

		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidas(); i++)
			vidasR.agregar(new Corazon());

		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(19.0f, 0.0f));//suelo1
		dineros.agregar(new Moneda(21.0f, 0.0f));
		dineros.agregar(new Moneda(23.0f, 0.0f));
		dineros.agregar(new Moneda(25.0f, 4.0f));
		dineros.agregar(new Moneda(36.0f, 0.0f));

		dineros.agregar(new Moneda(39.0f, 2.5f)); //plat1

		dineros.agregar(new Moneda(43.0f, 5.0f));//plat2

		dineros.agregar(new Moneda(54.0f, 5.0f)); //plat3
		dineros.agregar(new Moneda(56.0f, 5.0f));
		dineros.agregar(new Moneda(58.0f, 5.0f));
		dineros.agregar(new Moneda(60.0f, 5.0f));
		dineros.agregar(new Moneda(62.0f, 5.0f));
		//en plat movil tambien ponemos alguna moneda

		dineros.agregar(new Moneda(115.5f, 0.0f));//suelo2
		dineros.agregar(new Moneda(117.5f, 0.0f));
		dineros.agregar(new Moneda(119.5f, 0.0f));
		dineros.agregar(new Moneda(121.5f, 0.0f));
		dineros.agregar(new Moneda(123.5f, 0.0f));

		dineros.agregar(new Moneda(132.0f, 0.0f));//suelo3
		dineros.agregar(new Moneda(133.0f, 0.0f));

		dineros.agregar(new Moneda(139.0f, 2.50f));//plat7
		dineros.agregar(new Moneda(143.0f, 2.50f));

		dineros.agregar(new Moneda(152.0f, 0.0f));//suelo4
		dineros.agregar(new Moneda(154.0f, 0.0f));
		dineros.agregar(new Moneda(156.0f, 0.0f));
		dineros.agregar(new Moneda(158.0f, 0.0f));
		dineros.agregar(new Moneda(160.0f, 0.0f));

		dineros.agregar(new Moneda(179.0f, 9.0f));//plat9

		dineros.agregar(new Moneda(175.0f, 0.0f));//suelo5
		dineros.agregar(new Moneda(177.0f, 0.0f));
		dineros.agregar(new Moneda(179.0f, 4.0f));
		dineros.agregar(new Moneda(181.0f, 4.0f));
		dineros.agregar(new Moneda(183.0f, 0.0f));
		dineros.agregar(new Moneda(185.0f, 0.0f));

		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 3)
	{
		//Agregamos los suelos 
		plataformas.agregar(new Pared(10.0f, 0.0f, -10.0f, 0.0f, 50, 150, 250)); //suelo1
		plataformas.agregar(new Pared(20.0f, 0.0f, 14.0f, 0.0f, 50, 150, 250));  //suelo2
		plataformas.agregar(new Pared(30.0f, 0.0f, 24.0f, 0.0f, 50, 150, 250));  //suelo3
		plataformas.agregar(new Pared(39.0f, 0.0f, 34.0f, 0.0f, 50, 150, 250));  //suelo4
		plataformas.agregar(new Pared(62.0f, 0.0f, 42.0f, 0.0f, 50, 150, 250));  //suelo5
		plataformas.agregar(new Pared(101.0f, 0.0f, 94.0f, 0.0f, 50, 150, 250));  //suelo6
		plataformas.agregar(new Pared(140.0f, 5.0f, 123.0f, 5.0f, 50, 150, 250));  //suelo7_1
		plataformas.agregar(new Pared(140.0f, 5.0f, 140.0f, -1.0f, 50, 150, 250)); //suelo7_2 vertical
		plataformas.agregar(new Pared(162.0f, 0.0f, 140.0f, 0.0f, 50, 150, 250));  //suelo7_3
		//Agregamos las paredes de los pozos
		plataformas.agregar(new Pared(10.0f, 0.0f, 10.0f, -10.0f, 0, 250, 0)); //pozo 1_i
		plataformas.agregar(new Pared(14.0f, 0.0f, 14.0f, -10.0f, 0, 250, 0));  //pozo 2_i
		plataformas.agregar(new Pared(20.0f, 0.0f, 20.0f, -10.0f, 0, 250, 0));  //pozo 2_d
		plataformas.agregar(new Pared(24.0f, 0.0f, 24.0f, -10.0f, 0, 250, 0));  //pozo 3_i
		plataformas.agregar(new Pared(30.0f, 0.0f, 30.0f, -10.0f, 0, 250, 0));  //pozo 3_d
		plataformas.agregar(new Pared(34.0f, 0.0f, 34.0f, -10.0f, 0, 250, 0));  //pozo 4_i
		plataformas.agregar(new Pared(39.0f, 0.0f, 39.0f, -10.0f, 0, 250, 0));  //pozo 4_d
		plataformas.agregar(new Pared(42.0f, 0.0f, 42.0f, -10.0f, 0, 250, 0)); // pozo 5_i
		plataformas.agregar(new Pared(62.0f, 0.0f, 62.0f, -10.0f, 0, 250, 0)); // pozo 5_d
		plataformas.agregar(new Pared(94.0f, 0.0f, 94.0f, -10.0f, 0, 250, 0));  //pozo 6_i
		plataformas.agregar(new Pared(101.0f, 0.0f, 101.0f, -10.0f, 0, 250, 0));  //pozo 6_d
		plataformas.agregar(new Pared(123.0f, 5.0f, 123.0f, -10.0f, 0, 250, 0)); //pozo 7_i
		plataformas.agregar(new Pared(162.0f, 0.0f, 162.0f, -10.0f, 0, 250, 0));  //pozo 7_d
		//Agregamos las plataformas
		plataformas.agregar(new Pared(78.0f, 2.5f, 65.0f, 2.5f, 50, 150, 250));   //plat2
		plataformas.agregar(new Pared(90.0f, 2.5f, 82.0f, 2.5f, 50, 150, 250));   //plat3
		plataformas.agregar(new Pared(105.0f, 2.5f, 102.0f, 2.5f, 50, 150, 250));  //plat4
		plataformas.agregar(new Pared(110.0f, 5.0f, 104.0f, 5.0f, 50, 150, 250));  //plat5
		plataformas.agregar(new Pared(120.0f, 7.5f, 114.0f, 7.50f, 50, 150, 250)); //plat6
		plataformas.agregar(new Pared(170.0f, 0.75f, 165.0f, 0.75f, 50, 150, 250)); //plat7
		plataformas.agregar(new Pared(179.0f, 2.0f, 173.5f, 2.0f, 150, 150, 250));  //plat8
		plataformas.agregar(new Pared(187.0f, 4.0f, 180.0f, 4.0f, 50, 150, 250));  //plat9
		plataformas.agregar(new Pared(181.0f, 6.75f, 176.0f, 6.75f, 50, 150, 250));  //plat10
		plataformas.agregar(new Pared(173.0f, 7.50f, 167.0f, 7.50f, 50, 150, 250)); //plat11
		plataformas.agregar(new Pared(165.0f, 9.0f, 161.5f, 9.0f, 150, 150, 250));  //plat12
		plataformas.agregar(new Pared(171.0f, 10.50f, 166.0f, 10.50f, 50, 150, 250)); //plat13
		plataformas.agregar(new Pared(180.0f, 12.0f, 173.0f, 12.0f, 50, 150, 250));	  //plat14
		plataformas.agregar(new Pared(200.0f, 12.0f, 183.0f, 12.0f, 250, 150, 250));  //plat15	
		//Creamos las bolas de fuego
		listaFuego.agregar(new BolaFuego(12.0f, -13.0f, 5.0f, -15.0f));
		listaFuego.agregar(new BolaFuego(22.0f, -8.0f, 5.0f, -15.0f));
		listaFuego.agregar(new BolaFuego(32.0f, -2.0f, 5.0f, -15.0f));
		listaFuego.agregar(new BolaFuego(40.5f, -15.0f, 5.0f, -15.0f));
		//Creacion de los enemigos
		babosas.agregar(new Babosa(36.0f, 13.0f));
		babosas.agregar(new Babosa(56.0f, 12.0f));
		bombers.agregar(new bomber(57.0f, 2.5f));
		bombers.agregar(new bomber(156.0f, 7.0f));
		
		EnemigoDisp* ped1 = new EnemigoDisp(97.0f, 0.0f), //suelo6
			* ped2 = new EnemigoDisp(137.0f, 7.50f), //suelo7
			* ped4 = new EnemigoDisp(150.0f, 0.0f), //suelo7
			* ped5 = new EnemigoDisp(168.0f, 0.75f), //plat7
			* ped6 = new EnemigoDisp(176.0f, 2.5f), //plat8
			* ped7 = new EnemigoDisp(170.0f, 7.50f),  //plat11
			* ped8 = new EnemigoDisp(178.0f, 12.0f); //plat14
		//meter enemigos en sus listas
		enemigosDisp.agregar(ped1);
		enemigosDisp.agregar(ped2);
		enemigosDisp.agregar(ped4);
		enemigosDisp.agregar(ped5);
		enemigosDisp.agregar(ped6);
		enemigosDisp.agregar(ped7);
		enemigosDisp.agregar(ped8);
		//meter disparos en lista
		disparos.agregar(ped1->dispEnem1);
		disparos.agregar(ped2->dispEnem1);
		disparos.agregar(ped4->dispEnem1);
		disparos.agregar(ped5->dispEnem1);
		disparos.agregar(ped6->dispEnem1);
		disparos.agregar(ped7->dispEnem1);
		disparos.agregar(ped8->dispEnem1);

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(60.0f, 0.5f)); //suelo5
		vidas.agregar(new Corazon(107.5f, 5.5f)); //plat 5
		vidas.agregar(new Corazon(135.0f, 3.0f)); //suelo7
		vidas.agregar(new Corazon(163.0f, 9.5f)); //plat12
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidas(); i++)
			vidasR.agregar(new Corazon());

		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(-2.0f, 0.0f));//suelo1
		dineros.agregar(new Moneda(0.0f, 0.0f));
		dineros.agregar(new Moneda(2.0f, 0.0f));
		dineros.agregar(new Moneda(4.0f, 0.0f));
		dineros.agregar(new Moneda(6.0f, 0.0f));
		dineros.agregar(new Moneda(12.0f, 2.5f)); //plat1
		dineros.agregar(new Moneda(16.0f, 0.0f));//suelo2
		dineros.agregar(new Moneda(26.0f, 0.0f));//suelo3
		dineros.agregar(new Moneda(36.0f, 0.0f));//suelo4
		dineros.agregar(new Moneda(44.0f, 0.0f));//suelo5
		dineros.agregar(new Moneda(46.0f, 0.0f));
		dineros.agregar(new Moneda(38.0f, 0.0f));
		dineros.agregar(new Moneda(66.0f, 3.0f));//plat2
		dineros.agregar(new Moneda(68.0f, 3.0f));
		dineros.agregar(new Moneda(70.0f, 3.0f));
		dineros.agregar(new Moneda(72.0f, 3.0f));
		dineros.agregar(new Moneda(74.0f, 3.0f));
		dineros.agregar(new Moneda(76.0f, 3.0f));
		dineros.agregar(new Moneda(84.0f, 3.0f)); //plat3
		dineros.agregar(new Moneda(86.0f, 3.0f));
		dineros.agregar(new Moneda(88.0f, 3.0f));
		dineros.agregar(new Moneda(117.0f, 7.50f));//plat6
		dineros.agregar(new Moneda(125.0f, 5.0f));//plat7
		dineros.agregar(new Moneda(127.5f, 5.0f));
		dineros.agregar(new Moneda(129.5f, 5.0f));
		dineros.agregar(new Moneda(142.5f, 0.0f));
		dineros.agregar(new Moneda(144.5f, 4.0f));
		dineros.agregar(new Moneda(146.5f, 4.0f));
		dineros.agregar(new Moneda(148.5f, 4.0f));
		dineros.agregar(new Moneda(150.5f, 4.0f));

		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 4)
	{
		//Agregamos los suelos
		plataformas.agregar(new Pared(15.0f, 10.5f, -10.0f, 10.5f, 50, 150, 250)); //suelo1
		plataformas.agregar(new Pared(30.0f, 7.5f, 15.0f, 7.5f, 50, 150, 250));  //suelo2
		plataformas.agregar(new Pared(42.0f, 5.0f, 30.0f, 5.0f, 50, 150, 250));  //suelo3
		plataformas.agregar(new Pared(55.0f, 5.0f, 45.0f, 5.0f, 50, 150, 250));  //suelo3.5
		plataformas.agregar(new Pared(65.0f, 2.5f, 55.0f, 2.5f, 50, 150, 250));  //suelo4
		plataformas.agregar(new Pared(95.0f, 0.0f, 65.0f, 0.0f, 50, 150, 250));  //suelo5
		plataformas.agregar(new Pared(120.0f, 0.0f, 102.0f, 0.0f, 50, 150, 250));  //suelo6
		plataformas.agregar(new Pared(145.0f, 0.0f, 132.0f, 0.0f, 50, 150, 250));  //suelo7
		plataformas.agregar(new Pared(150.0f, 2.5f, 145.0f, 2.5f, 50, 150, 250)); //suelo8 
		plataformas.agregar(new Pared(170.0f, 5.0f, 150.0f, 5.0f, 50, 150, 250));  //suelo9
		plataformas.agregar(new Pared(180.0f, 2.5f, 170.0f, 2.5f, 50, 150, 250));  //suelo10
		plataformas.agregar(new Pared(187.0f, 0.0f, 180.0f, 0.0f, 50, 150, 250));  //suelo11
		plataformas.agregar(new Pared(200.0f, 0.0f, 190.0f, 0.0f, 150, 150, 250)); //suelo12 
		//Agregamos las paredes de los pozos
		plataformas.agregar(new Pared(15.0f, 10.5f, 15.0f, -10.0f, 5, 150, 25)); //PARED1
		plataformas.agregar(new Pared(30.0f, 7.5f, 30.0f, -10.0f, 5, 150, 25));  //PARED2
		plataformas.agregar(new Pared(42.0f, 5.0f, 42.0f, -10.0f, 5, 150, 25)); //PARED1*
		plataformas.agregar(new Pared(45.0f, 5.0f, 45.0f, -10.0f, 5, 150, 25));  //PARED2*
		plataformas.agregar(new Pared(55.0f, 5.0f, 55.0f, -10.0f, 5, 150, 25));  //PARED3
		plataformas.agregar(new Pared(65.0f, 2.5f, 65.0f, -10.0f, 5, 150, 25));  //PARED4
		plataformas.agregar(new Pared(145.0f, 2.5f, 145.0f, -10.0f, 5, 150, 25));  //PARED7
		plataformas.agregar(new Pared(150.0f, 5.0f, 150.0f, -10.0f, 5, 150, 25)); //PARED8 
		plataformas.agregar(new Pared(170.0f, 5.0f, 170.0f, -10.0f, 5, 150, 25));  //PARED9
		plataformas.agregar(new Pared(180.0f, 2.5f, 180.0f, -10.0f, 5, 150, 25));  //PARED10
		plataformas.agregar(new Pared(95.0f, 0.0f, 95.0f, -10.0f, 5, 150, 25));  //pozo 5_d
		plataformas.agregar(new Pared(102.0f, 0.0f, 102.0f, -10.0f, 5, 150, 25));  //pozo6_i
		plataformas.agregar(new Pared(120.0f, 0.0f, 120.0f, -10.0f, 5, 150, 25));  //pozo6_d
		plataformas.agregar(new Pared(132.0f, 0.0f, 132.0f, -10.0f, 5, 150, 25));  //pozo7_i
		plataformas.agregar(new Pared(187.0f, 0.0f, 187.0f, -10.0f, 5, 150, 25));  //pozo11_d
		plataformas.agregar(new Pared(190.0f, 0.0f, 190.0f, -10.0f, 5, 150, 25)); //pozo12_i 
		//Agregamos las plataformas aéreas
		plataformas.agregar(new Pared(101.0f, 2.25f, 96.0f, 2.25f, 50, 150, 250)); //plat1
		plataformas.agregar(new Pared(106.0f, 5.0f, 102.5f, 5.0f, 50, 150, 250));   //plat2
		plataformas.agregar(new Pared(112.0f, 6.25f, 108.0f, 6.25f, 50, 150, 250));   //plat3
		plataformas.agregar(new Pared(116.0f, 7.5f, 113.0f, 7.5f, 50, 150, 250));  //plat4
		plataformas.agregar(new Pared(123.0f, 5.0f, 117.0f, 5.0f, 50, 150, 250));  //plat5
		plataformas.agregar(new Pared(140.0f, 7.5f, 136.0f, 7.5f, 50, 150, 250)); //plat7
		plataformas.agregar(new Pared(130.0f, 2.5f, 122.0f, 2.5f, 50, 150, 250)); //plat6
		plataformas.agregar(new Pared(136.0f, 10.0f, 130.0f, 10.0f, 150, 150, 250));  //plat8
		plataformas.agregar(new Pared(145.0f, 5.0f, 138.0f, 5.0f, 50, 150, 250));  //plat9
		//Agregamos el resto de elementos
		listPinchos.agregar(new Pincho(140.0f, 5.0f));
		listPinchos.agregar(new Pincho(157.0f, 5.0f));
		listPinchos.agregar(new Pincho(163.0f, 5.0f));
		listaFuego.agregar(new BolaFuego(43.5f, 0.0f, 8.0f, -5.0f));
		listaFuego.agregar(new BolaFuego(188.5f, 0.0f, 5.0f, -5.0f));

		//Agregamos los enemigos
		tentaculos.agregar(new Tentaculo(191.0f, 0.0f));
		bombers.agregar(new bomber(75.0f, 10.0f));
		bombers.agregar(new bomber(85.0f, 10.0f));
		EnemigoDisp* ped1 = new EnemigoDisp(40.0f, 5.0f), //suelo3
			* ped2 = new EnemigoDisp(150.0f, 2.50f), //suelo4
			* ped3 = new EnemigoDisp(170.0f, 0.0f), //suelo5 y AÑADIR BABOSA
			* ped4 = new EnemigoDisp(110.0f, 6.25f), //plat3
			* ped5 = new EnemigoDisp(132.0f, 10.5f), //plat8
			* ped6 = new EnemigoDisp(124.0f, 2.5f), //plat6
			* ped7 = new EnemigoDisp(160.0f, 5.0f),  //suelo9
			* ped8 = new EnemigoDisp(185.0f, 0.0f); //suelo11
		Tank* tank1 = new Tank(175.0f, 2.5f);
		//meter enemigos en sus listas
		enemigosDisp.agregar(ped1);
		enemigosDisp.agregar(ped2);
		enemigosDisp.agregar(ped3);
		enemigosDisp.agregar(ped4);
		enemigosDisp.agregar(ped5);
		enemigosDisp.agregar(ped6);
		enemigosDisp.agregar(ped7);
		enemigosDisp.agregar(ped8);
		Tanks.agregar(tank1);
		disparos.agregar(ped1->dispEnem1);
		disparos.agregar(ped2->dispEnem1);
		disparos.agregar(ped3->dispEnem1);
		disparos.agregar(ped4->dispEnem1);
		disparos.agregar(ped5->dispEnem1);
		disparos.agregar(ped6->dispEnem1);
		disparos.agregar(ped7->dispEnem1);
		disparos.agregar(ped8->dispEnem1);
		disparos.agregar(tank1->dispTank1);
		disparos.agregar(tank1->dispTank2);
		disparos.agregar(tank1->dispTank3);
		disparos.agregar(tank1->dispTank4);
		disparos.agregar(tank1->dispTank5);

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(60.0f, 0.5f)); //suelo5
		vidas.agregar(new Corazon(114.5f, 8.5f)); //plat 4
		vidas.agregar(new Corazon(133.0f, 10.5f)); //suelo7
		vidas.agregar(new Corazon(160.0f, 6.0f)); //plat12
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidas(); i++)
			vidasR.agregar(new Corazon());
		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(17.0f, 7.5f));  //suelo2
		dineros.agregar(new Moneda(19.0f, 7.5f));
		dineros.agregar(new Moneda(21.0f, 7.5f));
		dineros.agregar(new Moneda(23.0f, 7.5f));  //suelo2
		dineros.agregar(new Moneda(25.0f, 7.5f));
		dineros.agregar(new Moneda(27.0f, 7.5f));
		dineros.agregar(new Moneda(58.0f, 2.5f));  //suelo4
		dineros.agregar(new Moneda(63.0f, 2.5f));
		dineros.agregar(new Moneda(69.0f, 0.0f));  //suelo5
		dineros.agregar(new Moneda(73.0f, 0.0f));
		dineros.agregar(new Moneda(78.0f, 0.0f));
		dineros.agregar(new Moneda(82.0f, 0.0f));
		dineros.agregar(new Moneda(86.0f, 0.0f));
		dineros.agregar(new Moneda(91.0f, 0.0f));
		dineros.agregar(new Moneda(98.0f, 2.50f));  //plat1
		dineros.agregar(new Moneda(135.0f, 0.0f));  //suelo7
		dineros.agregar(new Moneda(137.0f, 0.0f));
		dineros.agregar(new Moneda(139.0f, 0.0f));
		dineros.agregar(new Moneda(141.0f, 0.0f));
		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
	}
	else if (nivel == 5)
	{
		//Agregamos las plataformas del inicio
		plataformas.agregar(new Pared(20.0f, 5.0f, -30.0f, 5.0f, 0, 100, 0)); //Plat1
		plataformas.agregar(new Pared(30.0f, 7.5f, 25.0f, 7.5f, 0, 100, 0)); //Plat2
		plataformas.agregar(new Pared(38.0f, 2.5f, 30.0f, 2.5f, 0, 100, 0)); //Plat3
		//Agregamos los suelos
		plataformas.agregar(new Pared(60.0f, 0.0f, 40.0f, 0.0f, 0, 100, 0)); //Suelo1
		plataformas.agregar(new Pared(80.0f, 0.0f, 65.0f, 0.0f, 0, 100, 0)); //suelo 2
		plataformas.agregar(new Pared(132.0f, 8.0f, 110.0f, 8.0f, 0, 100, 0)); //Suelo 3 (elige)
		plataformas.agregar(new Pared(180.0f, 18.0f, 150.0f, 18.0f, 0, 100, 0)); //Techo malo
		plataformas.agregar(new Pared(180.0f, 12.0f, 150.0f, 12.0f, 0, 100, 0)); //Suelo malo
		plataformas.agregar(new Pared(180.0f, 8.0f, 150.0f, 8.0f, 0, 100, 0)); //Techo bueno
		plataformas.agregar(new Pared(180.0f, 2.0f, 150.0f, 2.0f, 0, 100, 0)); //Suelo bueno
		plataformas.agregar(new Pared(200.0f, 2.0f, 195.0f, 2.0f, 0, 100, 0)); //Suelo fin
		//Agregamos las paredes de los pozos
		plataformas.agregar(new Pared(40.0f, 0.0f, 40.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(60.0f, 0.0f, 60.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(65.0f, 0.0f, 65.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(80.0f, 0.0f, 80.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(110.0f, 8.0f, 110.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(132.0f, 8.0f, 132.0f, -10.0f, 0, 250, 0));
		plataformas.agregar(new Pared(150.0f, 20.0f, 150.0f, 18.0f, 0, 250, 0)); //Pared vertical alto
		plataformas.agregar(new Pared(150.0f, 12.0f, 150.0f, 8.0f, 0, 250, 0)); //Pared vertical medio
		plataformas.agregar(new Pared(150.0f, 2.0f, 150.0f, -10.0f, 0, 250, 0)); //Pared vertical bajo
		plataformas.agregar(new Pared(180.0f, 20.0f, 180.0f, 18.0f, 0, 250, 0)); //Pared vertical alto
		plataformas.agregar(new Pared(180.0f, 12.0f, 180.0f, 8.0f, 0, 250, 0)); //Pared vertical medio
		plataformas.agregar(new Pared(180.0f, 2.0f, 180.0f, -10.0f, 0, 250, 0)); //Pared vertical bajo
		plataformas.agregar(new Pared(195.0f, 2.0f, 195.0f, -10.0f, 0, 250, 0));
		//Agregamos el resto de plataformas aéreas
		plataformas.agregar(new Pared(90.0f, 2.5f, 85.0f, 2.5f, 0, 100, 0)); //Plat4
		plataformas.agregar(new Pared(97.0f, 5.0f, 92.0f, 5.0f, 0, 100, 0)); //Plat5
		plataformas.agregar(new Pared(105.0f, 7.5f, 100.0f, 7.5f, 0, 100, 0)); //Plat6
		plataformas.agregar(new PlatMovil(142.0f, 11.0f, 148.0f, 11.0f, 5.0f, 1.0f, 135.0f, 9.0f, 150.0f, 12.0f, 50, 150, 250));//Arriba MAL
		plataformas.agregar(new PlatMovil(142.0f, 3.0f, 148.0f, 3.0f, 5.0f, -1.0f, 135.0f, 5.0f, 150.0f, 2.0f, 50, 150, 250));//Abajo BIEN
		plataformas.agregar(new PlatMovil(184.0f, 2.0f, 189.0f, 2.0f, 3.0f, 0.0f, 182.0f, 2.0f, 192.0f, 2.0f, 50, 150, 250));//Movil fin

		//Agregamos el resto de elementos
		listPinchos.agregar(new Pincho(27.5f, 7.5f));
		listPinchos.agregar(new Pincho(152.0f, 12.0f));
		listPinchos.agregar(new Pincho(154.0f, 12.0f));
		listPinchos.agregar(new Pincho(156.0f, 12.0f));
		listPinchos.agregar(new Pincho(158.0f, 12.0f));
		listPinchos.agregar(new Pincho(160.0f, 12.0f));
		listPinchos.agregar(new Pincho(162.0f, 12.0f));
		listPinchos.agregar(new Pincho(164.0f, 12.0f));
		listPinchos.agregar(new Pincho(166.0f, 12.0f));
		listPinchos.agregar(new Pincho(168.0f, 12.0f));
		listPinchos.agregar(new Pincho(170.0f, 12.0f));
		listPinchos.agregar(new Pincho(172.0f, 12.0f));
		listPinchos.agregar(new Pincho(174.0f, 12.0f));
		listPinchos.agregar(new Pincho(176.0f, 12.0f));
		listPinchos.agregar(new Pincho(178.0f, 12.0f));
		listaFuego.agregar(new BolaFuego(62.5f, 0.0f, 3.0f, -5.0f));
		listaFuego.agregar(new BolaFuego(82.5f, 0.0f, 7.0f, -5.0f));
		listaFuego.agregar(new BolaFuego(107.5f, 0.0f, 10.0f, -5.0f));

		//Agregamos enemigos
		tentaculos.agregar(new Tentaculo(10.0f, 5.0f));
		tentaculos.agregar(new Tentaculo(15.0f, 5.0f));
		bombers.agregar(new bomber(50.0f, 2.0f));

		EnemigoDisp* ped1 = new EnemigoDisp(70.0f, 1.0f),
			* ped2 = new EnemigoDisp(155.0f, 12.5f),
			* ped3 = new EnemigoDisp(160.0f, 12.5f),
			* ped4 = new EnemigoDisp(170.0f, 12.5f),
			* ped5 = new EnemigoDisp(175.0f, 12.5f);
		Tank* tank1 = new Tank(120.0f, 8.5f);
		//bossFinal* boss = new bossFinal(111.0f, 8.5f);

		enemigosDisp.agregar(ped1);
		enemigosDisp.agregar(ped2);
		enemigosDisp.agregar(ped3);
		enemigosDisp.agregar(ped4);
		enemigosDisp.agregar(ped5);
		Tanks.agregar(tank1);

		disparos.agregar(ped1->dispEnem1);
		disparos.agregar(ped2->dispEnem1);
		disparos.agregar(ped3->dispEnem1);
		disparos.agregar(ped4->dispEnem1);
		disparos.agregar(ped5->dispEnem1);
		disparos.agregar(tank1->dispTank1);
		disparos.agregar(tank1->dispTank2);
		disparos.agregar(tank1->dispTank3);
		disparos.agregar(tank1->dispTank4);
		disparos.agregar(tank1->dispTank5);

		misiles.agregar(boss.misil1);
		misiles.agregar(boss.misil2);
		misiles.agregar(boss.misil3);
		misiles.agregar(boss.misil4);
		misiles.agregar(boss.misil5);
		misiles.agregar(boss.misil6);
		misiles.agregar(boss.misil7);
		misiles.agregar(boss.misil8);
		misiles.agregar(boss.misil9);
		misiles.agregar(boss.misil10);

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(160.0f, 2.5f));
		vidas.agregar(new Corazon(170.0f, 2.5f));
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidas(); i++)
			vidasR.agregar(new Corazon());
		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(66.0f, 0.0f));
		dineros.agregar(new Moneda(68.0f, 0.0f));
		dineros.agregar(new Moneda(70.0f, 0.0f));
		dineros.agregar(new Moneda(72.0f, 0.0f));
		dineros.agregar(new Moneda(74.0f, 0.0f));
		dineros.agregar(new Moneda(76.0f, 0.0f));
		dineros.agregar(new Moneda(78.0f, 0.0f));
		dineros.agregar(new Moneda(152.0f, 2.5f));
		dineros.agregar(new Moneda(154.0f, 2.5f));
		dineros.agregar(new Moneda(156.0f, 2.5f));
		dineros.agregar(new Moneda(158.0f, 2.5f));
		dineros.agregar(new Moneda(162.0f, 2.5f));
		dineros.agregar(new Moneda(164.0f, 2.5f));
		dineros.agregar(new Moneda(166.0f, 2.5f));
		dineros.agregar(new Moneda(168.0f, 2.5f));
		dineros.agregar(new Moneda(172.0f, 2.5f));
		dineros.agregar(new Moneda(174.0f, 2.5f));
		dineros.agregar(new Moneda(176.0f, 2.5f));
		dineros.agregar(new Moneda(178.0f, 2.5f));
		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
	}
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

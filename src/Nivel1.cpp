#include "Nivel1.h"

void Nivel1::dibuja()
{	//Creamos la cámara
	gluLookAt(hombre.posicion.x, 11.5, z_ojo,  // posicion del ojo  
		hombre.posicion.x, 7.5f, 0.0,      // hacia que punto mira  (hombre.posicion.y + 8)
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//Dibuja la estructura del nivel
	caja.dibuja();
	plataformas.dibuja();
	bonus1.dibuja();
	bonus2.dibuja();
	bonus3.dibuja();
	bonus4.dibuja();
	pincho1.dibuja();
	pincho2.dibuja();
	pincho3.dibuja();

	//Dibuja Vida
	vidas.dibuja();			//Dibuja vidas del entorno
	vidasR.dibuja();		//Dibuja Vidas Recogidas

	//Dibuja Monedas
	dineros.dibuja();			//Dibuja monedas del entorno
	dinerosR.dibuja();			//Dibuja Debajo de Vidas Recogidas, el simbolo de moneda

	//Hay que desimplementar la union dibuja-logica todavia
	Vector2D pos = hombre.getPos();
	dinerosR.dibujaContador(pos.x);	//Dibuja Debajo de Vidas Recogidas, el numero de monedas

	//Dibujamos lo animado
	hombre.dibuja();
	enemigosDisp.dibuja();
	Tanks.dibuja();
	babosas.dibuja();			
	tentaculos.dibuja();
	bombers.dibuja();
	disparos.dibuja();
	dispAmig.dibuja();
}

void Nivel1::mueve()
{
	//Movimientos personaje y disparo
	hombre.mueve(0.025f);
	dispAmig.mueve(0.025f);

	//Movimiento de los enemigos
	enemigosDisp.mueve(0.025f);
	Tanks.mueve(0.025f);
	babosas.mueve(0.025f);
	tentaculos.mueve(0.025f);
	bombers.mueve(0.025f);
	disparos.mueve(0.025f);

	//Movimiento Vidas
	vidas.mueve(0.025f);
	Vector2D pos=hombre.getPos();
	vidasR.mueve(0.025f,pos.x);

	//Movimiento Monedas
	dineros.mueve(0.025f);
	
	dinerosR.mueve(0.025f, pos.x);

	//Interacciones personaje con el entorno
	Interaccion::rebote(hombre, caja);
	Interaccion::rebote(hombre, plataformas);

	//Interacciones enemigos con el entorno
	enemigosDisp.rebote(caja);
	enemigosDisp.rebote(plataformas);
	Tanks.rebote(caja);	
	Tanks.rebote(plataformas);
	bombers.rebote(caja);
	bombers.rebote(plataformas);
	
	//Interacciones disparo con el entorno
	disparos.rebote(caja);
	disparos.rebote(plataformas);

	dispAmig.rebote(caja);
	dispAmig.rebote(plataformas);

	//Interaccion Pj con enemigo
	Interaccion::rebote(hombre, enemigosDisp,vidasR);
	//Interaccion::rebote(hombre, eneDisp1);
	//Interaccion::rebote(hombre, eneDisp2);
	//Interaccion::mov(babosas, hombre);
	babosas.mov(hombre);

	//Interaccion Pj con Vida
	 
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

	//Posicionamos todo el entorno
	Pared* plat1 = new Pared(2.0f, 10.0f, -5.0f, 10.0f, 50, 150, 250),
		* plat2 = new Pared(27.0f, 5.0f, 18.0f, 5.0f, 150, 150, 50),
		* plat3 = new Pared(45.0f, 10.0f, 36.0f, 10.0f, 50, 150, 250),
		* plat4 = new Pared(68.0f, 5.0f, 57.0f, 5.0f, 150, 150, 50),
		* plat5 = new Pared(100.0f, 10.0f, 82.0f, 10.0f, 50, 150, 250),
		* plat6 = new Pared(123.0f, 5.0f, 108.0f, 5.0f, 150, 150, 50),
		* plat7 = new Pared(145.0f, 10.0f, 135.0f, 10.0f, 50, 150, 250),
		* plat8 = new Pared(175.0f, 5.0f, 158.0f, 5.0f, 150, 150, 50),
		* plat9 = new Pared(197.0f, 5.0f, 189.0f, 5.0f, 150, 150, 50);
	plataformas.agregar(plat1);
	plataformas.agregar(plat2);
	plataformas.agregar(plat3);
	plataformas.agregar(plat4);
	plataformas.agregar(plat5);
	plataformas.agregar(plat6);
	plataformas.agregar(plat7);
	plataformas.agregar(plat8);
	plataformas.agregar(plat9);

	pincho1.setPos(25.0f, 0.0f);
	pincho2.setPos(42.0f, 10.0f);//Pincho en plataforma3
	pincho3.setPos(148.0f, 0.0f);
	bonus1.setPos(15.0f, 7.0f);
	bonus2.setPos(35.0f, 7.0f);
	bonus3.setPos(75.0f, 7.0f);
	bonus4.setPos(185.0f, 7.0f);


	//Creacion de los enemigos
	//tank.setPos(193.0f, 15.0f);//Jefe en la plataforma final
	EnemigoDisp* ped1 = new EnemigoDisp(0.0f, 9.0f), //Enemigo plat1
		* ped2 = new EnemigoDisp(15.0f, 0.0f),
		* ped3 = new EnemigoDisp(22.0f, 0.0f),
		* ped4 = new EnemigoDisp(35.0f, 0.0f),
		* ped5 = new EnemigoDisp(87.0f, 0.0f),
		* ped6 = new EnemigoDisp(62.0f, 7.0f), //Enemigo plat4
		* ped7 = new EnemigoDisp(174.0f, 0.0f),
		* ped8 = new EnemigoDisp(140.0f, 11.0f), //Enemigo plat7
		* ped9 = new EnemigoDisp(193.0f, 0.0f);
	Tank* Tank1 = new Tank(193.0f, 15.0f);
	//babosa.setPos(10.0f, 13.0f);
	Babosa* babosa1 = new Babosa(10.0f, 13.0f),
		* babosa2 = new Babosa(-8.0f, 2.0f);
	Tentaculo* tentaculo1 = new Tentaculo(10.0f, 0.0f);
	
	bomber* bomber1 = new bomber(10.0f, 10.0f);
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
	Tanks.agregar(Tank1);
	babosas.agregar(babosa1);
	babosas.agregar(babosa2);
	tentaculos.agregar(tentaculo1);
	bombers.agregar(bomber1);
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

	//Creaccion de Vidas Recolectables
	vidas.agregar(new Corazon(4.0f, 0.0f));		//Corazon (Posicion x, Posicion y)
	vidas.agregar(new Corazon(12.0f, 0.0f));

	//Creaccion de las Vidas del Pj
	for (int i = 0; i < vidasR.getVidas(); i++) 
		vidasR.agregar(new Corazon());
	
	//Creaccion de Monedas Recolectables
	dineros.agregar(new Moneda(8.0f, 0.0f));		//Moneda (Posicion x, Posicion y)
	dineros.agregar(new Moneda(14.0f, 0.0f));

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
#include "Nivel.h"
#include "freeglut.h"

void Nivel::dibuja()
{	//Creamos la cámara
	gluLookAt(hombre.getPos().x, 11.5, z_ojo,  // posicion del ojo  
		hombre.getPos().x, 7.5f, 0.0,      // hacia que punto mira  (hombre.posicion.y + 8)
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//Dibuja la estructura del nivel
	caja.dibuja(); //Aqui le podemos pasar por parámetro mundo
	solidos.dibuja(); //Idem a con la caja

	//Dibuja Vida y Monedas
	vidas.dibuja();			//Vidas del entorno
	vidasR.dibuja();		//Vidas Recogidas
	dineros.dibuja();		//Monedas del entorno
	dinerosR.dibuja();		//Debajo de Vidas Recogidas, el simbolo de moneda
	dinerosR.dibujaContador();	//Debajo de Vidas Recogidas, el numero de monedas

	//Dibujamos lo animado
	hombre.dibuja();	
	enemigos.dibuja();
	espada.dibuja();
	disparos.dibuja();
	glPushMatrix();
	glTranslatef(hombre.getPos().x, 0, -1);
	switch (hombre.flagnivel) {
	case 1:
		//mundo1
		glEnable(GL_TEXTURE_2D);
		
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(25, -10, -10);
		glTexCoord2d(1, 1); glVertex3f(25, 25, -10);
		glTexCoord2d(1, 0); glVertex3f(-30, 25, -10);
		glTexCoord2d(0, 0); glVertex3f(-30, -10, -10);
		glEnd();
		break;
	case 2:
		//mundo1
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(25, -10, -10);
		glTexCoord2d(1, 1); glVertex3f(25, 25, -10);
		glTexCoord2d(1, 0); glVertex3f(-30, 25, -10);
		glTexCoord2d(0, 0); glVertex3f(-30, -10, -10);
		glEnd();
		break;
	case 3:
		//mundo1
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(25, -10, -10);
		glTexCoord2d(1, 1); glVertex3f(25, 25, -10);
		glTexCoord2d(1, 0); glVertex3f(-30, 25, -10);
		glTexCoord2d(0, 0); glVertex3f(-30, -10, -10);
		glEnd();
		break;

	case 4:
		//mundo2
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(25, -10, -10);
	glTexCoord2d(1, 1); glVertex3f(25, 25, -10);
	glTexCoord2d(1, 0); glVertex3f(-30, 25, -10);
	glTexCoord2d(0, 0); glVertex3f(-30, -10, -10);
	glEnd();
		break;
	case 5:
		//mundo2
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(25, -10, -10);
		glTexCoord2d(1, 1); glVertex3f(25, 25, -10);
		glTexCoord2d(1, 0); glVertex3f(-30, 25, -10);
		glTexCoord2d(0, 0); glVertex3f(-30, -10, -10);
		glEnd();
		break;
	case 6:
		//mundo2
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(25, -10, -10);
		glTexCoord2d(1, 1); glVertex3f(25, 25, -10);
		glTexCoord2d(1, 0); glVertex3f(-30, 25, -10);
		glTexCoord2d(0, 0); glVertex3f(-30, -10, -10);
		glEnd();
		break;
	case 7:
		//mundo3

	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Espacio.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(25, -10, -10);
	glTexCoord2d(1, 1); glVertex3f(25, 25, -10);
	glTexCoord2d(1, 0); glVertex3f(-30, 25, -10);
	glTexCoord2d(0, 0); glVertex3f(-30, -10, -10);
	glEnd();
	case 8:
		//mundo3

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Espacio.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(25, -10, -10);
		glTexCoord2d(1, 1); glVertex3f(25, 25, -10);
		glTexCoord2d(1, 0); glVertex3f(-30, 25, -10);
		glTexCoord2d(0, 0); glVertex3f(-30, -10, -10);
		glEnd();
	case 9:
		//mundo3

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Espacio.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(25, -10, -10);
		glTexCoord2d(1, 1); glVertex3f(25, 25, -10);
		glTexCoord2d(1, 0); glVertex3f(-30, 25, -10);
		glTexCoord2d(0, 0); glVertex3f(-30, -10, -10);
		glEnd();
	}
	glPopMatrix();
}

void Nivel::mueve()
{
	//Movimientos personaje, disparos y enemigos
	hombre.mueve(0.025f);
	espada.mueve(0.025f);
	Interaccion::mov(espada, hombre);
	enemigos.mueve(0.025f);
	disparos.mueve(0.025f);
	//Interaccion::dispara(enemigos, disparos); //Aún no se donde va jaja

	//Movimiento vidas y monedas
	vidas.mueve(0.025f);
	Vector2D pos = hombre.getPos();
	vidasR.mueve(0.025f, pos.x);
	dineros.mueve(0.025f);
	dinerosR.mueve(0.025f, pos);

	//Movimiento de los solidos e interacciones con estos
	solidos.mueve(0.025f);
	Interaccion::rebote(hombre, caja, vidasR);
	Interaccion::rebote(hombre, solidos, vidasR);
	Interaccion::rebote(enemigos, solidos);
	Interaccion::choque(disparos, solidos);

	//Interacciones del hombre con los enemigos
	Interaccion::colision(hombre, enemigos, vidasR);
	if (espada.getFlag())
		Interaccion::colision(espada, enemigos);
	Interaccion::colision(disparos, enemigos);
	Interaccion::colision(hombre, disparos, vidasR);

	//Interaccion Pj con Vida y Monedas
	//Elimina Vida recogida
	Corazon* aux_c = vidas.recoleccion(hombre);
	if (aux_c != 0) {				//si alguna Vida ha chocado
		vidas.eliminar(aux_c);
		vidasR.agregar(new Corazon());
	}
	//Elimina Monedas recogidas
	Moneda* aux_m = dineros.recoleccion(hombre);
	if (aux_m != 0) {				//si alguna Moneda ha chocado
		dineros.eliminar(aux_m);
		dinerosR.aumentaDinero();
	}
}

void Nivel::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	nivel = hombre.getNivel();
	cargarnivel();
}

bool Nivel::cargarnivel()
{
	if (nivel == 1)
	{
		//background
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo_rojo.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 0); glVertex2f(10, 15);
		glTexCoord2d(0, 0); glVertex2f(-10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);*/
		//Agregamos los suelos
		solidos.agregar(new Pared(50.0f, 0.0f, -30.0f, 0.0f, 0, 100, 0));
		solidos.agregar(new Suelo(-30.0f, 0.0f, 50.0f, -10.0f));
		solidos.agregar(new Pared(80.0f, 0.0f, 55.0f, 0.0f, 0, 100, 0));
		solidos.agregar(new Suelo(55.0f, 0.0f, 80.0f, -10.0f));
		solidos.agregar(new Pared(132.0f, 0.0f, 87.0f, 0.0f, 0, 100, 0));
		solidos.agregar(new Suelo(97.0f, 0.0f, 132.0f, -10.0f));
		solidos.agregar(new Pared(150.0f, 0.0f, 139.0f, 0.0f, 0, 100, 0));
		solidos.agregar(new Suelo(139.0f, 0.0f, 150.0f, -10.0f));
		solidos.agregar(new Pared(200.0f, 0.0f, 156.0f, 0.0f, 0, 100, 0));
		solidos.agregar(new Suelo(156.0f, 0.0f, 200.0f, -10.0f));
		//Agregamos las paredes de los pozos
		solidos.agregar(new Pared(50.0f, 0.0f, 50.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(55.0f, 0.0f, 55.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(80.0f, 0.0f, 80.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(87.0f, 0.0f, 87.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(132.0f, 0.0f, 132.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(139.0f, 0.0f, 139.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(150.0f, 0.0f, 150.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(156.0f, 0.0f, 156.0f, -10.0f, 0, 250, 0));
		//Agregamos las plataformas aéreas
		solidos.agregar(new Pared(2.0f, 10.0f, -5.0f, 10.0f, 50, 150, 250));
		solidos.agregar(new Pared(16.0f, 2.50f, 11.0f, 2.50f, 150, 150, 50));
		solidos.agregar(new Pared(27.0f, 5.0f, 18.0f, 5.0f, 150, 150, 50));
		solidos.agregar(new Pared(35.0f, 7.50f, 30.0f, 7.50f, 150, 150, 50));
		solidos.agregar(new Pared(45.0f, 10.0f, 36.0f, 10.0f, 50, 150, 250));
		solidos.agregar(new Pared(68.0f, 5.0f, 57.0f, 5.0f, 150, 150, 50));
		solidos.agregar(new Pared(90.0f, 8.0f, 70.0f, 8.0f, 50, 150, 250));
		solidos.agregar(new Pared(102.0f, 7.50f, 98.0f, 7.50f, 150, 150, 50));
		solidos.agregar(new Pared(118.0f, 5.0f, 104.0f, 5.0f, 150, 150, 50));
		solidos.agregar(new Pared(130.0f, 7.50f, 124.0f, 7.50f, 150, 150, 50));
		solidos.agregar(new Pared(145.0f, 10.0f, 135.0f, 10.0f, 50, 150, 250));
		solidos.agregar(new Pared(155.0f, 7.50f, 150.0f, 7.50f, 150, 150, 50));
		solidos.agregar(new Pared(175.0f, 5.0f, 158.0f, 5.0f, 150, 150, 50));
		solidos.agregar(new Final(197.0f, 5.0f, 182.0f, 5.0f));
		//Agregamos los pinchos
		solidos.agregar(new Pincho(25.0f, 0.0f));
		solidos.agregar(new Pincho(40.0f, 10.0f)); //Pincho en plat3
		solidos.agregar(new Pincho(69.0f, 0.0f));
		solidos.agregar(new Pincho(78.0f, 0.0f));
		solidos.agregar(new Pincho(108.0f, 5.0f)); //Pincho en plat6
		solidos.agregar(new Pincho(115.0f, 5.0f)); //Pincho en plat6
		solidos.agregar(new Pincho(148.0f, 0.0f));
		solidos.agregar(new Pincho(165.0f, 5.0f)); //Pincho en plat8

		//Creacion de los enemigos
		enemigos.agregar(new EnemigoDisp(0.0f,12.0f)); //Enemigo plat1
		enemigos.agregar(new EnemigoDisp(15.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(22.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(35.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(62.0f, 7.0f)); //Enemigo plat4
		enemigos.agregar(new EnemigoDisp(87.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(95.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(120.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(130.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(140.0f, 11.0f)); //Enemigo plat7
		enemigos.agregar(new EnemigoDisp(174.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(193.0f, 0.0f));
		enemigos.agregar(new Tank(193.0f, 7.0f));
		enemigos.agregar(new Babosa(10.0f, 13.0f));

		Interaccion::dispara(enemigos, disparos); //Aún no se donde va jaja

		/*
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
		disparos.agregar(Tank1->dispTank5);*/
		//meter enemigos en sus listas
		/*moviles.agregar(ped1);
		moviles.agregar(ped2);
		moviles.agregar(ped3);
		moviles.agregar(ped4);
		moviles.agregar(ped5);
		moviles.agregar(ped6);
		moviles.agregar(ped7);
		moviles.agregar(ped8);
		moviles.agregar(ped9);
		moviles.agregar(ped10);
		moviles.agregar(ped11);
		moviles.agregar(ped12);
		moviles.agregar(Tank1);
		moviles.agregar(new Babosa(10.0f, 13.0f));
		//meter disparos en lista
		moviles.agregar(ped1->dispEnem1);
		moviles.agregar(ped2->dispEnem1);
		moviles.agregar(ped3->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped5->dispEnem1);
		moviles.agregar(ped6->dispEnem1);
		moviles.agregar(ped7->dispEnem1);
		moviles.agregar(ped8->dispEnem1);
		moviles.agregar(ped9->dispEnem1);
		moviles.agregar(Tank1->dispTank1);
		moviles.agregar(Tank1->dispTank2);
		moviles.agregar(Tank1->dispTank3);
		moviles.agregar(Tank1->dispTank4);
		moviles.agregar(Tank1->dispTank5);*/

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(32.5f, 8.0f)); //La vida a la que invita la casa
		vidas.agregar(new Corazon(111.5f, 5.5f)); //Vida entre los dos pinchos
		vidas.agregar(new Corazon(178.0f, 5.0f)); //Vida antes del jefe final

		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidasInicial(); i++)
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
		solidos.agregar(new Pared(37.0f, 0.0f, -10.0f, 0.0f, 50, 150, 250));
		solidos.agregar(new Suelo(-10.0f, 0.0f, 37.0f, -10.0f));
		solidos.agregar(new Pared(125.0f, 0.0f, 112.0f, 0.0f, 50, 150, 250));
		solidos.agregar(new Suelo(112.0f, 0.0f, 125.0f, -10.0f));
		solidos.agregar(new Pared(135.0f, 0.0f, 130.0f, 0.0f, 50, 150, 250));
		solidos.agregar(new Suelo(130.0f, 0.0f, 135.0f, -10.0f));
		solidos.agregar(new Pared(167.0f, 0.0f, 147.0f, 0.0f, 50, 150, 250));
		solidos.agregar(new Suelo(147.0f, 0.0f, 167.0f, -10.0f));
		solidos.agregar(new Pared(186.0f, 0.0f, 172.0f, 0.0f, 50, 150, 250)); //suelo entre plataformas para meter monedas
		solidos.agregar(new Suelo(172.0f, 0.0f, 186.0f, -10.0f));
		solidos.agregar(new Pared(200.0f, 0.0f, 190.0f, 0.0f, 50, 150, 250));
		solidos.agregar(new Suelo(190.0f, 0.0f, 200.0f, -10.0f));
		//Agregamos las paredes de los pozos
		solidos.agregar(new Pared(37.0f, 0.0f, 37.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(112.0f, 0.0f, 112.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(125.0f, 0.0f, 125.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(130.0f, 0.0f, 130.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(135.0f, 0.0f, 135.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(147.0f, 0.0f, 147.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(167.0f, 0.0f, 167.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(172.0f, 0.0f, 172.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(186.0f, 0.0f, 186.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(190.0f, 0.0f, 190.0f, -10.0f, 0, 250, 0));
		//Agregamos las plataformas aéreas
		solidos.agregar(new Pared(40.0f, 2.5f, 37.0f, 2.5f, 50, 150, 250));//plat entre medias
		solidos.agregar(new Pared(45.0f, 5.0f, 41.0f, 5.0f, 50, 150, 250));
		solidos.agregar(new Pared(63.0f, 5.0f, 48.0f, 5.0f, 50, 150, 250));
		solidos.agregar(new Pared(69.0f, 7.0f, 65.0f, 7.0f, 50, 150, 250));
		solidos.agregar(new Pared(75.0f, 9.0f, 71.0f, 9.0f, 50, 150, 250));
		solidos.agregar(new Pared(82.0f, 10.5f, 78.0f, 10.50f, 50, 150, 250));//la siguiente plat es movil
		solidos.agregar(new PlatMovil(86.0f, 8.0f, 92.0f, 8.0f, 3.0f, 0.0f, 86.0f, 8.0f, 120.0f, 8.0f));//Plataforma móvil
		solidos.agregar(new Pared(145.0f, 2.50f, 137.0f, 2.50f, 50, 150, 250));
		solidos.agregar(new Pared(175.0f, 2.5f, 167.5f, 2.5f, 150, 150, 250));
		solidos.agregar(new Pared(183.0f, 6.0f, 177.0f, 6.0f, 50, 150, 250));//plat movil en esta posicion
		solidos.agregar(new Pared(190.0f, 7.5f, 185.0f, 7.50f, 50, 150, 250));
		solidos.agregar(new Pared(200.0f, 12.0f, 197.0f, 12.0f, 250, 150, 250));
		solidos.agregar(new Pared(200.0f, 10.0f, 197.0f, 10.0f, 250, 150, 250));
		solidos.agregar(new Pared(200.0f, 8.0f, 197.0f, 8.0f, 250, 150, 250));
		solidos.agregar(new Final(200.0f, 2.0f, 197.0f, 2.0f));
		//Agregamos los pinchos
		solidos.agregar(new Pincho(25.0f, 0.0f));//suelo1
		solidos.agregar(new Pincho(162.0f, 0.0f));//suelo4
		solidos.agregar(new Pincho(180.0f, 0.0f));//suelo5
		//Agregamos las bolas de fuego 
		solidos.agregar(new BolaFuego(87.0f, 0.0f, 16.0f, -5.0f));
		solidos.agregar(new BolaFuego(99.0f, -2.0f, 16.0f, -5.0f));
		solidos.agregar(new BolaFuego(110.0f, -4.0f, 16.0f, -5.0f));

		//Creacion de los enemigos
		enemigos.agregar(new Tentaculo(192.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(0.0f, 9.0f));
		enemigos.agregar(new EnemigoDisp(10.0f, 0.0f)); //suelo1	
		enemigos.agregar(new EnemigoDisp(23.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(55.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(73.0f, 9.0f)); //p5
		enemigos.agregar(new EnemigoDisp(80.0f, 10.5f)); //p6
		enemigos.agregar(new EnemigoDisp(117.0f, 0.0f)); //suelo2
		enemigos.agregar(new EnemigoDisp(120.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(132.0f, 0.0f)); //suelo3
		enemigos.agregar(new EnemigoDisp(140.0f, 2.5f)); //p7
		enemigos.agregar(new EnemigoDisp(172.0f, 2.5f)); //p8
		enemigos.agregar(new EnemigoDisp(178.0f, 0.0f)); //suelo intermedio
		enemigos.agregar(new EnemigoDisp(198.0f, 12.5f)); //enemigos apoyo al tentaculo
		enemigos.agregar(new EnemigoDisp(198.0f, 10.5f));
		enemigos.agregar(new EnemigoDisp(199.0f, 8.5f));

		//meter disparos en lista
		/*moviles.agregar(ped1->dispEnem1);
		moviles.agregar(ped2->dispEnem1);
		moviles.agregar(ped3->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped5->dispEnem1);
		moviles.agregar(ped6->dispEnem1);
		moviles.agregar(ped7->dispEnem1);
		moviles.agregar(ped8->dispEnem1);
		moviles.agregar(ped9->dispEnem1);
		moviles.agregar(ped10->dispEnem1);
		moviles.agregar(ped11->dispEnem1);
		moviles.agregar(ped12->dispEnem1);
		moviles.agregar(ped14->dispEnem1);
		moviles.agregar(ped15->dispEnem1);
		moviles.agregar(ped16->dispEnem1);*/

		//Agregamos las vidas recolectables
		vidas.agregar(new Corazon(67.0f, 7.5f)); //plat 4
		vidas.agregar(new Corazon(117.5f, 0.5f)); //suelo 2
		vidas.agregar(new Corazon(170.0f, 2.5f)); //plat 8

		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidasInicial(); i++)
			vidasR.agregar(new Corazon());

		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(19.0f, 0.5f));//suelo1
		dineros.agregar(new Moneda(21.0f, 0.5f));
		dineros.agregar(new Moneda(23.0f, 0.5f));
		dineros.agregar(new Moneda(25.0f, 4.0f));
		dineros.agregar(new Moneda(36.0f, 0.5f));

		dineros.agregar(new Moneda(39.0f, 3.0f)); //plat1

		dineros.agregar(new Moneda(43.0f, 5.5f));//plat2

		dineros.agregar(new Moneda(54.0f, 5.5f)); //plat3
		dineros.agregar(new Moneda(56.0f, 5.5f));
		dineros.agregar(new Moneda(58.0f, 5.5f));
		dineros.agregar(new Moneda(60.0f, 5.5f));
		dineros.agregar(new Moneda(62.0f, 5.5f));
		//en plat movil tambien ponemos alguna moneda

		dineros.agregar(new Moneda(115.5f, 0.5f));//suelo2
		dineros.agregar(new Moneda(117.5f, 0.5f));
		dineros.agregar(new Moneda(119.5f, 0.5f));
		dineros.agregar(new Moneda(121.5f, 0.5f));
		dineros.agregar(new Moneda(123.5f, 0.5f));

		dineros.agregar(new Moneda(132.0f, 0.5f));//suelo3
		dineros.agregar(new Moneda(133.0f, 0.5f));

		dineros.agregar(new Moneda(139.0f, 3.0f));//plat7
		dineros.agregar(new Moneda(143.0f, 3.0f));

		dineros.agregar(new Moneda(152.0f, 0.5f));//suelo4
		dineros.agregar(new Moneda(154.0f, 0.5f));
		dineros.agregar(new Moneda(156.0f, 0.5f));
		dineros.agregar(new Moneda(158.0f, 0.5f));
		dineros.agregar(new Moneda(160.0f, 0.5f));

		dineros.agregar(new Moneda(179.0f, 9.0f));//plat9

		dineros.agregar(new Moneda(175.0f, 0.5f));//suelo5
		dineros.agregar(new Moneda(177.0f, 0.5f));
		dineros.agregar(new Moneda(179.0f, 4.0f));
		dineros.agregar(new Moneda(181.0f, 4.0f));
		dineros.agregar(new Moneda(183.0f, 0.5f));
		dineros.agregar(new Moneda(185.0f, 0.5f));

		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 3)
	{
		//Agregamos los suelos 
		solidos.agregar(new Pared(10.0f, 0.0f, -10.0f, 0.0f, 50, 150, 250)); //suelo1
		solidos.agregar(new Suelo(-10.0f, 0.0f, 10.0f, -10.0f));
		solidos.agregar(new Pared(20.0f, 0.0f, 14.0f, 0.0f, 50, 150, 250));  //suelo2
		solidos.agregar(new Suelo(14.0f, 0.0f, 20.0f, -10.0f));
		solidos.agregar(new Pared(30.0f, 0.0f, 24.0f, 0.0f, 50, 150, 250));  //suelo3
		solidos.agregar(new Suelo(24.0f, 0.0f, 30.0f, -10.0f));
		solidos.agregar(new Pared(39.0f, 0.0f, 34.0f, 0.0f, 50, 150, 250));  //suelo4
		solidos.agregar(new Suelo(34.0f, 0.0f, 39.0f, -10.0f));
		solidos.agregar(new Pared(62.0f, 0.0f, 42.0f, 0.0f, 50, 150, 250));  //suelo5
		solidos.agregar(new Suelo(42.0f, 0.0f, 62.0f, -10.0f));
		solidos.agregar(new Pared(101.0f, 0.0f, 94.0f, 0.0f, 50, 150, 250));  //suelo6
		solidos.agregar(new Suelo(94.0f, 0.0f, 101.0f, -10.0f));
		solidos.agregar(new Pared(140.0f, 5.0f, 123.0f, 5.0f, 50, 150, 250));  //suelo7_1
		solidos.agregar(new Suelo(123.0f, 5.0f, 140.0f, -10.0f));
		solidos.agregar(new Pared(140.0f, 5.0f, 140.0f, -1.0f, 50, 150, 250)); //suelo7_2 vertical

		solidos.agregar(new Pared(162.0f, 0.0f, 140.0f, 0.0f, 50, 150, 250));  //suelo7_3
		solidos.agregar(new Suelo(140.0f, 0.0f, 162.0f, -10.0f));
		//Agregamos las paredes de los pozos
		solidos.agregar(new Pared(10.0f, 0.0f, 10.0f, -10.0f, 0, 250, 0)); //pozo 1_i
		solidos.agregar(new Pared(14.0f, 0.0f, 14.0f, -10.0f, 0, 250, 0));  //pozo 2_i
		solidos.agregar(new Pared(20.0f, 0.0f, 20.0f, -10.0f, 0, 250, 0));  //pozo 2_d
		solidos.agregar(new Pared(24.0f, 0.0f, 24.0f, -10.0f, 0, 250, 0));  //pozo 3_i
		solidos.agregar(new Pared(30.0f, 0.0f, 30.0f, -10.0f, 0, 250, 0));  //pozo 3_d
		solidos.agregar(new Pared(34.0f, 0.0f, 34.0f, -10.0f, 0, 250, 0));  //pozo 4_i
		solidos.agregar(new Pared(39.0f, 0.0f, 39.0f, -10.0f, 0, 250, 0));  //pozo 4_d
		solidos.agregar(new Pared(42.0f, 0.0f, 42.0f, -10.0f, 0, 250, 0)); // pozo 5_i
		solidos.agregar(new Pared(62.0f, 0.0f, 62.0f, -10.0f, 0, 250, 0)); // pozo 5_d
		solidos.agregar(new Pared(94.0f, 0.0f, 94.0f, -10.0f, 0, 250, 0));  //pozo 6_i
		solidos.agregar(new Pared(101.0f, 0.0f, 101.0f, -10.0f, 0, 250, 0));  //pozo 6_d
		solidos.agregar(new Pared(123.0f, 5.0f, 123.0f, -10.0f, 0, 250, 0)); //pozo 7_i
		solidos.agregar(new Pared(162.0f, 0.0f, 162.0f, -10.0f, 0, 250, 0));  //pozo 7_d
		//Agregamos las plataformas
		solidos.agregar(new Pared(78.0f, 2.5f, 65.0f, 2.5f, 50, 150, 250));   //plat2
		solidos.agregar(new Pared(90.0f, 2.5f, 82.0f, 2.5f, 50, 150, 250));   //plat3
		solidos.agregar(new Pared(105.0f, 2.5f, 102.0f, 2.5f, 50, 150, 250));  //plat4
		solidos.agregar(new Pared(110.0f, 5.0f, 104.0f, 5.0f, 50, 150, 250));  //plat5
		solidos.agregar(new Pared(120.0f, 7.5f, 114.0f, 7.50f, 50, 150, 250)); //plat6
		solidos.agregar(new Pared(170.0f, 0.75f, 165.0f, 0.75f, 50, 150, 250)); //plat7
		solidos.agregar(new Pared(179.0f, 2.0f, 173.5f, 2.0f, 150, 150, 250));  //plat8
		solidos.agregar(new Pared(187.0f, 4.0f, 180.0f, 4.0f, 50, 150, 250));  //plat9
		solidos.agregar(new Pared(181.0f, 6.75f, 176.0f, 6.75f, 50, 150, 250));  //plat10
		solidos.agregar(new Pared(173.0f, 7.50f, 167.0f, 7.50f, 50, 150, 250)); //plat11
		solidos.agregar(new Pared(165.0f, 9.0f, 161.5f, 9.0f, 150, 150, 250));  //plat12
		solidos.agregar(new Pared(171.0f, 10.50f, 166.0f, 10.50f, 50, 150, 250)); //plat13
		solidos.agregar(new Pared(180.0f, 12.0f, 173.0f, 12.0f, 50, 150, 250));	  //plat14
		solidos.agregar(new Pared(200.0f, 12.0f, 183.0f, 12.0f, 250, 150, 250));  //plat15	
		//Creamos las bolas de fuego
		solidos.agregar(new BolaFuego(12.0f, -13.0f, 5.0f, -15.0f));
		solidos.agregar(new BolaFuego(22.0f, -8.0f, 5.0f, -15.0f));
		solidos.agregar(new BolaFuego(32.0f, -2.0f, 5.0f, -15.0f));
		solidos.agregar(new BolaFuego(40.5f, -15.0f, 5.0f, -15.0f));
		//Creacion de los enemigos
		enemigos.agregar(new Babosa(36.0f, 13.0f));
		enemigos.agregar(new Babosa(56.0f, 12.0f));
		enemigos.agregar(new Bomber(57.0f, 2.5f));
		enemigos.agregar(new Bomber(156.0f, 7.0f));

		enemigos.agregar(new EnemigoDisp(97.0f, 0.0f)); //suelo6
		enemigos.agregar(new EnemigoDisp(137.0f, 7.50f)); //suelo7
		enemigos.agregar(new EnemigoDisp(150.0f, 7.50f));
		enemigos.agregar(new EnemigoDisp(168.0f, 0.75f)); //p7
		enemigos.agregar(new EnemigoDisp(170.0f, 2.5f)); //p11
		enemigos.agregar(new EnemigoDisp(176.0f, 7.5f)); //p8	
		enemigos.agregar(new EnemigoDisp(178.0f, 12.0f)); //p14

		//meter disparos en lista
		/*moviles.agregar(ped1->dispEnem1);
		moviles.agregar(ped2->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped5->dispEnem1);
		moviles.agregar(ped6->dispEnem1);
		moviles.agregar(ped7->dispEnem1);
		moviles.agregar(ped8->dispEnem1);*/

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(60.0f, 0.5f)); //suelo5
		vidas.agregar(new Corazon(107.5f, 5.5f)); //plat 5
		vidas.agregar(new Corazon(135.0f, 3.0f)); //suelo7
		vidas.agregar(new Corazon(163.0f, 9.5f)); //plat12
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidasInicial(); i++)
			vidasR.agregar(new Corazon());
		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(-2.0f, 0.5f));//suelo1
		dineros.agregar(new Moneda(0.0f, 0.5f));
		dineros.agregar(new Moneda(2.0f, 0.5f));
		dineros.agregar(new Moneda(4.0f, 0.5f));
		dineros.agregar(new Moneda(6.0f, 0.5f));
		dineros.agregar(new Moneda(12.0f, 3.0f)); //plat1
		dineros.agregar(new Moneda(16.0f, 0.5f));//suelo2
		dineros.agregar(new Moneda(26.0f, 0.5f));//suelo3
		dineros.agregar(new Moneda(36.0f, 0.5f));//suelo4
		dineros.agregar(new Moneda(44.0f, 0.5f));//suelo5
		dineros.agregar(new Moneda(46.0f, 0.5f));
		dineros.agregar(new Moneda(38.0f, 0.5f));
		dineros.agregar(new Moneda(66.0f, 3.0f));//plat2
		dineros.agregar(new Moneda(68.0f, 3.0f));
		dineros.agregar(new Moneda(70.0f, 3.0f));
		dineros.agregar(new Moneda(72.0f, 3.0f));
		dineros.agregar(new Moneda(74.0f, 3.0f));
		dineros.agregar(new Moneda(76.0f, 3.0f));
		dineros.agregar(new Moneda(84.0f, 3.0f)); //plat3
		dineros.agregar(new Moneda(86.0f, 3.0f));
		dineros.agregar(new Moneda(88.0f, 3.0f));
		dineros.agregar(new Moneda(117.0f, 8.0f));//plat6
		dineros.agregar(new Moneda(125.0f, 5.5f));//plat7
		dineros.agregar(new Moneda(127.5f, 5.5f));
		dineros.agregar(new Moneda(129.5f, 5.5f));
		dineros.agregar(new Moneda(142.5f, 0.5f));
		dineros.agregar(new Moneda(144.5f, 4.0f));
		dineros.agregar(new Moneda(146.5f, 4.0f));
		dineros.agregar(new Moneda(148.5f, 4.0f));
		dineros.agregar(new Moneda(150.5f, 4.0f));
		dineros.agregar(new Moneda(178.0f, 8.0f));//plat10
		dineros.agregar(new Moneda(169.0f, 10.5f));//plat13
		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 4)
	{
		//Agregamos los suelos
		solidos.agregar(new Pared(15.0f, 10.5f, -10.0f, 10.5f, 50, 150, 250)); //suelo1
		solidos.agregar(new Suelo(15.0f, 10.5f, -10.0f, -10.0f));
		solidos.agregar(new Pared(30.0f, 7.5f, 15.0f, 7.5f, 50, 150, 250));  //suelo2
		solidos.agregar(new Suelo(15.0f, 7.5f, 30.0f, -10.0f));
		solidos.agregar(new Pared(42.0f, 5.0f, 30.0f, 5.0f, 50, 150, 250));  //suelo3
		solidos.agregar(new Suelo(30.0f, 5.0f, 42.0f, -10.0f));
		solidos.agregar(new Pared(55.0f, 5.0f, 45.0f, 5.0f, 50, 150, 250));  //suelo3.5
		solidos.agregar(new Suelo(45.0f, 5.0f, 55.0f, -10.0f));
		solidos.agregar(new Pared(65.0f, 2.5f, 55.0f, 2.5f, 50, 150, 250));  //suelo4
		solidos.agregar(new Suelo(55.0f, 2.5f, 65.0f, -10.0f));
		solidos.agregar(new Pared(95.0f, 0.0f, 65.0f, 0.0f, 50, 150, 250));  //suelo5
		solidos.agregar(new Suelo(65.0f, 0.0f, 95.0f, -10.0f));
		solidos.agregar(new Pared(120.0f, 0.0f, 102.0f, 0.0f, 50, 150, 250));  //suelo6
		solidos.agregar(new Suelo(102.0f, 0.0f, 120.0f, -10.0f));
		solidos.agregar(new Pared(145.0f, 0.0f, 132.0f, 0.0f, 50, 150, 250));  //suelo7
		solidos.agregar(new Suelo(132.0f, 0.0f, 145.0f, -10.0f));
		solidos.agregar(new Pared(150.0f, 2.5f, 145.0f, 2.5f, 50, 150, 250)); //suelo8 
		solidos.agregar(new Suelo(145.0f, 2.5f, 150.0f, -10.0f));
		solidos.agregar(new Pared(170.0f, 5.0f, 150.0f, 5.0f, 50, 150, 250));  //suelo9
		solidos.agregar(new Suelo(150.0f, 5.0f, 170.0f, -10.0f));
		solidos.agregar(new Pared(180.0f, 2.5f, 170.0f, 2.5f, 50, 150, 250));  //suelo10
		solidos.agregar(new Suelo(170.0f, 2.5f, 180.0f, -10.0f));
		solidos.agregar(new Pared(187.0f, 0.0f, 180.0f, 0.0f, 50, 150, 250));  //suelo11
		solidos.agregar(new Suelo(180.0f, 0.0f, 187.0f, -10.0f));
		solidos.agregar(new Pared(200.0f, 0.0f, 190.0f, 0.0f, 150, 150, 250)); //suelo12 
		solidos.agregar(new Suelo(190.0f, 0.0f, 200.0f, -10.0f));
		//Agregamos las paredes de los pozos
		solidos.agregar(new Pared(15.0f, 10.5f, 15.0f, -10.0f, 5, 150, 25)); //PARED1
		solidos.agregar(new Pared(30.0f, 7.5f, 30.0f, -10.0f, 5, 150, 25));  //PARED2
		solidos.agregar(new Pared(42.0f, 5.0f, 42.0f, -10.0f, 5, 150, 25)); //PARED1*
		solidos.agregar(new Pared(45.0f, 5.0f, 45.0f, -10.0f, 5, 150, 25));  //PARED2*
		solidos.agregar(new Pared(55.0f, 5.0f, 55.0f, -10.0f, 5, 150, 25));  //PARED3
		solidos.agregar(new Pared(65.0f, 2.5f, 65.0f, -10.0f, 5, 150, 25));  //PARED4
		solidos.agregar(new Pared(145.0f, 2.5f, 145.0f, -10.0f, 5, 150, 25));  //PARED7
		solidos.agregar(new Pared(150.0f, 5.0f, 150.0f, -10.0f, 5, 150, 25)); //PARED8 
		solidos.agregar(new Pared(170.0f, 5.0f, 170.0f, -10.0f, 5, 150, 25));  //PARED9
		solidos.agregar(new Pared(180.0f, 2.5f, 180.0f, -10.0f, 5, 150, 25));  //PARED10
		solidos.agregar(new Pared(95.0f, 0.0f, 95.0f, -10.0f, 5, 150, 25));  //pozo 5_d
		solidos.agregar(new Pared(102.0f, 0.0f, 102.0f, -10.0f, 5, 150, 25));  //pozo6_i
		solidos.agregar(new Pared(120.0f, 0.0f, 120.0f, -10.0f, 5, 150, 25));  //pozo6_d
		solidos.agregar(new Pared(132.0f, 0.0f, 132.0f, -10.0f, 5, 150, 25));  //pozo7_i
		solidos.agregar(new Pared(187.0f, 0.0f, 187.0f, -10.0f, 5, 150, 25));  //pozo11_d
		solidos.agregar(new Pared(190.0f, 0.0f, 190.0f, -10.0f, 5, 150, 25)); //pozo12_i 
		//Agregamos las plataformas aéreas
		solidos.agregar(new Pared(101.0f, 2.25f, 96.0f, 2.25f, 50, 150, 250)); //plat1
		solidos.agregar(new Pared(106.0f, 5.0f, 102.5f, 5.0f, 50, 150, 250));   //plat2
		solidos.agregar(new Pared(112.0f, 6.25f, 108.0f, 6.25f, 50, 150, 250));   //plat3
		solidos.agregar(new Pared(116.0f, 7.5f, 113.0f, 7.5f, 50, 150, 250));  //plat4
		solidos.agregar(new Pared(123.0f, 5.0f, 117.0f, 5.0f, 50, 150, 250));  //plat5
		solidos.agregar(new Pared(140.0f, 7.5f, 136.0f, 7.5f, 50, 150, 250)); //plat7
		solidos.agregar(new Pared(130.0f, 2.5f, 122.0f, 2.5f, 50, 150, 250)); //plat6
		solidos.agregar(new Pared(136.0f, 10.0f, 130.0f, 10.0f, 150, 150, 250));  //plat8
		solidos.agregar(new Pared(145.0f, 5.0f, 138.0f, 5.0f, 50, 150, 250));  //plat9
		//Agregamos el resto de elementos
		solidos.agregar(new Pincho(140.0f, 5.0f));
		solidos.agregar(new Pincho(157.0f, 5.0f));
		solidos.agregar(new Pincho(163.0f, 5.0f));
		solidos.agregar(new BolaFuego(43.5f, 0.0f, 8.0f, -5.0f));
		solidos.agregar(new BolaFuego(188.5f, 0.0f, 5.0f, -5.0f));

		//Agregamos los enemigos
		enemigos.agregar(new Tentaculo(191.0f, 0.0f));
		enemigos.agregar(new Bomber(75.0f, 10.0f));
		enemigos.agregar(new Bomber(85.0f, 10.0f));
		enemigos.agregar(new EnemigoDisp(40.0f, 5.0f)); //suelo3
		enemigos.agregar(new EnemigoDisp(150.0f, 2.5f)); //suelo4
		enemigos.agregar(new EnemigoDisp(170.0f, 0.0f)); //suelo5 y AÑADIR BABOSA
		enemigos.agregar(new EnemigoDisp(110.0f, 6.25f)); //p3
		enemigos.agregar(new EnemigoDisp(132.0f, 10.5f)); //p8
		enemigos.agregar(new EnemigoDisp(124.0f, 2.5f)); //p6
		enemigos.agregar(new EnemigoDisp(160.0f, 5.0f)); //suelo9
		enemigos.agregar(new EnemigoDisp(185.0f, 0.0f)); //suelo11
		enemigos.agregar(new Tank(175.0f, 2.5f));

		//meter enemigos en sus listas
		/*moviles.agregar(ped1->dispEnem1);
		moviles.agregar(ped2->dispEnem1);
		moviles.agregar(ped3->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped5->dispEnem1);
		moviles.agregar(ped6->dispEnem1);
		moviles.agregar(ped7->dispEnem1);
		moviles.agregar(ped8->dispEnem1);
		moviles.agregar(tank1->dispTank1);
		moviles.agregar(tank1->dispTank2);
		moviles.agregar(tank1->dispTank3);
		moviles.agregar(tank1->dispTank4);
		moviles.agregar(tank1->dispTank5);*/

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(60.0f, 0.5f)); //suelo5
		vidas.agregar(new Corazon(114.5f, 8.5f)); //plat 4
		vidas.agregar(new Corazon(133.0f, 10.5f)); //suelo7
		vidas.agregar(new Corazon(160.0f, 6.0f)); //plat12
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidasInicial(); i++)
			vidasR.agregar(new Corazon());
		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(17.0f, 8.0f));  //suelo2
		dineros.agregar(new Moneda(19.0f, 8.0f));
		dineros.agregar(new Moneda(21.0f, 8.0f));
		dineros.agregar(new Moneda(23.0f, 8.0f));  //suelo2
		dineros.agregar(new Moneda(25.0f, 8.0f));
		dineros.agregar(new Moneda(27.0f, 8.0f));
		dineros.agregar(new Moneda(58.0f, 3.0f));  //suelo4
		dineros.agregar(new Moneda(63.0f, 3.0f));
		dineros.agregar(new Moneda(69.0f, 0.5f));  //suelo5
		dineros.agregar(new Moneda(73.0f, 0.5f));
		dineros.agregar(new Moneda(78.0f, 0.5f));
		dineros.agregar(new Moneda(82.0f, 0.5f));
		dineros.agregar(new Moneda(86.0f, 0.5f));
		dineros.agregar(new Moneda(91.0f, 0.5f));
		dineros.agregar(new Moneda(98.0f, 3.0f));  //plat1
		dineros.agregar(new Moneda(135.0f, 0.5f));  //suelo7
		dineros.agregar(new Moneda(137.0f, 0.5f));
		dineros.agregar(new Moneda(139.0f, 0.5f));
		dineros.agregar(new Moneda(141.0f, 0.5f));
		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 5)
	{
		//Agregamos las plataformas del inicio
		solidos.agregar(new Pared(20.0f, 5.0f, -30.0f, 5.0f, 0, 100, 0)); //Plat1
		solidos.agregar(new Pared(30.0f, 7.5f, 25.0f, 7.5f, 0, 100, 0)); //Plat2
		solidos.agregar(new Pared(38.0f, 2.5f, 30.0f, 2.5f, 0, 100, 0)); //Plat3
		//Agregamos los suelos
		solidos.agregar(new Pared(60.0f, 0.0f, 40.0f, 0.0f, 0, 100, 0)); //Suelo1
		solidos.agregar(new Suelo(40.0f, 0.0f, 60.0f, -10.0f));
		solidos.agregar(new Pared(80.0f, 0.0f, 65.0f, 0.0f, 0, 100, 0)); //suelo 2
		solidos.agregar(new Suelo(65.0f, 0.0f, 80.0f, -10.0f));
		solidos.agregar(new Pared(132.0f, 8.0f, 110.0f, 8.0f, 0, 100, 0)); //Suelo 3 (elige)
		solidos.agregar(new Suelo(110.0f, 8.0f, 132.0f, -10.0f));
		solidos.agregar(new Pared(180.0f, 18.0f, 150.0f, 18.0f, 0, 100, 0)); //Techo malo
		solidos.agregar(new Pared(180.0f, 12.0f, 150.0f, 12.0f, 0, 100, 0)); //Suelo malo
		solidos.agregar(new Suelo(150.0f, 12.0f, 180.0f, 8.0f));
		solidos.agregar(new Pared(180.0f, 8.0f, 150.0f, 8.0f, 0, 100, 0)); //Techo bueno
		solidos.agregar(new Pared(180.0f, 2.0f, 150.0f, 2.0f, 0, 100, 0)); //Suelo bueno
		solidos.agregar(new Suelo(150.0f, 2.0f, 180.0f, -10.0f));
		solidos.agregar(new Pared(200.0f, 2.0f, 195.0f, 2.0f, 0, 100, 0)); //Suelo fin
		solidos.agregar(new Suelo(195.0f, 2.0f, 200.0f, -10.0f));
		//Agregamos las paredes de los pozos
		solidos.agregar(new Pared(40.0f, 0.0f, 40.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(60.0f, 0.0f, 60.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(65.0f, 0.0f, 65.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(80.0f, 0.0f, 80.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(110.0f, 8.0f, 110.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(132.0f, 8.0f, 132.0f, -10.0f, 0, 250, 0));
		solidos.agregar(new Pared(150.0f, 20.0f, 150.0f, 18.0f, 0, 250, 0)); //Pared vertical alto
		solidos.agregar(new Pared(150.0f, 12.0f, 150.0f, 8.0f, 0, 250, 0)); //Pared vertical medio
		solidos.agregar(new Pared(150.0f, 2.0f, 150.0f, -10.0f, 0, 250, 0)); //Pared vertical bajo
		solidos.agregar(new Pared(180.0f, 20.0f, 180.0f, 18.0f, 0, 250, 0)); //Pared vertical alto
		solidos.agregar(new Pared(180.0f, 12.0f, 180.0f, 8.0f, 0, 250, 0)); //Pared vertical medio
		solidos.agregar(new Pared(180.0f, 2.0f, 180.0f, -10.0f, 0, 250, 0)); //Pared vertical bajo
		solidos.agregar(new Pared(195.0f, 2.0f, 195.0f, -10.0f, 0, 250, 0));
		//Agregamos el resto de plataformas aéreas
		solidos.agregar(new Pared(90.0f, 2.5f, 85.0f, 2.5f, 0, 100, 0)); //Plat4
		solidos.agregar(new Pared(97.0f, 5.0f, 92.0f, 5.0f, 0, 100, 0)); //Plat5
		solidos.agregar(new Pared(105.0f, 7.5f, 100.0f, 7.5f, 0, 100, 0)); //Plat6
		solidos.agregar(new PlatMovil(142.0f, 11.0f, 148.0f, 11.0f, 5.0f, 1.0f, 135.0f, 9.0f, 150.0f, 12.0f));//Arriba MAL
		solidos.agregar(new PlatMovil(142.0f, 3.0f, 148.0f, 3.0f, 5.0f, -1.0f, 135.0f, 5.0f, 150.0f, 2.0f));//Abajo BIEN
		solidos.agregar(new PlatMovil(184.0f, 2.0f, 189.0f, 2.0f, 3.0f, 0.0f, 182.0f, 2.0f, 192.0f, 2.0f));//Movil fin
		//Agregamos el resto de elementos
		solidos.agregar(new Pincho(27.5f, 7.5f));
		solidos.agregar(new Pincho(152.0f, 12.0f));
		solidos.agregar(new Pincho(154.0f, 12.0f));
		solidos.agregar(new Pincho(156.0f, 12.0f));
		solidos.agregar(new Pincho(158.0f, 12.0f));
		solidos.agregar(new Pincho(160.0f, 12.0f));
		solidos.agregar(new Pincho(162.0f, 12.0f));
		solidos.agregar(new Pincho(164.0f, 12.0f));
		solidos.agregar(new Pincho(166.0f, 12.0f));
		solidos.agregar(new Pincho(168.0f, 12.0f));
		solidos.agregar(new Pincho(170.0f, 12.0f));
		solidos.agregar(new Pincho(172.0f, 12.0f));
		solidos.agregar(new Pincho(174.0f, 12.0f));
		solidos.agregar(new Pincho(176.0f, 12.0f));
		solidos.agregar(new Pincho(178.0f, 12.0f));
		solidos.agregar(new BolaFuego(62.5f, 0.0f, 3.0f, -5.0f));
		solidos.agregar(new BolaFuego(82.5f, 0.0f, 7.0f, -5.0f));
		solidos.agregar(new BolaFuego(107.5f, 0.0f, 10.0f, -5.0f));

		//Agregamos enemigos
		enemigos.agregar(new Tentaculo(10.0f, 5.0f));
		enemigos.agregar(new Tentaculo(15.0f, 5.0f));
		enemigos.agregar(new Bomber(50.0f, 2.0f));
		enemigos.agregar(new EnemigoDisp(70.0f, 1.0f));
		enemigos.agregar(new EnemigoDisp(155.0f, 12.5f));
		enemigos.agregar(new EnemigoDisp(160.0f, 12.5f));
		enemigos.agregar(new EnemigoDisp(170.0f, 12.5f));
		enemigos.agregar(new EnemigoDisp(175.0f, 12.5f));
		enemigos.agregar(new Tank(120.0f, 8.5f));

		/*moviles.agregar(ped1->dispEnem1);
		moviles.agregar(ped2->dispEnem1);
		moviles.agregar(ped3->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped5->dispEnem1);
		moviles.agregar(tank1->dispTank1);
		moviles.agregar(tank1->dispTank2);
		moviles.agregar(tank1->dispTank3);
		moviles.agregar(tank1->dispTank4);
		moviles.agregar(tank1->dispTank5);*/

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(160.0f, 2.5f));
		vidas.agregar(new Corazon(170.0f, 2.5f));
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidasInicial(); i++)
			vidasR.agregar(new Corazon());
		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(66.0f, 0.5f));
		dineros.agregar(new Moneda(68.0f, 0.5f));
		dineros.agregar(new Moneda(70.0f, 0.5f));
		dineros.agregar(new Moneda(72.0f, 0.5f));
		dineros.agregar(new Moneda(74.0f, 0.5f));
		dineros.agregar(new Moneda(76.0f, 0.5f));
		dineros.agregar(new Moneda(78.0f, 0.5f));
		dineros.agregar(new Moneda(152.0f, 3.0f));
		dineros.agregar(new Moneda(154.0f, 3.0f));
		dineros.agregar(new Moneda(156.0f, 3.0f));
		dineros.agregar(new Moneda(158.0f, 3.0f));
		dineros.agregar(new Moneda(162.0f, 3.0f));
		dineros.agregar(new Moneda(164.0f, 3.0f));
		dineros.agregar(new Moneda(166.0f, 3.0f));
		dineros.agregar(new Moneda(168.0f, 3.0f));
		dineros.agregar(new Moneda(172.0f, 3.0f));
		dineros.agregar(new Moneda(174.0f, 3.0f));
		dineros.agregar(new Moneda(176.0f, 3.0f));
		dineros.agregar(new Moneda(178.0f, 3.0f));
		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 6)
	{
		//Agregamos los suelos
		solidos.agregar(new Pared(68.0f, 0.0f, 52.0f, 0.0f, 200, 150, 250));      //suelo1 
		solidos.agregar(new Suelo(52.0f, 7.5f, 68.0f, -10.0f));
		solidos.agregar(new Pared(82.0f, 0.0f, 71.0f, 0.0f, 200, 150, 250));      //suelo2
		solidos.agregar(new Suelo(71.0f, 7.5f, 82.0f, -10.0f));
		solidos.agregar(new Pared(200.0f, 0.0f, 180.0f, 0.0f, 200, 150, 50));     //suelo3
		solidos.agregar(new Suelo(180.0f, 7.5f, 200.0f, -10.0f));
		//Agregamos las paredes de los pozos
		solidos.agregar(new Pared(52.0f, 0.0f, 52.0f, -10.0f, 200, 150, 250));    //pozo 1 izq
		solidos.agregar(new Pared(68.0f, 0.0f, 68.0f, -10.0f, 200, 150, 250));    //pozo 1 drcha
		solidos.agregar(new Pared(71.0f, 0.0f, 71.0f, -10.0f, 200, 150, 250));    //pozo 2 izq
		solidos.agregar(new Pared(82.0f, 0.0f, 82.0f, -10.0f, 200, 150, 250));    //pozo 2 drcha
		solidos.agregar(new Pared(180.0f, 0.0f, 180.0f, -10.0f, 200, 150, 50));    //pozo 3 izq
		//Agregamos las plataformas aéreas
		solidos.agregar(new Pared(20.0f, 5.0f, -10.0f, 5.0f, 50, 150, 50));       //plat1
		solidos.agregar(new Pared(37.0f, 7.5f, 25.0f, 7.5f, 50, 150, 50));        //plat2 
		solidos.agregar(new Pared(47.0f, 2.5f, 38.0f, 2.5f, 50, 150, 50));        //plat3
		solidos.agregar(new Pared(60.0f, 5.0f, 52.0f, 5.0f, 50, 150, 50));        //plat4
		solidos.agregar(new Pared(70.0f, 7.5f, 64.0f, 7.5f, 50, 150, 50));        //plat5
		solidos.agregar(new Pared(80.0f, 10.0f, 74.0f, 10.0f, 50, 150, 50));      //plat6
		solidos.agregar(new Pared(92.0f, 2.5f, 86.0f, 2.5f, 50, 150, 50));        //plat7
		solidos.agregar(new Pared(104.0f, 5.0f, 96.0f, 5.0f, 50, 150, 50));       //plat8
		solidos.agregar(new Pared(115.0f, 7.5f, 107.0f, 7.5f, 50, 150, 50));      //plat9
		solidos.agregar(new PlatMovil(117.0f, 7.5f, 122.0f, 7.5f, 5.0f, 0.0f, 119.5f, 7.5f, 150.5f, 7.5f));
		solidos.agregar(new Pared(175.0f, 7.5f, 155.0f, 7.5f, 50, 150, 50));      //plat11
		//Agregamos el resto de elementos
		solidos.agregar(new Pincho(63.5f, 0.0f)); //suelo1
		solidos.agregar(new Pincho(76.0f, 0.0f)); //suelo2	
		solidos.agregar(new Pincho(111.0f, 7.5f)); //plat9
		solidos.agregar(new Pincho(165.0f, 7.5f)); //plat11
		solidos.agregar(new Pincho(185.0f, 0.0f)); //suelo3
		solidos.agregar(new Pincho(195.0f, 0.0f)); //suelo3
		//Agregamos las bolas de fuego 
		solidos.agregar(new BolaFuego(22.5f, -4.0f, 16.0f, -5.0f));  //entre p1 y p2
		solidos.agregar(new BolaFuego(50.0f, -3.0f, 16.0f, -5.0f)); // entre p 3 y s1
		solidos.agregar(new BolaFuego(69.5f, 0.0f, 6.5f, -5.0f));   //entre s1 y s2
		solidos.agregar(new BolaFuego(125.0f, -2.0f, 16.0f, -5.0f)); //plat movil
		solidos.agregar(new BolaFuego(150.0f, -4.0f, 16.0f, -5.0f));
		solidos.agregar(new BolaFuego(177.5f, -1.0f, 16.0f, -5.0f)); //p11

		//Agregamos los enemigos
		enemigos.agregar(new Bomber(185.0f, 2.0f));//suelo3
		enemigos.agregar(new Babosa(59.0f, 0.0f));//suelo1
		enemigos.agregar(new EnemigoDisp(12.0f, 5.0f)); //p1
		enemigos.agregar(new EnemigoDisp(43.0f, 2.5f)); //p3
		enemigos.agregar(new EnemigoDisp(63.0f, 0.0f)); //suelo1
		enemigos.agregar(new EnemigoDisp(66.0f, 7.5f)); //p5
		enemigos.agregar(new EnemigoDisp(88.0f, 2.5f)); //p7
		enemigos.agregar(new EnemigoDisp(78.0f, 0.0f)); //suelo2
		enemigos.agregar(new Tank(167.5f, 7.5f)); //suelo3

		/*moviles.agregar(ped1->dispEnem1);
		moviles.agregar(ped2->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped5->dispEnem1);
		moviles.agregar(ped6->dispEnem1);
		moviles.agregar(ped7->dispEnem1);
		moviles.agregar(tank1->dispTank1);
		moviles.agregar(tank1->dispTank2);
		moviles.agregar(tank1->dispTank3);
		moviles.agregar(tank1->dispTank4);
		moviles.agregar(tank1->dispTank5);*/

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(30.0f, 8.0f)); //plat2
		vidas.agregar(new Corazon(130.0f, 8.0f)); //plat movil 10
		vidas.agregar(new Corazon(76.0f, 10.5f)); //plat6
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidasInicial(); i++)
			vidasR.agregar(new Corazon());
		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(54.0f, 0.5f));  //suelo1
		dineros.agregar(new Moneda(56.0f, 0.5f));
		dineros.agregar(new Moneda(58.0f, 0.5f));
		dineros.agregar(new Moneda(60.0f, 0.5f));
		dineros.agregar(new Moneda(74.0f, 0.5f)); //suelo2
		dineros.agregar(new Moneda(80.0f, 0.5f));
		dineros.agregar(new Moneda(188.0f, 0.5f)); //suelo3
		dineros.agregar(new Moneda(190.0f, 0.5f));
		dineros.agregar(new Moneda(193.0f, 0.5f));
		dineros.agregar(new Moneda(28.0f, 8.0f));  //plat1
		dineros.agregar(new Moneda(30.0, 8.0f));
		dineros.agregar(new Moneda(32.0f, 8.0f));
		dineros.agregar(new Moneda(24.0f, 8.0f));
		dineros.agregar(new Moneda(67.0f, 8.0f));  // plat5
		dineros.agregar(new Moneda(88.0f, 3.0f));  //plat7
		dineros.agregar(new Moneda(98.0, 5.5f));   //plat8
		dineros.agregar(new Moneda(100.0f, 5.5f));
		dineros.agregar(new Moneda(121.0f, 8.0f));  // plat movil
		dineros.agregar(new Moneda(124.0f, 8.0f));
		dineros.agregar(new Moneda(127.0, 8.0f));
		dineros.agregar(new Moneda(133.0f, 8.0f));
		dineros.agregar(new Moneda(136.0, 8.0f));
		dineros.agregar(new Moneda(139.0f, 8.0f));
		dineros.agregar(new Moneda(142.0f, 8.0f));
		dineros.agregar(new Moneda(145.0f, 8.0f));
		dineros.agregar(new Moneda(1428.0f, 8.0f));
		dineros.agregar(new Moneda(157.0f, 8.0f)); //plat 11
		dineros.agregar(new Moneda(160.0f, 8.0f));
		dineros.agregar(new Moneda(168.0f, 8.0f));
		dineros.agregar(new Moneda(171.0f, 8.0f));
		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 7)
	{
		//Agregamos los suelos
		solidos.agregar(new Pared(23.0f, 2.5f, -10.0f, 2.5f, 200, 150, 250));  //suelo1
		solidos.agregar(new Suelo(-10.0f, 2.5f, 23.0f, -10.0f));
		solidos.agregar(new Pared(52.0f, 0.0f, 42.0f, 0.0f, 200, 150, 250));   //suelo2
		solidos.agregar(new Suelo(42.0f, 0.0f, 52.0f, -10.0f));
		solidos.agregar(new Pared(60.0f, 0.0f, 55.0f, 0.0f, 200, 150, 50));    //suelo3
		solidos.agregar(new Suelo(55.0f, 0.0f, 60.0f, -10.0f));
		solidos.agregar(new Pared(67.0f, 2.5f, 60.0f, 2.5f, 200, 150, 50));    //suelo4
		solidos.agregar(new Suelo(60.0f, 2.5f, 67.0f, -10.0f));
		//Agregamos las paredes de los pozos
		solidos.agregar(new Pared(23.0f, -10.0f, 23.0f, 2.5f, 5, 150, 25));    //pozo 1 drcha
		solidos.agregar(new Pared(42.0f, -10.0f, 42.0f, 0.0f, 5, 150, 25));    //pozo 2 izq
		solidos.agregar(new Pared(52.0f, -10.0f, 52.0f, 0.0f, 5, 150, 25));    //pozo 2 drcha
		solidos.agregar(new Pared(55.0f, -10.0f, 55.0f, 0.0f, 5, 150, 25));    //pozo 3 izq
		solidos.agregar(new Pared(60.0f, 2.5f, 60.0f, -0.01f, 5, 150, 25));    //PARED 3 
		solidos.agregar(new Pared(67.0f, -10.0f, 67.0f, 2.5f, 5, 150, 25));    //pozo 4 drcha
		//Agregamos las plataformas aéreas
		solidos.agregar(new PlatMovil(27.0f, 2.5f, 32.0f, 2.5f, 5.0f, 0.0f, 27.0f, 2.5f, 39.0f, 2.5f));//plat1
		solidos.agregar(new Pared(75.0f, 5.0f, 69.0f, 5.0f, 50, 150, 50));     //plat2
		solidos.agregar(new Pared(86.0f, 7.5f, 77.0f, 7.5f, 50, 150, 50));     //plat3
		solidos.agregar(new Pared(92.0f, 10.0f, 87.0f, 10.0f, 50, 150, 50));   //plat4
		solidos.agregar(new Pared(114.0f, 12.0f, 94.0f, 12.0f, 50, 150, 50));  //plat5
		solidos.agregar(new Pared(105.0f, 7.5f, 95.0f, 7.5f, 50, 150, 50));    //plat6
		solidos.agregar(new Pared(112.0f, 7.5f, 107.0f, 7.5f, 50, 150, 50));   //plat7
		solidos.agregar(new Pared(123.0f, 10.0f, 117.0f, 10.0f, 50, 150, 50)); //plat8
		solidos.agregar(new Pared(130.0f, 7.5f, 125.0f, 7.5f, 50, 150, 50));   //plat9
		solidos.agregar(new Pared(138.0f, 5.0f, 132.0f, 5.0f, 50, 150, 50));   //plat10
		solidos.agregar(new Pared(141.0f, 2.5f, 135.0f, 2.5f, 50, 150, 50));   //plat11
		solidos.agregar(new PlatMovil(145.0f, 2.5f, 150.0f, 2.5f, 5.0f, 0.0f, 143.0f, 2.5f, 163.0f, 2.5f));  //plat12
		solidos.agregar(new Pared(173.0f, 2.5f, 167.0f, 2.5f, 50, 150, 50));   //plat13
		solidos.agregar(new Pared(180.0f, 5.0f, 175.0f, 5.0f, 50, 150, 50));   //plat14
		solidos.agregar(new Pared(187.0f, 7.5f, 182.0f, 7.5f, 50, 150, 50));   //plat15
		solidos.agregar(new Pared(200.0f, 10.0f, 190.0f, 10.0f, 50, 150, 50)); //plat16
		//Agregamos el resto de elementos
		solidos.agregar(new Pincho(5.0f, 2.5f)); //suelo1
		solidos.agregar(new Pincho(15.0f, 2.5f));
		solidos.agregar(new Pincho(81.0f, 7.5f)); //plat3
		solidos.agregar(new Pincho(100.0f, 12.0f)); //plat5
		solidos.agregar(new Pincho(108.0f, 12.0f));
		//Agregamos las bolas de fuego 
		solidos.agregar(new BolaFuego(28.0f, 0.0f, 16.0f, -5.0f));   //p1 movil
		solidos.agregar(new BolaFuego(32.0f, -2.0f, 16.0f, -5.0f));
		solidos.agregar(new BolaFuego(36.0f, -4.0f, 16.0f, -5.0f));
		solidos.agregar(new BolaFuego(54.0f, -6.0, 16.0f, -5.0f)); //s2 y s3
		solidos.agregar(new BolaFuego(93.0f, -3.0f, 16.0f, -5.0f));  //entre p4 y p5
		solidos.agregar(new BolaFuego(115.5f, -3.0f, 16.0f, -5.0f)); // entre p5 y p8
		solidos.agregar(new BolaFuego(146.0f, -1.0f, 16.0f, -5.0f)); //p11
		solidos.agregar(new BolaFuego(188.5f, -3.0f, 16.0f, -5.0f)); //p16


		//Agregamos los enemigos
		enemigos.agregar(new EnemigoDisp(57.5f, 0.0f)); //suelo3
		enemigos.agregar(new EnemigoDisp(63.0f, 0.0f)); //suelo4
		enemigos.agregar(new EnemigoDisp(71.0f, 5.0f)); //p2
		enemigos.agregar(new EnemigoDisp(110.0f, 7.5f)); //p7
		enemigos.agregar(new EnemigoDisp(134.0f, 5.0f)); //p10
		enemigos.agregar(new EnemigoDisp(167.0f, 2.5f)); //p13
		enemigos.agregar(new EnemigoDisp(184.0f, 7.5f)); //p15
		enemigos.agregar(new EnemigoDisp(137.0f, 2.5f)); //p11
		enemigos.agregar(new EnemigoDisp(100.0f, 7.5f)); //p6
		enemigos.agregar(new Tentaculo(104.0f, 12.0f));//plat5
		enemigos.agregar(new Bomber(120.0f, 12.0f));//plat8
		enemigos.agregar(new Babosa(137.0f, 2.5f));//plat11
		enemigos.agregar(new Tank(45.0f, 0.0f)); //suelo2

		/*moviles.agregar(ped1->dispEnem1);
		moviles.agregar(ped2->dispEnem1);
		moviles.agregar(ped3->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped5->dispEnem1);
		moviles.agregar(ped6->dispEnem1);
		moviles.agregar(ped7->dispEnem1);
		moviles.agregar(ped8->dispEnem1);
		moviles.agregar(ped9->dispEnem1);
		moviles.agregar(tank1->dispTank1);
		moviles.agregar(tank1->dispTank2);
		moviles.agregar(tank1->dispTank3);
		moviles.agregar(tank1->dispTank4);
		moviles.agregar(tank1->dispTank5);
		*/

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(90.0f, 10.5f)); //plat4
		vidas.agregar(new Corazon(120.0f, 10.5f)); //plat8
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidas(); i++)
			vidasR.agregar(new Corazon());
		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(7.0f, 3.0f));  //suelo1
		dineros.agregar(new Moneda(9.0f, 3.0f));
		dineros.agregar(new Moneda(11.0f, 3.0f));
		dineros.agregar(new Moneda(13.0f, 3.0f));
		dineros.agregar(new Moneda(28.0f, 3.0f)); //plat 1 movil
		dineros.agregar(new Moneda(31.0f, 3.0f));
		dineros.agregar(new Moneda(34.0f, 3.0f));
		dineros.agregar(new Moneda(34.0f, 3.0f));
		dineros.agregar(new Moneda(57.0f, 0.5f));  //suelo3
		dineros.agregar(new Moneda(63.0f, 3.0f));  //suelo4
		dineros.agregar(new Moneda(79.0f, 8.0f)); //plat3
		dineros.agregar(new Moneda(105.5f, 13.5f)); //plat5
		dineros.agregar(new Moneda(109.5f, 13.5f));
		dineros.agregar(new Moneda(97.5f, 8.0f));//plat6
		dineros.agregar(new Moneda(100.0f, 8.0f));
		dineros.agregar(new Moneda(102.5f, 8.0f));
		dineros.agregar(new Moneda(108.5f, 8.0f));//plat7
		dineros.agregar(new Moneda(110.0f, 8.0f));
		dineros.agregar(new Moneda(127.5f, 10.5f)); //plat9
		dineros.agregar(new Moneda(137.0f, 3.0f)); //plat11
		dineros.agregar(new Moneda(139.0f, 3.0f));
		dineros.agregar(new Moneda(147.0f, 3.0f)); //plat12 movil
		dineros.agregar(new Moneda(150.0f, 3.0f));
		dineros.agregar(new Moneda(153.0f, 3.0f));
		dineros.agregar(new Moneda(156.0f, 3.0f));
		dineros.agregar(new Moneda(159.0f, 3.0f));
		dineros.agregar(new Moneda(162.0f, 3.0f));
		dineros.agregar(new Moneda(177.5f, 5.5f)); //plat14
		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 8)
	{
		//Agregamos los suelos
		solidos.agregar(new Pared(15.0f, 12.5f, -10.0f, 12.5f, 200, 150, 250));     //suelo1 
		solidos.agregar(new Suelo(-10.0f, 12.5f, 15.0f, -10.0f));
		solidos.agregar(new Pared(72.0f, 10.0f, 65.0f, 10.0f, 200, 150, 250));      //suelo2
		solidos.agregar(new Suelo(65.0f, 10.0f, 72.0f, -10.0f));
		solidos.agregar(new Pared(123.0f, 5.0f, 72.0f, 5.0f, 200, 150, 50));        //suelo3
		solidos.agregar(new Suelo(72.0f, 5.0f, 200.0f, -10.0f));
		solidos.agregar(new Pared(110.0f, 10.0f, 80.0f, 10.0f, 200, 150, 250));     //suelo4 
		solidos.agregar(new Suelo(80.0f, 10.0f, 110.0f, -10.0f));
		solidos.agregar(new Pared(110.0f, 8.0f, 80.0f, 8.0f, 200, 150, 250));       //suelo4 debajo
		solidos.agregar(new Suelo(80.0f, 8.0f, 110.0f, -10.0f));
		solidos.agregar(new Pared(133.0f, 10.0f, 123.0f, 10.0f, 200, 150, 250));    //suelo5
		solidos.agregar(new Suelo(123.0f, 10.0f, 133.0f, -10.0f));
		solidos.agregar(new Pared(153.0f, 7.5f, 138.0f, 7.5f, 200, 150, 50));       //suelo6
		solidos.agregar(new Suelo(138.0f, 7.5f, 153.0f, -10.0f));
		solidos.agregar(new Pared(178.0f, 7.5f, 158.0f, 7.5f, 200, 150, 250));      //suelo7
		solidos.agregar(new Suelo(158.0f, 7.5f, 178.0f, -10.0f));
		//Agregamos las paredes de los pozos
		solidos.agregar(new Pared(15.0f, 12.5f, 15.0f, -10.0f, 200, 150, 250));     //pozo 1 izq
		solidos.agregar(new Pared(65.0f, 10.0f, 65.0f, -10.0f, 200, 150, 250));     //pozo 2 izq
		solidos.agregar(new Pared(72.0f, 10.0f, 72.0f, -10.0f, 200, 150, 250));     //pozo 2 drcha
		solidos.agregar(new Pared(80.0f, 10.0f, 80.0f, 8.0f, 200, 150, 250));       //pozo 4 izq
		solidos.agregar(new Pared(110.0f, 10.0f, 110.0f, 8.0f, 200, 150, 50));      //pozo 4 drcha
		solidos.agregar(new Pared(123.0f, 10.0f, 123.0f, -10.0f, 200, 150, 250));   //pozo 5 izq
		solidos.agregar(new Pared(133.0f, 10.0f, 133.0f, -10.0f, 200, 150, 250));   //pozo 5 drcha
		solidos.agregar(new Pared(138.0f, 7.5f, 138.0f, -10.0f, 200, 150, 250));    //pozo 6 izq
		solidos.agregar(new Pared(153.0f, 7.5f, 153.0f, -10.0f, 200, 150, 50));     //pozo 6 drcha
		solidos.agregar(new Pared(158.0f, 7.5f, 158.0f, -10.0f, 200, 150, 250));    //pozo 7 izq
		solidos.agregar(new Pared(178.0f, 7.5f, 178.0f, -10.0f, 200, 150, 50));     //pozo 7 drcha
		//Agregamos las plataformas aéreas
		solidos.agregar(new Pared(27.0f, 15.0f, 17.0f, 15.0f, 50, 150, 50));        //plat1
		solidos.agregar(new Pared(34.0f, 12.5f, 29.0f, 12.5f, 50, 150, 50));        //plat2 
		solidos.agregar(new Pared(44.0f, 10.0f, 35.0f, 10.0f, 50, 150, 50));        //plat3
		solidos.agregar(new Pared(52.0f, 10.0f, 46.0f, 10.0f, 50, 150, 50));        //plat4
		solidos.agregar(new Pared(61.0f, 7.5f, 51.0f, 7.5f, 50, 150, 50));          //plat5
		solidos.agregar(new Pared(188.0f, 10.0f, 183.0f, 10.0f, 50, 150, 50));      //plat6
		solidos.agregar(new Pared(200.0f, 12.5f, 190.0f, 12.5f, 50, 150, 50));      //plat7
		//plataformas para salir del subterraneo
		solidos.agregar(new Pared(80.0f, 9.0f, 76.0f, 9.0f, 50, 150, 50));          //plat8
		solidos.agregar(new Pared(74.0f, 7.0f, 72.0f, 7.0f, 50, 150, 50));          //plat9
		solidos.agregar(new Pared(117.0f, 9.0f, 110.0f, 9.0f, 50, 150, 50));        //plat10
		solidos.agregar(new Pared(123.0f, 7.0f, 119.0f, 7.0f, 50, 150, 50));        //plat11
		//Agregamos el resto de elementos
		solidos.agregar(new Pincho(85.5f, 5.0f)); //suelo3
		solidos.agregar(new Pincho(95.0f, 5.0f));
		solidos.agregar(new Pincho(105.0f, 5.0f));
		solidos.agregar(new Pincho(90.0f, 10.0f)); //suelo4
		solidos.agregar(new Pincho(100.0f, 10.0f));
		solidos.agregar(new Pincho(145.5f, 7.5f)); //suelo6
		solidos.agregar(new Pincho(168.0f, 7.5f)); //suelo7
		//Agregamos las bolas de fuego 
		solidos.agregar(new BolaFuego(28.0f, -4.0f, 16.0f, -5.0f));  //entre p1 y p2
		solidos.agregar(new BolaFuego(45.0f, -2.0f, 16.0f, -5.0f));  // entre p3 y p4
		solidos.agregar(new BolaFuego(62.5f, 0.0f, 16.0f, -5.0f));    //entre p5 y s2
		solidos.agregar(new BolaFuego(135.5f, -2.0f, 16.0f, -5.0f)); //entre s5 y s6
		solidos.agregar(new BolaFuego(155.5f, -4.0f, 16.0f, -5.0f)); //entre s6 y s7
		solidos.agregar(new BolaFuego(180.5f, -1.0f, 16.0f, -5.0f)); //entre s7 y p6

		//Agregamos los enemigos
		enemigos.agregar(new Tentaculo(128.0f, 8.5f));//suelo5
		enemigos.agregar(new Babosa(10.0f, 12.5f));//suelo1
		enemigos.agregar(new EnemigoDisp(23.0f, 15.0f)); //p1
		enemigos.agregar(new EnemigoDisp(43.0f, 7.5f)); //p3
		enemigos.agregar(new EnemigoDisp(48.0f, 7.5f)); //p4
		enemigos.agregar(new EnemigoDisp(97.0f, 5.0f)); //suelo3
		enemigos.agregar(new EnemigoDisp(117.0f, 5.0f));
		enemigos.agregar(new EnemigoDisp(78.0f, 5.0f));
		enemigos.agregar(new EnemigoDisp(95.0f, 10.0f)); //suelo4
		enemigos.agregar(new EnemigoDisp(160.0f, 7.5f)); //suelo8
		enemigos.agregar(new EnemigoDisp(184.0f, 10.0f)); //p6
		enemigos.agregar(new EnemigoDisp(161.0f, 7.5f)); //suelo8
		enemigos.agregar(new EnemigoDisp(171.0f, 7.5f));
		enemigos.agregar(new Tank(140.0f, 7.5f)); //suelo6
		enemigos.agregar(new Tank(88.0f, 10.0f)); //suelo4

		/*//meter enemigos en sus listas
		moviles.agregar(ped1->dispEnem1);
		moviles.agregar(ped2->dispEnem1);
		moviles.agregar(ped3->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped5->dispEnem1);
		moviles.agregar(ped6->dispEnem1);
		moviles.agregar(ped7->dispEnem1);
		moviles.agregar(ped8->dispEnem1);
		moviles.agregar(ped10->dispEnem1);
		moviles.agregar(ped11->dispEnem1);
		moviles.agregar(ped12->dispEnem1);
		moviles.agregar(tank1->dispTank1);
		moviles.agregar(tank1->dispTank2);
		moviles.agregar(tank1->dispTank3);
		moviles.agregar(tank1->dispTank4);
		moviles.agregar(tank1->dispTank5);
		moviles.agregar(tank2->dispTank1);
		moviles.agregar(tank2->dispTank2);
		moviles.agregar(tank2->dispTank3);
		moviles.agregar(tank2->dispTank4);
		moviles.agregar(tank2->dispTank5);*/

		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(53.0f, 8.0f)); //plat5
		vidas.agregar(new Corazon(78.0f, 5.5f)); //suelo3
		vidas.agregar(new Corazon(107.0f, 10.5f)); //suelo4
		vidas.agregar(new Corazon(141.0f, 8.0f)); //suelo6
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidasInicial(); i++)
			vidasR.agregar(new Corazon());
		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(0.0f, 13.0f));  //suelo1
		dineros.agregar(new Moneda(5.0f, 13.0f));
		dineros.agregar(new Moneda(10.0f, 13.0f));
		dineros.agregar(new Moneda(23.0f, 15.5f)); //plat1
		dineros.agregar(new Moneda(31.0f, 13.0f)); //plat2
		dineros.agregar(new Moneda(39.0f, 10.5f)); //plat3
		dineros.agregar(new Moneda(49.0f, 10.5f)); //plat4
		dineros.agregar(new Moneda(56.0f, 8.0f)); //plat5
		dineros.agregar(new Moneda(87.0f, 5.5f)); //suelo3
		dineros.agregar(new Moneda(89.0f, 5.5f));
		dineros.agregar(new Moneda(91.0f, 5.5f));
		dineros.agregar(new Moneda(93.0f, 5.5f));
		dineros.agregar(new Moneda(97.0f, 5.5f));
		dineros.agregar(new Moneda(99.0f, 5.5f));
		dineros.agregar(new Moneda(101.0f, 5.5f));
		dineros.agregar(new Moneda(103.0f, 5.5f));
		dineros.agregar(new Moneda(82.0f, 10.5f)); //suelo4
		dineros.agregar(new Moneda(84.0f, 10.5f));
		dineros.agregar(new Moneda(86.0f, 10.5f));
		dineros.agregar(new Moneda(88.0f, 10.5f));
		dineros.agregar(new Moneda(124.0f, 10.5f)); //suelo5 
		dineros.agregar(new Moneda(126.0f, 10.5f));
		dineros.agregar(new Moneda(128.0f, 10.5f));
		dineros.agregar(new Moneda(130.0f, 10.5f));
		dineros.agregar(new Moneda(132.0f, 10.5f));
		dineros.agregar(new Moneda(141.0f, 8.0f)); //suelo6 
		dineros.agregar(new Moneda(143.0f, 8.0f));
		dineros.agregar(new Moneda(149.0f, 8.0f));
		dineros.agregar(new Moneda(151.0f, 8.0f));
		dineros.agregar(new Moneda(160.0f, 8.0f)); //suelo7 
		dineros.agregar(new Moneda(162.0f, 8.0f));
		dineros.agregar(new Moneda(164.0f, 8.0f));
		dineros.agregar(new Moneda(172.0f, 8.0f));
		dineros.agregar(new Moneda(174.0f, 8.0f));
		dineros.agregar(new Moneda(176.0f, 8.0f));
		dineros.agregar(new Moneda(185.0f, 10.5f));  // plat6
		dineros.agregar(new Moneda(193.0f, 13.0f));  //plat7
		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else if (nivel == 9)
	{
		//Agregamos los suelos
		solidos.agregar(new Pared(200.0f, 0.0f, -10.0f, 0.0f, 200, 150, 250)); //suelo1 de todo
		solidos.agregar(new Suelo(-10.0f, 0.0f, 200.0f, -10.0f));
		solidos.agregar(new Pared(15.0f, 9.5f, -10.0f, 9.5f, 200, 150, 250));  //suelo2
		solidos.agregar(new Suelo(-10.0f, 9.5f, 15.0f, -10.0f));
		solidos.agregar(new Pared(50.0f, 6.0f, 7.0f, 6.0f, 200, 150, 50));  //suelo3
		solidos.agregar(new Suelo(7.0f, 6.0f, 50.0f, -10.0f));
		solidos.agregar(new Pared(35.0f, 13.5f, 20.0f, 13.5f, 200, 150, 250));  //suelo4
		solidos.agregar(new Suelo(20.0f, 13.5f, 35.0f, -10.0f));
		solidos.agregar(new Pared(85.0f, 8.75f, 35.0f, 8.75f, 200, 150, 250));  //suelo5
		solidos.agregar(new Suelo(35.0f, 8.75f, 85.0f, -10.0f));
		solidos.agregar(new Pared(85.0f, 11.5f, 65.0f, 11.5f, 200, 150, 250));  //suelo6
		solidos.agregar(new Suelo(65.0f, 11.5f, 85.0f, -10.0f));
		solidos.agregar(new Pared(100.0f, 9.50f, 85.0f, 9.50f, 200, 150, 250));  //suelo7
		solidos.agregar(new Suelo(85.0f, 9.5f, 100.0f, -10.0f));
		solidos.agregar(new Pared(135.0f, 11.0f, 115.0f, 11.0f, 200, 150, 250)); //suelo8 
		solidos.agregar(new Suelo(115.0f, 11.0f, 135.0f, -10.0f));
		solidos.agregar(new Pared(170.0f, 7.0f, 139.0f, 7.0f, 200, 150, 250));  //suelo9
		solidos.agregar(new Suelo(139.0f, 7.0f, 170.0f, -10.0f));
		solidos.agregar(new Pared(200.0f, 9.5f, 160.0f, 9.5f, 200, 150, 250));  //suelo10
		solidos.agregar(new Suelo(160.0f, 9.5f, 200.0f, -10.0f));
		solidos.agregar(new Pared(147.0f, 11.0f, 135.0f, 11.0f, 200, 150, 250));  //suelo11
		solidos.agregar(new Suelo(160.0f, 11.5f, 200.0f, -10.0f));
		//Agregamos las paredes de los pozos
		solidos.agregar(new Pared(-10.0f, 20.0f, -10.0f, -10.0f, 5, 150, 25)); //PARED1 inicial
		solidos.agregar(new Pared(50.0f, 6.0f, 50.0f, -10.0f, 5, 150, 25));  //PARED3
		solidos.agregar(new Pared(35.0f, 13.5f, 35.0f, 8.73f, 5, 150, 25));  //PARED4
		solidos.agregar(new Pared(85.0f, 11.5f, 85.0f, 8.73f, 5, 150, 25));  //PARED5 y 6
		solidos.agregar(new Pared(100.0f, 9.5f, 100.0f, -10.0f, 5, 150, 25)); //PARED7 
		solidos.agregar(new Pared(135.0f, 20.0f, 135.0f, 10.99f, 5, 150, 25));  //PARED8
		//Agregamos las plataformas aéreas
		solidos.agregar(new Pared(20.0f, 11.75f, 15.0f, 11.75f, 50, 150, 50)); //plat1
		solidos.agregar(new Pared(7.0f, 2.5f, 0.0f, 2.5f, 50, 150, 50)); //plat2 para subir 
		solidos.agregar(new Pared(68.0f, 2.5f, 63.0f, 2.5f, 50, 150, 50)); //plat7
		solidos.agregar(new Pared(85.0f, 4.5f, 75.0f, 4.5f, 50, 150, 50)); //plat8
		solidos.agregar(new Pared(108.0f, 10.25f, 103.0f, 10.25f, 50, 150, 50));  //plat10
		solidos.agregar(new Pared(122.0f, 2.5f, 117.0f, 2.5f, 50, 150, 50));  //plat11
		solidos.agregar(new Pared(128.0f, 5.0f, 124.0f, 5.0f, 50, 150, 50));  //plat12
		solidos.agregar(new Pared(135.0f, 7.0f, 130.0f, 7.0f, 50, 150, 50)); //plat13
		solidos.agregar(new Pared(185.0f, 2.5f, 178.0f, 2.5f, 50, 150, 50)); //plat14
		solidos.agregar(new Pared(180.0f, 5.0f, 170.0f, 5.0f, 50, 150, 50));  //plat15
		solidos.agregar(new Pared(165.0f, 9.5f, 160.0f, 9.5f, 50, 150, 50));  //plat16
		//Agregamos el resto de elementos
		solidos.agregar(new Pincho(68.5f, 0.0f)); //suelo1
		solidos.agregar(new Pincho(25.0f, 13.5f)); //suelo4
		solidos.agregar(new Pincho(30.0f, 13.5f)); //suelo4
		solidos.agregar(new Pincho(125.0f, 11.0f)); //suelo8
		solidos.agregar(new Pincho(130.0f, 11.0f)); //suelo8
		solidos.agregar(new Pincho(157.0f, 0.0f)); //suelo1
		solidos.agregar(new Pincho(120.0f, 0.0f)); //suelo1
		solidos.agregar(new Pincho(175.0f, 9.5f)); //suelo10

		//Agregamos los enemigos
		enemigos.agregar(new EnemigoDisp(20.0f, 2.0f)); //p2
		enemigos.agregar(new EnemigoDisp(30.0f, 2.0f)); //p4
		enemigos.agregar(new EnemigoDisp(75.0f, 11.5f)); //suelo6
		enemigos.agregar(new EnemigoDisp(132.0f, 11.0f)); //suelo8
		enemigos.agregar(new EnemigoDisp(126.0f, 5.0f)); //p12
		enemigos.agregar(new EnemigoDisp(120.0f, 0.0f)); //suelo1
		enemigos.agregar(new EnemigoDisp(145.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(170.0f, 0.0f));
		enemigos.agregar(new EnemigoDisp(142.0f, 7.0f)); //suelo9
		enemigos.agregar(new EnemigoDisp(175.0f, 5.0f)); //p15
		enemigos.agregar(new EnemigoDisp(140.0f, 11.0f)); //suelo11
		enemigos.agregar(new Tentaculo(162.5f, 9.5f));//plat16
		enemigos.agregar(new Tentaculo(110.0f, 0.0f));//plat16
		enemigos.agregar(new Bomber(23.0f, 6.0f));//suelo3
		enemigos.agregar(new Bomber(185.0f, 0.0f));//suelo1
		enemigos.agregar(new Babosa(35.0f, 0.0f));//suelo1
		enemigos.agregar(new Babosa(190.0f, 0.0f));//suelo1
		enemigos.agregar(new Tank(45.0f, 9.5f)); //suelo3

		/*
			//* tank3 = new Tank(195.0f, 0.0f); este me da problema asi que vamos viendo
			//bossFinal* boss = new bossFinal(111.0f, 8.5f);
		//meter enemigos en sus listas

		//moviles.agregar(tank3);
		moviles.agregar(ped1->dispEnem1);
		moviles.agregar(ped2->dispEnem1);
		moviles.agregar(ped4->dispEnem1);
		moviles.agregar(ped5->dispEnem1);
		moviles.agregar(ped6->dispEnem1);
		moviles.agregar(ped7->dispEnem1);
		moviles.agregar(ped8->dispEnem1);
		moviles.agregar(ped9->dispEnem1);
		moviles.agregar(ped10->dispEnem1);
		moviles.agregar(ped11->dispEnem1);
		moviles.agregar(ped12->dispEnem1);
		moviles.agregar(tank1->dispTank1);
		moviles.agregar(tank1->dispTank2);
		moviles.agregar(tank1->dispTank3);
		moviles.agregar(tank1->dispTank4);
		moviles.agregar(tank1->dispTank5);
		disparos.agregar(tank3->dispTank1);
		disparos.agregar(tank3->dispTank2);
		disparos.agregar(tank3->dispTank3);
		disparos.agregar(tank3->dispTank4);
		disparos.agregar(tank3->dispTank5);
		*/
		//Creaccion de Vidas Recolectables (Posicion x, Posicion y)
		vidas.agregar(new Corazon(47.0f, 1.0f)); //suelo1
		vidas.agregar(new Corazon(80.5f, 9.75f)); //suelo5
		vidas.agregar(new Corazon(133.0f, 12.0f)); //suelo8
		vidas.agregar(new Corazon(155.0f, 8.0f)); //suelo9
		vidas.agregar(new Corazon(167.0f, 10.5f)); //suelo10
		vidas.agregar(new Corazon(137.0f, 12.0f)); //suelo11
		//Creaccion de las Vidas del Pj
		for (int i = 0; i < vidasR.getVidasInicial(); i++)
			vidasR.agregar(new Corazon());
		//Creaccion de Monedas Recolectables
		dineros.agregar(new Moneda(17.0f, 6.5f));  //suelo3
		dineros.agregar(new Moneda(19.0f, 6.5f));
		dineros.agregar(new Moneda(21.0f, 6.5f));
		dineros.agregar(new Moneda(23.0f, 6.5f));
		dineros.agregar(new Moneda(25.0f, 6.5f));
		dineros.agregar(new Moneda(22.50f, 14.0f)); //suelo4
		dineros.agregar(new Moneda(27.5f, 14.0f));
		dineros.agregar(new Moneda(32.5f, 14.0f));
		dineros.agregar(new Moneda(80.0f, 0.5f)); //suelo5
		dineros.agregar(new Moneda(82.0f, 14.0f));
		dineros.agregar(new Moneda(84.0f, 14.0f));
		dineros.agregar(new Moneda(5.0f, 0.5f));  //suelo1
		dineros.agregar(new Moneda(10.0f, 0.5f));
		dineros.agregar(new Moneda(15.0f, 0.5f));
		dineros.agregar(new Moneda(20.0f, 0.5f));
		dineros.agregar(new Moneda(25.0f, 0.5f));
		dineros.agregar(new Moneda(30.0f, 0.5f));
		dineros.agregar(new Moneda(35.0f, 0.5f));
		dineros.agregar(new Moneda(40.0f, 0.5f));
		dineros.agregar(new Moneda(45.0f, 0.5f));
		dineros.agregar(new Moneda(190.0f, 0.5f));
		dineros.agregar(new Moneda(192.0f, 0.5f));
		dineros.agregar(new Moneda(194.0f, 0.5f));
		dineros.agregar(new Moneda(141.0f, 0.5f));
		//Creaccion de Monedas del Pj
		dinerosR.agregar(new Moneda(8.0f, 14.0f));
		return true;
	}
	else return false;
}

void Nivel::teclaUp(unsigned char key)
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

void Nivel::teclaDown(unsigned char key)
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
	case 'z':
		hombre.setColor(1, 0, 0);
	case ' ':
		DisparosAmigos * dispam = new DisparosAmigos(hombre.getPos().x, hombre.getPos().y + 1.8f * 2 / 3, hombre.velocidad.x, 0);
		if (disparos.agregar(dispam))
			hombre.setVel(0,hombre.velocidad.y);
		else delete dispam;
		break;
		/*default:
			hombre.setVelx(0.0f);
			hombre.salto = 1;
			break;*/
	
	}
}

void Nivel::teclaEspecial(unsigned char key)
{
	/*
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
	}*/
}
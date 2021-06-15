#pragma once
#include "Hombre.h"
#include "disparosAmigos.h"
#include "listaDispAmig.h"
#include "espada.h"
#include "Caja.h"
#include "listaPlat.h"
#include "Bonus.h"
#include "listaBonus.h"
#include "Pincho.h"
#include "listaPinchos.h"
#include "EnemigoDisp.h"
#include "listaEnemDisp.h"
#include "Tank.h"
#include "listaTank.h"
#include "Tentaculo.h"
#include "listaTent.h"
#include "babosa.h"
#include "listaBabosas.h"
#include "bomber.h"
#include "listabomber.h"
#include "bossFinal.h"
#include "misil.h"
#include "listamisiles.h"
#include "Vidas.h"
#include "VidasRec.h"
#include "Dinero.h"
#include "BolaFuego.h"
#include "PlatMovil.h"

class Interaccion
{
public:
	//PJ con entorno
	static void rebote(Hombre& h, Caja c);
	static void rebote(Hombre& h, Pared p);
	static void rebote(Hombre& h, PlatMovil pm);
	static void rebote(Hombre& h, listaPlat lp); 

	//Pj con Corazones
	static void rebote(Corazon& v, Pared p);
	static void rebote(Corazon& v, Caja c);
	static bool recoleccion(Corazon& v,Hombre h);

	//Pj con Monedas
	static void rebote(Moneda& v, Pared p);
	static void rebote(Moneda& v, Caja c);
	static bool recoleccion(Moneda& v, Hombre h);

	//Enemigos con entorno
	static void rebote(EnemigoDisp& ene, Caja c);
	static void rebote(EnemigoDisp& ene, Pared p);
	static void rebote(Tank& t, Caja c);
	static void rebote(Tank& t, Pared p);
	static void rebote(bomber& b, Caja c);
	static void rebote(bomber& b, Pared p);
	static void rebote(bossFinal& b, Caja c);
	static void rebote(bossFinal& b, Pared p);
	static void rebote(bossFinal& b, listaPlat lp);

	//Disparos con entorno
	static void rebote(DisparosEnemigos& ene, Caja c);
	static void rebote(DisparosEnemigos& ene, Pared p);
	static void rebote(disparosAmigos& ene, Caja c);
	static void rebote(disparosAmigos& ene, Pared p);
	static void rebote(misil& ene, Caja c);
	static void rebote(misil& ene, Pared p);

	//Interacci�n entre Pj y enemigos
	static void rebote(Hombre& h, EnemigoDisp e, VidasRec& v); 
	static void rebote(EnemigoDisp&, EnemigoDisp&);
	static void mov(Babosa& b, Hombre& h);
	static void mov(Hombre& h, misil& m);
	static void rebote(Hombre& h, listaEnemDisp l,VidasRec& v);

	static void colision(Hombre& h, Bonus& b);	//:c
	static void colision(Hombre& h, Pincho p);	

	static void colision(Hombre& h, DisparosEnemigos& de);
	static void colision(Hombre& h, misil& m);
	static void colision(Hombre& h, Babosa& ene);	
	static void colision(Hombre& h, bomber& ene);	
	static void colision(Hombre& h, Tentaculo& ene);

	static void colision(EnemigoDisp& ene, disparosAmigos& da);
	static void colision(Tank& ene, disparosAmigos& da);
	static void colision(Babosa& ene, disparosAmigos& da);
	static void colision(Tentaculo& ene, disparosAmigos& da);	//:c
	static void colision(bomber& ene, disparosAmigos& da);
	static void colision(bossFinal& ene, disparosAmigos& da);

	static void colision(listaEnemDisp ene, listaDispAmig da);
	static void colision(listaTank ene, listaDispAmig da);
	static void colision(listaBabosas ene, listaDispAmig da);
	static void colision(listaTentaculo ene, listaDispAmig da);
	static void colision(listabomber ene, listaDispAmig da);
	static void colision(bossFinal ene, listaDispAmig da);
	//colision con bola fuego
	//static void colision(Hombre& h, BolaFuego bola);???
	static void colision(Hombre& h, BolaFuego& b);
	//espada
	static void mov(espada& esp, Hombre& h);
	static void colision(listaEnemDisp ene, espada esp);
	static void colision(listaTank ene, espada esp);
	static void colision(listaBabosas ene, espada esp);
	static void colision(listaTentaculo ene, espada esp);
	static void colision(listabomber ene, espada esp);

	static void colision(EnemigoDisp& ene, espada& esp);
	static void colision(Tank& ene, espada& esp);
	static void colision(Babosa& ene, espada& esp);
	static void colision(Tentaculo& ene, espada& esp);
	static void colision(bomber& ene, espada& esp);
	static void colision(bossFinal& ene, espada& esp);
};


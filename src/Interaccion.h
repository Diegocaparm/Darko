#pragma once
#include "Solidos.h"
#include "ListaSolidos.h"
#include "Caja.h"
#include "Personaje.h"
#include "Recolectable.h"
#include "ListaEnemigos.h"

class Interaccion
{
public:
	//PJ con entorno
	static void rebote(Personaje& h, Solidos s, VidasRecolectadas &v);
	static void rebote(Personaje& h, Pared p, VidasRecolectadas& v);
	static void rebote(Personaje& h, PlatMovil pm, VidasRecolectadas& v);
	static void rebote(Personaje& h, Suelo s, VidasRecolectadas& v);
	static void rebote(Personaje& h, Pincho p, VidasRecolectadas& v);
	static void rebote(Personaje& h, Caja c, VidasRecolectadas& v);

	//Recolectables con el PJ
	static bool recoleccion(Corazon& c, Personaje h);
	static bool recoleccion(Moneda& m, Personaje h);

	//Enemigos con entorno
	void enemrebote(Enemigo& e, Solidos s);
	void enemrebote(Enemigo& e, Pared p);
	void enemrebote(Enemigo& e, PlatMovil pm);
	void enemrebote(Enemigo& e, Suelo s);
	void enemrebote(Enemigo& e, Pincho p);
	void enemrebote(Enemigo& e, Caja c);

	void enemrebote(EnemigoDisp& e, Solidos s);
	void enemrebote(EnemigoDisp& e, Pared p);
	void enemrebote(EnemigoDisp& e, PlatMovil pm);
	void enemrebote(EnemigoDisp& e, Suelo s);
	void enemrebote(EnemigoDisp& e, Pincho p);
	void enemrebote(EnemigoDisp& e, Caja c);

	void enemrebote(Babosa& b, Solidos s);
	void enemrebote(Babosa& b, Pared p);
	void enemrebote(Babosa& b, PlatMovil pm);
	void enemrebote(Babosa& b, Suelo s);
	void enemrebote(Babosa& b, Pincho p);
	void enemrebote(Babosa& b, Caja c);

	void enemrebote(Bomber& b, Solidos s);
	void enemrebote(Bomber& b, Pared p);
	void enemrebote(Bomber& b, PlatMovil pm);
	void enemrebote(Bomber& b, Suelo s);
	void enemrebote(Bomber& b, Pincho p);
	void enemrebote(Bomber& b, Caja c);

	void enemrebote(Tentaculo& t, Solidos s);
	void enemrebote(Tentaculo& t, Pared p);
	void enemrebote(Tentaculo& t, PlatMovil pm);
	void enemrebote(Tentaculo& t, Suelo s);
	void enemrebote(Tentaculo& t, Pincho p);
	void enemrebote(Tentaculo& t, Caja c);

	void enemrebote(Tank& t, Solidos s);
	void enemrebote(Tank& t, Pared p);
	void enemrebote(Tank& t, PlatMovil pm);
	void enemrebote(Tank& t, Suelo s);
	void enemrebote(Tank& t, Pincho p);
	void enemrebote(Tank& t, Caja c);

	void enemrebote(BossFinal& bf, Solidos s);
	void enemrebote(BossFinal& bf, Pared p);
	void enemrebote(BossFinal& bf, PlatMovil pm);
	void enemrebote(BossFinal& bf, Suelo s);
	void enemrebote(BossFinal& bf, Pincho p);
	void enemrebote(BossFinal& bf, Caja c);


	/*

	//Disparos con entorno
	static void rebote(DisparosEnemigos& ene, Caja c);
	static void rebote(DisparosEnemigos& ene, Pared p);
	static void rebote(disparosAmigos& ene, Caja c);
	static void rebote(disparosAmigos& ene, Pared p);
	static void rebote(misil& ene, Caja c);
	static void rebote(misil& ene, Pared p);*/

	//Interacción entre Pj y enemigos
	//static void rebote(Hombre& h, EnemigoDisp e, VidasRec& v); 
	//static void rebote(EnemigoDisp&, EnemigoDisp&);
	//static void mov(Babosa& b, Hombre& h, VidasRec &v);
	/*static void mov(Hombre& h, misil& m, VidasRec& v);
	static void rebote(Hombre& h, listaEnemDisp l,VidasRec& v);

	static void colision(Hombre& h, Bonus& b);	//:c
	static void colision(Hombre& h, Pincho p, VidasRec& v);

	static void colision(Hombre& h, DisparosEnemigos& de, VidasRec& v);
	static void colision(Hombre& h, misil& m, VidasRec& v);
	static void colision(Hombre& h, Babosa& ene, VidasRec& v);
	static void colision(Hombre& h, bomber& ene, VidasRec& v);
	static void colision(Hombre& h, Tentaculo& ene, VidasRec& v);

	static bool colision(EnemigoDisp& ene, disparosAmigos& da);
	static bool colision(Tank& ene, disparosAmigos& da);
	static bool colision(Babosa& ene, disparosAmigos& da);
	static bool colision(Tentaculo& ene, disparosAmigos& da);	
	static bool colision(bomber& ene, disparosAmigos& da);
	static bool colision(bossFinal& ene, disparosAmigos& da);

	static void colision(listaEnemDisp ene, listaDispAmig da);
	static void colision(listaTank ene, listaDispAmig da);
	static void colision(listaBabosas ene, listaDispAmig da);
	static void colision(listaTentaculo ene, listaDispAmig da);
	static void colision(listabomber ene, listaDispAmig da);
	static void colision(bossFinal ene, listaDispAmig da);
	//colision con bola fuego
	//static void colision(Hombre& h, BolaFuego bola);???
	static void colision(Hombre& h, BolaFuego& b);*/
	//espada
	/*
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
	static void colision(bossFinal& ene, espada& esp);*/
};


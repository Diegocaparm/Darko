#pragma once
#include "Solidos.h"
#include "ListaSolidos.h"
#include "Caja.h"
#include "Personaje.h"
#include "Recolectable.h"
//#include "ListaEnemigos.h"
#include "listas.h"


class Interaccion
{
public:
	//buscar sitio para esto
	static void rebote(listaObjetoMovil, ListaSolidos);
	static void rebote(ObjetoMovil, Solidos);
	void rebote(ObjetoMovil&, Caja);
	void rebote(Disparos&, Pared);
	static void mov(espada& esp, Personaje& h);
	static void rebote(Personaje&, listaObjetoMovil, VidasRecolectadas&);
	static void colision(Personaje& h, ObjetoMovil& om, VidasRecolectadas& v);
	void colision(Personaje& h, disparosEnemigos& de, VidasRecolectadas& v);
	void colision(Personaje& h, misiles& m, VidasRecolectadas& v);
	static void colision(Personaje&, Enemigo&, VidasRecolectadas&);
	void mov(Personaje&, Babosa&, VidasRecolectadas&);
	void colision(Personaje&, Tentaculo&, VidasRecolectadas&);//arreglar
	void colision(Personaje& h, Bomber& ene, VidasRecolectadas& v);
	static void rebote(listaObjetoMovil, listaObjetoMovil);
	static void rebote(ObjetoMovil, ObjetoMovil);
	void rebote(Enemigo, disparosAmigos);
	static void colision(listaObjetoMovil, espada);
	static void colision(ObjetoMovil, espada);
	void colision(Enemigo, espada);


	//PJ con entorno
	static void rebote(Personaje& h, ListaSolidos ls, VidasRecolectadas& v);
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
	void rebote(Enemigo& e, Solidos s);
	void rebote(Enemigo& e, Pared p);
	void rebote(Enemigo& e, PlatMovil pm);
	void rebote(Enemigo& e, Suelo s);
	void rebote(Enemigo& e, Pincho p);
	//void rebote(Enemigo& e, Caja c);

	void rebote(EnemigoDisp& e, Solidos s);
	//void rebote(EnemigoDisp& e, Pared p);
	void rebote(EnemigoDisp& e, PlatMovil pm);
	void rebote(EnemigoDisp& e, Suelo s);
	void rebote(EnemigoDisp& e, Pincho p);
	//void rebote(EnemigoDisp& e, Caja c);

	void rebote(Babosa& b, Solidos s);
	void rebote(Babosa& b, Pared p);
	void rebote(Babosa& b, PlatMovil pm);
	void rebote(Babosa& b, Suelo s);
	void rebote(Babosa& b, Pincho p);
	//void rebote(Babosa& b, Caja c);

	void rebote(Bomber& b, Solidos s);
	//void rebote(Bomber& b, Pared p);
	void rebote(Bomber& b, PlatMovil pm);
	void rebote(Bomber& b, Suelo s);
	void rebote(Bomber& b, Pincho p);
	//void rebote(Bomber& b, Caja c);

	void rebote(Tentaculo& t, Solidos s);
	void rebote(Tentaculo& t, Pared p);
	void rebote(Tentaculo& t, PlatMovil pm);
	void rebote(Tentaculo& t, Suelo s);
	void rebote(Tentaculo& t, Pincho p);
	//void rebote(Tentaculo& t, Caja c);

	void rebote(Tank& t, Solidos s);
	//void rebote(Tank& t, Pared p);
	void rebote(Tank& t, PlatMovil pm);
	void rebote(Tank& t, Suelo s);
	void rebote(Tank& t, Pincho p);
	//void rebote(Tank& t, Caja c);

	void rebote(BossFinal& bf, Solidos s);
	//void rebote(BossFinal& bf, Pared p);
	void rebote(BossFinal& bf, PlatMovil pm);
	void rebote(BossFinal& bf, Suelo s);
	void rebote(BossFinal& bf, Pincho p);
	//void rebote(BossFinal& bf, Caja c);


	//Disparos con entorno
	//void rebote(disparosEnemigos& ene, Caja c);
	//void rebote(disparosEnemigos& ene, Pared p);
	//void rebote(disparosAmigos& ene, Caja c);
	//void rebote(disparosAmigos& ene, Pared p);
	//void rebote(misiles& ene, Caja c);
	//void rebote(misiles& ene, Pared p);

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


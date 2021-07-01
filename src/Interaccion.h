#pragma once
#include "Solidos.h"
#include "ListaSolidos.h"
#include "Caja.h"
#include "Personaje.h"
#include "Recolectable.h"
#include "ListaEnemigos.h"
#include "Disparos.h"
#include "ListaDisparos.h"


class Interaccion
{
public:
	//////////////////////////////////////////////////////////////////// PJ
	//Entorno
	static void rebote(Personaje& h, ListaSolidos ls, VidasRecolectadas& v);
	static void rebote(Personaje& h, Solidos s, VidasRecolectadas &v);
	static void rebote(Personaje& h, Pared p, VidasRecolectadas& v);
	static void rebote(Personaje& h, PlatMovil pm, VidasRecolectadas& v);
	static void rebote(Personaje& h, Suelo s, VidasRecolectadas& v);
	static void rebote(Personaje& h, Pincho p, VidasRecolectadas& v);
	static void rebote(Personaje& h, BolaFuego b, VidasRecolectadas& v);
	static void rebote(Personaje& h, Caja c, VidasRecolectadas& v);
	//Recolectables
	static bool recoleccion(Corazon& c, Personaje h);
	static bool recoleccion(Moneda& m, Personaje h);
	//Espada y disparos buenos
	static void mov(Espada& esp, Personaje& h);
	//si eso un metodo dispara flambeante pero por ahora vacio
	//Disparos malos y misiles
	void colision(Personaje& h, ListaDisparos ld, VidasRecolectadas& v);
	void colision(Personaje& h, Disparos& d, VidasRecolectadas& v);
	void colision(Personaje& h, DisparosEnemigos& de, VidasRecolectadas& v);
	void colision(Personaje& h, Misiles& m, VidasRecolectadas& v);
	//Enemigos y listas
	void colision(Personaje& h, ListaEnemigos le, VidasRecolectadas& v);
	void colision(Personaje& h, Enemigo& e, VidasRecolectadas& v);
	void colision(Personaje& h, EnemigoDisp& e, VidasRecolectadas& v);
	void colision(Personaje& h, Babosa& b, VidasRecolectadas&);
	void colision(Personaje& h, Bomber& b, VidasRecolectadas& v);
	void colision(Personaje& h, Tentaculo& t, VidasRecolectadas&);//arreglar
	void colision(Personaje& h, Tank& t, VidasRecolectadas& v);
	void colision(Personaje& h, BossFinal& b, VidasRecolectadas& v);
	////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////// Enemigos
	//Entorno
	void rebote(ListaEnemigos le, ListaSolidos ls);
	void rebote(Enemigo& e, Solidos s);
	void rebote(Enemigo& e, Pared p);
	void rebote(Enemigo& e, PlatMovil pm);
	void rebote(Enemigo& e, Suelo s);
	void rebote(Enemigo& e, Pincho p);
	void rebote(Enemigo& e, BolaFuego b);
	//void rebote(Enemigo& e, Caja c);
	void rebote(EnemigoDisp& e, Solidos s);
	//void rebote(EnemigoDisp& e, Pared p);
	void rebote(EnemigoDisp& e, PlatMovil pm);
	void rebote(EnemigoDisp& e, Suelo s);
	void rebote(EnemigoDisp& e, Pincho p);
	void rebote(EnemigoDisp& e, BolaFuego p);
	//void rebote(EnemigoDisp& e, Caja c);
	void rebote(Babosa& b, Solidos s);
	void rebote(Babosa& b, Pared p);
	void rebote(Babosa& b, PlatMovil pm);
	void rebote(Babosa& b, Suelo s);
	void rebote(Babosa& b, Pincho p);
	void rebote(Babosa& b, BolaFuego p);
	//void rebote(Babosa& b, Caja c);
	void rebote(Bomber& b, Solidos s);
	//void rebote(Bomber& b, Pared p);
	void rebote(Bomber& b, PlatMovil pm);
	void rebote(Bomber& b, Suelo s);
	void rebote(Bomber& b, Pincho p);
	void rebote(Bomber& b, BolaFuego p);
	//void rebote(Bomber& b, Caja c);
	void rebote(Tentaculo& t, Solidos s);
	void rebote(Tentaculo& t, Pared p);
	void rebote(Tentaculo& t, PlatMovil pm);
	void rebote(Tentaculo& t, Suelo s);
	void rebote(Tentaculo& t, Pincho p);
	void rebote(Tentaculo& t, BolaFuego p);
	//void rebote(Tentaculo& t, Caja c);
	void rebote(Tank& t, Solidos s);
	//void rebote(Tank& t, Pared p);
	void rebote(Tank& t, PlatMovil pm);
	void rebote(Tank& t, Suelo s);
	void rebote(Tank& t, Pincho p);
	void rebote(Tank& t, BolaFuego p);
	//void rebote(Tank& t, Caja c);
	void rebote(BossFinal& bf, Solidos s);
	//void rebote(BossFinal& bf, Pared p);
	void rebote(BossFinal& bf, PlatMovil pm);
	void rebote(BossFinal& bf, Suelo s);
	void rebote(BossFinal& bf, Pincho p);
	void rebote(BossFinal& bf, BolaFuego p);
	//void rebote(BossFinal& bf, Caja c);
	//Espada y disparos buenos
	void colision(Espada esp, ListaEnemigos le);
	void colision(Espada esp, Enemigo e);
	void colision(Espada esp, EnemigoDisp e);
	void colision(Espada esp, Babosa b);
	void colision(Espada esp, Bomber b);
	void colision(Espada esp, Tentaculo t);
	void colision(Espada esp, Tank t);
	void colision(Espada esp, BossFinal b);
	void colision(ListaDisparos ld, ListaEnemigos le);
	void colision(Disparos d, Enemigo e);
	void colision(Disparos d, EnemigoDisp e);
	void colision(Disparos d, Babosa b);
	void colision(Disparos d, Bomber b);
	void colision(Disparos d, Tentaculo t);
	void colision(Disparos d, Tank t);
	void colision(Disparos d, BossFinal b);
	void colision(DisparosAmigos d, Enemigo e);
	void colision(DisparosAmigos d, EnemigoDisp e);
	void colision(DisparosAmigos d, Babosa b);
	void colision(DisparosAmigos d, Bomber b);
	void colision(DisparosAmigos d, Tentaculo t);
	void colision(DisparosAmigos d, Tank t);
	void colision(DisparosAmigos d, BossFinal b);
	////////////////////////////////////////////////////////////////////

	




	//buscar sitio para esto
	//static void rebote(listaObjetoMovil, ListaSolidos);
	static void rebote(ObjetoMovil, Solidos);
	void rebote(ObjetoMovil&, Caja);
	void rebote(Disparos&, Pared);

	//static void rebote(Personaje&, listaObjetoMovil, VidasRecolectadas&);
	//static void colision(Personaje& h, ObjetoMovil& om, VidasRecolectadas& v);

	//static void rebote(listaObjetoMovil, listaObjetoMovil);
	static void rebote(ObjetoMovil, ObjetoMovil);

	//static void colision(listaObjetoMovil, Espada);
	static void colision(ObjetoMovil, Espada);



	//Disparos con entorno
	//void rebote(disparosEnemigos& ene, Caja c);
	//void rebote(disparosEnemigos& ene, Pared p);
	//void rebote(disparosAmigos& ene, Caja c);
	//void rebote(disparosAmigos& ene, Pared p);
	//void rebote(misiles& ene, Caja c);
	//void rebote(misiles& ene, Pared p);
/*


	static void colision(Hombre& h, DisparosEnemigos& de, VidasRec& v);
	static void colision(Hombre& h, misil& m, VidasRec& v);

	static bool colision(EnemigoDisp& ene, disparosAmigos& da);
	static bool colision(Tank& ene, disparosAmigos& da);
	static bool colision(Babosa& ene, disparosAmigos& da);
	static bool colision(Tentaculo& ene, disparosAmigos& da);	
	static bool colision(bomber& ene, disparosAmigos& da);
	static bool colision(bossFinal& ene, disparosAmigos& da);

	*/
};
	
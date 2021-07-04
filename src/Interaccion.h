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
	static bool ColisionGen(Hitbox& ene, Hitbox& h, VidasRecolectadas& v);
	//////////////////////////////////////////////////////////////////// PJ
	//Entorno
	static void rebote(Personaje& h, ListaSolidos ls, VidasRecolectadas& v);
	static void rebote(Personaje& h, Solidos* s, VidasRecolectadas &v);
	static void rebote(Personaje& h, Pared* p, VidasRecolectadas& v);
	static void rebote(Personaje& h, PlatMovil* pm, VidasRecolectadas& v);
	static void rebote(Personaje& h, Suelo* s, VidasRecolectadas& v);
	static void rebote(Personaje& h, Final* f, VidasRecolectadas& v);
	static void rebote(Personaje& h, Pincho* p, VidasRecolectadas& v);
	static void rebote(Personaje& h, BolaFuego* b, VidasRecolectadas& v);
	static void rebote(Personaje& h, Caja c, VidasRecolectadas& v);
	//Recolectables
	static bool recoleccion(Corazon& c, Personaje h);
	static Corazon* recoleccion(Vidas& v, Personaje h);
	static bool recoleccion(Moneda& m, Personaje h);
	static Moneda* recoleccion(Dinero& d, Personaje h);
	//Espada y disparos buenos
	static void mov(Espada& esp, Personaje& h);
	//si eso un metodo dispara flambeante pero por ahora vacio
	//Disparos malos y misiles
	static void colision(Personaje& h, ListaDisparos ld, VidasRecolectadas& v);
	static void colision(Personaje& h, Disparos& d, VidasRecolectadas& v);
	static void colision(Personaje& h, DisparosEnemigos& de, VidasRecolectadas& v);
	static void colision(Personaje& h, Misiles& m, VidasRecolectadas& v);
	//Enemigos y listas
	static void colision(Personaje& h, ListaEnemigos le, VidasRecolectadas& v);
	static void colision(Personaje& h, Enemigo& e, VidasRecolectadas& v);
	static void colision(Personaje& h, EnemigoDisp& e, VidasRecolectadas& v);
	static void colision(Personaje& h, Babosa* b, VidasRecolectadas&);
	static void colision(Personaje& h, Bomber* b, VidasRecolectadas& v);
	static void colision(Personaje& h, Tentaculo* t, VidasRecolectadas&);//arreglar
	static void colision(Personaje& h, Tank& t, VidasRecolectadas& v);
	static void colision(Personaje& h, BossFinal& b, VidasRecolectadas& v);
	////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////// Enemigos
	//Entorno
	static void rebote(ListaEnemigos le, ListaSolidos ls);
	static void rebote(Enemigo* e, Solidos* s);
	static void rebote(Enemigo* e, Pared* p);
	static void rebote(Enemigo* e, PlatMovil pm);
	static void rebote(Enemigo* e, Suelo s);
	static void rebote(Enemigo* e, Final p);
	static void rebote(Enemigo* e, Pincho p);
	static void rebote(Enemigo* e, BolaFuego b);
	//void rebote(Enemigo& e, Caja c);
	static void rebote(EnemigoDisp* e, Solidos* s);
	static void rebote(EnemigoDisp* e, Pared* p);
	static void rebote(EnemigoDisp* e, PlatMovil* pm);
	static void rebote(EnemigoDisp* e, Suelo* s);
	static void rebote(EnemigoDisp* e, Final* p);
	static void rebote(EnemigoDisp* e, Pincho* p);
	static void rebote(EnemigoDisp* e, BolaFuego* p);
	//void rebote(EnemigoDisp& e, Caja c);
	static void rebote(Babosa* b, Solidos* s);
	static void rebote(Babosa* b, Pared* p);
	static void rebote(Babosa* b, PlatMovil* pm);
	static void rebote(Babosa* b, Suelo* s);
	static void rebote(Babosa* b, Final* p);
	static void rebote(Babosa* b, Pincho* p);
	static void rebote(Babosa* b, BolaFuego* p);
	//void rebote(Babosa& b, Caja c);
	static void rebote(Bomber* b, Solidos* s);
	static void rebote(Bomber* b, Pared* p);
	static void rebote(Bomber* b, PlatMovil* pm);
	static void rebote(Bomber* b, Suelo* s);
	static void rebote(Bomber* b, Final* p);
	static void rebote(Bomber* b, Pincho* p);
	static void rebote(Bomber* b, BolaFuego* p);
	//void rebote(Bomber& b, Caja c);
	static void rebote(Tentaculo* t, Solidos* s);
	static void rebote(Tentaculo* t, Pared* p);
	static void rebote(Tentaculo* t, PlatMovil* pm);
	static void rebote(Tentaculo* t, Suelo* s);
	static void rebote(Tentaculo* t, Final* p);
	static void rebote(Tentaculo* t, Pincho* p);
	static void rebote(Tentaculo* t, BolaFuego* p);
	//void rebote(Tentaculo& t, Caja c);
	static void rebote(Tank* t, Solidos* s);
	static void rebote(Tank* t, Pared* p);
	static void rebote(Tank* t, PlatMovil* pm);
	static void rebote(Tank* t, Suelo* s);
	static void rebote(Tank* t, Final* p);
	static void rebote(Tank* t, Pincho* p);
	static void rebote(Tank* t, BolaFuego* p);
	//void rebote(Tank& t, Caja c);
	static void rebote(BossFinal* bf, Solidos* s);
	static void rebote(BossFinal* bf, Pared* p);
	static void rebote(BossFinal* bf, PlatMovil* pm);
	static void rebote(BossFinal* bf, Suelo* s);
	static void rebote(BossFinal* bf, Final* p);
	static void rebote(BossFinal* bf, Pincho* p);
	static void rebote(BossFinal* bf, BolaFuego* p);
	//void rebote(BossFinal& bf, Caja c);
	//Espada y disparos buenos
	static void colision(Espada& esp, ListaEnemigos le);
	static void colision(Espada& esp, Enemigo* e);
	static void colision(Espada& esp, EnemigoDisp* e);
	static void colision(Espada& esp, Babosa* b);
	static void colision(Espada& esp, Bomber* b);
	static void colision(Espada& esp, Tentaculo* t);
	static void colision(Espada& esp, Tank* t);
	static void colision(Espada& esp, BossFinal* b);
	static void colision(ListaDisparos ld, ListaEnemigos le);
	static void colision(Disparos& d, Enemigo& e); //Este vale
	static void colision(Disparos& d, EnemigoDisp& e);
	static void colision(Disparos& d, Babosa& b);
	static void colision(Disparos& d, Bomber& b);
	static void colision(Disparos& d, Tentaculo& t);
	static void colision(Disparos& d, Tank& t);
	static void colision(Disparos& d, BossFinal& b);
	static void colision(DisparosAmigos& d, ListaEnemigos& le);
	static void colision(DisparosAmigos& d, Enemigo& e); //Este tmb
	static void colision(DisparosAmigos& d, EnemigoDisp& e);
	static void colision(DisparosAmigos& d, Babosa& b);
	static void colision(DisparosAmigos& d, Bomber& b);
	static void colision(DisparosAmigos& d, Tentaculo& t);
	static void colision(DisparosAmigos& d, Tank& t);
	static void colision(DisparosAmigos& d, BossFinal& b);
	////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////// Disparos
	//Entorno
	static void choque(ListaDisparos ld, ListaSolidos ls);
	static void choque(Disparos& d, Solidos s);
	static void choque(Disparos& d, Pared p);
	static void choque(Disparos& d, PlatMovil pm);
	static void choque(Disparos& d, Suelo s);
	static void choque(Disparos& d, Final f);
	static void choque(Disparos& d, Pincho s);
	static void choque(Disparos& d, BolaFuego b);
	static void choque(DisparosAmigos& d, Solidos s);
	static void choque(DisparosAmigos& d, Pared p);
	static void choque(DisparosAmigos& d, PlatMovil pm);
	static void choque(DisparosAmigos& d, Suelo s);
	static void choque(DisparosAmigos& d, Final f);
	static void choque(DisparosAmigos& d, Pincho s);
	static void choque(DisparosAmigos& d, BolaFuego b);
	static void choque(DisparosEnemigos& d, Solidos s);
	static void choque(DisparosEnemigos& d, Pared p);
	static void choque(DisparosEnemigos& d, PlatMovil pm);
	static void choque(DisparosEnemigos& d, Suelo s);
	static void choque(DisparosEnemigos& d, Final f);
	static void choque(DisparosEnemigos& d, Pincho s);
	static void choque(DisparosEnemigos& d, BolaFuego b);
	static void choque(Misiles& d, Solidos s);
	static void choque(Misiles& d, Pared p);
	static void choque(Misiles& d, PlatMovil pm);
	static void choque(Misiles& d, Suelo s);
	static void choque(Misiles& d, Final f);
	static void choque(Misiles& d, Pincho s);
	static void choque(Misiles& d, BolaFuego b);
	//Invocación de disparos desde cada enemigo
	static void dispara(ListaEnemigos le, ListaDisparos ld);
	static void dispara(Enemigo* e, ListaDisparos ld);
	static void dispara(EnemigoDisp* e, ListaDisparos ld);
	static void dispara(Tank* t, ListaDisparos ld);
	static void dispara(BossFinal* b, ListaDisparos ld);
	////////////////////////////////////////////////////////////////////
};
	
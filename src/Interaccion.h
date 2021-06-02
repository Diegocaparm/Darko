#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"
#include "EnemigoDisp.h"
#include "listaEnemDisp.h"
#include "listaPlat.h"
#include "Tank.h"
#include "babosa.h"
#include "listaBabosas.h"
#include "Vidas.h"
#include "VidasRec.h"
#include "Dinero.h"
#include "bomber.h"
#include "listabomber.h"

class Interaccion
{
public:
	//PJ con entorno
	static void rebote(Hombre& h, Caja c);
	static void rebote(Hombre& h, Pared p);
	static void rebote(Hombre& h, listaPlat lp); 
	static void disparoInicializa(Disparo*, Hombre*);

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

	//Interacción entre Pj y enemigos
	static void rebote(Hombre& h, EnemigoDisp e, VidasRec& v); 
	static void rebote(EnemigoDisp&, EnemigoDisp&);
	static void mov(Babosa& b, Hombre& h);
	static void rebote(Hombre& h, listaEnemDisp l,VidasRec& v);

};


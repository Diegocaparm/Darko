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
#include "Vidas.h"

class Interaccion
{
public:
	//PJ con entorno
	static void rebote(Hombre& h, Caja c);
	static void rebote(Hombre& h, Pared p);
	static void rebote(Hombre& h, listaPlat lp); //A�adida por David
	static void disparoInicializa(Disparo*, Hombre*);
	static void recoleccion(Hombre h, Vidas& v);

	//Enemigos con entorno
	static void rebote(EnemigoDisp& ene, Caja c);
	static void rebote(EnemigoDisp& ene, Pared p);
	static void rebote(Tank& t, Caja c);
	static void rebote(Tank& t, Pared p);

	//Interacci�n entre Pj y enemigos
	static void rebote(Hombre& h, EnemigoDisp e); 
	static void rebote(EnemigoDisp&, EnemigoDisp&);
	static void mov(Babosa& b, Hombre& h);
	static void rebote(Hombre& h, listaEnemDisp l);
};


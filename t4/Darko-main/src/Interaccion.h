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

class Interaccion
{
public:
	static void rebote(Hombre& h, Caja c);
	static void rebote(Hombre& h, Pared p);
	static void rebote(Hombre& h, listaPlat lp);
	static void disparoInicializa(Disparo*, Hombre*);

	static void rebote(EnemigoDisp& ene, Caja c);
	static void rebote(EnemigoDisp& ene, Pared p);
	static void rebote(Tank& t, Caja c);
	static void rebote(Tank& t, Pared p);

	static void rebote(Hombre& h, EnemigoDisp e); //Interacción entre Pj y enemigos
	static void rebote(EnemigoDisp&, EnemigoDisp&);
	static void mov(Babosa& b, Hombre& h);

};


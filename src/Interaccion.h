#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"
#include "EnemigoDisp.h"
#include "Tank.h"

class Interaccion
{
public:
	static void rebote(Hombre& h, Caja c);
	static void rebote(Hombre& h, Pared p);

	static void rebote(EnemigoDisp& ene, Caja c);
	static void rebote(EnemigoDisp& ene, Pared p);

	static void rebote(Tank& t, Caja c);
	static void rebote(Tank& t, Pared p);


	static bool rebote(Esfera& e, Pared p);
	static bool rebote(Esfera& e, Caja c);
	static bool rebote(Esfera& e1, Esfera& e2);
	

	static void disparoInicializa(Disparo*, Hombre*);
};

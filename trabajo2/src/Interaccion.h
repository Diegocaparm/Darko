#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"

class Interaccion
{
public:
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Esfera& e, Pared p);
	static bool rebote(Esfera& e, Caja c);
	static bool rebote(Esfera& e1, Esfera& e2);
	static void rebote(Hombre& h, Pared p);

	static void disparoInicializa(Disparo*, Hombre*);
};


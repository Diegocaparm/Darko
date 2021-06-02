#include "VidasRec.h"

void VidasRec::mueve(float t,float posx)
{
	
	for (int i = 0; i < numero; i++) {
		lista[i]->setPos(posx + 4 + i * 2, 16);
		lista[i]->mueve(t);
	}
}

int VidasRec::getVidas()
{
	return vida_inicial;
}

//void VidasRec::reduceVida()
//{
//	eliminar()
//}


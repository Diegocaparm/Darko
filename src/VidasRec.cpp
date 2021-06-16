#include "VidasRec.h"
#include "Interaccion.h"
#include "stdio.h"

bool VidasRec::agregar(Corazon* c)
{
	for (int i = 0; i < numero; i++) //Evitar que se añada una vida ya existente
		if (lista[i] == c)
			return false;

	if (numero < MAX_VIDAS) {
		lista[numero++] = c; // último puesto sin rellenar
		contador_vidas++;
		printf("%d\n", contador_vidas);
	}
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void VidasRec::eliminar(int i)
{
	Vidas::eliminar(i);
	contador_vidas--;
	if (contador_vidas < -1) {
		contador_vidas = -1;
	}
}

void VidasRec::mueve(float t,float posx)
{
	for (int i = 0; i < numero; i++) {
		lista[i]->setPos(posx + 12 - i * 2, 16);
		lista[i]->mueve(t);
	}
}

int VidasRec::getVidas()
{
	return contador_vidas;
}

int VidasRec::getVidasInicial()
{
	return vida_inicial;
}

//Corazon* VidasRec::colisionEnemigoDisp(EnemigoDisp e)
//{
//	for (int i = 0; i < numero; i++)
//	{
//		if (Interaccion::rebote(*(lista[i]), e))
//			return lista[i];
//	}
//	return 0; //no hay colisión
//}



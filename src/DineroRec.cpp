#include "DineroRec.h"
#include "ETSIDI.h"
void DineroRec::mueve(float t, float posx)
{

	for (int i = 0; i < numero; i++) {
		lista[i]->setPos(posx + 12 + i * 2, 14);
		lista[i]->mueve(t);
	}
}

void DineroRec::aumentaDinero()
{
	dinero_actual += 1;
}

void DineroRec::dibujaContador(float posx)
{
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	
	switch (dinero_actual)
	{
	case 0:
		ETSIDI::printxy("0", 5 + posx, 14);
		break;

	case 1:
		ETSIDI::printxy("1", 5 + posx, 14);
		break;
	case 2:
		ETSIDI::printxy("2", 5 + posx, 14);
		break;
	case 3:
		ETSIDI::printxy("3", 5 + posx, 14);
		break;
	case 4:
		ETSIDI::printxy("4", 5 + posx, 14);
		break;
	case 5:
		ETSIDI::printxy("5", 5 + posx, 14);
		break;
	case 6:
		ETSIDI::printxy("6", 5 + posx, 14);
		break;
	case 7:
		ETSIDI::printxy("7", 5 + posx, 14);
		break;
	case 8:
		ETSIDI::printxy("8", 5 + posx, 14);
		break;
	case 9:
		ETSIDI::printxy("9", 5 + posx, 14);
		break;
	}
	
	
}

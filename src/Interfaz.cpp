#include "Interfaz.h"

void Interfaz::dibuja()
{
	switch (corazon.getCantidad())
	{
	case 1:
		corazon.dibuja(7);
		break;
	case 2:
		corazon.dibuja(7);
		corazon.dibuja(7-4);
		break;
	case 3:
		corazon.dibuja(7);
		corazon.dibuja(7-3);
		corazon.dibuja(7-6);
		break;
	default:
		break;
	}
	
}

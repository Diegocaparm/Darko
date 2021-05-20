#include "Interfaz.h"

void Interfaz::dibuja(Vector2D h)
{
	switch (corazon.getCantidad())
	{
	case 1:
		corazon.dibuja(h.x, h.y);
		break;
	case 2:
		corazon.dibuja(h.x + 3, h.y);
		corazon.dibuja(h.x, h.y);
		break;
	case 3:
		corazon.dibuja(h.x + 4, h.y);
		corazon.dibuja(h.x + 2, h.y);
		corazon.dibuja(h.x,h.y);
		break;
	default:
		break;
	}
	moneda.dibuja();
}

void Interfaz::mueve(float t)
{
	moneda.mueve();
}

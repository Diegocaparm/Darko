#include "Interfaz.h"

//void Interfaz::dibuja(Vector2D h)
//{
//	//corazon.dibuja(10, 0,getRecogido());
//
//	switch (corazon.getCantidad())
//	{
//	case 1:
//		corazon.dibuja(h.x + 12, 16, true);
//		break;
//	case 2:
//		corazon.dibuja(h.x + 12, 16, true);
//		corazon.dibuja(h.x + 10, 16, true);
//		break;
//	case 3:
//		corazon.dibuja(h.x + 12, 16, true);
//		corazon.dibuja(h.x + 10, 16, true);
//		corazon.dibuja(h.x + 8, 16, true);
//		break;
//	case 4:
//		corazon.dibuja(h.x + 12, 16, true);
//		corazon.dibuja(h.x + 10, 16, true);
//		corazon.dibuja(h.x + 8, 16, true);
//		corazon.dibuja(h.x + 6, 16, true);
//		break;
//	case 5:
//		corazon.dibuja(h.x + 12, 16, true);
//		corazon.dibuja(h.x + 10, 16, true);
//		corazon.dibuja(h.x + 8, 16, true);
//		corazon.dibuja(h.x + 6, 16, true);
//		corazon.dibuja(h.x + 4, 16, true);
//		break;
//	default:
//		break;
//	}
//	moneda.dibuja();
//}

void Interfaz::mueve(float t)
{
	moneda.mueve();
}

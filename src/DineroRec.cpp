#include "DineroRec.h"
#include "ETSIDI.h"

DineroRec::DineroRec()
{
	nUnidad.setCenter(0, 0);
	nUnidad.setSize(2, 2);

	nDecena.setCenter(0, 0);
	nDecena.setSize(2, 2);
}

void DineroRec::mueve(float t, Vector2D v)
{
	pos.x = v.x;
	for (int i = 0; i < numero; i++) {
		lista[i]->setPos(v.x + 12 + i * 2, 14);
		lista[i]->mueve(t);
	}
}

void DineroRec::aumentaDinero()
{
	dinero_actual += 1;
}

void DineroRec::dibujaContador()
{

	glPushMatrix();
	glTranslatef(pos.x + 10, 12, 1);
	
	glutSolidSphere(0.2, 20, 20);
	for (int i = 0; i < 10; i++) {
		if (i == dinero_actual) {
			nUnidad.setState(i, true);
		}
		else {
			for (int j = 0; j < 10; j++) {
				int unidad;
				if (dinero_actual > j * 10) {
					unidad = dinero_actual - j * 10;
					nUnidad.setState(unidad, true);
					nDecena.setState(j,true);
					if (unidad==0) {
						nDecena.setState(j + 1, true);
					}
				}

			}
		}

	}
	nUnidad.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(pos.x + 8, 12, 1);
	
	//for (int i = 0; i < 10; i++) {
	//	if (i == dinero_actual) {
	//		nDecena.setState(i, true);
	//	}
	//	else {
	//		for (int j = 0; j < 10; j++) {
	//			int unidad;
	//			if (dinero_actual > j * 10) {
	//				unidad = dinero_actual - j * 10;
	//				nDecena.setState(unidad, true);
	//			}

	//		}
	//	}

	//}
	nDecena.draw();
	glPopMatrix();
}
	

#include "Disparo.h"
#include "Estela.h"
#include "Vector2D.h"
#include "freeglut.h"

Disparo::Disparo() {
	radio = 0.25f;
	aceleracion.x = aceleracion.y = 0.0f;
	velocidad.x = 0.0f;
	velocidad.y = 1.75f;
}

void Disparo::dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0); //disparo
	glutSolidSphere(radio, 20, 20);
	glTranslatef(0, -posicion.y, 0);		//origen
	//estela
	if (posicion.y > 0.0 && posicion.y < 2.5f) {
		estela1.dibuja(0.0);
	}
	if (posicion.y > 1.0f && posicion.y < 3.5f) {
		estela2.dibuja(1.0);
	}
	if (posicion.y > 2.0f && posicion.y < 4.5f) {
		estela3.dibuja(2.0);
	}
	if (posicion.y > 3.0f && posicion.y < 5.5f) {
		estela4.dibuja(3.0);
	}//ssssssssssssssssssssss
	if (posicion.y > 4.0f && posicion.y < 6.5f) {
		estela1.dibuja(4.0);
	}
	if (posicion.y > 5.0f && posicion.y < 7.5f) {
		//estela3.radio2 = 0.2;
		estela2.dibuja(5.0);
	}
	if (posicion.y > 6.0f && posicion.y < 8.5f) {
		estela3.dibuja(6.0);
	}
	if (posicion.y > 7.0f && posicion.y < 9.5f) {
		estela4.dibuja(7.0);
	}//sssssssssssssssssssssssssss
	if (posicion.y > 8.0f && posicion.y < 10.5f) {
		estela1.dibuja(8.0);
	}
	if (posicion.y > 9.0f && posicion.y < 11.5f) {
		estela2.dibuja(9.0);
	}
	if (posicion.y > 10.0f && posicion.y < 12.5f) {
		estela3.dibuja(10.0);
	}
	if (posicion.y > 11.0f && posicion.y < 13.5f) {
		estela4.dibuja(11.0);
	}//sssssssssssssssssssssssssss
	if (posicion.y > 12.0f && posicion.y < 14.5f) {
		estela1.dibuja(12.0);
	}
	if (posicion.y > 13.0f && posicion.y < 15.5f) {
		estela2.dibuja(13.0);
	}
	if (posicion.y > 14.0f && posicion.y < 16.5f) {
		estela3.dibuja(14.0);
	}
	if (posicion.y > 15.0f && posicion.y < 17.5f) {
		estela4.dibuja(15.0);
	}//sssssssssssssssssssssssssss
	glPopMatrix();
}
void Disparo::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	if (ini == 0) {
		estela1.radio2 = 0.2;
		estela2.radio2 = 0.2;
		estela3.radio2 = 0.2;
		estela4.radio2 = 0.2;
		ini = 1;
	}
	if (posicion.y > 0.0 && posicion.y < 3.0f) {
		estela1.mueve(t);
	}
	if (posicion.y > 1.0f && posicion.y < 4.0f) {
		estela2.mueve(t);
	}
	if (posicion.y > 2.0f && posicion.y < 5.0f) {
		estela3.mueve(t);
	}
	if (posicion.y > 3.0f && posicion.y < 6.0f) {
		if (posicion.y < 4.0f)
			estela1.radio2 = 0.2;
		estela4.mueve(t);
	}//sssssssssssssssssssssssss
	if (posicion.y > 4.0f && posicion.y < 7.0f) {
		if (posicion.y < 5.0f)
			estela2.radio2 = 0.2;
		estela1.mueve(t);
	}
	if (posicion.y > 5.0f && posicion.y < 8.0f) {
		if (posicion.y < 6.0f)
			estela3.radio2 = 0.2;
		estela2.mueve(t);
	}
	if (posicion.y > 6.0f && posicion.y < 9.0f) {
		if (posicion.y < 7.0f)
			estela4.radio2 = 0.2;
		estela3.mueve(t);
	}
	if (posicion.y > 7.0f && posicion.y < 10.0f) {
		if (posicion.y < 8.0f)
			estela1.radio2 = 0.2;
		estela4.mueve(t);
	}//sssssssssssssssssssssssssss
	if (posicion.y > 8.0 && posicion.y < 11.0f) {
		if (posicion.y < 9.0f)
			estela2.radio2 = 0.2;
		estela1.mueve(t);
	}
	if (posicion.y > 9.0f && posicion.y < 12.0f) {
		if (posicion.y < 10.0f)
			estela3.radio2 = 0.2;
		estela2.mueve(t);
	}
	if (posicion.y > 10.0f && posicion.y < 13.0f) {
		if (posicion.y < 11.0f)
			estela4.radio2 = 0.2;
		estela3.mueve(t);
	}
	if (posicion.y > 11.0f && posicion.y < 14.0f) {
		if (posicion.y < 12.0f)
			estela1.radio2 = 0.2;
		estela4.mueve(t);
	}//sssssssssssssssssssssssss
	if (posicion.y > 12.0f && posicion.y < 15.0f) {
		if (posicion.y < 13.0f)
			estela2.radio2 = 0.2;
		estela1.mueve(t);
	}
	if (posicion.y > 13.0f && posicion.y < 16.0f) {
		if (posicion.y < 14.0f)
			estela3.radio2 = 0.2;
		estela2.mueve(t);
	}
	if (posicion.y > 14.0f && posicion.y < 17.0f) {
		if (posicion.y < 15.0f)
			estela4.radio2 = 0.2;
		estela3.mueve(t);
	}
	if (posicion.y > 15.0f && posicion.y < 18.0f) {
		if (posicion.y < 16.0f)
			estela1.radio2 = 0.2;
		estela4.mueve(t);
	}//sssssssssssssssssssssssssss
}

void Disparo::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Disparo::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void estela(float posiciony) {
	float radio1, radio2;
	radio1 = 0.1f;
	radio2 = 0.2f;
	
}
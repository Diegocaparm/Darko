#include "Interaccion.h"
#include <math.h>
#define pi 3.14159265

void Interaccion::rebote(Hombre& h, Caja c)
{
	

	float xmin = c.pared_izq.limite2.x;
	float xmax = c.techo.limite1.x;
	if (h.posicion.x > xmax) {
		h.posicion.x = xmax;
	}
	if (h.posicion.x < xmin) {
		h.posicion.x = xmin;
	}


	float ymin = c.pared_dcha.limite2.y;
	float ymax = c.pared_dcha.limite1.y - h.altura;
	if (h.posicion.y > ymax) {
		h.posicion.y = ymax;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;
	}
	if (h.posicion.y < ymin) {
		h.posicion.y = ymin + 0.001f;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = 0.0f;
	}
}

void Interaccion::rebote(Hombre& h, Pared p)
{
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - h.altura;//arr
	if (h.posicion.y > ymin - h.altura / 2)
		h.zona = 1;
	else
		h.zona = 0;

	if (h.posicion.x < xmax && h.posicion.x > xmin) {  //zona=0 abajo    zona=1 arriba
		if (h.zona == 0) {
			if (h.posicion.y > ymax) {
				h.posicion.y = ymax;
				h.velocidad.y = 0.0f;
				h.aceleracion.y = -9.8f;
			}
		}
		else
			if (h.posicion.y < ymin) {
				h.posicion.y = ymin;
				h.velocidad.y = 0.0f;
			//	h.aceleracion.y = -9.8f;
			}
	}
}

void Interaccion::disparoInicializa(Disparo* disparo, Hombre* hombre) {
	disparo->radio = 0.2f;
	disparo->posicion.x = hombre->posicion.x;
	disparo->posicion.y = hombre->posicion.y;
	disparo->ini = 0;
}

void Interaccion::rebote(EnemigoDisp& ene, Caja c)
{
	float xmin = c.techo.limite2.x;
	float xmax = c.techo.limite1.x;
	if (ene.posicion.x > xmax) {
		ene.posicion.x = xmax;
	}
	if (ene.posicion.x < xmin) {
		ene.posicion.x = xmin;
	}


	float ymin = c.pared_dcha.limite2.y;
	float ymax = c.pared_dcha.limite1.y - ene.altura;
	if (ene.posicion.y > ymax) {
		ene.posicion.y = ymax;
		ene.velocidad.y = 0.0f;
		ene.aceleracion.y = -9.8f;
	}
	if (ene.posicion.y < ymin) {
		ene.posicion.y = ymin;
	}
}

void Interaccion::rebote(EnemigoDisp& ene, Pared p)
{
	//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - ene.altura;//arr
	//Decidimos si estamos arriba o abajo
	if (ene.posicion.y > ymin - ene.altura / 2)
		ene.zonaV = 1; //Estamos arriba
	else
		ene.zonaV = 0; //Abajo
	//Decidimos si estamos dentro y si estamos encima
	if (ene.posicion.x < xmax && ene.posicion.x > xmin) 
	{
		if (ene.zonaV == 0) { //Sigue igual si esta debajo
			if (ene.posicion.y > ymax) {
				ene.posicion.y = ymax;
				ene.velocidad.y = 0.0f;
				ene.aceleracion.y = -9.8f;
			}
		}
		else //Si está arriba
		{
			if (ene.posicion.y < ymin) {
				ene.posicion.y = ymin;
				ene.velocidad.y = 0.0f;
			}
			if (ene.posicion.x < xmin + 0.5f) {		//cambiar de direccion
			ene.sentido = 0;
			}
			if (ene.posicion.x > xmax - 0.5f) {
			ene.sentido = 1;
			}
		}
	}
}

void Interaccion::rebote(Tank& t, Caja c)
{
	float xmin = c.techo.limite2.x;
	float xmax = c.techo.limite1.x;
	if (t.posicion.x > xmax) {
		t.posicion.x = xmax;
	}
	if (t.posicion.x < xmin) {
		t.posicion.x = xmin;
	}


	float ymin = c.pared_dcha.limite2.y;
	float ymax = c.pared_dcha.limite1.y - t.altura;
	if (t.posicion.y > ymax) {
		t.posicion.y = ymax;
		t.velocidad.y = 0.0f;
		t.aceleracion.y = -9.8f;
	}
	if (t.posicion.y < ymin) {
		t.posicion.y = ymin;
	}
}
void Interaccion::rebote(Tank& t, Pared p)
{
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - t.altura;//arr
	if (t.posicion.y > ymin - t.altura / 2)
		t.zonaV = 1;
	else
		t.zonaV = 0;

	if (t.posicion.x < xmax && t.posicion.x > xmin) {  //zona=0 abajo    zona=1 arriba
		if (t.zonaV == 0) {
			if (t.posicion.y > ymax) {
				t.posicion.y = ymax;
				t.velocidad.y = 0.0f;
				t.aceleracion.y = -9.8f;
			}
		}
		else
			if (t.posicion.y < ymin) {
				t.posicion.y = ymin;
				t.velocidad.y = 0.0f;
				//	ene.aceleracion.y = -9.8f;
			}

		if (t.posicion.x < xmin + 0.5f) {		//cambiar de direccion
			t.sentido = 1;
		}
		if (t.posicion.x > xmax - 0.5f) {
			t.sentido = 0;
		}
	}
}

void Interaccion::rebote(Hombre& h, EnemigoDisp e)
{
	bool izq = 0;	//Posicion relativa del Pj con enemigo. En la izquierda=TRUE

	Vector2D diferencia = (h.posicion - e.posicion);
	float modulo = diferencia.modulo();
	if (h.posicion.x >= e.posicion.x) {
		izq = false;
	}
	else {
		izq = true;
	}

	if (modulo <= 0.5 && izq==true) {
		//h.posicion.x -= 0.2;	//Con posicion funciona pero si se mantiene la tecla de ir a derecha se traspasa enemigo
		h.aceleracion.x = -200;

	}

	if (modulo<=0.5 && izq==false) {
		//h.posicion.x += 0.2; ////Con posicion funciona pero si se mantiene la tecla de ir a iquierda se traspasa enemigo
		h.aceleracion.x = 200;

	}
	
	if (modulo > 1.0 && modulo < 1.5) {
		h.aceleracion.x = 0;
		h.velocidad.x = 0;
	}
}

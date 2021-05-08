#include "Interaccion.h"
#include <math.h>
#define pi 3.14159265

void Interaccion::rebote(Hombre& h, Caja c)
{
	float xmin = c.suelo.limite2.x;
	float xmax = c.suelo.limite1.x;
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

bool Interaccion::rebote(Esfera& e, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.velocidad;
		e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		e.posicion = e.posicion - dir * dif;
		return true;
	}
	return false;
}

bool Interaccion::rebote(Esfera& e, Caja c) {
	Vector2D dir1;
	float dif1 = c.suelo.distancia(e.posicion, &dir1) - e.radio;
	Vector2D dir2;
	float dif2 = c.techo.distancia(e.posicion, &dir2) - e.radio;
	Vector2D dir3;
	float dif3 = c.pared_izq.distancia(e.posicion, &dir3) - e.radio;
	Vector2D dir4;
	float dif4 = c.pared_dcha.distancia(e.posicion, &dir4) - e.radio;
		//suelo
	if (dif1 < 0) {
		if (dif1 <= 0.0f)
		{
			Vector2D v_inicial1 = e.velocidad;
			e.velocidad = v_inicial1 - dir1 * 2.0 * (v_inicial1 * dir1);
			e.posicion = e.posicion - dir1 * dif1;
			return true;
		}
		return false;
	}

		//techo
	if (dif2 < 0) {
		if (dif2 <= 0.0f)
		{
			Vector2D v_inicial2 = e.velocidad;
			e.velocidad = v_inicial2 - dir2 * 2.0 * (v_inicial2 * dir2);
			e.posicion = e.posicion - dir2 * dif2;
			return true;
		}
		return false;
	}

		//pared_izq
	if (dif3 < 0) {
		if (dif3 <= 0.0f)
		{
			Vector2D v_inicial3 = e.velocidad;
			e.velocidad = v_inicial3 - dir3 * 2.0 * (v_inicial3 * dir3);
			e.posicion = e.posicion - dir3 * dif3;
			return true;
		}
		return false;
	}

		//pare_dcha
	if (dif4 < 0) {
		if (dif4 <= 0.0f)
		{
			Vector2D v_inicial4 = e.velocidad;
			e.velocidad = v_inicial4 - dir4 * 2.0 * (v_inicial4 * dir4);
			e.posicion = e.posicion - dir4 * dif4;
			return true;
		}
		return false;
	}
}

bool Interaccion::rebote(Esfera& e1, Esfera& e2) {
	Vector2D dif = e2.posicion - e1.posicion;
	float d = dif.modulo();
	float distancia = d - (e1.radio + e2.radio);

	if (distancia < 0.0f)//si hay colision
	{
		//modulo y argumento
		float v1 = e1.velocidad.modulo();
		float arg1 = e1.velocidad.argumento();

		float v2 = e2.velocidad.modulo();
		float arg2 = e2.velocidad.argumento();

		float argd = dif.argumento();

		//mover las esferas en sus respectivas direcciones
		Vector2D desp(distancia / 2 * cos(argd), distancia / 2 * sin(argd));
		e1.posicion = e1.posicion + desp;
		e2.posicion = e2.posicion - desp;

		argd = argd - pi / 2;

		//angulo v antes del choque
		float th1 = arg1 - argd;
		float th2 = arg2 - argd;

		//v antes del choque
		float u1x = v1 * cos(th1);
		float u1y = v1 * sin(th1);

		float u2x = v2 * cos(th2);
		float u2y = v2 * sin(th2);

		//vx despues del choque
		float v1x = u1x;
		float v2x = u2x;

		//la masa depende del radio
		float m1 = e1.radio;
		float m2 = e2.radio;
		float py = m1 * u1y + m2 * u2y;				//p inicial ejey
		float ey = m1 * u1y * u1y + m2 * u2y * u2y;	//Ec inicial ejey

		float a = m2 * m2 + m1 * m2;
		float b = -2 * py * m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a * c;
		if (disc < 0)
			disc = 0;

		//vy despues del choque
		float v2y = (-b + sqrt(disc)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;

		//modulo y argumento de v1 y v2
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x * v1x + v1y * v1y);
		modv2 = sqrt(v2x * v2x + v2y * v2y);
		fi1 = argd + atan2(v1y, v1x);
		fi2 = argd + atan2(v2y, v2x);

		//cambiar las velocidades de las esferas
		e1.velocidad.x = modv1 * cos(fi1);
		e1.velocidad.y = modv1 * sin(fi1);
		e2.velocidad.x = modv2 * cos(fi2);
		e2.velocidad.y = modv2 * sin(fi2);
	}
	return false;

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
	float xmin = c.suelo.limite2.x;
	float xmax = c.suelo.limite1.x;
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
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - ene.altura;//arr
	if (ene.posicion.y > ymin - ene.altura / 2)
		ene.zonaV = 1;
	else
		ene.zonaV = 0;

	if (ene.posicion.x < xmax && ene.posicion.x > xmin) {  //zona=0 abajo    zona=1 arriba
		if (ene.zonaV == 0) {
			if (ene.posicion.y > ymax) {
				ene.posicion.y = ymax;
				ene.velocidad.y = 0.0f;
				ene.aceleracion.y = -9.8f;
			}
		}
		else
			if (ene.posicion.y < ymin) {
				ene.posicion.y = ymin;
				ene.velocidad.y = 0.0f;
				//	ene.aceleracion.y = -9.8f;
			}

		if (ene.posicion.x < xmin+0.5f) {		//cambiar de direccion
			ene.sentido = 1;
		}
		if (ene.posicion.x > xmax-0.5f) {
			ene.sentido = 0;
		}
	}
}

void Interaccion::rebote(Tank& t, Caja c)
{
	float xmin = c.suelo.limite2.x;
	float xmax = c.suelo.limite1.x;
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
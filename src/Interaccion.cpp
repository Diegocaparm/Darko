#include "Interaccion.h"
#include <math.h>
#define pi 3.14159265

void Interaccion::rebote(Hombre& h, Caja c)
{
	//Generamos los límites de la caja en el eje x
	float xmin = c.pared_izq.limite2.x;
	float xmax = c.techo.limite1.x;
	if (h.posicion.x > xmax) {
		h.posicion.x = xmax;
	}
	if (h.posicion.x < xmin) {
		h.posicion.x = xmin;
	}
	//Tratamos los rebotes del techo y los suelos como plataformas standar
	rebote(h, c.techo);
	rebote(h, c.suelo1);
	rebote(h, c.suelo2);
	rebote(h, c.suelo3);
	rebote(h, c.suelo4);
	rebote(h, c.suelo5);
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

void Interaccion::rebote(Hombre& h, listaPlat p) {
	for (int i = 0; i < p.numero; i++)
		rebote(h, *p.lista[i]);
}

void Interaccion::disparoInicializa(Disparo* disparo, Hombre* hombre) {
	disparo->radio = 0.2f;
	disparo->posicion.x = hombre->posicion.x;
	disparo->posicion.y = hombre->posicion.y;
	disparo->ini = 0;
}

void Interaccion::rebote(EnemigoDisp& ene, Caja c)
{
	rebote(ene, c.techo);
	rebote(ene, c.pared_dcha);
	rebote(ene, c.pared_izq);
	rebote(ene, c.suelo1);
	rebote(ene, c.suelo2);
	rebote(ene, c.suelo3);
	rebote(ene, c.suelo4);
	rebote(ene, c.suelo5);
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

void Interaccion::rebote(Hombre & h, EnemigoDisp e,VidasRec& v)
{
	//bool izq = 0;	//Posicion relativa del Pj con enemigo. En la izquierda=TRUE

	//Vector2D diferencia = (h.posicion - e.posicion);
	//float modulo = diferencia.modulo();

	//if (h.posicion.x >= e.posicion.x) {
	//	izq = false;
	//}
	//else {
	//	izq = true;
	//}

	//if (modulo <= 0.5 && izq == true) {
	//	h.posicion.x -= 1;	//Con posicion funciona pero si se mantiene la tecla de ir a derecha se traspasa enemigo
	//	//h.aceleracion.x = -200;

	//}

	//if (modulo <= 0.2 && izq == false) {
	//	h.posicion.x += 1;  //Con posicion funciona pero si se mantiene la tecla de ir a iquierda se traspasa enemigo
	//	//h.aceleracion.x = 200;

	//}

	//Si se usa velocidad o aceleracion para el empuje
	//if (modulo > 1.0 && modulo < 1.5) {
	//	h.aceleracion.x = 0;
	//	h.velocidad.x = 0;
	//}
	 
	if (h.hitbox.izquierda.limite1.x == e.hitbox.derecha.limite1.x && h.hitbox.izquierda.limite1.y <= e.hitbox.derecha.limite1.y) {
		v.eliminar(v.numero);
	}

}

void Interaccion::rebote(EnemigoDisp& ed1, EnemigoDisp& ed2) {
	float xmin = ed1.posicion.x - 0.1;
	float xmax = ed1.posicion.x + 0.1;
	float ymin = ed1.posicion.y - 0.1;
	float ymax = ed1.posicion.y + 0.1;

	Vector2D diferencia = (ed2.posicion - ed1.posicion);
	float modulo = diferencia.modulo();

	if (modulo <= 1.0) {

		//h.velocidad.x = -10.0f;
		ed2.aceleracion.x = -200.0f;
	}
}

void Interaccion::mov(Babosa& b, Hombre& h) {
	Vector2D dist = b.posicion - h.posicion;
	if (dist.modulo() < 5)
		b.cerca = 1;
	else
		b.cerca = 0;
	
	if (b.posicion.x < h.posicion.x)
		b.px = 0;
	else
		b.px = 1;
	if (b.posicion.y < h.posicion.y + h.altura / 2)
		b.py = 0;
	else
		b.py = 1;


}

void Interaccion::rebote(Corazon& v, Pared p)
{
	float xmin = p.limite1.x;//izq
	float xmax = p.limite2.x;//dcha
	float ymin = p.limite1.y;//dw
	float ymax = p.limite2.y;//up

	if (v.posicion.y < ymin || v.posicion.y>ymax) {
		v.velocidad.y = 0;
	}
	if (v.posicion.x<xmin || v.posicion.x>xmax) {
		v.velocidad.x = 0;
	}
}

void Interaccion::rebote(Corazon& v, Caja c)
{
	rebote(v, c.techo);
	rebote(v, c.pared_izq);
	rebote(v, c.pared_dcha);
	rebote(v, c.suelo1);
	rebote(v, c.suelo2);
	rebote(v, c.suelo3);
	rebote(v, c.suelo4);
	rebote(v, c.suelo5);
}

bool Interaccion::recoleccion(Corazon& v, Hombre h)
{
	Vector2D pos = h.getPos(); //la posicion de la base del hombre
	pos.y += h.altura / 2.0f; //posicion del centro
	float distancia = (v.posicion - pos).modulo();
	if (distancia < v.radio)
		return true;
	return false;
}

void Interaccion::rebote(Moneda& m, Pared p)
{
	float xmin = p.limite1.x;//izq
	float xmax = p.limite2.x;//dcha
	float ymin = p.limite1.y;//dw
	float ymax = p.limite2.y;//up

	if (m.posicion.y < ymin || m.posicion.y>ymax) {
		m.velocidad.y = 0;
	}
	if (m.posicion.x<xmin || m.posicion.x>xmax) {
		m.velocidad.x = 0;
	}
}

void Interaccion::rebote(Moneda& m, Caja c)
{
	rebote(m, c.techo);
	rebote(m, c.pared_izq);
	rebote(m, c.pared_dcha);
	rebote(m, c.suelo1);
	rebote(m, c.suelo2);
	rebote(m, c.suelo3);
	rebote(m, c.suelo4);
	rebote(m, c.suelo5);
}

bool Interaccion::recoleccion(Moneda& v, Hombre h)
{
	Vector2D pos = h.getPos(); //la posicion de la base del hombre
	pos.y += h.altura / 2.0f; //posicion del centro
	float distancia = (v.posicion - pos).modulo();
	if (distancia < v.radio)
		return true;
	return false;
}

void Interaccion::rebote(Hombre& h, listaEnemDisp l,VidasRec& v) 
{
	for (int i = 0; i < l.numero; i++)
		rebote(h, *l.lista[i],v);
}

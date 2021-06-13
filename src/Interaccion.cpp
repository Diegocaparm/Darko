#include "Interaccion.h"
#include <math.h>
#include "stdio.h"
#define pi 3.14159265

void Interaccion::rebote(Hombre& h, Caja c)
{
	//Generamos los límites de la caja en el eje x
	float xmin = c.pared_izq.limite2.x;
	float xmax = c.techo.limite1.x-0.1f;
	if (h.posicion.x > xmax) {
		h.posicion.x = xmax;
	}
	if (h.posicion.x < xmin) {
		h.posicion.x = xmin;
	}
	//Tratamos los rebotes del techo y los suelos como plataformas standar
	rebote(h, c.techo);
	rebote(h, c.suelo);
}

void Interaccion::rebote(Hombre& h, Pared p)
{
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - h.altura;//arr
	
	if (h.posicion.y > ymin - h.altura / 2)
		h.zonaV = 1;
	else
		h.zonaV = 0;

	if (h.posicion.x < xmax && h.posicion.x > xmin) {  //zona=0 abajo    zona=1 arriba
		if (h.zonaV == 0) {
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

void Interaccion::rebote(EnemigoDisp& ene, Caja c)
{
	rebote(ene, c.techo);
	rebote(ene, c.pared_dcha);
	rebote(ene, c.pared_izq);
	rebote(ene, c.suelo);
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

void Interaccion::rebote(bomber& b, Caja c)
{
	float xmin = c.techo.limite2.x;
	float xmax = c.techo.limite1.x;
	if (b.posicion.x > xmax) {
		b.posicion.x = xmax;
	}
	if (b.posicion.x < xmin) {
		b.posicion.x = xmin;
	}


	float ymin = c.pared_dcha.limite2.y;
	float ymax = c.pared_dcha.limite1.y - b.radio;
	if (b.posicion.y > ymax) {
		b.posicion.y = ymax;
		b.velocidad.y = 0.0f;
		b.aceleracion.y = -9.8f;
	}
	if (b.posicion.y < ymin) {
		b.posicion.y = ymin;
	}
}

void Interaccion::rebote(bomber& b, Pared p)
{
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - b.radio;//arr
	if (b.posicion.y > ymin - b.radio / 2)
		b.zonaV = 1;
	else
		b.zonaV = 0;

	if (b.posicion.x < xmax && b.posicion.x > xmin) {  //zona=0 abajo    zona=1 arriba
		if (b.zonaV == 0) {
			if (b.posicion.y > ymax) {
				b.posicion.y = ymax;
				b.velocidad.y = 0.0f;
				b.aceleracion.y = -9.8f;
			}
		}
		else
			if (b.posicion.y < ymin) {
				b.posicion.y = ymin;
				b.velocidad.y = 0.0f;
				//	ene.aceleracion.y = -9.8f;
			}

		if (b.posicion.x < xmin + 0.5f) {		//cambiar de direccion
			b.sentido = 1;
		}
		if (b.posicion.x > xmax - 0.5f) {
			b.sentido = 0;
		}
	}
}

void Interaccion::rebote(DisparosEnemigos& ene, Caja c)
{
	rebote(ene, c.techo);
	rebote(ene, c.pared_dcha);
	rebote(ene, c.pared_izq);
	rebote(ene, c.suelo);
}

void Interaccion::rebote(DisparosEnemigos& ene, Pared p)
{
	//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y;//arr
	//Decidimos si estamos arriba o abajo
	if (ene.getPos().y > ymin - ene.getRadio() / 2)
		ene.zonaV = 1; //Estamos arriba
	else
		ene.zonaV = 0; //Abajo
	//Decidimos si estamos dentro y si estamos encima
	if (ene.getPos().x < xmax && ene.getPos().x > xmin)
	{
		if (ene.zonaV == 0) { //Sigue igual si esta debajo
			if (ene.getPos().y > ymax) {
				ene.setPos(ene.getPos().x,ymax);
				ene.setVel(ene.vel, 0.0f);
				ene.setAc(0.0f, -9.8f);
			}
		}
		else //Si está arriba
		{
			if (ene.getPos().y < ymin) {
				/*ene.posicion.y = ymin;
				ene.velocidad.y = 0.0f;*/
				//ene.setColor(1, 1, 1);
				ene.flagdibujar = 0;
			}
			/*if (ene.getPos().x < xmin + 0.5f) {		//cambiar de direccion
				ene.sentido = 0;
			}
			if (ene.getPos().x > xmax - 0.5f) {
				ene.sentido = 1;
			}*/
		}
	}
}

void Interaccion::rebote(disparosAmigos& ene, Caja c)
{
	rebote(ene, c.techo);
	rebote(ene, c.pared_dcha);
	rebote(ene, c.pared_izq);
	rebote(ene, c.suelo);
}

void Interaccion::rebote(disparosAmigos& ene, Pared p)
{
	//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y;//arr
	//Decidimos si estamos arriba o abajo
	if (ene.getPos().y > ymin - ene.getRadio() / 2)
		ene.zonaV = 1; //Estamos arriba
	else
		ene.zonaV = 0; //Abajo
	//Decidimos si estamos dentro y si estamos encima
	if (ene.getPos().x < xmax && ene.getPos().x > xmin)
	{
		if (ene.zonaV == 0) { //Sigue igual si esta debajo
			if (ene.getPos().y > ymax) {
				ene.setPos(ene.getPos().x, ymax);
				ene.setVel(ene.vel, 0.0f);
				ene.setAc(0.0f, -9.8f);
			}
		}
		else //Si está arriba
		{
			if (ene.getPos().y < ymin) {
				
				//ene.setColor(1, 1, 1);
				ene.flagdibujar = 0;
			}
		}
	}
}

void Interaccion::rebote(Hombre & h, EnemigoDisp e,VidasRec& v)
{

	if (h.hitbox.compareRight(e.hitbox)) {
		h.posicion.x -= 2;

	}
	if (h.hitbox.compareLeft(e.hitbox)) {
		h.posicion.x += 2;

	}
	if (h.hitbox.compareUp(e.hitbox)) {
		h.posicion.y -= 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;
	}
	if (h.hitbox.compareDown(e.hitbox)) {
		h.posicion.y += 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;
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
		b.prx = 0;
	else
		b.prx = 1;
	if (b.posicion.y < h.posicion.y + h.altura / 2)
		b.pry = 0;
	else
		b.pry = 1;


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
	rebote(v, c.suelo);
	/*rebote(v, c.pozo1_dcha);
	rebote(v, c.pozo1_izq);
	rebote(v, c.pozo2_dcha);
	rebote(v, c.pozo2_izq);
	rebote(v, c.pozo3_dcha);
	rebote(v, c.pozo3_izq);
	rebote(v, c.pozo4_dcha);
	rebote(v, c.pozo4_izq);*/
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
	rebote(m, c.suelo);
	/*rebote(m, c.pozo1_dcha);
	rebote(m, c.pozo1_izq);
	rebote(m, c.pozo2_dcha);
	rebote(m, c.pozo2_izq);
	rebote(m, c.pozo3_dcha);
	rebote(m, c.pozo3_izq);
	rebote(m, c.pozo4_dcha);
	rebote(m, c.pozo4_izq);*/
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
void Interaccion::colision(Hombre& h, Bonus& b) {
	//gestion de comportamiento
	if (h.hitbox.zonaH == 0 && h.hitbox.zonaV == -1) {//entrando por abajo
		if (h.hitbox.esquina1.y > b.hitbox.esquina3.y)
			//b.setColor(10.0, 0.0, 0.0);
			h.posicion.y -= 2;
	}else
	if (h.hitbox.zonaH == 0 && h.hitbox.zonaV == 1) {//entrando por arriba
		if (h.hitbox.esquina3.y < b.hitbox.esquina1.y) {
			h.posicion.y += 2;
			h.velocidad.y = 0.0f;
		}
	}else
	if (h.hitbox.zonaV == 0 && h.hitbox.zonaH == -1) {//entrando por la izquierda
		if (h.hitbox.esquina2.x > b.hitbox.esquina1.x)
			h.posicion.x -= 2;
	}else
	if (h.hitbox.zonaV == 0 && h.hitbox.zonaH == 1) {//entrando por la derecha
		if (h.hitbox.esquina1.x < b.hitbox.esquina2.x)
			h.posicion.x += 2;
	}
	//comprobar posicion horizontal relativa
	if (h.hitbox.esquina1.x > b.hitbox.esquina2.x)
		h.hitbox.zonaH = 1;		//h derecha de b
	if (h.hitbox.esquina2.x < b.hitbox.esquina1.x)
		h.hitbox.zonaH = -1;	//h izquierda de b
	if (h.hitbox.esquina1.x > b.hitbox.esquina1.x && h.hitbox.esquina2.x < b.hitbox.esquina2.x)
		h.hitbox.zonaH = 0;		//h dentro de b
	//comprobar posicion vertical relativa
	if (h.hitbox.esquina1.y < b.hitbox.esquina3.y)
		h.hitbox.zonaV = -1;
	if (h.hitbox.esquina3.y > b.hitbox.esquina1.y)
		h.hitbox.zonaV = 1;
	if (h.hitbox.esquina1.y < b.hitbox.esquina1.y && h.hitbox.esquina3.y > b.hitbox.esquina3.y)
		h.hitbox.zonaV = 0;
	

	/*if (h.hitbox.compareRight(b.hitbox)) {
		h.posicion.x -= 2;

	}
	if (h.hitbox.compareLeft(b.hitbox)) {
		h.posicion.x += 2;

	}
	if (h.hitbox.compareUp(b.hitbox)) {
		h.posicion.y -= 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;
	}
	if (h.hitbox.compareDown(b.hitbox)) {
		/*h.posicion.y += 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;*/
	//	b.setColor(1.0, 0, 0);
	//}
}
void Interaccion::colision(Hombre& h, Pincho b) {

	if (h.hitbox.compareRight(b.hitbox)) {
		h.posicion.x -= 2;

	}
	if (h.hitbox.compareLeft(b.hitbox)) {
		h.posicion.x += 2;

	}
	if (h.hitbox.compareUp(b.hitbox)) {
		h.posicion.y -= 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;
	}
	if (h.hitbox.compareDown(b.hitbox)) {
		h.posicion.y += 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;
		//b.setColor(1.0, 0, 0);
	}
}

void Interaccion::colision(Hombre& h, DisparosEnemigos& de) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x)
			de.setColor(0, 1, 0);
}

void Interaccion::colision(Hombre& h, Babosa& ene) {

}


void Interaccion::colision(EnemigoDisp& h, disparosAmigos& de) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x)
			de.setColor(0, 1, 0);
}
void Interaccion::colision(Tank& h, disparosAmigos& de) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x)
			de.setColor(0, 1, 0);
}
void Interaccion::colision(Babosa& h, disparosAmigos& de) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x)
			de.setColor(0, 1, 0);
}
/*void Interaccion::colision(Tentaculo& h, disparosAmigos& de) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x)
			de.setColor(0, 1, 0);
}*/
void Interaccion::colision(bomber& h, disparosAmigos& de) {
	if ((h.getPos() - de.getPos()).modulo() < (h.radio + de.getRadio()))
		de.setColor(0, 1, 0);
}

void Interaccion::colision(listaEnemDisp ene, listaDispAmig da) {
	for (int i = 0; i < da.numero; i++)
		for (int j = 0; j < ene.numero; j++)
			colision(*ene.lista[j], *da.lista[i]);
}
void Interaccion::colision(listaTank ene, listaDispAmig da) {
	for (int i = 0; i < da.numero; i++)
		for (int j = 0; j < ene.numero; j++)
			colision(*ene.lista[j], *da.lista[i]);
}
void Interaccion::colision(listaBabosas ene, listaDispAmig da) {
	for (int i = 0; i < da.numero; i++)
		for (int j = 0; j < ene.numero; j++)
			colision(*ene.lista[j], *da.lista[i]);
}
/*void Interaccion::colision(listaTentaculo ene, listaDispAmig da) {
	for (int i = 0; i < da.numero; i++)
		for (int j = 0; j < ene.numero; j++)
			colision(*ene.lista[j], *da.lista[i]);
}*/
void Interaccion::colision(listabomber ene, listaDispAmig da) {
	for (int i = 0; i < da.numero; i++)
		for (int j = 0; j < ene.numero; j++)
			colision(*ene.lista[j], *da.lista[i]);
}
float DistSegmento(segmento s1, disparosAmigos p1) {
	float delta_x = s1.x1 - s1.x2;
	float delta_y = s1.y1 - s1.y2;
	float Segment = delta_x * delta_x + delta_y * delta_y;
	float S = sqrt(Segment);
	float h11 = s1.x1 - p1.getPos().x;
	float h12 = s1.y1 - p1.getPos().y;
	float normh1 = h11 * h11 + h12 * h12;
	float h1 = sqrt(normh1);
	float h21 = s1.x2 - p1.getPos().x;
	float h22 = s1.y2 - p1.getPos().y;
	float normh2 = h21 * h21 + h22 * h22;
	float h2 = sqrt(normh2);
	float d;
	float termino1 = h2 * h2;
	float termino2 = S / 2 + (h2 * h2) / (2 * S) - (h1 * h1) / (2 * S);
	float t2 = termino2 * termino2;
	float aux = termino1 - t2;
	d = sqrt(aux);
	if ((sqrt((h1 * h1) - (d * d)) < S) && sqrt((h2 * h2) - (d * d)) < S) {

		return d;
	}
	else {
		if (h1 > S) {
			d = sqrt((s1.x2 - p1.getPos().x) * (s1.x2 - p1.getPos().x) + (s1.y2 - p1.getPos().y) * (s1.y2 - p1.getPos().y));
			return d;
		}
		if (h2 > S) {
			d = sqrt((s1.x1 - p1.getPos().x) * (s1.x1 - p1.getPos().x) + (s1.y1 - p1.getPos().y) * (s1.y1 - p1.getPos().y));
			return d;
		}
	}

}
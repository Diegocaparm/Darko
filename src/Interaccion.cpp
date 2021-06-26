#include "Interaccion.h"
#include <math.h>
#include "stdio.h"
#define pi 3.14159265

//Funciones auxiliares
bool DistHitbox(Hitbox h, Vector2D e)
{
	if (h.top_r.x<e.x && h.top_l.x>e.x && h.top_r.y > e.y && h.bot_r.y < e.y)
		return true;		//solo funciona con rectangulos
	else
		return false;
}
float DistSeg(Hitbox h, Vector2D p);
//float DistSegmento(segmento s1, Vector2D p);

//Rebote del PJ con los SOLIDOS llamados todos desde la lista
void Interaccion::rebote(Personaje& h, Solidos s, VidasRecolectadas& v)
{
	//EStá por necesidad, pero no tiene porque tener nada
}
void Interaccion::rebote(Personaje& h, Pared p, VidasRecolectadas& v)
{
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - h.altura;//arr
	
	if (p.limite1.y==p.limite2.y) {
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
	else if (sqrt((h.posicion.x - xmin) * (h.posicion.x - xmin)) < 0.7) {	
		if (h.hitbox.top_r.x > xmin + 0.2)
			h.zonaH = 1;	//dcha
		else if(h.hitbox.top_l.x < xmin - 0.2)
			h.zonaH = 0;	//izq
		if (h.hitbox.bot_r.y < p.limite1.y-0.5 && h.hitbox.bot_r.y > p.limite2.y) 
		{  //zona=0 izq    zona=1 dcha
			if (h.zonaH == 0) {
				if (h.hitbox.top_l.x > xmax) {
					h.posicion.x = xmin - 0.4;
					h.velocidad.x = 0.0f;
					h.aceleracion.y = -9.8f;
				}
			}
			else
				if (h.hitbox.top_r.x < xmin) {
					h.posicion.x = xmax + 0.4;
					h.velocidad.x = 0.0f;
					h.aceleracion.y = -9.8f;
				}
		}
	}
}
void Interaccion::rebote(Personaje& h, PlatMovil pm, VidasRecolectadas& v)
{
	float xmin = pm.limite2.x;//izq
	float xmax = pm.limite1.x;//dcha
	float ymin = pm.limite2.y;//ab
	float ymax = pm.limite1.y - h.altura;//arr

	if (pm.limite1.y == pm.limite2.y) {
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
	/*
	else if (sqrt((h.posicion.x - xmin) * (h.posicion.x - xmin)) < 0.7) {
		if (h.hitbox.esquina1.x > xmin + 0.2)
			h.zonaH = 1;	//dcha
		else if (h.hitbox.esquina2.x < xmin - 0.2)
			h.zonaH = 0;	//izq
		if (h.hitbox.esquina3.y < pm.limite1.y - 0.5 && h.hitbox.esquina3.y > pm.limite2.y) {  //zona=0 izq    zona=1 dcha
			if (h.zonaH == 0) {
				if (h.hitbox.esquina2.x > xmax) {
					h.posicion.x = xmin - 0.4;
					h.velocidad.x = 0.0f;
					h.aceleracion.y = -9.8f;
				}
			}
			else
				if (h.hitbox.esquina1.x < xmin) {
					h.posicion.x = xmax + 0.4;
					h.velocidad.x = 0.0f;
					h.aceleracion.y = -9.8f;
				}
		}
	}*/
}
void Interaccion::rebote(Personaje& h, Suelo s, VidasRecolectadas& v)
{
	//Tampoco tiene porque tener nada pero si que tiene que estar
}
void Interaccion::rebote(Personaje& h, Pincho p, VidasRecolectadas& v)
{
	bool b1, b2, b3, b4;
	b1 = DistHitbox(h.hitbox, p.hitbox.top_r);
	b2 = DistHitbox(h.hitbox, p.hitbox.top_l);
	b3 = DistHitbox(h.hitbox, p.hitbox.bot_r);
	b4 = DistHitbox(h.hitbox, p.hitbox.bot_l);
	if (b1 || b2 || b3 || b4) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}
}
void Interaccion::rebote(Personaje& h, Caja c, VidasRecolectadas& v)
{
	//Generamos los límites de la caja en el eje x
	float xmin = c.pared_izq.limite2.x;
	float xmax = c.techo.limite1.x - 0.1f;
	if (h.posicion.x > xmax) {
		h.posicion.x = xmax;
	}
	if (h.posicion.x < xmin) {
		h.posicion.x = xmin;
	}
	//Tratamos los rebotes del techo y los suelos como plataformas standar
	rebote(h, c.techo, v);
	rebote(h, c.suelo, v);
}

//Recoleccion del PJ
bool Interaccion::recoleccion(Corazon& c, Personaje h)
{
	bool dentro = DistHitbox(h.hitbox, c.posicion);
	return dentro;
}
bool Interaccion::recoleccion(Moneda& m, Personaje h)
{
	bool dentro = DistHitbox(h.hitbox, m.posicion);
	return dentro;
}

//Rebote de los enemigos con los solidos y la caja
void Interaccion::enemrebote(Enemigo& e, Solidos s)
{
}
void Interaccion::enemrebote(Enemigo& e, Pared p)
{
}
void Interaccion::enemrebote(Enemigo& e, PlatMovil pm)
{
}
void Interaccion::enemrebote(Enemigo& e, Suelo s)
{
}
void Interaccion::enemrebote(Enemigo& e, Pincho p)
{
}
void Interaccion::enemrebote(Enemigo& e, Caja c)
{
}

void Interaccion::enemrebote(EnemigoDisp& e, Solidos s)
{
}
void Interaccion::enemrebote(EnemigoDisp& e, Pared p)
{
	//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - e.altura;//arr
	//Decidimos si estamos arriba o abajo
	if (e.posicion.y > ymin - e.altura / 2)
		e.zonaV = 1; //Estamos arriba
	else
		e.zonaV = 0; //Abajo
	//Decidimos si estamos dentro y si estamos encima
	if (e.posicion.x < xmax && e.posicion.x > xmin)
	{
		if (e.zonaV == 0) { //Sigue igual si esta debajo
			if (e.posicion.y > ymax) {
				e.posicion.y = ymax;
				e.velocidad.y = 0.0f;
				e.aceleracion.y = -9.8f;
			}
		}
		else //Si está arriba
		{
			if (e.posicion.y < ymin) {
				e.posicion.y = ymin;
				e.velocidad.y = 0.0f;
			}
			if (e.posicion.x < xmin + 0.5f) {		//cambiar de direccion
				e.sentido = 0;
			}
			if (e.posicion.x > xmax - 0.5f) {
				e.sentido = 1;
			}
		}
	}
}
void Interaccion::enemrebote(EnemigoDisp& e, PlatMovil pm)
{
}
void Interaccion::enemrebote(EnemigoDisp& e, Suelo s)
{
}
void Interaccion::enemrebote(EnemigoDisp& e, Pincho p)
{
}
void Interaccion::enemrebote(EnemigoDisp& e, Caja c)
{
	enemrebote(e, c.techo);
	enemrebote(e, c.pared_dcha);
	enemrebote(e, c.pared_izq);
	enemrebote(e, c.suelo);
}

void Interaccion::enemrebote(Babosa& b, Solidos s)
{
}
void Interaccion::enemrebote(Babosa& b, Pared p)
{
}
void Interaccion::enemrebote(Babosa& b, PlatMovil pm)
{
}
void Interaccion::enemrebote(Babosa& b, Suelo s)
{
}
void Interaccion::enemrebote(Babosa& b, Pincho p)
{
}
void Interaccion::enemrebote(Babosa& b, Caja c)
{
}

void Interaccion::enemrebote(Bomber& b, Solidos s)
{
}
void Interaccion::enemrebote(Bomber& b, Pared p)
{
	/*float xmin = p.limite2.x;//izq
float xmax = p.limite1.x;//dcha
float ymin = p.limite2.y;//ab
float ymax = p.limite1.y - b.radio;//arr
if (b.posicion.y > ymin - b.radio / 2)
	b.zonaV = 1;
else
	b.zonaV = 0;

if (b.posicion.x+b.radio < xmax && b.posicion.x-b.radio > xmin) {  //zona=0 abajo    zona=1 arriba
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

	if (b.posicion.x-b.radio < xmin + 0.5f) {		//cambiar de direccion
		b.sentido = 1;
	}
	if (b.posicion.x+b.radio > xmax - 0.5f) {
		b.sentido = 0;
	}
}*/
//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y;//arr
	if (sqrt((b.hitbox.esquina3.y * ene.hitbox.esquina3.y) + (ymin * ymin)) < 0.5) {
		//Decidimos si estamos arriba o abajo
		if (ene.hitbox.esquina2.y > ymin)
			ene.zonaV = 1; //Estamos arriba
		else
			ene.zonaV = 0; //Abajo
		//Decidimos si estamos dentro y si estamos encima
		if (ene.hitbox.esquina2.x < xmax && ene.hitbox.esquina1.x > xmin)
		{
			if (ene.zonaV == 0) { //Sigue igual si esta debajo
				if (ene.hitbox.esquina1.y > ymax) {
					ene.posicion.y = ymax - ene.radio;
					ene.velocidad.y = 0.0f;
					ene.aceleracion.y = -9.8f;
				}
			}
			else //Si está arriba
			{
				if (ene.hitbox.esquina3.y < ymin) {
					ene.posicion.y = ymin + ene.radio;
					ene.velocidad.y = 0.0f;
				}
				if (ene.hitbox.esquina1.x < xmin + 0.5) {		//cambiar de direccion
					ene.sentido = 0;
				}
				if (ene.hitbox.esquina2.x > xmax - 0.5) {
					ene.sentido = 1;
				}
			}
		}
	}
}
void Interaccion::enemrebote(Bomber& b, PlatMovil pm)
{
}
void Interaccion::enemrebote(Bomber& b, Suelo s)
{
}
void Interaccion::enemrebote(Bomber& b, Pincho p)
{
}
void Interaccion::enemrebote(Bomber& b, Caja c)
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

void Interaccion::enemrebote(Tentaculo& t, Solidos s)
{
}
void Interaccion::enemrebote(Tentaculo& t, Pared p)
{
}
void Interaccion::enemrebote(Tentaculo& t, PlatMovil pm)
{
}
void Interaccion::enemrebote(Tentaculo& t, Suelo s)
{
}
void Interaccion::enemrebote(Tentaculo& t, Pincho p)
{
}
void Interaccion::enemrebote(Tentaculo& t, Caja c)
{
}

void Interaccion::enemrebote(Tank& t, Solidos s)
{

}
void Interaccion::enemrebote(Tank& t, Pared p)
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
void Interaccion::enemrebote(Tank& t, PlatMovil pm)
{

}
void Interaccion::enemrebote(Tank& t, Suelo s)
{

}
void Interaccion::enemrebote(Tank& t, Pincho p)
{

}
void Interaccion::enemrebote(Tank& t, Caja c)
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

void Interaccion::enemrebote(BossFinal& bf, Solidos s)
{

}
void Interaccion::enemrebote(BossFinal& bf, Pared p)
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
void Interaccion::enemrebote(BossFinal& bf, PlatMovil pm)
{

}
void Interaccion::enemrebote(BossFinal& bf, Suelo s)
{

}
void Interaccion::enemrebote(BossFinal& bf, Pincho p)
{

}
void Interaccion::enemrebote(BossFinal& bf, Caja c)
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










/*
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
				ene.velocidad.y = 0.0f;
				//ene.setColor(1, 1, 1);
				ene.flagdibujar = 0;
			}
			if (ene.getPos().x < xmin + 0.5f) {		//cambiar de direccion
				ene.sentido = 0;
			}
			if (ene.getPos().x > xmax - 0.5f) {
				ene.sentido = 1;
			}
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
void Interaccion::rebote(misil& ene, Caja c)
{
	rebote(ene, c.techo);
	rebote(ene, c.pared_dcha);
	rebote(ene, c.pared_izq);
	rebote(ene, c.suelo);
}
void Interaccion::rebote(misil& ene, Pared p)
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
void Interaccion::rebote(Hombre & h, EnemigoDisp e, VidasRec &v)
{
	//int v_aux = v.getVidas();
	if (h.hitbox.compareRight(e.hitbox)) {
		h.posicion.x -= 2;
		v.reduceVida();
		//v.eliminar(v_aux);
	}
	if (h.hitbox.compareLeft(e.hitbox)) {
		h.posicion.x += 2;
		v.reduceVida();

		//v.eliminar(v_aux);
	}
	if (h.hitbox.compareUp(e.hitbox)) {
		h.posicion.y -= 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;
		v.reduceVida();

		//v.eliminar(v_aux);
	}
	if (h.hitbox.compareDown(e.hitbox)) {
		h.posicion.y += 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;
		v.reduceVida();

		//v.eliminar(v_aux);
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
/*void Interaccion::mov(Babosa& b, Hombre& h, VidasRec& v) 
{
	Vector2D dist = b.posicion - h.posicion;
	if (dist.modulo() < 5) {
		b.cerca = 1;

	}
	else
		b.cerca = 0;
	if (b.posicion.x < h.posicion.x)
		b.prx = 0;
	else {
		;
		b.prx = 1;
	}

	if (b.posicion.y < h.posicion.y + h.altura / 2)
		b.pry = 0;
	else
		b.pry = 1;
}*/
/*

void Interaccion::mov(Hombre& h, misil& m,VidasRec &v) {
	Vector2D dist = m.getPos() - h.posicion;
	if (dist.modulo() < 5) {
		m.cerca = 1;
		v.reduceVida();
	}
		

	else
		m.cerca = 0;

	if (m.getPos().x < h.posicion.x)
		m.prx = 0;
	else
		m.prx = 1;
	if (m.getPos().y < h.posicion.y + h.altura / 2)
		m.pry = 0;
	else
		m.pry = 1;


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
	
	//:c
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
	//:D
	/*bool b1, b2, b3, b4;
	b1 = DistHitbox(h.hitbox, b.hitbox.esquina1);
	b2 = DistHitbox(h.hitbox, b.hitbox.esquina2);
	b3 = DistHitbox(h.hitbox, b.hitbox.esquina3);
	b4 = DistHitbox(h.hitbox, b.hitbox.esquina4);
	if (b1 || b2 || b3 || b4)
		b.setColor(0, 1, 0);
}



void Interaccion::colision(Hombre& h, DisparosEnemigos& de, VidasRec &v) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x) {
			de.setColor(0, 1, 0);
			v.reduceVida();

		}
			
}

void Interaccion::colision(Hombre& h, misil& m, VidasRec &v) {
	if (m.getPos().y - m.getRadio() < h.hitbox.esquina1.y && m.getPos().y + m.getRadio() > h.hitbox.esquina3.y)
		if (m.getPos().x - m.getRadio() < h.hitbox.esquina2.x && m.getPos().x + m.getRadio() > h.hitbox.esquina1.x) {
			v.reduceVida();
			m.setColor(0, 1, 0);
		}
			

}

void Interaccion::colision(Hombre& h, Babosa& ene, VidasRec &v) {
	bool b1, b2, b3, b4;
	b1 = DistHitbox(h.hitbox, ene.hitbox.esquina1);
	b2 = DistHitbox(h.hitbox, ene.hitbox.esquina2);
	b3 = DistHitbox(h.hitbox, ene.hitbox.esquina3);
	b4 = DistHitbox(h.hitbox, ene.hitbox.esquina4);
	bool b5, b6, b7, b8;
	b5 = DistHitbox(ene.hitbox, h.hitbox.esquina1);
	b6 = DistHitbox(ene.hitbox, h.hitbox.esquina2);
	b7 = DistHitbox(ene.hitbox, h.hitbox.esquina3);
	b8 = DistHitbox(ene.hitbox, h.hitbox.esquina4);
	if (b1 || b2 || b3 || b4 || b5 || b6 || b7 || b8) {
		v.reduceVida();
		ene.setColor(0, 1, 0);
	}
		
}

void Interaccion::colision(Hombre& h, bomber& ene, VidasRec& v) {
	if ((h.getPos() - ene.getPos()).modulo() < 4) {
		ene.flag=1;
	}
	if (ene.flag) {
		ene.temp--;
		ene.setVelx(0);
	}
	if (ene.temp == 0) {
		ene.radio = 6;
		v.reduceVida();
	}
}

void Interaccion::colision(Hombre& h, Tentaculo& ene, VidasRec &v) {
	for (int i = 0; i < 3; i++) {
		float dist1 = DistSeg(ene.hitbox[i], h.hitbox.esquina1),
			dist2 = DistSeg(ene.hitbox[i], h.hitbox.esquina2),
			dist3 = DistSeg(ene.hitbox[i], h.hitbox.esquina3),
			dist4 = DistSeg(ene.hitbox[i], h.hitbox.esquina4);
		if (dist1 < 0.2 || dist2 < 0.2 || dist3 < 0.2 || dist4 < 0.2) {
			v.reduceVida();
			h.setColor(0, 1, 0);
		}
			
	}
}

bool Interaccion::colision(EnemigoDisp& h, disparosAmigos& de) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x) {
			de.setColor(0, 1, 0);
			h.flagdmg = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
			return true;
		}
	return false;
}

bool Interaccion::colision(Tank& h, disparosAmigos& de) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x) {
			de.setColor(0, 1, 0);
			h.flagdmg = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
			return true;
		}
	return false;
}

bool Interaccion::colision(Babosa& h, disparosAmigos& de) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x)
		{
			de.setColor(0, 1, 0);
			h.flagdmg = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
			return true;
		}
	return false;
}

bool Interaccion::colision(Tentaculo& h, disparosAmigos& de) {
	/*if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x)
			de.setColor(0, 1, 0);*/
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			float dist = DistSegmento(h.hitbox[i].segmento[j], de.getPos());
			
			if (dist < de.getRadio())
				de.setColor(0, 1, 0);
		}

	}
	for (int i = 0; i < 3; i++) {
		float dist1 = DistSeg(h.hitbox[i], de.getPos());
		if (dist1 < de.getRadio())
		{
			de.setColor(0, 1, 0);
			h.flagdmg = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
			return true;
		}
		return false;
		/*else
			de.setColor(1, 0, 0);*/
	//}
	/*bool b1;
	for (int i = 0; i < 3; i++) {
		b1 = DistHitbox(h.hitbox[i], de.getPos());

		if (b1)
			de.setColor(0, 1, 0);
	}
}

bool Interaccion::colision(bomber& h, disparosAmigos& de) {
	if ((h.getPos() - de.getPos()).modulo() < (h.radio + de.getRadio())) 
		{
			de.setColor(0, 1, 0);
			h.flagdmg = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
			return true;
		}
		return false;
}

bool Interaccion::colision(bossFinal& h, disparosAmigos& de) {
	if (de.getPos().y - de.getRadio() < h.hitbox.esquina1.y && de.getPos().y + de.getRadio() > h.hitbox.esquina3.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.esquina2.x && de.getPos().x + de.getRadio() > h.hitbox.esquina1.x)
		{
			de.setColor(0, 1, 0);
			h.flagdmg = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
			return true;
		}
	return false;
}

void Interaccion::colision(listaEnemDisp ene, listaDispAmig da) {
	for (int i = 0; i < da.numero; i++)
		for (int j = 0; j < ene.numero; j++) {
			colision(*ene.lista[j], *da.lista[i]);
			if (colision(*ene.lista[j], *da.lista[i])) {
				da.eliminar(i);
			}
		}
			
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

void Interaccion::colision(listaTentaculo ene, listaDispAmig da) {
	for (int i = 0; i < da.numero; i++)
		for (int j = 0; j < ene.numero; j++)
			Interaccion::colision(*ene.lista[j], *da.lista[i]);
}

void Interaccion::colision(listabomber ene, listaDispAmig da) {
	for (int i = 0; i < da.numero; i++)
		for (int j = 0; j < ene.numero; j++)
			colision(*ene.lista[j], *da.lista[i]);
}

void Interaccion::colision(bossFinal ene, listaDispAmig da) {
	for (int i = 0; i < da.numero; i++)
		colision(ene, *da.lista[i]);
}

void Interaccion::mov(espada& esp, Hombre& h) {
	esp.setPos(h.getPos().x, h.getPos().y+h.altura/2);
}

void Interaccion::colision(listaEnemDisp ene, espada esp) {
	for (int j = 0; j < ene.numero; j++)
		colision(*ene.lista[j], esp);
}

void Interaccion::colision(listaTank ene, espada esp) {
	for (int j = 0; j < ene.numero; j++)
		colision(*ene.lista[j], esp);
}

void Interaccion::colision(listaBabosas ene, espada esp) {
	for (int j = 0; j < ene.numero; j++)
		colision(*ene.lista[j], esp);
}

void Interaccion::colision(listaTentaculo ene, espada esp) {
	for (int j = 0; j < ene.numero; j++)
		colision(*ene.lista[j], esp);
}

void Interaccion::colision(listabomber ene, espada esp) {
	for (int j = 0; j < ene.numero; j++)
		colision(*ene.lista[j], esp);
}

void Interaccion::colision(EnemigoDisp& h, espada& esp) {
	if (esp.getPos().y - esp.getLong() < h.hitbox.esquina1.y && esp.getPos().y + esp.getLong() > h.hitbox.esquina3.y)
		if (esp.getPos().x - esp.getLong() < h.hitbox.esquina2.x && esp.getPos().x + esp.getLong() > h.hitbox.esquina1.x)
		{
			esp.setColor(0, 1, 0);
			h.flagdmg = 1;
			h.flagesp = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
		}
}

void Interaccion::colision(Tank& h, espada& esp) {
	if (esp.getPos().y - esp.getLong() < h.hitbox.esquina1.y && esp.getPos().y + esp.getLong() > h.hitbox.esquina3.y)
		if (esp.getPos().x - esp.getLong() < h.hitbox.esquina2.x && esp.getPos().x + esp.getLong() > h.hitbox.esquina1.x)
		{
			esp.setColor(0, 1, 0);
			h.flagdmg = 1;
			h.flagesp = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
		}
}

void Interaccion::colision(Babosa& h, espada& esp) {
	if (esp.getPos().y - esp.getLong() < h.hitbox.esquina1.y && esp.getPos().y + esp.getLong() > h.hitbox.esquina3.y)
		if (esp.getPos().x - esp.getLong() < h.hitbox.esquina2.x && esp.getPos().x + esp.getLong() > h.hitbox.esquina1.x)
		{
			esp.setColor(0, 1, 0);
			h.flagdmg = 1;
			h.flagesp = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
		}
}

void Interaccion::colision(Tentaculo& h, espada& esp) {
	for (int i = 0; i < 3; i++) {
		float dist1 = DistSeg(h.hitbox[i], esp.getPos());
		if (dist1 < esp.getLong())
		{
			esp.setColor(0, 1, 0);
			h.flagdmg = 1;
			h.flagesp = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
		}
	}
}

void Interaccion::colision(bomber& h, espada& esp) {
	if ((h.getPos() - esp.getPos()).modulo() < (h.radio + esp.getLong()))
	{
		esp.setColor(0, 1, 0);
		h.flagdmg = 1;
		h.flagesp = 1;
		if (h.tempdmg == 0)
			h.tempdmg = 40;
	}

}

void Interaccion::colision(bossFinal& h, espada& esp) {
	if (esp.getPos().y - esp.getLong() < h.hitbox.esquina1.y && esp.getPos().y + esp.getLong() > h.hitbox.esquina3.y)
		if (esp.getPos().x - esp.getLong() < h.hitbox.esquina2.x && esp.getPos().x + esp.getLong() > h.hitbox.esquina1.x)
		{
			esp.setColor(0, 1, 0);
			h.flagdmg = 1;
			h.flagesp = 1;
			if (h.tempdmg == 0)
				h.tempdmg = 40;
		}
}

float DistSegmento(segmento s1, Vector2D p1) {
	float delta_x = s1.x1 - s1.x2;
	float delta_y = s1.y1 - s1.y2;
	float Segment = delta_x * delta_x + delta_y * delta_y;
	float S = sqrt(Segment);
	float h11 = s1.x1 - p1.x;
	float h12 = s1.y1 - p1.y;
	float normh1 = h11 * h11 + h12 * h12;
	float h1 = sqrt(normh1);
	float h21 = s1.x2 - p1.x;
	float h22 = s1.y2 - p1.y;
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
			d = sqrt((s1.x2 - p1.x) * (s1.x2 - p1.x) + (s1.y2 - p1.y) * (s1.y2 - p1.y));
			return d;
		}
		if (h2 > S) {
			d = sqrt((s1.x1 - p1.x) * (s1.x1 - p1.x) + (s1.y1 - p1.y) * (s1.y1 - p1.y));
			return d;
		}
	}

}

float DistSeg(Hitbox h, Vector2D p) 
{
	float //m1 = (h.esquina1 - h.esquina2).modulo(),
		m2 = (h.esquina2 - h.esquina4).modulo(),
		//m3 = (h.esquina3 - h.esquina4).modulo(),
		m4 = (h.esquina1 - h.esquina3).modulo();
	float h1 = (h.esquina1 - p).modulo(),
		h2 = (h.esquina2 - p).modulo(),
		h3 = (h.esquina3 - p).modulo(),
		h4 = (h.esquina4 - p).modulo();
	float a1 = (h3 * h3 - h1 * h1 + m2 * m2) / (2 * m2),
		a2 = (h4 * h4 - h2 * h2 + m4 * m4) / (2 * m4),
		d1 = sqrt(h3 * h3 - a1 * a1),
		d2 = sqrt(h4 * h4 - a2 * a2);
	if (d1 < d2)
		return d1;
	else 
		return d2;
}

void Interaccion::colision(Hombre& h, BolaFuego& bola) {
	bool b1, b2, b3, b4;
	b1 = DistHitbox(h.hitbox, bola.hitbox.esquina1);
	b2 = DistHitbox(h.hitbox, bola.hitbox.esquina2);
	b3 = DistHitbox(h.hitbox, bola.hitbox.esquina3);
	b4 = DistHitbox(h.hitbox, bola.hitbox.esquina4);
	if (b1 || b2 || b3 || b4)
		bola.setColor(0, 1, 0);
}

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
float DistSeg(Hitbox h, Vector2D p) {
	float //m1 = (h.esquina1 - h.esquina2).modulo(),
		m2 = (h.top_r - h.bot_r).modulo(),
		//m3 = (h.esquina3 - h.esquina4).modulo(),
		m4 = (h.top_l - h.bot_l).modulo();
	float h1 = (h.top_l - p).modulo(),
		h2 = (h.top_r - p).modulo(),
		h3 = (h.bot_l - p).modulo(),
		h4 = (h.bot_r - p).modulo();
	float a1 = (h3 * h3 - h1 * h1 + m2 * m2) / (2 * m2),
		a2 = (h4 * h4 - h2 * h2 + m4 * m4) / (2 * m4),
		d1 = sqrt(h3 * h3 - a1 * a1),
		d2 = sqrt(h4 * h4 - a2 * a2);
	if (d1 < d2)
		return d1;
	else return d2;
}

//////////////////////////////////////////////////////////////////// PJ
//Entorno
void Interaccion::rebote(Personaje& h, ListaSolidos ls, VidasRecolectadas& v) {
	for(int i = 0; i < ls.numero; i++)
		rebote(h, *ls.lista[i], v);
}
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
void Interaccion::rebote(Personaje& h, Final p, VidasRecolectadas& v)
{
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - h.altura;//arr

	if (p.limite1.y == p.limite2.y) {
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
			else //Estamos arriba, hemos pasado el nivel
				if (h.posicion.y < ymin) {
					h.posicion.y = ymin;
					h.velocidad.y = 0.0f;
					h.flagnivel++; //Aumenta el nivel que se crea
					h.setPos(-4, 11); //Y posiciona al PJ al inicio de este
				}
		}
	}
	else if (sqrt((h.posicion.x - xmin) * (h.posicion.x - xmin)) < 0.7) {
		if (h.hitbox.top_r.x > xmin + 0.2)
			h.zonaH = 1;	//dcha
		else if (h.hitbox.top_l.x < xmin - 0.2)
			h.zonaH = 0;	//izq
		if (h.hitbox.bot_r.y < p.limite1.y - 0.5 && h.hitbox.bot_r.y > p.limite2.y)
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
void Interaccion::rebote(Personaje& h, BolaFuego b, VidasRecolectadas& v)
{
	bool b1, b2, b3, b4;
	b1 = DistHitbox(h.hitbox, b.hitbox.top_l);
	b2 = DistHitbox(h.hitbox, b.hitbox.top_r);
	b3 = DistHitbox(h.hitbox, b.hitbox.bot_l);
	b4 = DistHitbox(h.hitbox, b.hitbox.bot_r);
	if (b1 || b2 || b3 || b4)
	{
		b.setColor(0, 1, 0);
		v.reduceVida();
	}
}
void Interaccion::rebote(Personaje& h, Caja c, VidasRecolectadas& v)
{
	//Generamos los límites de la caja en el eje x
	float xmin = c.pared_izq.limite2.x + 0.1f;
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
//Recolectables
bool Interaccion::recoleccion(Corazon& c, Personaje h)
{
	bool dentro = DistHitbox(h.hitbox, c.posicion);
	return dentro;
}
Corazon* Interaccion::recoleccion(Vidas& v,Personaje h)
{
	for (int i = 0; i < v.numero; i++)
	{
		if (Interaccion::recoleccion(*(v.lista[i]), h))
			return v.lista[i];
	}
	return 0; //no hay colisión
}
bool Interaccion::recoleccion(Moneda& m, Personaje h)
{
	bool dentro = DistHitbox(h.hitbox, m.posicion);
	return dentro;
}
Moneda* Interaccion::recoleccion(Dinero& d, Personaje h)
{
	for (int i = 0; i < d.numero; i++)
	{
		if (Interaccion::recoleccion(*d.lista[i], h))
			return d.lista[i];
	}
	return 0; //no hay colisión
}
//Espada y disparos buenos
void Interaccion::mov(Espada& esp, Personaje& h) {
	esp.setPos(h.getPos().x, h.getPos().y + h.altura / 2);
}
//Disparos malos y misiles
void Interaccion::colision(Personaje& h, ListaDisparos ld, VidasRecolectadas& v)
{
	for (int i = 0; i < ld.numero;i++)
		colision(h, *ld.lista[i], v);
}
void Interaccion::colision(Personaje& h, Disparos& d, VidasRecolectadas& v) {
}
void Interaccion::colision(Personaje& h, DisparosEnemigos& de, VidasRecolectadas& v) {
	if (de.getPos().y - de.getRadio() < h.hitbox.top_l.y && de.getPos().y + de.getRadio() > h.hitbox.bot_l.y)
		if (de.getPos().x - de.getRadio() < h.hitbox.top_r.x && de.getPos().x + de.getRadio() > h.hitbox.top_l.x) {
			de.setColor(0, 1, 0);
			v.reduceVida();
		}
}
void Interaccion::colision(Personaje& h, Misiles& m, VidasRecolectadas& v) {
	if (m.getPos().y - m.getRadio() < h.hitbox.top_l.y && m.getPos().y + m.getRadio() > h.hitbox.bot_l.y)
		if (m.getPos().x - m.getRadio() < h.hitbox.top_r.x && m.getPos().x + m.getRadio() > h.hitbox.top_l.x) {
			m.setColor(0, 1, 0);
			v.reduceVida();
		}
	Vector2D dist = m.getPos() - h.getPos();
	if (dist.modulo() < 5) {
		m.cerca = 1;
		v.reduceVida();
	}
	else
		m.cerca = 0;
	if (m.getPos().x < h.getPos().x)
		m.prx = 0;
	else
		m.prx = 1;
	if (m.getPos().y < h.getPos().y + h.altura / 2)
		m.pry = 0;
	else
		m.pry = 1;
}
//Enemigos y listas
void Interaccion::colision(Personaje& h, ListaEnemigos le, VidasRecolectadas& v)
{
	for (int i = 0; i < le.numero; i++)
		colision(h, *le.lista[i], v);
}
void Interaccion::colision(Personaje& h, Enemigo& ene, VidasRecolectadas& v) {
	float dist1 = DistSeg(ene.hitbox, h.hitbox.top_l),
		dist2 = DistSeg(ene.hitbox, h.hitbox.top_r),
		dist3 = DistSeg(ene.hitbox, h.hitbox.bot_l),
		dist4 = DistSeg(ene.hitbox, h.hitbox.bot_r);
	if (dist1 < 0.2 || dist2 < 0.2 || dist3 < 0.2 || dist4 < 0.2) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}
}
void Interaccion::colision(Personaje& h, EnemigoDisp& e, VidasRecolectadas& v)
{
	float dist1 = DistSeg(e.hitbox, h.hitbox.top_l),
		dist2 = DistSeg(e.hitbox, h.hitbox.top_r),
		dist3 = DistSeg(e.hitbox, h.hitbox.bot_l),
		dist4 = DistSeg(e.hitbox, h.hitbox.bot_r);
	if (dist1 < 0.2 || dist2 < 0.2 || dist3 < 0.2 || dist4 < 0.2) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}
}
void Interaccion::colision(Personaje& h, Babosa& ene, VidasRecolectadas& v) {
	float dist1 = DistSeg(ene.hitbox, h.hitbox.top_l),
		dist2 = DistSeg(ene.hitbox, h.hitbox.top_r),
		dist3 = DistSeg(ene.hitbox, h.hitbox.bot_l),
		dist4 = DistSeg(ene.hitbox, h.hitbox.bot_r);
	if (dist1 < 0.2 || dist2 < 0.2 || dist3 < 0.2 || dist4 < 0.2) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}
	Vector2D dist = ene.getPos() - h.getPos();
	if (dist.modulo() < 5) {
		ene.cerca = 1;
	}
	else
		ene.cerca = 0;
	if (ene.getPos().x < h.getPos().x)
		ene.prx = 0;
	else {
		;
		ene.prx = 1;
	}
	if (ene.getPos().y < h.getPos().y + h.altura / 2)
		ene.pry = 0;
	else
		ene.pry = 1;
}
void Interaccion::colision(Personaje& h, Tentaculo& ene, VidasRecolectadas& v) {
	float dist1 = DistSeg(ene.hitbox, h.hitbox.top_l),
		dist2 = DistSeg(ene.hitbox, h.hitbox.top_r),
		dist3 = DistSeg(ene.hitbox, h.hitbox.bot_l),
		dist4 = DistSeg(ene.hitbox, h.hitbox.bot_r);
	if (dist1 < 0.2 || dist2 < 0.2 || dist3 < 0.2 || dist4 < 0.2) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}
}//3 hitboxes
void Interaccion::colision(Personaje& h, Bomber& ene, VidasRecolectadas& v) {
	float dist1 = DistSeg(ene.hitbox, h.hitbox.top_l),
		dist2 = DistSeg(ene.hitbox, h.hitbox.top_r),
		dist3 = DistSeg(ene.hitbox, h.hitbox.bot_l),
		dist4 = DistSeg(ene.hitbox, h.hitbox.bot_r);
	if (dist1 < 0.2 || dist2 < 0.2 || dist3 < 0.2 || dist4 < 0.2) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}

	if ((h.getPos() - ene.getPos()).modulo() < 4) {
		ene.flag = 1;
	}
	if (ene.flag) {
		ene.temp--;
		ene.setVel(0, 0);
	}
	if (ene.temp == 0) {
		ene.altura = 6;
		//v.reduceVida();		//arreglar esto
	}
}
void Interaccion::colision(Personaje& h, Tank& t, VidasRecolectadas& v)
{

}
void Interaccion::colision(Personaje& h, BossFinal& b, VidasRecolectadas& v)
{

}
////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////// Enemigos
//Entorno
void Interaccion::rebote(ListaEnemigos le, ListaSolidos ls)
{
	for (int i = 0; i < le.numero; i++)
		for (int j = 0; j < ls.numero; j++)
			rebote(*le.lista[i], *ls.lista[j]);
}
void Interaccion::rebote(Enemigo& e, Solidos s)
{
		//esta tiene cosas porque varios enemigos se 
		//comportan igual: EnemigoDisp, Tank, Boss, Bomber
		//asi que se eliminan las correspondientes para que elija estas
}
void Interaccion::rebote(Enemigo& e, Pared p)
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
void Interaccion::rebote(Enemigo& e, PlatMovil pm)
{
}
void Interaccion::rebote(Enemigo& e, Suelo s)
{
}
void Interaccion::rebote(Enemigo& e, Final p)
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
void Interaccion::rebote(Enemigo& e, Pincho p)
{
}
void Interaccion::rebote(Enemigo& e, BolaFuego b)
{
}
/*void Interaccion::rebote(Enemigo& e, Caja c)
{
	rebote(e, c.techo);
	rebote(e, c.pared_dcha);
	rebote(e, c.pared_izq);
	rebote(e, c.suelo);
}*/
void Interaccion::rebote(EnemigoDisp& e, Solidos s)
{
}
/*
void Interaccion::rebote(EnemigoDisp& e, Pared p)
{
	
}*/
void Interaccion::rebote(EnemigoDisp& e, PlatMovil pm)
{
}
void Interaccion::rebote(EnemigoDisp& e, Suelo s)
{
}
void Interaccion::rebote(EnemigoDisp& e, Final p)
{

}
void Interaccion::rebote(EnemigoDisp& e, Pincho p)
{
}
void Interaccion::rebote(EnemigoDisp& e, BolaFuego p)
{
}
/*void Interaccion::rebote(EnemigoDisp& e, Caja c)
{
	
}*/
void Interaccion::rebote(Babosa& b, Solidos s)
{
}
void Interaccion::rebote(Babosa& b, Pared p)
{
}
void Interaccion::rebote(Babosa& b, PlatMovil pm)
{
}
void Interaccion::rebote(Babosa& b, Suelo s)
{
}
void Interaccion::rebote(Babosa& b, Final p)
{
}
void Interaccion::rebote(Babosa& b, Pincho p)
{
}
void Interaccion::rebote(Babosa& b, BolaFuego p)
{
}
/*void Interaccion::rebote(Babosa& b, Caja c)
{
}*/
void Interaccion::rebote(Bomber& b, Solidos s)
{
}
/*void Interaccion::rebote(Bomber& b, Pared p)
{
//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y;//arr
	if (sqrt((b.hitbox.bot_l.y * b.hitbox.bot_l.y) + (ymin * ymin)) < 0.5) {
		//Decidimos si estamos arriba o abajo
		if (b.hitbox.top_r.y > ymin)
			b.zonaV = 1; //Estamos arriba
		else
			b.zonaV = 0; //Abajo
		//Decidimos si estamos dentro y si estamos encima
		if (b.hitbox.top_r.x < xmax && b.hitbox.top_l.x > xmin)
		{
			if (b.zonaV == 0) { //Sigue igual si esta debajo
				if (b.hitbox.top_l.y > ymax) {
					b.posicion.y = ymax - b.altura;
					b.velocidad.y = 0.0f;
					b.aceleracion.y = -9.8f;
				}
			}
			else //Si está arriba
			{
				if (b.hitbox.bot_l.y < ymin) {
					b.posicion.y = ymin + b.altura;
					b.velocidad.y = 0.0f;
				}
				if (b.hitbox.top_l.x < xmin + 0.5) {		//cambiar de direccion
					b.sentido = 0;
				}
				if (b.hitbox.top_r.x > xmax - 0.5) {
					b.sentido = 1;
				}
			}
		}
	}
}*/
void Interaccion::rebote(Bomber& b, PlatMovil pm)
{
}
void Interaccion::rebote(Bomber& b, Suelo s)
{
}
void Interaccion::rebote(Bomber& b, Final p)
{
}
void Interaccion::rebote(Bomber& b, Pincho p)
{
}
void Interaccion::rebote(Bomber& b, BolaFuego p)
{
}
/*void Interaccion::rebote(Bomber& b, Caja c)
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
	float ymax = c.pared_dcha.limite1.y - b.altura;
	if (b.posicion.y > ymax) {
		b.posicion.y = ymax;
		b.velocidad.y = 0.0f;
		b.aceleracion.y = -9.8f;
	}
	if (b.posicion.y < ymin) {
		b.posicion.y = ymin;
	}
}*/
void Interaccion::rebote(Tentaculo& t, Solidos s)
{
}
void Interaccion::rebote(Tentaculo& t, Pared p)
{
}
void Interaccion::rebote(Tentaculo& t, PlatMovil pm)
{
}
void Interaccion::rebote(Tentaculo& t, Suelo s)
{
}
void Interaccion::rebote(Tentaculo& t, Final p)
{
}
void Interaccion::rebote(Tentaculo& t, Pincho p)
{
}
void Interaccion::rebote(Tentaculo& t, BolaFuego p)
{
}
/*void Interaccion::rebote(Tentaculo& t, Caja c)
{
}*/
void Interaccion::rebote(Tank& t, Solidos s)
{

}
/*void Interaccion::rebote(Tank& t, Pared p)
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
}*/
void Interaccion::rebote(Tank& t, PlatMovil pm)
{

}
void Interaccion::rebote(Tank& t, Suelo s)
{

}
void Interaccion::rebote(Tank& t, Final p)
{
}
void Interaccion::rebote(Tank& t, Pincho p)
{

}
void Interaccion::rebote(Tank& t, BolaFuego p)
{
}
/*void Interaccion::rebote(Tank& t, Caja c)
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
}*/
void Interaccion::rebote(BossFinal& bf, Solidos s)
{

}
/*void Interaccion::rebote(BossFinal& bf, Pared p)
{
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - bf.altura;//arr
	if (bf.posicion.y > ymin - bf.altura / 2)
		bf.zonaV = 1;
	else
		bf.zonaV = 0;

	if (bf.posicion.x < xmax && bf.posicion.x > xmin) {  //zona=0 abajo    zona=1 arriba
		if (bf.zonaV == 0) {
			if (bf.posicion.y > ymax) {
				bf.posicion.y = ymax;
				bf.velocidad.y = 0.0f;
				bf.aceleracion.y = -9.8f;
			}
		}
		else
			if (bf.posicion.y < ymin) {
				bf.posicion.y = ymin;
				bf.velocidad.y = 0.0f;
				//	ene.aceleracion.y = -9.8f;
			}

		if (bf.posicion.x < xmin + 0.5f) {		//cambiar de direccion
			bf.sentido = 1;
		}
		if (bf.posicion.x > xmax - 0.5f) {
			bf.sentido = 0;
		}
	}
}*/
void Interaccion::rebote(BossFinal& bf, PlatMovil pm)
{

}
void Interaccion::rebote(BossFinal& bf, Suelo s)
{

}
void Interaccion::rebote(BossFinal& bf, Final p)
{
}
void Interaccion::rebote(BossFinal& bf, Pincho p)
{

}
void Interaccion::rebote(BossFinal& bf, BolaFuego p)
{
}
/*void Interaccion::rebote(BossFinal& bf, Caja c)
{
	float xmin = c.techo.limite2.x;
	float xmax = c.techo.limite1.x;
	if (bf.posicion.x > xmax) {
		bf.posicion.x = xmax;
	}
	if (bf.posicion.x < xmin) {
		bf.posicion.x = xmin;
	}


	float ymin = c.pared_dcha.limite2.y;
	float ymax = c.pared_dcha.limite1.y - bf.altura;
	if (bf.posicion.y > ymax) {
		bf.posicion.y = ymax;
		bf.velocidad.y = 0.0f;
		bf.aceleracion.y = -9.8f;
	}
	if (bf.posicion.y < ymin) {
		bf.posicion.y = ymin;
	}
}*/
//Espada y disparos buenos
void Interaccion::colision(Espada esp, ListaEnemigos le)
{
	for (int i = 0; i < le.numero; i++)
		colision(*le.lista[i], esp);
}
void Interaccion::colision(Espada esp, Enemigo e)
{

}
void Interaccion::colision(Espada esp, EnemigoDisp e)
{
	if (esp.getPos().y - esp.getLong() < e.hitbox.top_l.y && esp.getPos().y + esp.getLong() > e.hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < e.hitbox.top_r.x && esp.getPos().x + esp.getLong() > e.hitbox.top_l.x)
		{
			e.setColor(0, 1, 0);
			e.flagdmg = 1;
			e.flagesp = 1;
			if (e.tempdmg == 0)
				e.tempdmg = 40;
		}
}
void Interaccion::colision(Espada esp, Babosa b)
{
	if (esp.getPos().y - esp.getLong() < b.hitbox.top_l.y && esp.getPos().y + esp.getLong() > b.hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < b.hitbox.top_r.x && esp.getPos().x + esp.getLong() > b.hitbox.top_l.x)
		{
			b.setColor(0, 1, 0);
			b.flagdmg = 1;
			b.flagesp = 1;
			if (b.tempdmg == 0)
				b.tempdmg = 40;
		}
}
void Interaccion::colision(Espada esp, Bomber b)
{
	if (esp.getPos().y - esp.getLong() < b.hitbox.top_l.y && esp.getPos().y + esp.getLong() > b.hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < b.hitbox.top_r.x && esp.getPos().x + esp.getLong() > b.hitbox.top_l.x)
		{
			b.setColor(0, 1, 0);
			b.flagdmg = 1;
			b.flagesp = 1;
			if (b.tempdmg == 0)
				b.tempdmg = 40;
		}
}
void Interaccion::colision(Espada esp, Tentaculo t)
{
	if (esp.getPos().y - esp.getLong() < t.hitbox.top_l.y && esp.getPos().y + esp.getLong() > t.hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < t.hitbox.top_r.x && esp.getPos().x + esp.getLong() > t.hitbox.top_l.x)
		{
			t.setColor(0, 1, 0);
			t.flagdmg = 1;
			t.flagesp = 1;
			if (t.tempdmg == 0)
				t.tempdmg = 40;
		}
}
void Interaccion::colision(Espada esp, Tank t)
{
	if (esp.getPos().y - esp.getLong() < t.hitbox.top_l.y && esp.getPos().y + esp.getLong() > t.hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < t.hitbox.top_r.x && esp.getPos().x + esp.getLong() > t.hitbox.top_l.x)
		{
			t.setColor(0, 1, 0);
			t.flagdmg = 1;
			t.flagesp = 1;
			if (t.tempdmg == 0)
				t.tempdmg = 40;
		}
}
void Interaccion::colision(Espada esp, BossFinal b)
{
	if (esp.getPos().y - esp.getLong() < b.hitbox.top_l.y && esp.getPos().y + esp.getLong() > b.hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < b.hitbox.top_r.x && esp.getPos().x + esp.getLong() > b.hitbox.top_l.x)
		{
			b.setColor(0, 1, 0);
			b.flagdmg = 1;
			b.flagesp = 1;
			if (b.tempdmg == 0)
				b.tempdmg = 40;
		}
}
void Interaccion::colision(ListaDisparos ld, ListaEnemigos le)
{
	for (int i = 0; i < le.numero; i++)
		for (int j = 0; j < ld.numero; j++)
			colision(*ld.lista[i], *le.lista[j]);
}
void Interaccion::colision(Disparos d, Enemigo e)
{
}
void Interaccion::colision(Disparos d, EnemigoDisp e)
{
}
void Interaccion::colision(Disparos d, Babosa b)
{
}
void Interaccion::colision(Disparos d, Bomber b)
{
}
void Interaccion::colision(Disparos d, Tentaculo t)
{
}
void Interaccion::colision(Disparos d, Tank t)
{
}
void Interaccion::colision(Disparos d, BossFinal b)
{
}
void Interaccion::colision(DisparosAmigos d, ListaEnemigos le)
{
	for (int i = 0; i < le.numero; i++)
		colision(d, *le.lista[i]);
}
void Interaccion::colision(DisparosAmigos d, Enemigo e)
{
	if (d.getPos().y - d.getRadio() < e.hitbox.top_l.y && d.getPos().y + d.getRadio() > e.hitbox.bot_l.y)
		if (d.getPos().x - d.getRadio() < e.hitbox.top_r.x && d.getPos().x + d.getRadio() > e.hitbox.top_l.x) {
			d.setColor(0, 1, 0);
			e.flagdmg = 1;
			if (e.tempdmg == 0)
				e.tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos d, EnemigoDisp e)
{
	if (d.getPos().y - d.getRadio() < e.hitbox.top_l.y && d.getPos().y + d.getRadio() > e.hitbox.bot_l.y)
		if (d.getPos().x - d.getRadio() < e.hitbox.top_r.x && d.getPos().x + d.getRadio() > e.hitbox.top_l.x) {
			d.setColor(0, 1, 0);
			e.flagdmg = 1;
			if (e.tempdmg == 0)
				e.tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos d, Babosa b)
{
	if (d.getPos().y - d.getRadio() < b.hitbox.top_l.y && d.getPos().y + d.getRadio() > b.hitbox.bot_l.y)
		if (d.getPos().x - d.getRadio() < b.hitbox.top_r.x && d.getPos().x + d.getRadio() > b.hitbox.top_l.x) {
			d.setColor(0, 1, 0);
			b.flagdmg = 1;
			if (b.tempdmg == 0)
				b.tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos d, Bomber b)
{
	if (d.getPos().y - d.getRadio() < b.hitbox.top_l.y && d.getPos().y + d.getRadio() > b.hitbox.bot_l.y)
		if (d.getPos().x - d.getRadio() < b.hitbox.top_r.x && d.getPos().x + d.getRadio() > b.hitbox.top_l.x) {
			d.setColor(0, 1, 0);
			b.flagdmg = 1;
			if (b.tempdmg == 0)
				b.tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos d, Tentaculo t)
{
	if (d.getPos().y - d.getRadio() < t.hitbox.top_l.y && d.getPos().y + d.getRadio() > t.hitbox.bot_l.y)
		if (d.getPos().x - d.getRadio() < t.hitbox.top_r.x && d.getPos().x + d.getRadio() > t.hitbox.top_l.x) {
			d.setColor(0, 1, 0);
			t.flagdmg = 1;
			if (t.tempdmg == 0)
				t.tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos d, Tank t)
{
	if (d.getPos().y - d.getRadio() < t.hitbox.top_l.y && d.getPos().y + d.getRadio() > t.hitbox.bot_l.y)
		if (d.getPos().x - d.getRadio() < t.hitbox.top_r.x && d.getPos().x + d.getRadio() > t.hitbox.top_l.x) {
			d.setColor(0, 1, 0);
			t.flagdmg = 1;
			if (t.tempdmg == 0)
				t.tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos d, BossFinal b)
{
	if (d.getPos().y - d.getRadio() < b.hitbox.top_l.y && d.getPos().y + d.getRadio() > b.hitbox.bot_l.y)
		if (d.getPos().x - d.getRadio() < b.hitbox.top_r.x && d.getPos().x + d.getRadio() > b.hitbox.top_l.x) {
			d.setColor(0, 1, 0);
			b.flagdmg = 1;
			if (b.tempdmg == 0)
				b.tempdmg = 40;
		}
}
////////////////////////////////////////////////////////////////////












//encontrarle un nuevo hogar a lo que haya aqui
/*
void Interaccion::rebote(listaObjetoMovil om, ListaSolidos so) {
	for (int i = 0; i < om.numero; i++)
		for (int j = 0; j < so.numero; j++)
			rebote(*om.lista[i], *so.lista[j]);
}*/
void Interaccion::rebote(ObjetoMovil om, Solidos s) {
	//no se si tiene que hacer algo o se llama 
	//a los correspondientes directamente
	//objetomovil->enemigo,disparo,personaje->especifico
}
void Interaccion::rebote(ObjetoMovil& ob, Caja c) {
	rebote(ob, c.techo);
	rebote(ob, c.pared_dcha);
	rebote(ob, c.pared_izq);
	rebote(ob, c.suelo);
}
void Interaccion::rebote(Disparos& ene, Pared p)
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
				ene.setColor(1, 1, 1);
				//ene.flagdibujar = 0;
			}
		}
	}
}
/*
void Interaccion::rebote(Personaje& h, listaObjetoMovil om, VidasRecolectadas& vidasR) {
	for (int i = 0; i < om.numero; i++)
		colision(h, *om.lista[i], vidasR);
}
void Interaccion::colision(Personaje& h, ObjetoMovil& om, VidasRecolectadas& v) {
}



void Interaccion::rebote(listaObjetoMovil om, listaObjetoMovil om2) {
	for (int i = 0; i < om.numero; i++)
		for (int j = 0; j < om2.numero; j++)
			rebote(*om.lista[i], *om2.lista[j]);
}*/
void Interaccion::rebote(ObjetoMovil ob1, ObjetoMovil ob2) {

}




/*
void Interaccion::colision(listaObjetoMovil om, Espada es) {
	for (int i = 0; i < om.numero; i++)
		for (int j = 0; j < om.numero; j++)
			rebote(*om.lista[i], es);
}*/
void Interaccion::colision(ObjetoMovil ob1, Espada esp) {

}




/*void Interaccion::rebote(disparosEnemigos& ene, Caja c)
{
	rebote(ene, c.techo);
	rebote(ene, c.pared_dcha);
	rebote(ene, c.pared_izq);
	rebote(ene, c.suelo);
}*/

/*void Interaccion::rebote(disparosEnemigos& ene, Pared p)
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
				ene.setColor(1, 1, 1);
				//ene.flagdibujar = 0;
			}
		}
	}
}*/
/*void Interaccion::rebote(disparosAmigos& ene, Caja c)
{
	rebote(ene, c.techo);
	rebote(ene, c.pared_dcha);
	rebote(ene, c.pared_izq);
	rebote(ene, c.suelo);
}*/
/*void Interaccion::rebote(disparosAmigos& ene, Pared p)
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
				
				ene.setColor(1, 1, 1);
				//ene.flagdibujar = 0;
			}
		}
	}
}*/
/*void Interaccion::rebote(misiles& ene, Caja c)
{
	rebote(ene, c.techo);
	rebote(ene, c.pared_dcha);
	rebote(ene, c.pared_izq);
	rebote(ene, c.suelo);
}*/
/*void Interaccion::rebote(misiles& ene, Pared p)
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

				ene.setColor(1, 1, 1);
				//ene.flagdibujar = 0;
			}
		}
	}
}*/
/*
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



/*void Interaccion::colision(Hombre& h, Bonus& b) {
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
}/*



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
	*/


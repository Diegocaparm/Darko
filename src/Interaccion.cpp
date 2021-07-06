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
	float //m1 = (h.top_l - h.top_r).modulo(),
		m2 = (h.top_r - h.bot_r).modulo(),
		//m3 = (h.bot_l - h.bot_r).modulo(),
		m4 = (h.top_l - h.bot_l).modulo();
	float h1 = (h.top_l - p).modulo(),
		h2 = (h.top_r - p).modulo(),
		h3 = (h.bot_l - p).modulo(),
		h4 = (h.bot_r - p).modulo();
	float a1 = (h3 * h3 - h1 * h1 + m2 * m2) / (2 * m2),
		a2 = (h4 * h4 - h2 * h2 + m4 * m4) / (2 * m4),
		d1 = sqrt(h3 * h3 - a1 * a1),
		d2 = sqrt(h4 * h4 - a2 * a2);
	if (h.top_l.y > p.y && h.bot_l.y < p.y)
		if (d1 < d2)
			return d1;
		else return d2;
	else return 1;
}
bool Interaccion::ColisionGen(Hitbox& ene, Hitbox& h, VidasRecolectadas& v) {
	float dist1 = DistSeg(ene, h.top_l),
		dist2 = DistSeg(ene, h.top_r),
		dist3 = DistSeg(ene, h.bot_l),
		dist4 = DistSeg(ene, h.bot_r);
	if (dist1 < 0.2 || dist2 < 0.2 || dist3 < 0.2 || dist4 < 0.2) {
		return true;
	}
	else return false;
}

//////////////////////////////////////////////////////////////////// PJ
//Entorno
void Interaccion::rebote(Personaje& h, ListaSolidos ls, VidasRecolectadas& v) {
	for(int i = 0; i < ls.numero; i++)
		rebote(h, ls.lista[i], v);
}
void Interaccion::rebote(Personaje& h, Solidos *s, VidasRecolectadas& v)
{
	//Está por necesidad, pero no tiene porque tener nada
	if (s->cosa == 1) {
		Pared* p;
		p = dynamic_cast <Pared*> (s);
		Interaccion::rebote(h, p, v);
	}
	else if (s->cosa == 2) {
		PlatMovil* p;
		p = dynamic_cast <PlatMovil*> (s);
		Interaccion::rebote(h, p, v);
	}
	else if (s->cosa == 3) {
		Suelo* p;
		p = dynamic_cast <Suelo*> (s);
		Interaccion::rebote(h, p, v);
	}
	else if (s->cosa == 4) {
		Final* p;
		p = dynamic_cast <Final*> (s);
		Interaccion::rebote(h, p, v);
	}
	else if (s->cosa == 5) {
		Pincho *p;
		p = dynamic_cast <Pincho*> (s);
		Interaccion::rebote(h, p, v);
	}
	else if (s->cosa == 6) {
		BolaFuego* p;
		p = dynamic_cast <BolaFuego*> (s);
		Interaccion::rebote(h, p, v);
	}

}
void Interaccion::rebote(Personaje& h, Pared *p, VidasRecolectadas& v)
{
	float xmin = p->limite2.x;//izq
	float xmax = p->limite1.x;//dcha
	float ymin = p->limite2.y;//ab
	float ymax = p->limite1.y - h.altura;//arr
	
	if (p->limite1.y==p->limite2.y) {
		if (h.posicion.y > ymin - h.altura / 2)
			h.zonaV = 1;
		else
			h.zonaV = 0;

		if (h.posicion.x < xmax && h.posicion.x > xmin) {  //zona=0 abajo    zona=1 arriba
			if (h.zonaV == 0) { //Esta abajo
				if (h.posicion.y > ymax) {
					h.posicion.y = ymax;
					h.velocidad.y = 0.0f;
					h.aceleracion.y = -9.8f;
				}
			}
			else //Está arriba
				if (h.posicion.y < ymin) {
					h.posicion.y = ymin;
					h.velocidad.y = 0.0f;
					h.salto = 1;
					//	h.aceleracion.y = -9.8f;
				}
		}
	}
	else if (sqrt(pow(h.posicion.x - xmin, 2) < 0.7) && p->limite1.x == p->limite2.x) {
		if (h.hitbox.top_l.x > xmin + 0.2)
			h.zonaH = 1;	//dcha
		else if(h.hitbox.top_r.x < xmin - 0.2)
			h.zonaH = 0;	//izq
		if (h.hitbox.bot_r.y < p->limite1.y-0.5 && h.hitbox.bot_r.y > p->limite2.y)
		{  //zona=0 izq    zona=1 dcha
			if (h.zonaH == 0) {
				if (h.hitbox.top_r.x > xmax) {
					h.posicion.x = xmin - 0.4;
					h.velocidad.x = 0.0f;
					h.aceleracion.y = -9.8f;
				}
			}
			else
				if (h.hitbox.top_l.x < xmin) {
					h.posicion.x = xmax + 0.4;
					h.velocidad.x = 0.0f;
					h.aceleracion.y = -9.8f;
				}
		}
	}
}
void Interaccion::rebote(Personaje& h, PlatMovil* pm, VidasRecolectadas& v)
{
	float xmin = pm->limite1.x;//izq
	float xmax = pm->limite2.x;//dcha
	float ymin = pm->limite2.y;//ab
	float ymax = pm->limite1.y - h.altura;//arr

	if (pm->limite1.y == pm->limite2.y) {
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
					h.velocidad = pm->vel;
					h.salto = 1;
				}
		}
	}
	/*
	else if (sqrt((h.posicion.x - xmin) * (h.posicion.x - xmin)) < 0.7) {
		if (h.hitbox.top_l.x > xmin + 0.2)
			h.zonaH = 1;	//dcha
		else if (h.hitbox.top_r.x < xmin - 0.2)
			h.zonaH = 0;	//izq
		if (h.hitbox.bot_l.y < pm.limite1.y - 0.5 && h.hitbox.bot_l.y > pm.limite2.y) {  //zona=0 izq    zona=1 dcha
			if (h.zonaH == 0) {
				if (h.hitbox.top_r.x > xmax) {
					h.posicion.x = xmin - 0.4;
					h.velocidad.x = 0.0f;
					h.aceleracion.y = -9.8f;
				}
			}
			else
				if (h.hitbox.top_l.x < xmin) {
					h.posicion.x = xmax + 0.4;
					h.velocidad.x = 0.0f;
					h.aceleracion.y = -9.8f;
				}
		}
	}*/
}
void Interaccion::rebote(Personaje& h, Suelo* s, VidasRecolectadas& v)
{
	//Tampoco tiene porque tener nada pero si que tiene que estar
}
void Interaccion::rebote(Personaje& h, Final* p, VidasRecolectadas& v)
{
	float xmin = p->limite2.x;//izq
	float xmax = p->limite1.x;//dcha
	float ymin = p->limite2.y;//ab
	float ymax = p->limite1.y - h.altura;//arr

	if (p->limite1.y == p->limite2.y) {
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
					h.setPos(-4, 16); //Y posiciona al PJ al inicio de este
				}
		}
	}
	else if (sqrt((h.posicion.x - xmin) * (h.posicion.x - xmin)) < 0.7) {
		if (h.hitbox.top_r.x > xmin + 0.2)
			h.zonaH = 1;	//dcha
		else if (h.hitbox.top_l.x < xmin - 0.2)
			h.zonaH = 0;	//izq
		if (h.hitbox.bot_r.y < p->limite1.y - 0.5 && h.hitbox.bot_r.y > p->limite2.y)
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
void Interaccion::rebote(Personaje& h, Pincho *p, VidasRecolectadas& v)
{
	if (ColisionGen(p->hitbox, h.hitbox, v)) {
		v.reduceVida();
		h.setColor(0, 1, 1);
	}
}
void Interaccion::rebote(Personaje& h, BolaFuego* b, VidasRecolectadas& v)
{
	bool b1, b2, b3, b4;
	b1 = DistHitbox(h.hitbox, b->hitbox.top_l);
	b2 = DistHitbox(h.hitbox, b->hitbox.top_r);
	b3 = DistHitbox(h.hitbox, b->hitbox.bot_l);
	b4 = DistHitbox(h.hitbox, b->hitbox.bot_r);
	if (b1 || b2 || b3 || b4)
	{
		b->setColor(0, 1, 0);
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
	rebote(h, &c.techo, v);
	rebote(h, &c.suelo, v);
}
//Recolectables
bool Interaccion::recoleccion(Corazon& c, Personaje h)
{
	/*bool dentro = DistHitbox(h.hitbox, c.posicion);
	return dentro;*/
	Vector2D pos = h.getPos(); //la posicion de la base del hombre
	pos.y += h.altura / 2.0f; //posicion del centro
	float distancia = (c.posicion - pos).modulo();
	if (distancia < c.radio)
		return true;
	return false;
}
bool Interaccion::recoleccion(Moneda& m, Personaje h)
{
	/*bool dentro = DistHitbox(h.hitbox, m.posicion);
	return dentro;*/
	Vector2D pos = h.getPos(); //la posicion de la base del hombre
	pos.y += h.altura / 2.0f; //posicion del centro
	float distancia = (m.posicion - pos).modulo();
	if (distancia < m.radio)
		return true;
	return false;
}
//Espada y disparos buenos
void Interaccion::mov(Espada& esp, Personaje& h) {
	esp.setPos(h.getPos().x, h.getPos().y + h.altura / 2);
}
//Disparos malos y misiles
void Interaccion::colision(Personaje& h, ListaDisparos ld, VidasRecolectadas& v)
{
	for (int i = 0; i < ld.numero;i++)
		colision(h, ld.lista[i], v);
}
void Interaccion::colision(Personaje& h, Disparos* d, VidasRecolectadas& v) {
	if (d->cosa == 2) {
		DisparosEnemigos* p;
		p = dynamic_cast <DisparosEnemigos*> (d);
		Interaccion::colision(h, p, v);
	}
	else if (d->cosa == 3) {
		Misiles* p;
		p = dynamic_cast <Misiles*> (d);
		Interaccion::colision(h, p, v);
	}
}
void Interaccion::colision(Personaje& h, DisparosEnemigos* de, VidasRecolectadas& v) {
	if (de->getPos().y - de->getRadio() < h.hitbox.top_l.y && de->getPos().y + de->getRadio() > h.hitbox.bot_l.y)
		if (de->getPos().x - de->getRadio() < h.hitbox.top_r.x && de->getPos().x + de->getRadio() > h.hitbox.top_l.x) {
			de->setColor(0, 1, 0);
			v.reduceVida();
		}
}
void Interaccion::colision(Personaje& h, Misiles* m, VidasRecolectadas& v) {
	if (m->getPos().y - m->getRadio() < h.hitbox.top_l.y && m->getPos().y + m->getRadio() > h.hitbox.bot_l.y)
		if (m->getPos().x - m->getRadio() < h.hitbox.top_r.x && m->getPos().x + m->getRadio() > h.hitbox.top_l.x) {
			m->setColor(0, 1, 0);
			v.reduceVida();
		}
	Vector2D dist = m->getPos() - h.getPos();
	if (dist.modulo() < 5) {
		m->cerca = 1;
		v.reduceVida();
	}
	else
		m->cerca = 0;
	if (m->getPos().x < h.getPos().x)
		m->prx = 0;
	else
		m->prx = 1;
	if (m->getPos().y < h.getPos().y + h.altura / 2)
		m->pry = 0;
	else
		m->pry = 1;
}
//Enemigos y listas
void Interaccion::colision(Personaje& h, ListaEnemigos le, VidasRecolectadas& v)
{
	for (int i = 0; i < le.numero; i++) {
		if (le.lista[i]->cosa == 3) {
			Babosa* p;
			p = dynamic_cast <Babosa*> (le.lista[i]);
			Interaccion::colision(h, p, v);
		}
		else if (le.lista[i]->cosa == 4) {
			Bomber* p;
			p = dynamic_cast <Bomber*> (le.lista[i]);
			Interaccion::colision(h, p, v);
		}
		else if (le.lista[i]->cosa == 5) {
			Tentaculo* p;
			p = dynamic_cast <Tentaculo*> (le.lista[i]);
			Interaccion::colision(h, p, v);
		}
		else
			colision(h, *le.lista[i], v);
	}
}
void Interaccion::colision(Personaje& h, Enemigo& ene, VidasRecolectadas& v) {
	if (ColisionGen(ene.hitbox, h.hitbox, v)) {
		v.reduceVida();
		h.setColor(0, 1, 1);
	}
}
void Interaccion::colision(Personaje& h, EnemigoDisp& e, VidasRecolectadas& v)
{
	/*float dist1 = DistSeg(e.hitbox, h.hitbox.top_l),
		dist2 = DistSeg(e.hitbox, h.hitbox.top_r),
		dist3 = DistSeg(e.hitbox, h.hitbox.bot_l),
		dist4 = DistSeg(e.hitbox, h.hitbox.bot_r);
	if (dist1 < 0.2 || dist2 < 0.2 || dist3 < 0.2 || dist4 < 0.2) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}*/
}
void Interaccion::colision(Personaje& h, Babosa* ene, VidasRecolectadas& v) {
	if (ColisionGen(ene->hitbox, h.hitbox, v)) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}
	Vector2D dist = ene->getPos() - h.getPos();
	if (dist.modulo() < 5) {
		ene->cerca = 1;
	}
	else
		ene->cerca = 0;
	if (ene->getPos().x < h.getPos().x)
		ene->prx = 0;
	else {
		ene->prx = 1;
	}
	if (ene->getPos().y < h.getPos().y + h.altura / 2)
		ene->pry = 0;
	else
		ene->pry = 1;
}
void Interaccion::colision(Personaje& h, Tentaculo* ene, VidasRecolectadas& v) {
	for (int i = 0; i < 3; i++) {
		float dist1 = DistSeg(ene->hitbox[i], h.hitbox.top_l),
			dist2 = DistSeg(ene->hitbox[i], h.hitbox.top_r),
			dist3 = DistSeg(ene->hitbox[i], h.hitbox.bot_l),
			dist4 = DistSeg(ene->hitbox[i], h.hitbox.bot_r);
		if (dist1 < 0.2 || dist2 < 0.2 || dist3 < 0.2 || dist4 < 0.2) {
			v.reduceVida();
			h.setColor(0, 1, 0);
		}

	}
}//3 hitboxes
void Interaccion::colision(Personaje& h, Bomber* ene, VidasRecolectadas& v) {
	if (ColisionGen(ene->hitbox, h.hitbox, v)) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}

	if ((h.getPos() - ene->getPos()).modulo() < 4) {
		ene->flag = 1;
	}
	if (ene->flag) {
		ene->temp--;
		ene->setVel(0, 0);
	}
	if (ene->temp == 0) {
		ene->altura = 6;
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
			rebote(le.lista[i], ls.lista[j]);
}
void Interaccion::rebote(Enemigo* e, Solidos* s)
{
	//esta tiene cosas porque varios enemigos se 
	//comportan igual: EnemigoDisp, Tank, Boss, Bomber
	//asi que se eliminan las correspondientes para que elija estas
	if (e->cosa == 1) {
		EnemigoDisp* ene;
		ene = dynamic_cast <EnemigoDisp*> (e);
		Interaccion::rebote(ene, s);
	}
	else if (e->cosa == 2) {
		Tank* ene;
		ene = dynamic_cast <Tank*> (e);
		Interaccion::rebote(ene, s);
	}
	else if (e->cosa == 3) {
		Babosa* ene;
		ene = dynamic_cast <Babosa*> (e);
		Interaccion::rebote(ene, s);
	}
	else if (e->cosa == 4) {
		Bomber* ene;
		ene = dynamic_cast <Bomber*> (e);
		Interaccion::rebote(ene, s);
	}
	else if (e->cosa == 5) {
		Tentaculo* ene;
		ene = dynamic_cast <Tentaculo*> (e);
		Interaccion::rebote(ene, s);
	}
	else if (e->cosa == 6) {
		BossFinal* ene;
		ene = dynamic_cast <BossFinal*> (e);
		Interaccion::rebote(ene, s);
	}
}
void Interaccion::rebote(Enemigo* e, Pared* p)
{
	//Ponemos los limites de la plataforma
	if (sqrt(pow(e->posicion.y - p->limite1.y, 2)) < 1) {
		float xmin = p->limite2.x;//izq
		float xmax = p->limite1.x;//dcha
		float ymin = p->limite2.y;//ab
		float ymax = p->limite1.y - e->altura;//arr
		//Decidimos si estamos arriba o abajo
		if (e->posicion.y > ymin - e->altura / 2)
			e->zonaV = 1; //Estamos arriba
		else
			e->zonaV = 0; //Abajo
		//Decidimos si estamos dentro y si estamos encima
		if (e->posicion.x < xmax && e->posicion.x > xmin)
		{
			if (e->zonaV == 0) { //Sigue igual si esta debajo
				if (e->posicion.y > ymax) {
					e->posicion.y = ymax;
					e->velocidad.y = 0.0f;
					e->aceleracion.y = -9.8f;
				}
			}
			else //Si está arriba
			{
				if (e->posicion.y < ymin) {
					e->posicion.y = ymin;
					e->velocidad.y = 0.0f;
				}
				if (e->posicion.x < xmin + 0.5f) {		//cambiar de direccion
					e->sentido = 1;
				}
				if (e->posicion.x > xmax - 0.5f) {
					e->sentido = 0;
				}
			}
		}
	}
}
void Interaccion::rebote(Enemigo* e, PlatMovil pm)
{
}
void Interaccion::rebote(Enemigo* e, Suelo s)
{
}
void Interaccion::rebote(Enemigo* e, Final p)
{
	//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - e->altura;//arr
	//Decidimos si estamos arriba o abajo
	if (e->posicion.y > ymin - e->altura / 2)
		e->zonaV = 1; //Estamos arriba
	else
		e->zonaV = 0; //Abajo
	//Decidimos si estamos dentro y si estamos encima
	if (e->posicion.x < xmax && e->posicion.x > xmin)
	{
		if (e->zonaV == 0) { //Sigue igual si esta debajo
			if (e->posicion.y > ymax) {
				e->posicion.y = ymax;
				e->velocidad.y = 0.0f;
				e->aceleracion.y = -9.8f;
			}
		}
		else //Si está arriba
		{
			if (e->posicion.y < ymin) {
				e->posicion.y = ymin;
				e->velocidad.y = 0.0f;
			}
			if (e->posicion.x < xmin + 0.5f) {		//cambiar de direccion
				e->sentido = 0;
			}
			if (e->posicion.x > xmax - 0.5f) {
				e->sentido = 1;
			}
		}
	}
}
void Interaccion::rebote(Enemigo* e, Pincho p)
{
}
void Interaccion::rebote(Enemigo* e, BolaFuego b)
{
}
/*void Interaccion::rebote(Enemigo& e, Caja c)
{
	rebote(e, c.techo);
	rebote(e, c.pared_dcha);
	rebote(e, c.pared_izq);
	rebote(e, c.suelo);
}*/
void Interaccion::rebote(EnemigoDisp* e, Solidos* s)
{
	if (s->cosa == 1) {
		Pared* p;
		p = dynamic_cast <Pared*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 2) {
		PlatMovil* p;
		p = dynamic_cast <PlatMovil*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 3) {
		Suelo* p;
		p = dynamic_cast <Suelo*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 4) {
		Final* p;
		p = dynamic_cast <Final*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 5) {
		Pincho* p;
		p = dynamic_cast <Pincho*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 6) {
		BolaFuego* p;
		p = dynamic_cast <BolaFuego*> (s);
		Interaccion::rebote(e, p);
	}
}

void Interaccion::rebote(EnemigoDisp* e, Pared* p)
{
	Enemigo* ene;
	ene = dynamic_cast <Enemigo*> (e);
	Interaccion::rebote(ene, p);
}
void Interaccion::rebote(EnemigoDisp* e, PlatMovil* pm)
{
}
void Interaccion::rebote(EnemigoDisp* e, Suelo* s)
{
}
void Interaccion::rebote(EnemigoDisp* e, Final* p)
{

}
void Interaccion::rebote(EnemigoDisp* e, Pincho* p)
{
}
void Interaccion::rebote(EnemigoDisp* e, BolaFuego* p)
{
}
/*void Interaccion::rebote(EnemigoDisp& e, Caja c)
{
	
}*/
void Interaccion::rebote(Babosa* e, Solidos* s)
{
	if (s->cosa == 1) {
		Pared* p;
		p = dynamic_cast <Pared*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 2) {
		PlatMovil* p;
		p = dynamic_cast <PlatMovil*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 3) {
		Suelo* p;
		p = dynamic_cast <Suelo*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 4) {
		Final* p;
		p = dynamic_cast <Final*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 5) {
		Pincho* p;
		p = dynamic_cast <Pincho*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 6) {
		BolaFuego* p;
		p = dynamic_cast <BolaFuego*> (s);
		Interaccion::rebote(e, p);
	}
}
void Interaccion::rebote(Babosa* b, Pared* p)
{
}
void Interaccion::rebote(Babosa* b, PlatMovil* pm)
{
}
void Interaccion::rebote(Babosa* b, Suelo* s)
{
}
void Interaccion::rebote(Babosa* b, Final* p)
{
}
void Interaccion::rebote(Babosa* b, Pincho* p)
{
}
void Interaccion::rebote(Babosa* b, BolaFuego* p)
{
}
/*void Interaccion::rebote(Babosa& b, Caja c)
{
}*/
void Interaccion::rebote(Bomber* e, Solidos* s)
{
	if (s->cosa == 1) {
		Pared* p;
		p = dynamic_cast <Pared*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 2) {
		PlatMovil* p;
		p = dynamic_cast <PlatMovil*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 3) {
		Suelo* p;
		p = dynamic_cast <Suelo*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 4) {
		Final* p;
		p = dynamic_cast <Final*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 5) {
		Pincho* p;
		p = dynamic_cast <Pincho*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 6) {
		BolaFuego* p;
		p = dynamic_cast <BolaFuego*> (s);
		Interaccion::rebote(e, p);
	}
}
void Interaccion::rebote(Bomber* e, Pared* p)
{
	Enemigo* ene;
	ene = dynamic_cast <Enemigo*> (e);
	Interaccion::rebote(ene, p);
}
void Interaccion::rebote(Bomber* b, PlatMovil* pm)
{
}
void Interaccion::rebote(Bomber* b, Suelo* s)
{
}
void Interaccion::rebote(Bomber* b, Final* p)
{
}
void Interaccion::rebote(Bomber* b, Pincho* p)
{
}
void Interaccion::rebote(Bomber* b, BolaFuego* p)
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
void Interaccion::rebote(Tentaculo* e, Solidos* s)
{
	if (s->cosa == 1) {
		Pared* p;
		p = dynamic_cast <Pared*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 2) {
		PlatMovil* p;
		p = dynamic_cast <PlatMovil*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 3) {
		Suelo* p;
		p = dynamic_cast <Suelo*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 4) {
		Final* p;
		p = dynamic_cast <Final*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 5) {
		Pincho* p;
		p = dynamic_cast <Pincho*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 6) {
		BolaFuego* p;
		p = dynamic_cast <BolaFuego*> (s);
		Interaccion::rebote(e, p);
	}
}
void Interaccion::rebote(Tentaculo* t, Pared* p)
{
}
void Interaccion::rebote(Tentaculo* t, PlatMovil* pm)
{
}
void Interaccion::rebote(Tentaculo* t, Suelo* s)
{
}
void Interaccion::rebote(Tentaculo* t, Final* p)
{
}
void Interaccion::rebote(Tentaculo* t, Pincho* p)
{
}
void Interaccion::rebote(Tentaculo* t, BolaFuego* p)
{
}
/*void Interaccion::rebote(Tentaculo& t, Caja c)
{
}*/
void Interaccion::rebote(Tank* e, Solidos* s)
{
	if (s->cosa == 1) {
		Pared* p;
		p = dynamic_cast <Pared*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 2) {
		PlatMovil* p;
		p = dynamic_cast <PlatMovil*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 3) {
		Suelo* p;
		p = dynamic_cast <Suelo*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 4) {
		Final* p;
		p = dynamic_cast <Final*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 5) {
		Pincho* p;
		p = dynamic_cast <Pincho*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 6) {
		BolaFuego* p;
		p = dynamic_cast <BolaFuego*> (s);
		Interaccion::rebote(e, p);
	}
}
void Interaccion::rebote(Tank* e, Pared* p)
{
	Enemigo* ene;
	ene = dynamic_cast <Enemigo*> (e);
	Interaccion::rebote(ene, p);
}
void Interaccion::rebote(Tank* t, PlatMovil* pm)
{

}
void Interaccion::rebote(Tank* t, Suelo* s)
{

}
void Interaccion::rebote(Tank* t, Final* p)
{
}
void Interaccion::rebote(Tank* t, Pincho* p)
{

}
void Interaccion::rebote(Tank* t, BolaFuego* p)
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
void Interaccion::rebote(BossFinal* e, Solidos* s)
{
	if (s->cosa == 1) {
		Pared* p;
		p = dynamic_cast <Pared*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 2) {
		PlatMovil* p;
		p = dynamic_cast <PlatMovil*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 3) {
		Suelo* p;
		p = dynamic_cast <Suelo*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 4) {
		Final* p;
		p = dynamic_cast <Final*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 5) {
		Pincho* p;
		p = dynamic_cast <Pincho*> (s);
		Interaccion::rebote(e, p);
	}
	else if (s->cosa == 6) {
		BolaFuego* p;
		p = dynamic_cast <BolaFuego*> (s);
		Interaccion::rebote(e, p);
	}
}
void Interaccion::rebote(BossFinal* e, Pared* p)
{
	Enemigo* ene;
	ene = dynamic_cast <Enemigo*> (e);
	Interaccion::rebote(ene, p);
}
void Interaccion::rebote(BossFinal* bf, PlatMovil* pm)
{

}
void Interaccion::rebote(BossFinal* bf, Suelo* s)
{

}
void Interaccion::rebote(BossFinal* bf, Final* p)
{
}
void Interaccion::rebote(BossFinal* bf, Pincho* p)
{

}
void Interaccion::rebote(BossFinal* bf, BolaFuego* p)
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
void Interaccion::colision(Espada& esp, ListaEnemigos le)
{
	for (int i = 0; i < le.numero; i++)
		colision(esp, le.lista[i]);
}
void Interaccion::colision(Espada& esp, Enemigo* e)
{
	if (e->cosa == 1) {
		EnemigoDisp* ene;
		ene = dynamic_cast <EnemigoDisp*> (e);
		Interaccion::colision(esp, ene);
	}
	else if (e->cosa == 2) {
		Tank* ene;
		ene = dynamic_cast <Tank*> (e);
		Interaccion::colision(esp, ene);
	}
	else if (e->cosa == 3) {
		Babosa* ene;
		ene = dynamic_cast <Babosa*> (e);
		Interaccion::colision(esp, ene);
	}
	else if (e->cosa == 4) {
		Bomber* ene;
		ene = dynamic_cast <Bomber*> (e);
		Interaccion::colision(esp, ene);
	}
	else if (e->cosa == 5) {
		Tentaculo* ene;
		ene = dynamic_cast <Tentaculo*> (e);
		Interaccion::colision(esp, ene);
	}
	else if (e->cosa == 6) {
		BossFinal* ene;
		ene = dynamic_cast <BossFinal*> (e);
		Interaccion::colision(esp, ene);
	}
}
void Interaccion::colision(Espada& esp, EnemigoDisp* e)
{
	if ((esp.getPos() - e->hitbox.top_l).modulo() < esp.getLong() ||
		(esp.getPos() - e->hitbox.top_r).modulo() < esp.getLong() ||
		(esp.getPos() - e->hitbox.bot_l).modulo() < esp.getLong() ||
		(esp.getPos() - e->hitbox.bot_r).modulo() < esp.getLong())
	{
		e->setColor(0, 1, 0);
		e->flagdmg = 1;
		e->flagesp = 1;
		if (e->tempdmg == 0)
			e->tempdmg = 40;
	}
}
void Interaccion::colision(Espada& esp, Babosa* b)
{
	if (esp.getPos().y - esp.getLong() < b->hitbox.top_l.y && esp.getPos().y + esp.getLong() > b->hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < b->hitbox.top_r.x && esp.getPos().x + esp.getLong() > b->hitbox.top_l.x)
		{
			b->setColor(0, 1, 0);
			b->flagdmg = 1;
			b->flagesp = 1;
			if (b->tempdmg == 0)
				b->tempdmg = 40;
		}
}
void Interaccion::colision(Espada& esp, Bomber* b)
{
	if (esp.getPos().y - esp.getLong() < b->hitbox.top_l.y && esp.getPos().y + esp.getLong() > b->hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < b->hitbox.top_r.x && esp.getPos().x + esp.getLong() > b->hitbox.top_l.x)
		{
			b->setColor(0, 1, 0);
			b->flagdmg = 1;
			b->flagesp = 1;
			if (b->tempdmg == 0)
				b->tempdmg = 40;
		}
}
void Interaccion::colision(Espada& esp, Tentaculo* t)
{
	for (int i = 0; i < 3; i++) {
		float dist1 = DistSeg(t->hitbox[i], esp.getPos());
		if (dist1 < esp.getLong())
		{
			esp.setColor(0, 1, 0);
			t->flagdmg = 1;
			t->flagesp = 1;
			if (t->tempdmg == 0)
				t->tempdmg = 40;
		}
	}
}
void Interaccion::colision(Espada& esp, Tank* t)
{
	if (esp.getPos().y - esp.getLong() < t->hitbox.top_l.y && esp.getPos().y + esp.getLong() > t->hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < t->hitbox.top_r.x && esp.getPos().x + esp.getLong() > t->hitbox.top_l.x)
		{
			t->setColor(0, 1, 0);
			t->flagdmg = 1;
			t->flagesp = 1;
			if (t->tempdmg == 0)
				t->tempdmg = 40;
		}
}
void Interaccion::colision(Espada& esp, BossFinal* b)
{
	if (esp.getPos().y - esp.getLong() < b->hitbox.top_l.y && esp.getPos().y + esp.getLong() > b->hitbox.bot_l.y)
		if (esp.getPos().x - esp.getLong() < b->hitbox.top_r.x && esp.getPos().x + esp.getLong() > b->hitbox.top_l.x)
		{
			b->setColor(0, 1, 0);
			b->flagdmg = 1;
			b->flagesp = 1;
			if (b->tempdmg == 0)
				b->tempdmg = 40;
		}
}
void Interaccion::colision(ListaDisparos ld, ListaEnemigos le)
{
	for (int i = 0; i < le.numero; i++)
		for (int j = 0; j < ld.numero; j++) {
			//int i = 0;
			Interaccion::colision(ld.lista[i], *le.lista[j]);
		}
}
void Interaccion::colision(Disparos* d, Enemigo& e)
{
	if (d->cosa == 1) {							// no esta entrando
		d->setColor(0, 0, 0);
		DisparosAmigos* p;
		p = dynamic_cast <DisparosAmigos*> (d);
		Interaccion::colision(p, e);
	}
	if (d->cosa == 2) {
		d->setColor(1, 0, 1);			//disparos morados
		DisparosEnemigos* p;
		p = dynamic_cast <DisparosEnemigos*> (d);
		//Interaccion::colision(p, e);
	}
	else if (d->cosa == 3) {				//aqui tampoco
		d->setColor(1, 0, 1);
		Misiles* p;
		p = dynamic_cast <Misiles*> (d);
		//Interaccion::colision(p, e);
	}
}
void Interaccion::colision(Disparos* d, EnemigoDisp& e)
{
}
void Interaccion::colision(Disparos* d, Babosa& b)
{
}
void Interaccion::colision(Disparos* d, Bomber& b)
{
}
void Interaccion::colision(Disparos* d, Tentaculo& t)
{
}
void Interaccion::colision(Disparos* d, Tank& t)
{
}
void Interaccion::colision(Disparos* d, BossFinal& b)
{
}
void Interaccion::colision(DisparosAmigos* d, ListaEnemigos& le)
{
	for (int i = 0; i < le.numero; i++)
		Interaccion::colision(d, *le.lista[i]);
}
void Interaccion::colision(DisparosAmigos* d, Enemigo& e)
{
	if (d->getPos().y - d->getRadio() < e.hitbox.top_l.y && d->getPos().y + d->getRadio() > e.hitbox.bot_l.y)
		if (d->getPos().x - d->getRadio() < e.hitbox.top_r.x && d->getPos().x + d->getRadio() > e.hitbox.top_l.x) {
			d->setColor(0, 1, 1);
			e.flagdmg = 1;
			if (e.tempdmg == 0)
				e.tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos* d, EnemigoDisp& e)
{
	if (d->getPos().y - d->getRadio() < e.hitbox.top_l.y && d->getPos().y + d->getRadio() > e.hitbox.bot_l.y)
		if (d->getPos().x - d->getRadio() < e.hitbox.top_r.x && d->getPos().x + d->getRadio() > e.hitbox.top_l.x) {
			d->setColor(0, 1, 1);
			e.flagdmg = 1;
			if (e.tempdmg == 0)
				e.tempdmg = 40;
		}
}
/*void Interaccion::colision(DisparosAmigos* d, Babosa& b)
{
	if (d->getPos().y - d->getRadio() < b.hitbox.top_l.y && d->getPos().y + d->getRadio() > b.hitbox.bot_l.y)
		if (d->getPos().x - d->getRadio() < b.hitbox.top_r.x && d->getPos().x + d->getRadio() > b.hitbox.top_l.x) {
			d->setColor(0, 1, 0);
			b.flagdmg = 1;
			if (b.tempdmg == 0)
				b.tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos* d, Bomber& b)
{
	if (d->getPos().y - d->getRadio() < b.hitbox.top_l.y && d->getPos().y + d->getRadio() > b.hitbox.bot_l.y)
		if (d->getPos().x - d->getRadio() < b.hitbox.top_r.x && d->getPos().x + d->getRadio() > b.hitbox.top_l.x) {
			d->setColor(0, 1, 0);
			b.flagdmg = 1;
			if (b.tempdmg == 0)
				b.tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos* d, Tentaculo& t)
{
	/*if (d->getPos().y - d->getRadio() < t.hitbox.top_l.y && d->getPos().y + d->getRadio() > t.hitbox.bot_l.y)
		if (d->getPos().x - d->getRadio() < t.hitbox.top_r.x && d->getPos().x + d->getRadio() > t.hitbox.top_l.x)
			d->setColor(0, 1, 0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			float dist = DistSeg(t.hitbox[i].segmento[j], d->getPos());
			if (dist < d->getRadio())
				d->setColor(0, 1, 0);
		}

	}
	for (int i = 0; i < 3; i++) {
		float dist1 = DistSeg(t.hitbox[i], d->getPos());
		if (dist1 < d->getRadio())
		{
			d->setColor(0, 1, 0);
			t.flagdmg = 1;
			if (t.tempdmg == 0)
				t.tempdmg = 40;
		}
		else
			d->setColor(1, 0, 0);
	}
	bool b1;
	for (int i = 0; i < 3; i++) {
		b1 = DistHitbox(t.hitbox[i], d->getPos());

		if (b1)
			d->setColor(0, 1, 0);
	}*/
	/*	for (int i = 0; i < 3; i++) {
			float dist1 = DistSeg(t.hitbox[i], d->getPos());
			if (dist1 < d->getRadio())
			{
				d->setColor(0, 1, 0);
				t.flagdmg = 1;
				if (t.tempdmg == 0)
					t.tempdmg = 40;
			}
		}
	}
	void Interaccion::colision(DisparosAmigos* d, Tank& t)
	{
		if (d->getPos().y - d->getRadio() < t.hitbox.top_l.y && d->getPos().y + d->getRadio() > t.hitbox.bot_l.y)
			if (d->getPos().x - d->getRadio() < t.hitbox.top_r.x && d->getPos().x + d->getRadio() > t.hitbox.top_l.x) {
				d->setColor(1, 1, 0);
				t.flagdmg = 1;
				if (t.tempdmg == 0)
					t.tempdmg = 40;
			}
	}
	void Interaccion::colision(DisparosAmigos* d, BossFinal& b)
	{
		if (d->getPos().y - d->getRadio() < b.hitbox.top_l.y && d->getPos().y + d->getRadio() > b.hitbox.bot_l.y)
			if (d->getPos().x - d->getRadio() < b.hitbox.top_r.x && d->getPos().x + d->getRadio() > b.hitbox.top_l.x) {
				d->setColor(0, 1, 0);
				b.flagdmg = 1;
				if (b.tempdmg == 0)
					b.tempdmg = 40;
			}
	}*/
////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////// Disparos
//Entorno
void Interaccion::choque(ListaDisparos ld, ListaSolidos ls)
{
}
void Interaccion::choque(Disparos& d, Solidos s)
{
}
void Interaccion::choque(Disparos& d, Pared p)
{
	//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y;//arr
	//Decidimos si estamos arriba o abajo
	if (d.getPos().y > ymin - d.getRadio() / 2)
		d.zonaV = 1; //Estamos arriba
	else
		d.zonaV = 0; //Abajo
	//Decidimos si estamos dentro y si estamos encima
	if (d.getPos().x < xmax && d.getPos().x > xmin)
	{
		if (d.zonaV == 0) { //Sigue igual si esta debajo
			if (d.getPos().y > ymax) {
				d.setPos(d.getPos().x, ymax);
				d.setVel(d.vel, 0.0f);
				d.setAc(0.0f, -9.8f);
			}
		}
		else //Si está arriba
		{
			if (d.getPos().y < ymin) {
				d.setColor(1, 1, 1);
				//d.flagdibujar = 0;
			}
		}
	}
}
void Interaccion::choque(Disparos& d, PlatMovil pm)
{
}
void Interaccion::choque(Disparos& d, Suelo s)
{
}
void Interaccion::choque(Disparos& d, Final f)
{
}
void Interaccion::choque(Disparos& d, Pincho s)
{
}
void Interaccion::choque(Disparos& d, BolaFuego b)
{
}
void Interaccion::choque(DisparosAmigos& d, Solidos s)
{
}
void Interaccion::choque(DisparosAmigos& d, Pared p)
{
	//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y;//arr
	//Decidimos si estamos arriba o abajo
	if (d.getPos().y > ymin - d.getRadio() / 2)
		d.zonaV = 1; //Estamos arriba
	else
		d.zonaV = 0; //Abajo
	//Decidimos si estamos dentro y si estamos encima
	if (d.getPos().x < xmax && d.getPos().x > xmin)
	{
		if (d.zonaV == 0) { //Sigue igual si esta debajo
			if (d.getPos().y > ymax) {
				d.setPos(d.getPos().x, ymax);
				d.setVel(d.vel, 0.0f);
				d.setAc(0.0f, -9.8f);
			}
		}
		else //Si está arriba
		{
			if (d.getPos().y < ymin) {

				d.setColor(1, 1, 1);
				//ene.flagdibujar = 0;
			}
		}
	}
}
void Interaccion::choque(DisparosAmigos& d, PlatMovil pm)
{
}
void Interaccion::choque(DisparosAmigos& d, Suelo s)
{
}
void Interaccion::choque(DisparosAmigos& d, Final f)
{
}
void Interaccion::choque(DisparosAmigos& d, Pincho s)
{
}
void Interaccion::choque(DisparosAmigos& d, BolaFuego b)
{
}
void Interaccion::choque(DisparosEnemigos& d, Solidos s)
{
}
void Interaccion::choque(DisparosEnemigos& d, Pared p)
{
	//Ponemos los limites de la plataforma
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y;//arr
	//Decidimos si estamos arriba o abajo
	if (d.getPos().y > ymin - d.getRadio() / 2)
		d.zonaV = 1; //Estamos arriba
	else
		d.zonaV = 0; //Abajo
	//Decidimos si estamos dentro y si estamos encima
	if (d.getPos().x < xmax && d.getPos().x > xmin)
	{
		if (d.zonaV == 0) { //Sigue igual si esta debajo
			if (d.getPos().y > ymax) {
				d.setPos(d.getPos().x, ymax);
				d.setVel(d.vel, 0.0f);
				d.setAc(0.0f, -9.8f);
			}
		}
		else //Si está arriba
		{
			if (d.getPos().y < ymin) {
				d.setColor(1, 1, 1);
				//ene.flagdibujar = 0;
			}
		}
	}
}
void Interaccion::choque(DisparosEnemigos& d, PlatMovil pm)
{
}
void Interaccion::choque(DisparosEnemigos& d, Suelo s)
{
}
void Interaccion::choque(DisparosEnemigos& d, Final f)
{
}
void Interaccion::choque(DisparosEnemigos& d, Pincho s)
{
}
void Interaccion::choque(DisparosEnemigos& d, BolaFuego b)
{
}
void Interaccion::choque(Misiles& d, Solidos s)
{
}
void Interaccion::choque(Misiles& d, Pared p)
{
}
void Interaccion::choque(Misiles& d, PlatMovil pm)
{
}
void Interaccion::choque(Misiles& d, Suelo s)
{
}
void Interaccion::choque(Misiles& d, Final f)
{
}
void Interaccion::choque(Misiles& d, Pincho s)
{
}
void Interaccion::choque(Misiles& d, BolaFuego b)
{
}
//Invocación de disparos desde cada enemigo
void Interaccion::dispara(ListaEnemigos le, ListaDisparos* ld)
{
	for (int i = 0; i < le.numero; i++)
		dispara(le.lista[i], ld);
}
void Interaccion::dispara(Enemigo* e, ListaDisparos* ld)
{
	if (e->cosa == 1) {
		EnemigoDisp* ene;
		ene = dynamic_cast <EnemigoDisp*> (e);
		Interaccion::dispara(ene, ld);
	}
	else if (e->cosa == 2) {
		Tank* ene;
		ene = dynamic_cast <Tank*> (e);
		Interaccion::dispara(ene, ld);
	}
	else if (e->cosa == 6) {
		BossFinal* ene;
		ene = dynamic_cast <BossFinal*> (e);
		Interaccion::dispara(ene, ld);
	}
}
void Interaccion::dispara(EnemigoDisp* e, ListaDisparos* ld)
{
	e->dispEnem1->setPos(1, 2);
	if (ld->agregar(e->dispEnem1)) {
		e->setColor(1, 1, 1);
	}
	else e->setColor(1, 0, 1);
}
void Interaccion::dispara(Tank* t, ListaDisparos* ld)
{
	if (ld->agregar(t->dispTank1) &&
		ld->agregar(t->dispTank2) &&
		ld->agregar(t->dispTank3) &&
		ld->agregar(t->dispTank4) &&
		ld->agregar(t->dispTank5)) {
		t->setColor(1, 1, 1);
	}
	else t->setColor(1, 0, 1);
}
void Interaccion::dispara(BossFinal* b, ListaDisparos* ld)
{
	ld->agregar(b->misil1);
	ld->agregar(b->misil2);
	ld->agregar(b->misil3);
	ld->agregar(b->misil4);
	ld->agregar(b->misil5);
	ld->agregar(b->misil6);
	ld->agregar(b->misil7);
	ld->agregar(b->misil8);
	ld->agregar(b->misil9);
	ld->agregar(b->misil10);
}
////////////////////////////////////////////////////////////////////

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
}*/




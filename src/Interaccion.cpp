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
	float m2 = (h.top_r - h.bot_r).modulo(),
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
bool Interaccion::ColisionGen(Hitbox ene, Hitbox h) {
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
					h.velocidad.x = pm->vel.x+h.velocidad.x;
					h.velocidad.y = 0;
					h.salto = 1;
				}
		}
	}
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
	if (ColisionGen(p->hitbox, h.hitbox)) {
		if (h.tempdmg == 0) {
			v.reduceVida();
			h.tempdmg = 40;
		}
	}
}
void Interaccion::rebote(Personaje& h, BolaFuego* b, VidasRecolectadas& v)
{
	if (ColisionGen(b->hitbox, h.hitbox)) {
		if (h.tempdmg == 0) {
			v.reduceVida();
			h.tempdmg = 40;
		}
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
void Interaccion::colision(Personaje& h, DisparosEnemigos* de, VidasRecolectadas& v)
{
	float dist = DistSeg(h.hitbox, de->getPos());
	if (dist < de->getRadio() && de->existe)
	{
		de->setColor(0, 1, 1);
		if (h.tempdmg == 0) {
			v.reduceVida();
			h.tempdmg = 40;
		}
		de->existe = false;
	}
}
void Interaccion::colision(Personaje& h, Misiles* m, VidasRecolectadas& v) {
	float distd = DistSeg(h.hitbox, m->getPos());
	if (distd < m->getRadio() && m->existe)
	{
		m->setColor(0, 1, 1);
		if (h.tempdmg == 0) {
			v.reduceVida();
			h.tempdmg = 40;
		}
		m->existe = false;
	}
	Vector2D dist = m->getPos() - h.getPos();
	if (dist.modulo() < 5) {
		m->cerca = 1;
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
	if (ColisionGen(ene.hitbox, h.hitbox)) {
		if (h.tempdmg == 0) {
			v.reduceVida();
			h.tempdmg = 40;
		}
		h.setColor(0, 1, 1);
	}
}
void Interaccion::colision(Personaje& h, EnemigoDisp& e, VidasRecolectadas& v)
{
}
void Interaccion::colision(Personaje& h, Babosa* ene, VidasRecolectadas& v) {
	if (ColisionGen(ene->hitbox, h.hitbox)) {
		if (h.tempdmg == 0) {
			v.reduceVida();
			h.tempdmg = 40;
		}
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
			if (h.tempdmg == 0) {
				v.reduceVida();
				h.tempdmg = 40;
			}
			h.setColor(0, 1, 0);
		}

	}
}//3 hitboxes
void Interaccion::colision(Personaje& h, Bomber* ene, VidasRecolectadas& v) {
	if (ColisionGen(ene->hitbox, h.hitbox)) {
		if (h.tempdmg == 0) {
			v.reduceVida();
			h.tempdmg = 40;
		}
	}

	if ((h.getPos() - ene->getPos()).modulo() < 4) {
		ene->flag = 1;
	}
	if (ene->flag) {
		ene->temp--;
		ene->setVel(0, 0);
	}
	if (ene->temp == 5) {
		ene->altura = 6;
		ene->sprite.setCenter(3.5, 1);
		ene->sprite.setSize(7, 7);
	}
	if (ene->temp == 0)
		ene->vida = 0;
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
	Enemigo* ene;
	ene = dynamic_cast <Enemigo*> (t);
	Interaccion::rebote(ene, p);
}
void Interaccion::rebote(Tank* t, Pincho* p)
{

}
void Interaccion::rebote(Tank* t, BolaFuego* p)
{
}
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
		e->flagdmg = 1;
		e->flagesp = 3;
		if (e->tempdmg == 0)
			e->tempdmg = 40;
	}
}
void Interaccion::colision(Espada& esp, Babosa* b)
{
	if ((esp.getPos() - b->hitbox.top_l).modulo() < esp.getLong() ||
		(esp.getPos() - b->hitbox.top_r).modulo() < esp.getLong() ||
		(esp.getPos() - b->hitbox.bot_l).modulo() < esp.getLong() ||
		(esp.getPos() - b->hitbox.bot_r).modulo() < esp.getLong()) 
	{
		b->flagdmg = 1;
		b->flagesp = 5;
		if (b->tempdmg == 0)
			b->tempdmg = 40;
	}
}
void Interaccion::colision(Espada& esp, Bomber* b)
{
	if ((esp.getPos() - b->hitbox.top_l).modulo() < esp.getLong() ||
		(esp.getPos() - b->hitbox.top_r).modulo() < esp.getLong() ||
		(esp.getPos() - b->hitbox.bot_l).modulo() < esp.getLong() ||
		(esp.getPos() - b->hitbox.bot_r).modulo() < esp.getLong())
	{
		b->flagdmg = 1;
		b->flagesp = 3;
		if (b->tempdmg == 0)
			b->tempdmg = 40;
	}
}
void Interaccion::colision(Espada& esp, Tentaculo* t)
{
	for (int i = 0; i < 3; i++) {
		if ((esp.getPos() - t->hitbox[i].top_l).modulo() < esp.getLong() ||
			(esp.getPos() - t->hitbox[i].top_r).modulo() < esp.getLong() ||
			(esp.getPos() - t->hitbox[i].bot_l).modulo() < esp.getLong() ||
			(esp.getPos() - t->hitbox[i].bot_r).modulo() < esp.getLong())
		{
			esp.setColor(0, 1, 0);
			t->flagdmg = 1;
			t->flagesp = 3;
			if (t->tempdmg == 0)
				t->tempdmg = 40;
		}
	}
}
void Interaccion::colision(Espada& esp, Tank* t)
{
	if ((esp.getPos() - t->hitbox.top_l).modulo() < esp.getLong() ||
		(esp.getPos() - t->hitbox.top_r).modulo() < esp.getLong() ||
		(esp.getPos() - t->hitbox.bot_l).modulo() < esp.getLong() ||
		(esp.getPos() - t->hitbox.bot_r).modulo() < esp.getLong())
	{
		t->flagdmg = 1;
		t->flagesp = 2;
		if (t->tempdmg == 0)
		{
			t->tempdmg = 40;
		}
	}
}
void Interaccion::colision(Espada& esp, BossFinal* b)
{
	if ((esp.getPos() - b->hitbox.top_l).modulo() < esp.getLong() ||
		(esp.getPos() - b->hitbox.top_r).modulo() < esp.getLong() ||
		(esp.getPos() - b->hitbox.bot_l).modulo() < esp.getLong() ||
		(esp.getPos() - b->hitbox.bot_r).modulo() < esp.getLong())
	{
		b->flagdmg = 1;
		b->flagesp = 2;
		if (b->tempdmg == 0)
		{
			b->tempdmg = 40;
		}

	}
}
void Interaccion::colision(ListaDisparos ld, ListaEnemigos le)
{
	for (int i = 0; i < ld.numero; i++)
		for (int j = 0; j < le.numero; j++) {
			//int i = 0;
			Interaccion::colision(ld.lista[i], le.lista[j]);
		}
}
void Interaccion::colision(Disparos* d, Enemigo* e)
{
	if (d->cosa == 1) {	
		DisparosAmigos* p;
		p = dynamic_cast <DisparosAmigos*> (d);
		Interaccion::colision(p, e);
	}
	if (d->cosa == 2) {
		;
	}
	else if (d->cosa == 3) {
		;
	}
}
void Interaccion::colision(Disparos* d, EnemigoDisp* e)
{
	if (d->cosa == 1) {
		DisparosAmigos* p;
		p = dynamic_cast <DisparosAmigos*> (d);
		Interaccion::colision(p, e);
	}
}
void Interaccion::colision(Disparos* d, Babosa* b)
{
	if (d->cosa == 1) {
		DisparosAmigos* p;
		p = dynamic_cast <DisparosAmigos*> (d);
		Interaccion::colision(p, b);
	}
}
void Interaccion::colision(Disparos* d, Bomber* b)
{
	if (d->cosa == 1) {
		DisparosAmigos* p;
		p = dynamic_cast <DisparosAmigos*> (d);
		Interaccion::colision(p, b);
	}
}
void Interaccion::colision(Disparos* d, Tentaculo* t)
{
	if (d->cosa == 1) {
		DisparosAmigos* p;
		p = dynamic_cast <DisparosAmigos*> (d);
		Interaccion::colision(p, t);
	}
}
void Interaccion::colision(Disparos* d, Tank* t)
{
	if (d->cosa == 1) {
		DisparosAmigos* p;
		p = dynamic_cast <DisparosAmigos*> (d);
		Interaccion::colision(p, t);
	}
}
void Interaccion::colision(Disparos* d, BossFinal* b)
{
	if (d->cosa == 1) {
		DisparosAmigos* p;
		p = dynamic_cast <DisparosAmigos*> (d);
		Interaccion::colision(p, b);
	}
}
void Interaccion::colision(DisparosAmigos* d, ListaEnemigos le)
{
	for (int i = 0; i < le.numero; i++)
		Interaccion::colision(d, le.lista[i]);
}
void Interaccion::colision(DisparosAmigos* d, Enemigo* e)
{
	if (e->cosa == 4) {
		Bomber* p;
		p = dynamic_cast <Bomber*> (e);
		Interaccion::colision(d, p);
	} else
	if (e->cosa == 5) {
		Tentaculo* p;
		p = dynamic_cast <Tentaculo*> (e);
		Interaccion::colision(d, p);
	}
	else {
		float dist = DistSeg(e->hitbox, d->getPos());
		if (dist < d->getRadio() && d->existe)
		{
			d->setColor(0, 1, 1);
			e->flagdmg = 1;
			if (e->tempdmg == 0)
				e->tempdmg = 40;
			d->existe = false;
		}
	}
}
void Interaccion::colision(DisparosAmigos* d, EnemigoDisp* e)
{
}
void Interaccion::colision(DisparosAmigos* d, Babosa* b)
{
}
void Interaccion::colision(DisparosAmigos* d, Bomber* b)
{
}
void Interaccion::colision(DisparosAmigos* d, Tentaculo* t)
{
	if ((d->posicion.x >= t->hitbox[0].top_l.x) && (d->posicion.x <= t->hitbox[0].top_r.x))
	{
		if ((d->posicion.y >= t->hitbox[0].bot_l.y) && (d->posicion.y <= t->hitbox[0].top_l.y))
		{
			t->flagdmg = 1;
			if (t->tempdmg == 0)
				t->tempdmg = 40;
			d->existe = false;
		}
	}
	for (int i = 1; i < 3; i++) {
		float dist = DistSeg(t->hitbox[i], d->getPos());
		if (dist < d->getRadio() && d->existe)
		{
			t->flagdmg = 1;
			if (t->tempdmg == 0)
				t->tempdmg = 40;
			d->existe = false;
		}
	}
}
void Interaccion::colision(DisparosAmigos* d, Tank* t)
{
	if (d->getPos().y - d->getRadio() < t->hitbox.top_l.y && d->getPos().y + d->getRadio() > t->hitbox.bot_l.y)
		if (d->getPos().x - d->getRadio() < t->hitbox.top_r.x && d->getPos().x + d->getRadio() > t->hitbox.top_l.x) {
			d->setColor(1, 1, 0);
			t->flagdmg = 1;
			if (t->tempdmg == 0)
				t->tempdmg = 40;
		}
}
void Interaccion::colision(DisparosAmigos* d, BossFinal* b)
{
	if (d->getPos().y - d->getRadio() < b->hitbox.top_l.y && d->getPos().y + d->getRadio() > b->hitbox.bot_l.y)
		if (d->getPos().x - d->getRadio() < b->hitbox.top_r.x && d->getPos().x + d->getRadio() > b->hitbox.top_l.x) {
			d->setColor(0, 1, 0);
			b->flagdmg = 1;
			if (b->tempdmg == 0)
				b->tempdmg = 40;
		}
}
////////////////////////////////////////////////////////////////////

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




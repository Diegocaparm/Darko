#include "Interaccion.h"
#include <math.h>
#include "stdio.h"
#define pi 3.14159265

float DistSegmento(segmento s1, Vector2D p);
bool DistHitbox(Hitbox h1, Vector2D e);		//hitbox y esquina de otra hitbox
float DistSeg(Hitbox h, Vector2D p);

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
		if (h.hitbox.esquina1.x > xmin + 0.2)
			h.zonaH = 1;	//dcha
		else if(h.hitbox.esquina2.x < xmin - 0.2)
			h.zonaH = 0;	//izq
		if (h.hitbox.esquina3.y < p.limite1.y-0.5 && h.hitbox.esquina3.y > p.limite2.y) {  //zona=0 izq    zona=1 dcha
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
	}
}

void Interaccion::rebote(Hombre& h, PlatMovil pm)
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
	}
}

void Interaccion::rebote(Hombre& h, listaPlat p) {
	for (int i = 0; i < p.numero; i++)
		rebote(h, *p.lista[i]);
	for (int i = 0; i < p.numv; i++)
		rebote(h, *p.listamov[i]);
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

void Interaccion::rebote(bomber& ene, Pared p)
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
	if (sqrt((ene.hitbox.esquina3.y * ene.hitbox.esquina3.y) + (ymin * ymin)) < 0.5) {
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
				if (ene.hitbox.esquina1.x < xmin+0.5) {		//cambiar de direccion
					ene.sentido = 0;
				}
				if (ene.hitbox.esquina2.x > xmax-0.5) {
					ene.sentido = 1;
				}
			}
		}
	}
}

void Interaccion::rebote(bossFinal& h, listaPlat p) {
	for (int i = 0; i < p.numero; i++)
		rebote(h, *p.lista[i]);
}

void Interaccion::rebote(bossFinal& b, Caja c)
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
	float ymax = c.pared_dcha.limite1.y - b.altura/2;
	if (b.posicion.y > ymax) {
		b.posicion.y = ymax;
		b.velocidad.y = 0.0f;
		b.aceleracion.y = -9.8f;
	}
	if (b.posicion.y < ymin) {
		b.posicion.y = ymin;
	}
}

void Interaccion::rebote(bossFinal& b, Pared p)
{
	float xmin = p.limite2.x;//izq
	float xmax = p.limite1.x;//dcha
	float ymin = p.limite2.y;//ab
	float ymax = p.limite1.y - b.altura/2;//arr
	if (b.posicion.y > ymin - b.altura / 2)
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

void Interaccion::mov(Babosa& b, Hombre& h, VidasRec &v) {
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


}

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
		b.setColor(0, 1, 0);*/
}

void Interaccion::colision(Hombre& h, Pincho b,VidasRec &v) {

	bool b1, b2, b3, b4;
	b1 = DistHitbox(h.hitbox, b.hitbox.esquina1);
	b2 = DistHitbox(h.hitbox, b.hitbox.esquina2);
	b3 = DistHitbox(h.hitbox, b.hitbox.esquina3);
	b4 = DistHitbox(h.hitbox, b.hitbox.esquina4);
	if (b1 || b2 || b3 || b4) {
		v.reduceVida();
		h.setColor(0, 1, 0);
	}
		

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

	}*/
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
	}
	/*bool b1;
	for (int i = 0; i < 3; i++) {
		b1 = DistHitbox(h.hitbox[i], de.getPos());

		if (b1)
			de.setColor(0, 1, 0);
	}*/
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

float DistSeg(Hitbox h, Vector2D p) {
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
	else return d2;
}

bool DistHitbox(Hitbox h1, Vector2D e) {
	/*Vector2D diagonal1 = h1.esquina1 - h1.esquina4, diagonal2 = h1.esquina2 - h1.esquina3;
	float mod1 = diagonal1.modulo(), mod2 = diagonal2.modulo();
	Vector2D dist1 = h1.esquina1 - e, dist2 = h1.esquina2 - e,
		dist3 = h1.esquina3 - e, dist4 = h1.esquina4 - e;
	float m1 = dist1.modulo(), m2 = dist2.modulo(), m3 = dist3.modulo(), m4 = dist4.modulo();
	if (mod1 > m1 && mod1 > m4 || mod2 > m2 && mod2 > m3)	//comprueba que la esquina este dentro de la hitbox
		return true;
	else
		return false;*/

	if (h1.esquina1.x<e.x && h1.esquina2.x>e.x && h1.esquina1.y > e.y && h1.esquina3.y < e.y)
		return true;		//solo funciona con rectangulos
	else return false;

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


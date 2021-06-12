#pragma once
#include "Vector2D.h"
#include "Pared.h"
typedef struct {
	float x1, y1, x2, y2;
} segmento;

class Hitbox
{
public:
	Vector2D esquina1, esquina2, esquina3, esquina4;
	segmento segmento[4]{
		segmento[0] = { esquina1.x, esquina1.y, esquina2.x, esquina2.y },
		segmento[1] = { esquina2.x, esquina2.y, esquina4.x, esquina4.y },
		segmento[2] = { esquina3.x, esquina3.y, esquina4.x, esquina4.y },
		segmento[3] = { esquina1.x, esquina1.y, esquina3.x, esquina3.y } };
	Pared arriba;
	Pared abajo;
	Pared derecha;
	Pared izquierda;
	int zonaV, zonaH;
	//zonaV=-1 abajo	=0 dentro	=1 arriba	zonaH=-1 izqu	=0 dentro	=1 dcha
public:
	Hitbox();
	Hitbox(float x, float y);
	void setPared();
	void setPos(Vector2D e1, Vector2D e2, Vector2D e3, Vector2D e4);
	bool compareRight(Hitbox h);
	bool compareLeft(Hitbox h);
	bool compareUp(Hitbox h);
	bool compareDown(Hitbox h);
};
			
//			(1)---Arriba---(2)				(1)---Arriba---(2)		
//			 |		s1		|				 |				|
//			 |				|				 |				|
//		 Izquierda		 Derecha		 Izquierda		 Derecha
//		s4	 |				|	s2			 |				|
//			 |		s3		|				 |				|
//			(3)---Abajo ---(4)				(3)---Abajo ---(4)
	
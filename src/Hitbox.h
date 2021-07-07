#pragma once
#include "Vector2D.h"

class Hitbox
{
public:
	Vector2D top_r, top_l, bot_r, bot_l; //Esquinas de la hitbox
	Hitbox();//Constructor standar
	Hitbox(float Trx, float Try, float Tlx, float Tly, float Brx, float Bry, float Blx, float Bly); //Constructor con posicion
	void setPos(Vector2D e1, Vector2D e2, Vector2D e3, Vector2D e4);
};
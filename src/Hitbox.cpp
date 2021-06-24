#include "Hitbox.h"

Hitbox::Hitbox()
{
	//Necesaria para llamarla sin especificar las esquinas
}

Hitbox::Hitbox(float Trx, float Try, float Tlx, float Tly, float Brx, float Bry, float Blx, float Bly)
{
	top_r = { Trx, Try };
	top_l = { Tlx, Tly };
	bot_r = { Brx, Bry };
	bot_l = { Blx, Bly };
}

void Hitbox::setPos(Vector2D e1, Vector2D e2, Vector2D e3, Vector2D e4)
{
	top_l = e1;
	top_r = e2;
	bot_l = e3;
	bot_r = e4;
	//setPared();
}
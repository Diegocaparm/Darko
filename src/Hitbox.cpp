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

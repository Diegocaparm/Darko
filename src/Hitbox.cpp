#include "Hitbox.h"

Hitbox::Hitbox()
{
	arriba.setPos(0.0, 0.0, 0.0, 0.0);
	abajo.setPos(0.0, 0.0, 0.0, 0.0);
	izquierda.setPos(0.0, 0.0, 0.0, 0.0);
	derecha.setPos(0.0, 0.0, 0.0, 0.0);

}

Hitbox::Hitbox(float x, float y)
{
	arriba.setPos(x-1.0, y+1.0, x+1.0, y+1.0);
	abajo.setPos(x - 1.0, y - 1.0, x + 1.0, y - 1.0);
	izquierda.setPos(x - 1.0, y + 1.0, x - 1.0, y - 1.0);
	derecha.setPos(x + 1.0, y + 1.0, x + 1.0, y - 1.0);
}

void Hitbox::setPared()
{
	arriba.setPos(esquina1.x, esquina1.y, esquina2.x, esquina2.y);
	abajo.setPos(esquina3.x, esquina3.y, esquina4.x, esquina4.y);
	izquierda.setPos(esquina1.x, esquina1.y, esquina3.x, esquina3.y);
	derecha.setPos(esquina2.x, esquina2.y, esquina4.x, esquina4.y);
}

void Hitbox::setPos(Vector2D e1, Vector2D e2, Vector2D e3, Vector2D e4)
{
	esquina1 = e1;
	esquina2 = e2;
	esquina3 = e3;
	esquina4 = e4;
	setPared();
}



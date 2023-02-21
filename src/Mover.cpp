#include "Mover.h"

Mover::Mover(int dx, Vector2 pos, Texture2D* image) : SmartActor(pos, image)
{
}

void Mover::update()
{
	m_Pos.x += m_Dx;
}

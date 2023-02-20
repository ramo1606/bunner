#include "SmartActor.h"

SmartActor::SmartActor(Vector2 pos, Texture2D* image) : Actor(std::string("SmartActor"), pos, image)
{
}

void SmartActor::update()
{
	for (auto& child : m_Children)
	{
		child->update();
	}
}

void SmartActor::draw(float offset_x, float offset_y)
{
	//Set a new position with offset, draw the children actors and set the position to previous value
	m_Pos.x += offset_x;
	m_Pos.y += offset_y;

	Actor::draw();

	for (auto& child : m_Children)
	{
		child->draw(m_Pos.x, m_Pos.y);
	}

	m_Pos.x -= offset_x;
	m_Pos.y -= offset_y;
}


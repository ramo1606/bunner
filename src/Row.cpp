#include "Row.h"
#include "ResourceManager.h"

Row::Row(std::string& baseImage, int index, float y) : 
	SmartActor({0, y}, ResourceManager::getSprite(baseImage + std::to_string(index))),
	m_Index(index)
{
}

void Row::next()
{
}

SmartActor* Row::collide(float x, int margin)
{
	/*
	* Check to see if the given X coordinate is in contact with any of this row's child objects (e.g. logs, cars,
	* hedges).A negative margin makes the collideable area narrower than the child object's sprite, while a
	* positive margin makes the collideable area wider.
	*/  
	for (auto& child : m_Children) 
	{
		if(x >= child->getPosition().x - (child->getWidth() * 0.5f) - margin && 
		   child->getPosition().x + (child->getWidth() * 0.5f) + margin)
		{
			return child;
		}
	}
	return nullptr;
}

int Row::push()
{
	return 0;
}

std::pair<PlayerState, int> Row::checkCollision(float x)
{
	/*
	* Returns the new state the player should be in, based on whether or not the player collided with anything on
	* this road.As this class is the base class for other types of row, this method defines the default behaviour
	* - i.e. unless a subclass overrides this method, the player can walk around on a row without dying.
	*/ 
	return std::make_pair(PlayerState::ALIVE, 0);
}

bool Row::allowMovment(float x)
{
	// Ensure the player can't walk off the left or right sides of the screen
	return x >= 16.f && x <= WIDTH - 16;
}

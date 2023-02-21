#include "Car.h"
#include "ResourceManager.h"
#include "Game.h"

Car::Car(int dx, Vector2 pos) : Mover(dx, pos, ResourceManager::getSprite(std::string("car") + std::to_string(GetRandomValue(0, 3)) + std::to_string(m_Dx < 0 ? 0 : 1)))
{
}

void Car::playSound(CarSoundType type)
{
	if (!m_Played[static_cast<int>(type)])
	{
		Game::getInstance()->playSound(m_Sounds[static_cast<int>(type)].first, m_Sounds[static_cast<int>(type)].second);
		m_Played[static_cast<int>(type)] = true;
	}
}

#include "Train.h"
#include "ResourceManager.h"

Train::Train(int dx, Vector2 pos) : Mover(dx, pos, ResourceManager::getSprite(std::string("train") + std::to_string(GetRandomValue(0, 2)) + std::to_string(m_Dx < 0 ? 0 : 1)))
{
}

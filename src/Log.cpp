#include "Log.h"
#include "ResourceManager.h"

Log::Log(int dx, Vector2 pos) : Mover(dx, pos, ResourceManager::getSprite(std::string("log") + std::to_string(GetRandomValue(0, 1))))
{
}

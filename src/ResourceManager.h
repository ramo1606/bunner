#pragma once
#include <memory>
#include <map>

#include "raylib.h"
#include "rmem.h"

#include "Car.h"
#include "Log.h"
#include "Train.h"

#include "Common.h"

using namespace Common;

/*
* ResourceManager class will load all the images, sounds and music needed by the game and add it to a map,
* so we can get each resource by it file name. This way we don't have to load the resource every time we needed,
* we keep it in memory.
*/
class ResourceManager
{
public:
	~ResourceManager();
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	static std::shared_ptr<ResourceManager> getInstance();
	bool loadResources();
	void cleanup();

	static Texture2D* getSprite(std::string& obj);
	static Sound* getSound(std::string& obj);
	static Music* getMusic(std::string& obj);

	static Car* getCar(int dx, Vector2 pos);
	static Log* getLog(int dx, Vector2 pos);
	static Train* getTrain(int dx, Vector2 pos);

	static void destroyCar(Car& car);
	static void destroyLog(Log& log);
	static void destroyTrain(Train& train);

private:
	ResourceManager();
	static std::shared_ptr<ResourceManager> m_Instance;

	std::map<std::string, Texture2D> m_SpritesMap;
	std::map<std::string, Sound> m_SoundsMap;
	std::map<std::string, Music> m_MusicMap;

	ObjPool m_CarsPool = CreateObjPool(sizeof(Car), 30);
	ObjPool m_LogsPool = CreateObjPool(sizeof(Log), 30);
	ObjPool m_TrainsPool = CreateObjPool(sizeof(Train), 30);
	//ObjPool m_OrbsPool = CreateObjPool(sizeof(Orb), 10);
	//ObjPool m_BoltsPool = CreateObjPool(sizeof(Bolt), 40);
};
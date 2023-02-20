#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Bunny.h"
#include "Common.h"

#include "rmem.h"

using namespace Common;

/*
* Main class for the game logic, it creates and manages all the actors needed in the scene.
*/
class Game
{
public:
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	static std::shared_ptr<Game> getInstance();

	void init();
	void update();
	void draw();

	void reset();

	void playSound(std::string& sound, int count = 1);

private:
	Game();
	static std::shared_ptr<Game> m_Instance;

	int m_Frame{ 0 };
	Bunny* m_Bunny = nullptr;
	
	std::vector <std::string> m_LoopedSounds;
	ObjPool m_BoltsPool;

	bool m_SpaceDown{ false };
};
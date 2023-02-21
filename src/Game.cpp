#define RMEM_IMPLEMENTATION
#include "Game.h"
#include "ResourceManager.h"

#include <cmath>
#include <algorithm>
#include <random>

std::shared_ptr<Game> Game::m_Instance = nullptr;

Game::Game()
{
}

std::shared_ptr<Game> Game::getInstance()
{
	if (!m_Instance)
		m_Instance.reset(new Game());
	return m_Instance;
}

Game::~Game()
{
}

void Game::init()
{
}

void Game::update()
{
	
}

void Game::draw()
{
	
}

void Game::reset()
{
	
}

void Game::playSound(std::string& sound, int count)
{
	/*
	* Some sounds have multiple varieties. If count > 1, we'll randomly choose one from those
    * We don't play any sounds if there is no player (e.g. if we're on the menu)
	*/
	if (true)
	{
		PlaySound(*ResourceManager::getSound(sound + std::to_string(GetRandomValue(0, count - 1))));
	}
}
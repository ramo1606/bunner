#pragma once
#include "raylib.h"
#include "Actor.h"
#include "Common.h"
#include "ResourceManager.h"
#include "Game.h"
#include "Bunny.h"

using namespace Common;

enum class State : uint8_t
{
    MENU,
    PLAY,
    GAME_OVER
};

/*
* Cavern class will manage the game states
*/
class Bunner
{
public:
    Bunner()
    {
        m_Game = Game::getInstance();
    }

    void update()
    {
        switch (m_State)
        {
        case State::MENU:
            
            break;
        case State::PLAY:
            
            break;
        case State::GAME_OVER:
            
            break;
        default:
            break;
        }
    }

    void draw()
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        m_Game->draw();

        switch (m_State)
        {
        case State::MENU:
        {
            
            break;
        }
        case State::PLAY:
            
            break;
        case State::GAME_OVER:
            
            break;
        default:
            break;
        }

        EndDrawing();
    }

private:
    bool m_SpaceDown{ false };
    State m_State{ State::MENU };
    std::shared_ptr<Game> m_Game = nullptr;
};


int main(void)
{
    // Init Raylib
    InitWindow(WIDTH, HEIGHT, TITLE.c_str());
    InitAudioDevice();
    SetTargetFPS(60);

    // Load Resources
    ResourceManager::getInstance()->loadResources();

    Bunner bunner;

    // Play music
    PlayMusicStream(*ResourceManager::getMusic(std::string("theme")));
    SetMusicVolume(*ResourceManager::getMusic(std::string("theme")), 0.5f);

    // Main Loop
    while (!WindowShouldClose())
    {
        UpdateMusicStream(*ResourceManager::getMusic(std::string("theme")));
        bunner.update();
        bunner.draw();
    }

    //CleanUp and ShutDown
    ResourceManager::getInstance()->cleanup();
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

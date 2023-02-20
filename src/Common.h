#pragma once
#include <string>
#include <cmath>
#include <vector>

namespace Common
{
    //ENUMS
    enum class PlayerState : std::uint8_t
    {
        ALIVE,
        SPLAT,
        LEMON,
        SPLASH,
        EAGLE
    };

    constexpr int DIRECTION_UP = 0;
    constexpr int DIRECTION_RIGHT = 1;
    constexpr int DIRECTION_DOWN = 2;
    constexpr int DIRECTION_LEFT = 3;

    //CONSTANTS
    const std::string TITLE = "Bunner";

    constexpr int WIDTH = 480;
    constexpr int HEIGHT = 800;

    constexpr int ROW_HEIGHT = 40;

    constexpr bool DEBUG_SHOW_ROW_BOUNDARIES = false;
}
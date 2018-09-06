#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "TileGrid.h"

class Window
{
public:
    Window();

    void Update();

    bool IsOpen() const;

private:
    void fps_sleep();

    TileGrid tileGrid;

    sf::RenderWindow window;
    sf::CircleShape shape;

    sf::Clock frame_clock;
    sf::Time lastFrameTime;
    static const int req_FPS = 60;
};
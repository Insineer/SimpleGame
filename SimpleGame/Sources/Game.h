#pragma once

#include <vector>

#include <SFML/System.hpp>

#include <Graphics/Window.h>
#include <World/World.h>
#include <ResourceManager.h>

class Game
{
public:
    Game();

    void Run();

    static Game * const Get();

    World *GetWorld();

private:
    static Game *instance;
	
	ResourceManager rm;
    Window window;
    World world;
    Player player;

	sf::Clock clock;
};

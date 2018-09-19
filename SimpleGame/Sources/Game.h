#pragma once

#include <vector>

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
};

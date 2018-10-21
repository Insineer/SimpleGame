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

	ResourceManager *GetRM();
	World *GetWorld();
	Player *GetPlayer();
	Window *GetWindow();

private:
	static Game *instance;
	
	ResourceManager rm;
	World world;
	Player player;
	Window window;

	sf::Clock clock;
};

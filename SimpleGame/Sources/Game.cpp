#include "Game.h"

#include <Player.h>

Player CreatePlayer()
{
    return Player();
}

Game::Game()
{
    instance = this;
}

void Game::Run()
{
	player.Spawn();

	while (window.IsOpen()) {
		sf::Time timeElapsed = clock.getElapsedTime();
		window.Update();

		// TODO: should be in different thread
		world.Update(sf::Time());
	}
}

Game * const Game::Get()
{
    return instance;
}

World *Game::GetWorld()
{
    return &world;
}

int main()
{
    Game game;
    game.Run();

    return 0;
}

Game *Game::instance;

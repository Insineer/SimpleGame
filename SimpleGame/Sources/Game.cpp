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

    while (window.IsOpen()) 
    {
        window.Update();
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

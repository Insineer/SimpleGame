#include "Game.h"

Game::Game()
{

}

void Game::Run()
{
    while (window.IsOpen()) 
    {
        window.Update();
    }
}

int main()
{
    Game game;
    game.Run();

    return 0;
}
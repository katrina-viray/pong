#include "Game.hpp"
#include <SDL.h>

Game *game = nullptr;
int main(int argc, char *argv[])
{
    game = new Game();
    // For ex. same as (*game).init()
    game->init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(game->running()){
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}
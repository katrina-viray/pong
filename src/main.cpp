#include "Game.hpp"
#include <SDL.h>

Game *game = nullptr;
int main(int argc, char *argv[])
{
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    // For ex. same as (*game).init()
    game->init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(game->running()){
      // gets # of ms elapsed since SDL was first initialized
      frameStart = SDL_GetTicks();

      game->handleEvents();
      game->update();
      game->render();

      // # of ms it takes to go through handle, update, and render
      frameTime = SDL_GetTicks() - frameStart;

      // check if need to delay running the next frame
      if(frameDelay > frameTime){
        SDL_Delay(frameDelay - frameTime);
      }
    }

    game->clean();
    return 0;
}
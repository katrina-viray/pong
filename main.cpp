#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Hello SDL WORLD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI)
    
    if (NULL == window){
        cout << "COuld not create window: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Event windowEvent;

    while(true){
        if (SDL_PollEvent(&windowEvent)){
            if(SDL_QUIT == windowEvent.type)
                break;
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
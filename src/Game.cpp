#include "Game.hpp"

SDL_Texture* circleTex;
SDL_Rect srcR, destR;

Game::Game(){

}
Game::~Game(){

}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen){
    int flags = 0;

    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems Initialized" << std::endl;

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        if(window)
            std::cout << "Window created" << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 99, 91, 255, 255);
            std::cout << "Renderer created" << std::endl;
        }

        isRunning = true;
    }
    else{
        isRunning = false;
    }

    SDL_Surface* tmpSurface = IMG_Load("assets/circle.png");
    circleTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update(){
    count++;
    destR.h = 64;
    destR.w = 64;
    //destR.x = count;
    std::cout << count << std::endl;
}

void Game::render(){
    // clear renderer's buffer
    SDL_RenderClear(renderer);

    // add stuff to render

    // last 2 args: for srcRect, NULL uses entire img
    // for dstRect, NULL draws to the whole render frame.
    SDL_RenderCopy(renderer, circleTex, NULL, &destR);

    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
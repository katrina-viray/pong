#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"

SDL_Renderer* Game::renderer = nullptr;
Map* map;

Manager manager;
auto& player(manager.addEntity());

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
  map = new Map();

  // ECS implementation
  player.addComponent<TransformComponent>(100, 500);
  player.addComponent<SpriteComponent>("assets/circle.png");

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
    manager.refresh();
    manager.update();

    player.getComponent<TransformComponent>().position.Add(Vector2D(5, 0));
    if(player.getComponent<TransformComponent>().position.x > 100){
      player.getComponent<SpriteComponent>().setTex("assets/star.png");
    }

}

void Game::render(){
    // clear renderer's buffer
    SDL_RenderClear(renderer);

    map->DrawMap();
    manager.draw();

    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
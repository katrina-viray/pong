#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Map* map;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

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
  player.addComponent<TransformComponent>(2);
  player.addComponent<SpriteComponent>("assets/circle.png");
  player.addComponent<KeyboardController>();
  player.addComponent<ColliderComponent>("player");

  wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
  wall.addComponent<SpriteComponent>("assets/star.png");
  wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents(){
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

    if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
      wall.getComponent<ColliderComponent>().collider)){
        player.getComponent<TransformComponent>().scale = 1;
        std::cout << "Wall Hit!" << std::endl;
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
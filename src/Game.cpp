#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

AssetManager* Game::assets = new AssetManager(&manager);

std::vector<ColliderComponent*> Game::colliders;

auto& player1(manager.addEntity());
auto& player2(manager.addEntity());

//auto& wall(manager.addEntity());

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

  assets->AddTexture("player1", "assets/player1.png");
  map = new Map();

  player1.addComponent<TransformComponent>(2);
  player1.addComponent<SpriteComponent>("player1");
  player1.addComponent<KeyboardController>();
  player1.addComponent<ColliderComponent>("player1");

  player2.addComponent<TransformComponent>(2);
  player2.addComponent<SpriteComponent>("assets/player2.png");
  player2.addComponent<KeyboardController>();
  player2.addComponent<ColliderComponent>("player2");

  /*
  wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
  wall.addComponent<SpriteComponent>("assets/star.png");
  wall.addComponent<ColliderComponent>("wall");
  */
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

void Game::update() {
	Vector2D playerPos = player1.getComponent<TransformComponent>().position;
	manager.refresh();
	manager.update();

  for (auto cc : colliders){
    	if (Collision::AABB(player1.getComponent<ColliderComponent>(), *cc)) {
		    //player.getComponent<TransformComponent>().position = playerPos;
	    }
  }
}

void Game::render(){
    // clear renderer's buffer
    SDL_RenderClear(renderer);

    manager.draw();

    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

void Game::AddTile(int id, int x, int y){
  auto& tile(manager.addEntity());
  tile.addComponent<TileComponent>(x, y, 32, 32, id);
}
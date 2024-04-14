#pragma once

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

// KeyboardController inherits publicly from Component class.
// This means public/protected members of "Component" retain access levels
// when accessed by an object of the KeyboardController class.
class KeyboardController : public Component{
public:
  const Uint8* keystates = SDL_GetKeyboardState(NULL); 
  TransformComponent *transform;

  void init() override{
    transform = &entity->getComponent<TransformComponent>();
  }

  void update() override{
    /*
    if(Game::event.type == SDL_KEYDOWN){
      switch(Game::event.key.keysym.sym){
        // move up by decreasing y position, thus the -1
        case SDLK_w:
          transform->velocity.y = -1;
          break;
        case SDLK_a:
          transform->velocity.x = -1;
          break;
        case SDLK_s:
          transform->velocity.y = 1;
          break;
        case SDLK_d:
          transform->velocity.x = 1;
          break;
        default:
          break;
      }
    }

    if(Game::event.type == SDL_KEYUP){
      switch(Game::event.key.keysym.sym){
        // move up by decreasing y position, thus the -1
        case SDLK_w:
          transform->velocity.y = 0;
          break;
        case SDLK_a:
          transform->velocity.x = 0;
          break;
        case SDLK_s:
          transform->velocity.y = 0;
          break;
        case SDLK_d:
          transform->velocity.x = 0;
          break;
        default:
          break;
      }
    }
    */
   
    transform->velocity.x = 0;
		transform->velocity.y = 0;

		if (keystates[SDL_SCANCODE_UP]) {
			transform->velocity.y = -1;
		}
		if (keystates[SDL_SCANCODE_LEFT]) {
			transform->velocity.x = -1;
		}
		if (keystates[SDL_SCANCODE_DOWN]) {
			transform->velocity.y = 1;
		}
		if (keystates[SDL_SCANCODE_RIGHT]) {
			transform->velocity.x = 1;
		}
  }
};
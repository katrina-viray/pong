#pragma once

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

// KeyboardController inherits publicly from Component class.
// This means public/protected members of "Component" retain access levels
// when accessed by an object of the KeyboardController class.
class KeyboardController1 : public Component{
public:
  const Uint8* keystates = SDL_GetKeyboardState(NULL); 
  TransformComponent *transform;

  void init() override{
    transform = &entity->getComponent<TransformComponent>();
  }

  void update() override{
    //transform->velocity.x = 0;
		transform->velocity.y = 0;

		if (keystates[SDL_SCANCODE_UP]) {
			transform->velocity.y = -1;
		}
    /*
    		if (keystates[SDL_SCANCODE_LEFT]) {
			transform->velocity.x = -1;
		}
    	if (keystates[SDL_SCANCODE_RIGHT]) {
			transform->velocity.x = 1;
		}
    */
		if (keystates[SDL_SCANCODE_DOWN]) {
			transform->velocity.y = 1;
		}
  }
};
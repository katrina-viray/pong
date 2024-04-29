#pragma once

#include "Components.hpp"
#include <SDL.h>
#include "../TextureManager.hpp"
#include "../AssetManager.hpp"

class SpriteComponent : public Component{
private:
  TransformComponent *transform;
  SDL_Texture *texture;
  SDL_Rect srcRect, destRect;

public:
  SpriteComponent() = default;
  SpriteComponent(std::string id){
    setTex(id);
  }

  ~SpriteComponent(){
  
  }

  
// created so the texture can be updated later; for instance, you may
// break an item in the game. You must update the item's sprite with
// a new broken item texture, thus the need for a setTex function
void setTex(std::string id){
  texture = Game::assets->GetTexture(id);
}

  void init() override{
    transform = &entity->getComponent<TransformComponent>();

    srcRect.x = srcRect.y = 0;
    srcRect.w = transform->width;
    srcRect.h = transform->height;
  }

  void update() override {
    destRect.x = static_cast<int>(transform->position.x);
    destRect.y = static_cast<int>(transform->position.y);
    destRect.w = transform->width * transform->scale;
    destRect.h = transform->height * transform->scale;

  }

  void draw() override{
    TextureManager::Draw(texture, srcRect, destRect);
  }
};
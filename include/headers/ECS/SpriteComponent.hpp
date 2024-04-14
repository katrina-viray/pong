#pragma once

#include "Components.hpp"
#include <SDL.h>

class SpriteComponent : public Component{
private:
  TransformComponent *transform;
  SDL_Texture *texture;
  SDL_Rect srcRect, destRect;

public:
  SpriteComponent() = default;
  SpriteComponent(const char* path){
    setTex(path);
  }

// created so the texture can be updated later; for instance, you may
// break an item in the game. You must update the item's sprite with
// a new broken item texture, thus the need for a setTex function
void setTex(const char* path){
  texture = TextureManager::LoadTexture(path);
}

  void init() override{
    transform = &entity->getComponent<TransformComponent>();

    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 0;
    destRect.w = destRect.h = 64;
  }

  void update() override {
    destRect.x = position->x();
    destRect.y = position->y();
  }

  void draw() override{
    TextureManager::Draw(texture, srcRect, destRect);
  }
};
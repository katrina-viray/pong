#pragma once
#include "Game.hpp"

class GameObject{
private:
  int xPos;
  int yPos;

  // needed for drawing object
  SDL_Texture* objTexture;

  // needed for displaying object
  SDL_Rect srcRect, destRect;

public:
  GameObject(const char* textureSheet, int x, int y);
  ~GameObject();

  void Update();
  void Render();

};
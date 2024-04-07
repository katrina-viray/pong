#pragma once

#include "Game.hpp"

class Map{
private:
  SDL_Rect src, dest;
  SDL_Texture* sky;
  SDL_Texture* star;
  int map[20][25];

public:
  Map();
  ~Map();

  void LoadMap(int arr[20][25]);
  void DrawMap();

};
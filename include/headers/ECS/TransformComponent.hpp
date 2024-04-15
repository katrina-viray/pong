#pragma once

#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component{
public:
  Vector2D position;
  Vector2D velocity;

  int speed = 5;

  int height = 32;
  int width = 32;
  int scale = 1;

  TransformComponent(){
    position.Zero();
  }

  TransformComponent(int scale){
    position.Zero();
    scale = scale;
  }

  TransformComponent(float x, float y, int h, int w, int scale){
    position.x = x;
    position.y = y;
    height = h;
    width = w;
    scale = scale;
  }

  void init() override{
    velocity.Zero();
  }

  void update() override{
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
  }


};
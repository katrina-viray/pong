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
    position.x = 0.0f;
    position.y = 0.0f;
  }

  TransformComponent(int scale){
    position.x = 0.0f;
    position.y = 0.0f;
    scale = scale;
  }

  TransformComponent(float x, float y){
    position.x = x;
    position.y = y;
  }

  TransformComponent(float x, float y, int h, int w, int scale){
    position.x = x;
    position.y = y;
    height = h;
    width = w;
    scale = scale;
  }

  void init() override{
    velocity.x = 0;
    velocity.y = 0;
  }

  void update() override{
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
  }


};
#pragma once

#include "Components.hpp"

class TransformComponent : public Component{
private:
  int xPos;
  int yPos;

public:
  TransformComponent(){
    xPos = 0;
    yPos = 0;
  }

  TransformComponent(int x, int y){
    xPos = x;
    yPos = y;
  }
  int x(){ return xPos; }
  int y(){ return yPos; }

  void x(int x) { xPos = x; }
  void y(int y) { yPos = y; }

  void update() override{
    xPos++;
    yPos++;
  }

  void setPos(int x, int y){
    xPos = x;
    yPos = y;
  }

};
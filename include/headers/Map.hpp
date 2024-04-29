#pragma once
#include <string>


class Map{
private:
  std::string texID;


public:
  Map();
  ~Map();

  static void LoadMap(std::string path, int sizeX, int sizeY);

};
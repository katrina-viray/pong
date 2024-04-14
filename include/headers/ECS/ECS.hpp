/* Entity-Component-System (ECS):
- Design pattern to manage architecture of complex systems.
- 3 parts:
  1. Entity- reps a single object/element in the system. Identifier for components
  2. Component- self-contained piece of data which reps a single aspect/property
  of an entity.
  3. System- contains logic/behavior of the application.
*/

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

// alias for data type std::size_t
using ComponentID = std::size_t;

// inline expansion; compiler replaces function call w/actual code at the call site
// generates unique IDs for components w/static
inline ComponentID getComponentTypeID(){
  static ComponentID lastID = 0;
  return lastID++;
}

// template function for type-specific version of getComponentID()
template <typename T> inline ComponentID getComponentTypeID() noexcept{
  static_assert(std::is_base_of<Component, T>::value, "");
  static ComponentID typeID = getComponentTypeID();
  return typeID;
}

// check if an entity has a component attached
constexpr std::size_t maxComponents = 32;

// if an entity has a selection of components, can compare if it has
// the component or not. Bitset represents a fixed-size sequence of bits.
// It gives a way to work w/sequences of bits efficiently.
using ComponentBitSet = std::bitset<maxComponents>;

// array to get length of maxComponents
using ComponentArray = std::array<Component*, maxComponents>;

class Component{
public:
    Entity* entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual~Component() {}
};

class Entity{
private:
  bool active = true;
  // vector = array of dynamic size
  std::vector<std::unique_ptr<Component>> components;
  
  ComponentArray componentArray;
  ComponentBitSet componentBitSet;

public:
  void update(){
    for (auto& c : components) c->update();
  }

  void draw() {
    for(auto& c : components) c->draw();
  }
  bool isActive() const { return active; }
  void destroy() {active = false;}

  template <typename T> bool hasComponent() const{
    return componentBitSet[getComponentTypeID<T>()];
  }

  template <typename T, typename... TArgs>
  T& addComponent(TArgs&&... mArgs){
    T* c(new T(std::forward<TArgs>(mArgs)...));
    c->entity = this;
    std::unique_ptr<Component> uPtr{ c };
    components.emplace_back(std::move(uPtr));

    componentArray[getComponentTypeID<T>()] = c;
    componentBitSet[getComponentTypeID<T>()] = true;

    c->init();
    return *c;
  }

  template<typename T> T& getComponent() const{
    auto ptr(componentArray[getComponentTypeID<T>()]);
    return *static_cast<T*>(ptr);
  }
};

class Manager{
private:
  std::vector<std::unique_ptr<Entity>> entities;

public:
  void update() {
    for (auto& e : entities) e->update();
  }

  void draw(){
    for(auto& e: entities) e->draw();
  }

  void refresh(){
    entities.erase(std::remove_if(std::begin(entities), std::end(entities), 
    [](const std::unique_ptr<Entity> &mEntity)
    {
      return !mEntity->isActive();
    }),
      std::end(entities));
  }

  Entity& addEntity(){
    Entity* e  = new Entity();
    std::unique_ptr<Entity> uPtr{e};
    entities.emplace_back(std::move(uPtr));
    return *e;
  }
};

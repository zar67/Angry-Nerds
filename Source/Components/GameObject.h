#pragma once
#include "PhysicsComponent.h"
#include "SpriteComponent.h"
#include "Utility/Vector2.h"
#include <string>

/**
 *  Objects used throughout the game.
 *  Provides a nice solid base class for objects in this game world.
 *  They currently support only sprite components, but this could easily
 *  be extended to include things like rigid bodies or input systems.
 *  @see SpriteComponent
 */
class GameObject
{
 public:
  GameObject() = default;
  virtual ~GameObject();

  bool addSpriteComponent(ASGE::Renderer* renderer,
                          const std::string& texture_file_name);
  SpriteComponent* spriteComponent();

  void
  addPhysicsComponent(vector2 v, float a, float m, float width, float height);
  PhysicsComponent* physicsComponent();

  virtual void update(double delta_time){};

 protected:
  virtual bool collisionDetection() { return false; };
  void freeSprite();
  void freePhysics();
  SpriteComponent* sprite_component = nullptr;
  PhysicsComponent* physics_component = nullptr;

  float speed = 0;
};
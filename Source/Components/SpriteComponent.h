#pragma once
#include "Utility/Circle.h"
#include "Utility/Rectangle.h"
#include <Engine/Sprite.h>
/**
 *  Sprite Components are used by GameObjects
 *  A component based approach allows GameObjects to decide
 *  on whether they want to have specific functionality. This
 *  is a better approach than using multiple inheritance to
 *  construct an object using classes as traits.
 *  @see GameObject
 */
class SpriteComponent
{
 public:
  SpriteComponent() = default;
  ~SpriteComponent();

  bool
  loadSprite(ASGE::Renderer* renderer, const std::string& texture_file_name);

  ASGE::Sprite* getSprite();

  Rectangle getBoundingBox() const;
  Circle getBoundingCircle() const;

 private:
  void free();
  ASGE::Sprite* sprite = nullptr;
};
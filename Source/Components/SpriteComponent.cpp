#include "SpriteComponent.h"
#include <Engine/Renderer.h>

/**
 *  Destructor. Frees dynamic memory.
 */
SpriteComponent::~SpriteComponent()
{
  free();
}

/**
 *  Allocates and loads the sprite.
 *  Part of this process will attempt to load a texture file.
 *  If this fails this function will return false and the memory
 *  allocated, freed.
 *  @param [in] renderer The renderer used to perform the allocations
 *  @param [in] texture_file_name The file path to the the texture to load
 *  @return true if the sprite was successfully loaded
 */
bool SpriteComponent::loadSprite(ASGE::Renderer* renderer,
                                 const std::string& texture_file_name)
{
  free();
  sprite = renderer->createRawSprite();
  if (sprite->loadTexture(texture_file_name))
  {
    return true;
  }

  free();
  return false;
}

void SpriteComponent::free()
{
  delete sprite;
  sprite = nullptr;
}

/**
 *  Returns a pointer to the sprite residing in this component.
 *  As this is a pointer, you will need to check its contents before
 *  attempting to read from it. A simple nullptr will be solve this.
 *  @return a pointer to the objects sprite (if any)
 */
ASGE::Sprite* SpriteComponent::getSprite()
{
  return sprite;
}

/**
 *  Grabs a bounding box for the sprite.
 *  Will create a bounding box as a rectangle. This can be used to check
 *  for collisions with other rects.
 *  @return a rectangle represent the sprite's position and bounds.
 */
Rectangle SpriteComponent::getBoundingBox() const
{
  Rectangle bounding_box;
  bounding_box.x = sprite->xPos();
  bounding_box.y = sprite->yPos();
  bounding_box.width = sprite->width();
  bounding_box.height = sprite->height();

  return bounding_box;
}

Circle SpriteComponent::getBoundingCircle() const
{
  Circle bounding_circle;
  bounding_circle.x = sprite->xPos();
  bounding_circle.y = sprite->yPos();
  bounding_circle.radius = sprite->width() / 2;

  return bounding_circle;
}
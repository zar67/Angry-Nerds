#include "GameObject.h"
#include <Engine/Renderer.h>

/**
 *   @brief   Deconstrutor
 *   @details Frees up any dynamically allocated memory (the sprite and physics
 * components)
 */
GameObject::~GameObject()
{
  freeSprite();
  freePhysics();
}

/**
 *  Allocates and attaches a sprite component to the object.
 *  Part of this process will attempt to load a texture file.
 *  If this fails this function will return false and the memory
 *  allocated, freed.
 *  @param [in] renderer The renderer used to perform the allocations
 *  @param [in] texture_file_name The file path to the the texture to load
 *  @return true if the component is successfully added
 */
bool GameObject::addSpriteComponent(ASGE::Renderer* renderer,
                                    const std::string& texture_file_name)
{
  freeSprite();

  sprite_component = new SpriteComponent();
  if (sprite_component->loadSprite(renderer, texture_file_name))
  {
    return true;
  }

  freeSprite();
  return false;
}

/**
 *   @brief   Frees up sprite component
 *   @details Frees up the dynamically allocated sprite component
 *   @return void
 */
void GameObject::freeSprite()
{
  delete sprite_component;
  sprite_component = nullptr;
}

/**
 *   @brief   Frees up physics component
 *   @details Frees up the dynamically allocated physics component
 *   @return void
 */
void GameObject::freePhysics()
{
  delete physics_component;
  physics_component = nullptr;
}

/**
 *  Returns the sprite componenent.
 *  IT IS HIGHLY RECOMMENDED THAT YOU CHECK THE STATUS OF THE POINTER
 *  IS IS VALID FOR A COMPONENT TO BE NULL AS THEY ARE OPTIONAL!
 *  @return a pointer to the objects sprite component (if any)
 */
SpriteComponent* GameObject::spriteComponent()
{
  return sprite_component;
}

/**
 *  Allocates and attaches a physics component to the object with the given
 * values for initial velocity, initial angular velocity, mass, width and height
 *  @return void
 */
void GameObject::addPhysicsComponent(vector2 velocity,
                                     float angular_velocity,
                                     float mass,
                                     float width,
                                     float height)
{
  freePhysics();

  physics_component = new PhysicsComponent();
  physics_component->initPhysics(
    velocity, angular_velocity, mass, width, height);
}

/**
 *  Returns the physics component.
 *  @return a pointer to the objects physics component (if any)
 */
PhysicsComponent* GameObject::physicsComponent()
{
  return physics_component;
}

vector2 GameObject::position()
{
  return vector2(sprite_component->getSprite()->xPos(),
                 sprite_component->getSprite()->yPos());
}

int GameObject::getCollisionSide(vector2 point, Rectangle col_shape)
{
  if (point.x == col_shape.x && physicsComponent()->linearVelocity().x > 0)
  {
    return 1;
  }
  else if (point.x == col_shape.x + col_shape.width &&
           physicsComponent()->linearVelocity().x < 0)
  {
    return 2;
  }
  else if (point.y == col_shape.y && physicsComponent()->linearVelocity().y > 0)
  {
    return 3;
  }
  else if (point.y == col_shape.y + col_shape.height &&
           physicsComponent()->linearVelocity().y < 0)
  {
    return 4;
  }
  return 0;
}
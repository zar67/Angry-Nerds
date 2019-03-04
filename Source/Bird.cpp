//
// Created by Zoe on 04/03/2019.
//

#include "Bird.h"

/**
 *   @brief   Sets up the bird object
 *   @details Sprite component needs to be added before this function is called.
 * This function sets up the physics components and the needed attributes of the
 * bird class.
 *   @return  void
 */
void Bird::setUpBird(float x_,
                     float y_,
                     float r_,
                     vector2 velocity,
                     float angular_velocity,
                     float mass)
{
  addPhysicsComponent(velocity, angular_velocity, mass, r_, r_);
  spriteComponent()->getSprite()->xPos(x_);
  spriteComponent()->getSprite()->yPos(y_);
  spriteComponent()->getSprite()->width(r_);
  spriteComponent()->getSprite()->height(r_);
  shape.x = x_;
  shape.y = y_;
  shape.radius = r_;
}

/**
 *   @brief   Collision Detection
 *   @details Detects collision against the ground, pigs and blocks
 *   @return  Bool stating whether a collision has happened
 */
bool Bird::collisionDetection()
{
  // Ground Collision
  if (spriteComponent()->getSprite()->yPos() > 850 &&
      physics_component->linearVelocity().y > 0)
  {
    physics_component->linearVelocity(
      vector2(physics_component->linearVelocity().x,
              -physics_component->linearVelocity().y * friction));
    return true;
  }

  // Pig Collision
  // For each pig do circle/circle collision
  // If hit pig do force updates

  // Block collision
  // For each block do circle/AABB collision
  // if hit block do force update

  return false;
}

/**
 *   @brief   Update
 *   @details Calls collision detection, does physics and updates object
 * position
 *   @return  void
 */
void Bird::update(double delta_time)
{
  bool collision = collisionDetection();

  vector2 movement = physics_component->updatePosition(delta_time, collision);
  float rotation = physics_component->updateRotation(delta_time, collision);

  float new_x =
    spriteComponent()->getSprite()->xPos() + movement.x * float(delta_time);
  float new_y =
    spriteComponent()->getSprite()->yPos() + movement.y * float(delta_time);
  spriteComponent()->getSprite()->xPos(new_x);
  spriteComponent()->getSprite()->yPos(new_y);
  shape.x = new_x;
  shape.y = new_y;
  spriteComponent()->getSprite()->rotationInRadians((rotation * (3.14f / 180)) *
                                                    float(delta_time));
}

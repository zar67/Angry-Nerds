//
// Created by Zoe on 04/03/2019.
//

#include "PhysicsComponent.h"

/**
 *   @brief   Initialises the object's physics
 *   @details Sets the physics attributes to the given values
 *   @return  void
 */
void PhysicsComponent::initPhysics(vector2 velocity, float w_, float h_)
{
  linear_velocity = velocity;
  width = w_;
  height = h_;
}

/**
 *   @brief   Finds the movement vector to be applied to the object
 *   @details If the object collided with something, the forces generated from
 * that collision will be applied. If no collision happened, then gravity will
 * be applied.
 *   @return  The movement vector that should be applied to the object's
 * position
 */
vector2 PhysicsComponent::getMovement(double delta_time)
{
  vector2 linear_acceleration = vector2(0, gravity * 10);
  linear_velocity.increaseBy(float(linear_acceleration.x * delta_time),
                             float(linear_acceleration.y * delta_time));

  return vector2(linear_velocity.x, linear_velocity.y);
}

vector2 PhysicsComponent::linearVelocity()
{
  return linear_velocity;
}

void PhysicsComponent::linearVelocity(vector2 v)
{
  linear_velocity = v;
}

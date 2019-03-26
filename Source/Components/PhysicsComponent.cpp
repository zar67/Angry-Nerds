//
// Created by Zoe on 04/03/2019.
//

#include "PhysicsComponent.h"

/**
 *   @brief   Initialises the object's physics
 *   @details Sets the physics attributes to the given values
 *   @return  void
 */
void PhysicsComponent::initPhysics(vector2 velocity,
                                   float m_,
                                   float w_,
                                   float h_)
{
  linear_velocity = velocity;
  mass = m_;
  width = w_;
  height = h_;

  inertia = mass * (width * width + height * height) / 12;
}

/**
 *   @brief   Updates the object's position
 *   @details If the object collided with something, the forces generated from
 * that collision will be applied. If no collision happened, then gravity will
 * be applied.
 *   @return  The movement vector that should be applied to the object's
 * position
 */
vector2 PhysicsComponent::updatePosition(double delta_time)
{
  force.setAs(0, mass * gravity * 10);
  vector2 linear_acceleration = vector2(force.x / mass, force.y / mass);
  linear_velocity.increaseBy(float(linear_acceleration.x * delta_time),
                             float(linear_acceleration.y * delta_time));

  force.x = 0;
  force.y = 0;
  return vector2(linear_velocity.x, linear_velocity.y);
}

/**
 *   @brief   Adds force at a certain point
 *   @details Applies force and the correct rotation based on the collision
 * point given
 *   @return  void
 */
void PhysicsComponent::addForce(float fx, float fy, vector2 point)
{
  force.x += fx;
  force.y += fy;
}

vector2 PhysicsComponent::getForce()
{
  return force;
}

float PhysicsComponent::getMass()
{
  return mass;
}

//
// Created by Zoe on 04/03/2019.
//

#include "PhysicsComponent.h"

/**
 *   @brief   Initialises the object's physics
 *   @details Sets the physics attributes to the given values
 *   @return  void
 */
void PhysicsComponent::initPhysics(
  vector2 velocity, float a_velocity, float m_, float w_, float h_)
{
  linear_velocity = velocity;
  angular_velocity = a_velocity;
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
vector2 PhysicsComponent::updatePosition(double delta_time, bool collision)
{
  // Update force
  if (!collision)
  {
    force.setAs(0, mass * gravity * 10);
  }
  vector2 linear_acceleration = vector2(force.x / mass, force.y / mass);
  linear_velocity.increaseBy(float(linear_acceleration.x * delta_time),
                             float(linear_acceleration.y * delta_time));

  force.x = 0;
  force.y = 0;
  return vector2(linear_velocity.x, linear_velocity.y);
}

/**
 *   @brief   Updates the object's rotation
 *   @details If the object collided with something, the rotation generated from
 * that collision will be applied. If no collision happened, then rotation will
 * be calculated based on the object's centre of mass (arm_vector)
 *   @return  The amount of rotation that should be applied to the object's
 * rotation
 */
float PhysicsComponent::updateRotation(double delta_time, bool collision)
{
  // Update torque
  if (!collision)
  {
    vector2 arm_vector = vector2(width / 2, height / 2);
    torque = force.crossProduct(arm_vector);
  }
  float angular_acceleration = torque / inertia;
  angular_velocity += float(angular_acceleration * delta_time);

  torque = 0;
  return angular_velocity;
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
  torque +=
    force.crossProduct(vector2(point.x - (width / 2), point.y - (width / 2)));
}

/**
 *   @brief   Adds torque
 *   @return  void
 */
void PhysicsComponent::addTorque(float t_)
{
  torque += t_;
}
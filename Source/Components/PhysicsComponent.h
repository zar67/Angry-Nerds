//
// Created by Zoe on 04/03/2019.
//

#ifndef ANGRYNERDS_PHYSCISCOMPONENT_H
#define ANGRYNERDS_PHYSCISCOMPONENT_H

#include "Utility/Vector2.h"

class PhysicsComponent
{
 public:
  PhysicsComponent() = default;
  ~PhysicsComponent() = default;
  void initPhysics(vector2 velocity, float m_, float w_, float h_);
  vector2 updatePosition(double delta_time);
  void addForce(float fx, float fy, vector2 point);

  vector2 linearVelocity() { return linear_velocity; }
  void linearVelocity(vector2 v) { linear_velocity = v; }

  vector2 getForce();
  float getMass();

 private:
  float gravity = 9.81f;
  float width;
  float height;
  vector2 linear_velocity = vector2(0, 0);
  float mass = 0;
  vector2 force = vector2(0, 0);
  float inertia = 0;
};

#endif // ANGRYNERDS_PHYSCISCOMPONENT_H

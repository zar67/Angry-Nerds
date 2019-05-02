//
// Created by Zoe on 04/03/2019.
//

#ifndef ANGRYNERDS_PHYSCISCOMPONENT_H
#define ANGRYNERDS_PHYSCISCOMPONENT_H

#include "Utility/Vector2.h"

//@Feedback: good use of component design
class PhysicsComponent
{
 public:
  PhysicsComponent() = default;
  ~PhysicsComponent() = default;
  void initPhysics(vector2 velocity, float w_, float h_);
  vector2 getMovement(double delta_time);

  vector2 linearVelocity();
  void linearVelocity(vector2 v);

 private:
  float gravity = 9.81f;
  float width = 0.0f;
  float height = 0.0f;
  vector2 linear_velocity = vector2(0, 0);
};

#endif // ANGRYNERDS_PHYSCISCOMPONENT_H

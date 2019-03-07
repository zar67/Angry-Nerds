//
// Created by Zoe on 04/03/2019.
//

#ifndef ANGRYNERDS_BIRD_H
#define ANGRYNERDS_BIRD_H

#include "Components/GameObject.h"
#include "Utility/Circle.h"

class Bird : public GameObject
{
 public:
  Bird() = default;
  ~Bird() override = default;

  void update(double delta_time) override;
  void setUpBird(float x_,
                 float y_,
                 float r_,
                 vector2 velocity,
                 float angular_velocity,
                 float mass,
                 float speed_);

  bool released();
  void released(bool r);

 private:
  bool collisionDetection() override;
  Circle shape;
  float friction = 0.25f;
  bool free = false;
};

#endif // ANGRYNERDS_BIRD_H

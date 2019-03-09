//
// Created by Zoe on 04/03/2019.
//

#ifndef ANGRYNERDS_BIRD_H
#define ANGRYNERDS_BIRD_H

#include "Block.h"
#include "Components/GameObject.h"
#include "Utility/Circle.h"

class Block;

class Bird : public GameObject
{
 public:
  Bird() = default;
  ~Bird() override = default;

  void update(double delta_time, Block blocks[], int block_num);
  void setUpBird(float x_, float y_);

  Circle getShape();

  bool released();
  void released(bool r_);
  bool active();
  void active(bool a_);

 private:
  bool collisionDetection(Block blocks[], int block_num);
  int getCollisionSide(vector2 point, Rectangle col_shape);
  Circle shape;
  float friction = 0.25f;
  bool free = false;
  bool alive = true;
};

#endif // ANGRYNERDS_BIRD_H

//
// Created by Zoe on 08/03/2019.
//

#ifndef ANGRYNERDS_BLOCK_H
#define ANGRYNERDS_BLOCK_H

#include "Bird.h"
#include "Components/GameObject.h"
#include "Utility/Rectangle.h"

class Bird;

class Block : public GameObject
{
 public:
  Block() = default;
  ~Block() override = default;

  void update(double delta_time, Block blocks[], int block_num);
  void setUpBlock(float x_, float y_, float w_, float h_);

  Rectangle getShape();

 private:
  bool collisionDetection(Block blocks[], int block_num);
  int getCollisionSide(vector2 point, Rectangle col_shape);
  Rectangle shape;
  float friction = 0.1f;
};

#endif // ANGRYNERDS_BLOCK_H

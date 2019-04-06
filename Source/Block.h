//
// Created by Zoe on 08/03/2019.
//

#ifndef ANGRYNERDS_BLOCK_H
#define ANGRYNERDS_BLOCK_H

#include "Bird.h"
#include "Collision.h"
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

 private:
  void collision(Block* blocks, int block_num);
  Collision collision_detection;
  float friction = 0.1f;
};

#endif // ANGRYNERDS_BLOCK_H

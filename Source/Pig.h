//
// Created by Zoe on 10/03/2019.
//

#ifndef ANGRYNERDS_PIG_H
#define ANGRYNERDS_PIG_H

#include "Block.h"
#include "Components/GameObject.h"
#include "Utility/Circle.h"

class Block;

class Pig : public GameObject
{
 public:
  Pig() = default;
  ~Pig() override = default;
  void update(double delta_time, Block blocks[], int block_num);
  void setUpPig(float x_, float y_);

  Circle getShape();

  bool active();
  void active(bool a_);

 private:
  bool collision(Block* blocks, int block_num);
  Circle shape;
  float friction = 0.25f;
  bool alive = true;
};

#endif // ANGRYNERDS_PIG_H

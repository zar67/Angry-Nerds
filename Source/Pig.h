//
// Created by Zoe on 10/03/2019.
//

#ifndef ANGRYNERDS_PIG_H
#define ANGRYNERDS_PIG_H

#include "Block.h"
#include "Collision.h"
#include "Components/GameObject.h"
#include "Utility/Circle.h"

class Block;

class Pig : public GameObject
{
 public:
  Pig() = default;
  ~Pig() override = default;
  void setUpPig(float x_, float y_);

  bool active();
  void active(bool a_);

 private:
  bool alive = true;
};

#endif // ANGRYNERDS_PIG_H

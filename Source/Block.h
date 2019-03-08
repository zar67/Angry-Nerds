//
// Created by Zoe on 08/03/2019.
//

#ifndef ANGRYNERDS_BLOCK_H
#define ANGRYNERDS_BLOCK_H

#include "Components/GameObject.h"
#include "Utility/Rectangle.h"

class Block : public GameObject
{
 public:
  Block() = default;
  ~Block() override = default;

  void update(double delta_time) override;
  void setUpBlock(float x_, float y_, float w_, float h_);

 private:
  bool collisionDetection() override;
  Rectangle shape;
  float friction = 0.1f;
};

#endif // ANGRYNERDS_BLOCK_H

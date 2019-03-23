//
// Created by Zoe on 04/03/2019.
//

#ifndef ANGRYNERDS_BIRD_H
#define ANGRYNERDS_BIRD_H

#include "Block.h"
#include "Collision.h"
#include "Components/GameObject.h"
#include "Pig.h"
#include "Utility/Circle.h"

class Block;
class Pig;

class Bird : public GameObject
{
 public:
  Bird() = default;
  ~Bird() override = default;

  void update(
    double delta_time, Block blocks[], int block_num, Pig pigs[], int pig_num);
  void setUpBird(float x_, float y_);

  bool released();
  void released(bool r_);
  bool active();
  void active(bool a_);

 private:
  bool collision(Block* blocks, int block_num, Pig* pigs, int pig_num);
  Collision collision_detection;
  float friction = 0.25f;
  bool free = false;
  bool alive = true;
};

#endif // ANGRYNERDS_BIRD_H

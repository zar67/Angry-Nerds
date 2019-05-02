//
// Created by Zoe on 04/03/2019.
//

#ifndef ANGRYNERDS_BIRD_H
#define ANGRYNERDS_BIRD_H

#include "Collision.h"
#include "Components/GameObject.h"
#include "Utility/Circle.h"

class Block;
class Pig;

class Bird : public GameObject
{
 public:
  Bird() = default;

  //@Feedback: good work!!! saves the leak.
  ~Bird() override = default;

  void update(double delta_time,
              Block blocks[],
              int block_num,
              Pig pigs[],
              int pig_num,
              int* score);
  void setUpBird(float x_, float y_);

  bool released();
  void released(bool r_);

 private:
  //@Feedback; decouple Birds from the game. You should manage the collision
  // checks in the game not the Bird class. A Bird class should not know about
  // blocks or pigs, but the game should.
  void
  collision(Block* blocks, int block_num, Pig* pigs, int pig_num, int* score);
  float friction = 0.25f;
  bool free = false;
};

#endif // ANGRYNERDS_BIRD_H

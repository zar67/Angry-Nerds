//
// Created by Zoe on 10/03/2019.
//

#include "Pig.h"

void Pig::setUpPig(float x_, float y_)
{
  sprite_component->getSprite()->xPos(x_);
  sprite_component->getSprite()->yPos(y_);
  sprite_component->getSprite()->width(60);
  sprite_component->getSprite()->height(60);
}

bool Pig::active()
{
  return alive;
}

void Pig::active(bool a_)
{
  alive = a_;
}

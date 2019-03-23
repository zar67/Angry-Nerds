//
// Created by Zoe on 04/03/2019.
//

#include "Circle.h"

bool Circle::isInside(float x_, float y_) const
{
  vector2 dist_vector = vector2(x_ - (x + radius), y_ - (y + radius));
  float distance = dist_vector.length();

  return distance <= radius;
}

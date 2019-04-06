//
// Created by Zoe on 04/03/2019.
//

#ifndef ANGRYNERDS_CIRCLE_H
#define ANGRYNERDS_CIRCLE_H

#include "Utility/Rectangle.h"
#include "Utility/Vector2.h"

struct Rectangle;

struct Circle
{
  bool isInside(float x_, float y_) const;

  float x = 0;
  float y = 0;
  float radius = 0;
};

#endif // ANGRYNERDS_CIRCLE_H

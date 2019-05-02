
#ifndef ANGRYNERDS_RECTANGLE_H
#define ANGRYNERDS_RECTANGLE_H

#include "Utility/Circle.h"
#include "Utility/Vector2.h"

struct Rectangle
{
  bool isInside(float x_, float y_) const;

  float x = 0;
  float y = 0;
  float width = 0;
  float height = 0;
};

#endif // ANGRYNERDS_RECTANGLE_H
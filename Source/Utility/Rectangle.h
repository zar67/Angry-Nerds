
#ifndef ANGRYNERDS_RECTANGLE_H
#define ANGRYNERDS_RECTANGLE_H

#include "Circle.h"
#include "Vector2.h"

struct Circle;

struct Rectangle
{
  // Collision Detection
  vector2 AABBCollision(Rectangle rectangle);
  vector2 CircleCollision(Circle circle);
  bool isInside(float x_, float y_) const;

  float x = 0;
  float y = 0;
  float width = 0;
  float height = 0;
};

#endif // ANGRYNERDS_RECTANGLE_H
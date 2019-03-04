//
// Created by Zoe on 04/03/2019.
//

#ifndef ANGRYNERDS_CIRCLE_H
#define ANGRYNERDS_CIRCLE_H

#include "Rectangle.h"
#include "Vector2.h"

struct Rectangle;

struct Circle
{
  // Collision Detection
  vector2 AABBCollision(Rectangle rectangle);
  vector2 CircleCollision(Circle circle);

  float x = 0;
  float y = 0;
  float radius = 0;
};

#endif // ANGRYNERDS_CIRCLE_H

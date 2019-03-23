//
// Created by Zoe on 23/03/2019.
//

#ifndef ANGRYNERDS_COLLISION_H
#define ANGRYNERDS_COLLISION_H

#include "Utility/Circle.h"
#include "Utility/Rectangle.h"
#include "Utility/Vector2.h"

class Collision
{
 public:
  vector2 AABBAABB(Rectangle rect1, Rectangle rect2);
  vector2 AABBCircle(Rectangle rect, Circle circle);
  vector2 CircleCircle(Circle circle1, Circle circle2);
};

#endif // ANGRYNERDS_COLLISION_H

//
// Created by Zoe on 04/03/2019.
//

#include "Circle.h"
#include <math.h>

/**
 *   @brief   Circle-AABB Collision Detection
 *   @details Will check to see if this circle collides with the rectangle given
 * in the parameter
 *   @return  Returns the collision point or the vector 0,0 if they don't
 * collide
 */
vector2 Circle::AABBCollision(Rectangle rectangle)
{
  float closest_x =
    (x + radius) -
    fmaxf(rectangle.x, fminf((x + radius), (rectangle.x + rectangle.width)));
  float closest_y =
    (y + radius) -
    fmaxf(rectangle.y, fminf((y + radius), (rectangle.y + rectangle.height)));

  if ((radius * radius) > ((closest_x * closest_x) + (closest_y * closest_y)))
  {
    return vector2(closest_x, closest_y);
  }
  return vector2(0, 0);
}

/**
 *   @brief   Circle-Circle Collision Detection
 *   @details Will check to see if this circle collides with the circle given in
 * the parameter
 *   @return  Returns the collision point or the vector 0,0 if they don't
 * collide
 */
vector2 Circle::CircleCollision(Circle circle)
{
  float distance = radius + circle.radius;
  float x_difference = circle.x - x;
  float y_difference = circle.y - y;

  if ((distance * distance) >
      ((x_difference * x_difference) + (y_difference * y_difference)))
  {
    float dist_ratio = circle.radius / distance;
    float intersection_x = circle.x * (1 - dist_ratio) + (dist_ratio * x);
    float intersection_y = circle.y * (1 - dist_ratio) + (dist_ratio * y);

    return vector2(intersection_x, intersection_y);
  }
  return vector2(0, 0);
}

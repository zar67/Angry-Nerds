#include "Rectangle.h"
#include <math.h>

/**
 *   @brief   AABB-AABB Collision Detection
 *   @details Will check to see if this rectangle collides with the rectangle
 * given in the parameter
 *   @return  Returns the collision point or the vector 0,0 if they don't
 * collide
 */
vector2 Rectangle::AABBCollision(Rectangle rectangle)
{
  float delta_x = rectangle.x - x;
  float delta_y = rectangle.y - y;
  float intersect_x = abs(delta_x) - (width / 2 + rectangle.width / 2);
  float intersect_y = abs(delta_y) - (height / 2 + rectangle.height / 2);

  if (intersect_x <= 0 || intersect_y <= 0)
  {
    return vector2(0, 0);
  }

  // There is a collision
  if (abs(intersect_x) < abs(intersect_y))
  {
    // Intersected on left or right side
    if (delta_x > 0)
    {
      // Intersected on right side
      return vector2(x + width, y + (height / 2));
    }
    // Intersected on left side
    return vector2(x, y + (height / 2));
  }
  // Intersected on top or bottom side
  if (delta_y > 0)
  {
    // intersected on top side
    return vector2(x + (width / 2), y);
  }
  // intersected on bottom side
  return vector2(x + (width / 2), y + height);
}

/**
 *   @brief   Circle-AABB Collision Detection
 *   @details Will check to see if this rectangle collides with the circle given
 * in the parameter
 *   @return  Returns the collision point or the vector 0,0 if they don't
 * collide
 */
vector2 Rectangle::CircleCollision(Circle circle)
{
  float closest_x = fmaxf(x, fminf((circle.x + circle.radius), (x + width)));
  float closest_y = fmaxf(y, fminf((circle.y) + circle.radius, (y + height)));
  float x_diff = (circle.x + circle.radius) - closest_x;
  float y_diff = (circle.y + circle.radius) - closest_y;

  if ((circle.radius * circle.radius) > ((x_diff * x_diff) + (y_diff * y_diff)))
  {
    return vector2(closest_x, closest_y);
  }

  return vector2(0, 0);
}

/**
*   @brief   Does a point reside within this rectangle?
*   @details Will check to see if the x and y coordinates
             provided reside within the area of the rectangle.
*   @return  True if they do.
*/
bool Rectangle::isInside(float x_, float y_) const
{
  if (x_ >= x && x_ <= x + width && y_ >= y && y_ <= y + height)
  {
    return true;
  }

  return false;
}
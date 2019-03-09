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
  float dx = (rectangle.x + rectangle.width / 2) - (x + width / 2);
  float px = (rectangle.width / 2 + width / 2) - abs(dx);

  float dy = (rectangle.y + rectangle.height / 2) - (y + height / 2);
  float py = (rectangle.height / 2 + height / 2) - abs(dy);

  if (px <= 0 || py <= 0)
  {
    return vector2(0, 0);
  }

  float pos_x = 0;
  float pos_y = 0;

  if (px < py)
  {
    float sx = dx < 0 ? -1 : 1;
    pos_x = (x + width / 2) + (width / 2 * sx);
    pos_y = (rectangle.y + rectangle.height / 2);
  }
  else
  {
    float sy = dy < 0 ? -1 : 1;
    pos_x = (rectangle.x + rectangle.width / 2);
    pos_y = (y + width / 2) + (width / 2 * sy);
  }

  return vector2(pos_x, pos_y);
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
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

  if (intersect_x < 0 && intersect_y < 0)
  {
    if (abs(intersect_x) < abs(intersect_y))
    {
      // Intersected on left or right side
      if (delta_x > 0)
      {
        // Intersected on right side
        return vector2(x + width, y + (height / 2));
      }
      else
      {
        // Intersected on left side
        return vector2(x, y + (height / 2));
      }
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
  return vector2(0, 0);
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
  float closest_x = (circle.x + circle.radius) -
                    fmaxf(x, fminf((circle.x + circle.radius), (x + width)));
  float closest_y = (circle.y + circle.radius) -
                    fmaxf(y, fminf((circle.x) + circle.radius, (y + width)));

  if ((circle.radius * circle.radius) >
      ((closest_x * closest_x) + (closest_y * closest_y)))
  {
    return vector2(closest_x, closest_y);
  }
  else
  {
    return vector2(0, 0);
  }
}

/**
*   @brief   Does a point reside within this rectangle?
*   @details Will check to see if the x and y coordinates
             provided reside within the area of the rectangle.
*   @return  True if they do.
*/
bool Rectangle::isInside(float x_, float y_) const
{
  if (x_ >= this->x && x_ <= this->x + this->width && y_ >= this->y &&
      y_ <= this->y + this->height)
  {
    return true;
  }

  return false;
}
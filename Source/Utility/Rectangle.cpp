#include "Rectangle.h"

/**
*   @brief   Does a point reside within this rectangle?
*   @details Will check to see if the x and y coordinates
             provided reside within the area of the rectangle.
*   @return  True if they do.
*/
bool Rectangle::isInside(float x_, float y_) const
{
  return x_ >= x && x_ <= x + width && y_ >= y && y_ <= y + height;
}
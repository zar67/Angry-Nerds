#include "Vector2.h"
#include <math.h>

/**
 *   @brief   Constructor.
 *   @details Requires values for it's x and y magnitudes.
 *   @return  void
 */
vector2::vector2(float x_, float y_) : x(x_), y(y_) {}

/**
 *   @brief   Copies a vector.
 *   @details Constructs a new vector2 from an existing.
 *   @return  void
 */
vector2::vector2(const vector2& rhs)
{
  this->x = rhs.x;
  this->y = rhs.y;
}

/**
 *   @brief   Resets the vector
 *   @details Will set the x and y values to the values given by the parameters
 *   @return  void
 */
void vector2::setAs(float x_, float y_)
{
  x = x_;
  y = y_;
}

/**
 *   @brief   Increases the vector
 *   @details Will increase the x and y values by the values given by the
 * parameters
 *   @return  void
 */
void vector2::increaseBy(float x_, float y_)
{
  x += x_;
  y += y_;
}

/**
 *   @brief   Scales the vector
 *   @details Will scale the x and y values by the values given by the
 * parameters
 *   @return  void
 */
void vector2::multiplyBy(float x_, float y_)
{
  x *= x_;
  y *= y_;
}

/**
 *   @brief   Copies a vector.
 *   @details Updates vector2 from an existing.
 *   @return  void
 */
vector2& vector2::operator=(const vector2& rhs)
{
  this->x = rhs.x;
  this->y = rhs.y;

  return *this;
}

/**
 *   @brief   Normalises vector.
 *   @details Turns the vector into a unit vector.
 *   @return  void
 */
void vector2::normalise()
{
  float magnitude = sqrtf((x * x) + (y * y));

  if (!magnitude)
    return;

  x /= magnitude;
  y /= magnitude;
}

/**
 *   @brief   Scales the vector.
 *   @details Uses a single scalar value to adjust the vector.
 *   @return  void
 */
vector2 vector2::operator*(float scalar)
{
  vector2 vec(*this);
  vec.x *= scalar;
  vec.y *= scalar;
  return vec;
}

/**
 *   @brief   Cross Product
 *   @details Will get the scalar cross product of this vector and the one given
 * in the parameter
 *   @return  The scalar
 */
float vector2::crossProduct(vector2 vector)
{
  return (x * vector.y) - (y * vector.x);
}

float vector2::dotProduct(vector2 vector)
{
  return (x * vector.x) + (y * vector.y);
}

float vector2::distance(float x_, float y_)
{
  float x_diff = x - x_;
  float y_diff = y - y_;
  return sqrt((x_diff * x_diff) + (y_diff * y_diff));
}

#pragma once

struct vector2
{
  // construction
  vector2(float x_, float y_);
  vector2(const vector2& rhs);

  // operations
  void setAs(float x_, float y_);
  void increaseBy(float x_, float y_);
  void multiplyBy(float x_, float y_);

  vector2 operator*(float scalar);
  vector2& operator=(const vector2& rhs);

  void normalise();
  float crossProduct(vector2 vector);
  float dotProduct(vector2 vector);
  float distance(float x_, float y_);
  float length();

  // data
  float x = 0;
  float y = 0;
};

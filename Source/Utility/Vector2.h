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

  void normalise();
  float crossProduct(vector2 vector);

  // data
  float x = 0;
  float y = 0;
};

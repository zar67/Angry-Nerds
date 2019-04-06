//
// Created by Zoe on 23/03/2019.
//

#include "Collision.h"
#include <math.h>

vector2 Collision::AABBAABB(Rectangle rect1, Rectangle rect2)
{
  float dx = (rect2.x + rect2.width / 2) - (rect1.x + rect1.width / 2);
  float px = (rect2.width / 2 + rect1.width / 2) - abs(dx);

  float dy = (rect2.y + rect2.height / 2) - (rect1.y + rect1.height / 2);
  float py = (rect2.height / 2 + rect1.height / 2) - abs(dy);

  if (px <= 0 || py <= 0)
  {
    return vector2(0, 0);
  }

  float pos_x = 0;
  float pos_y = 0;

  if (px < py)
  {
    float sx = dx < 0 ? -1 : 1;
    pos_x = (rect1.x + rect1.width / 2) + (rect1.width / 2 * sx);
    pos_y = (rect2.y + rect2.height / 2);
  }
  else
  {
    float sy = dy < 0 ? -1 : 1;
    pos_x = (rect2.x + rect2.width / 2);
    pos_y = (rect1.y + rect1.width / 2) + (rect1.width / 2 * sy);
  }

  return vector2(pos_x, pos_y);
}

vector2 Collision::AABBCircle(Rectangle rect, Circle circle)
{
  float closest_x =
    fmaxf(rect.x, fminf((circle.x + circle.radius), (rect.x + rect.width)));
  float x_diff = (circle.x + circle.radius) - closest_x;

  float closest_y =
    fmaxf(rect.y, fminf((circle.y + circle.radius), (rect.y + rect.height)));
  float y_diff = (circle.y + circle.radius) - closest_y;

  if ((circle.radius * circle.radius) > ((x_diff * x_diff) + (y_diff * y_diff)))
  {
    return vector2(closest_x, closest_y);
  }
  return vector2(0, 0);
}

vector2 Collision::CircleCircle(Circle circle1, Circle circle2)
{
  float distance = circle1.radius + circle2.radius;
  float x_difference = circle2.x - circle1.x;
  float y_difference = circle2.y - circle1.y;

  if ((distance * distance) >
      ((x_difference * x_difference) + (y_difference * y_difference)))
  {
    float dist_ratio = circle2.radius / distance;
    float intersection_x =
      circle2.x * (1 - dist_ratio) + (dist_ratio * circle1.x);
    float intersection_y =
      circle2.y * (1 - dist_ratio) + (dist_ratio * circle1.y);

    return vector2(intersection_x, intersection_y);
  }
  return vector2(0, 0);
}

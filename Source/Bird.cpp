//
// Created by Zoe on 04/03/2019.
//

#include "Bird.h"
#include <iostream>

/**
 *   @brief   Sets up the bird object
 *   @details Sprite component needs to be added before this function is called.
 * This function sets up the physics components and the needed attributes of the
 * bird class.
 *   @return  void
 */
void Bird::setUpBird(float x_, float y_)
{
  addPhysicsComponent(vector2(0, 0), 0, 50, 50, 50);
  spriteComponent()->getSprite()->xPos(x_);
  spriteComponent()->getSprite()->yPos(y_);
  spriteComponent()->getSprite()->width(50);
  spriteComponent()->getSprite()->height(50);
  shape.x = x_;
  shape.y = y_;
  shape.radius = 50;
  speed = 3.5f;
}

/**
 *   @brief   Collision Detection
 *   @details Detects collision against the ground, pigs and blocks
 *   @return  Bool stating whether a collision has happened
 */
bool Bird::collisionDetection(Block blocks[], int block_num)
{
  bool collision = false;
  // Ground Collision
  if (spriteComponent()->getSprite()->yPos() > 850 &&
      physics_component->linearVelocity().y > 0)
  {
    physics_component->linearVelocity(
      vector2(physics_component->linearVelocity().x * friction,
              -physics_component->linearVelocity().y * friction));
    collision = true;
  }

  // Pig Collision
  // For each pig do circle/circle collision
  // If hit pig do force updates

  // Block collision
  for (int i = 0; i < block_num; i++)
  {
    vector2 point = blocks[i].getShape().CircleCollision(shape);

    // If there is a collision and the bird is travelling towards 
    // the side of the collision
    if ((point.x != 0 || point.y != 0) &&
        ((point.x == blocks[i].getShape().x &&
          physicsComponent()->linearVelocity().x > 0) ||
         (point.x == blocks[i].getShape().x + blocks[i].getShape().width &&
          physicsComponent()->linearVelocity().x < 0) ||
         (point.y == blocks[i].getShape().y &&
          physicsComponent()->linearVelocity().y > 0) ||
         (point.y == blocks[i].getShape().y + blocks[i].getShape().height &&
          physicsComponent()->linearVelocity().y < 0)))
    {
      collision = true;
      blocks[i].physicsComponent()->addForce(
        physicsComponent()->getForce().x * 0.4f,
        physicsComponent()->getForce().y * 0.4f,
        point);
      blocks[i].physicsComponent()->linearVelocity(
        vector2(physicsComponent()->linearVelocity().x,
                physicsComponent()->linearVelocity().y));
      physicsComponent()->addForce(physicsComponent()->getForce().x * 0.6f,
                                   physicsComponent()->getForce().y * 0.6f,
                                   point);
      std::cout << point.x << ", " << point.y << std::endl;
      if (point.x == blocks[i].getShape().x ||
          point.x == blocks[i].getShape().x + blocks[i].getShape().width)
      {
        physicsComponent()->linearVelocity(
          vector2(-physicsComponent()->linearVelocity().x,
                  physicsComponent()->linearVelocity().y));
      }
      else
      {
        physicsComponent()->linearVelocity(
          vector2(physicsComponent()->linearVelocity().x,
                  -physicsComponent()->linearVelocity().y));
      }
    }
  }
  // For each block do circle/AABB collision
  // if hit block do force update

  return collision;
}

/**
 *   @brief   Update
 *   @details Calls collision detection, does physics and updates object
 * position
 *   @return  void
 */
void Bird::update(double delta_time, Block blocks[], int block_num)
{
  bool collision = collisionDetection(blocks, block_num);

  vector2 movement = physics_component->updatePosition(delta_time, collision);
  float rotation = physics_component->updateRotation(delta_time, collision);

  float new_x = spriteComponent()->getSprite()->xPos() +
                movement.x * float(delta_time) * speed;
  float new_y = spriteComponent()->getSprite()->yPos() +
                movement.y * float(delta_time) * speed;
  spriteComponent()->getSprite()->xPos(new_x);
  spriteComponent()->getSprite()->yPos(new_y);

  shape.x = new_x;
  shape.y = new_y;
  spriteComponent()->getSprite()->rotationInRadians((rotation * (3.14f / 180)) *
                                                    float(delta_time));
}

bool Bird::released()
{
  return free;
}

void Bird::released(bool r_)
{
  free = r_;
}

Circle Bird::getShape()
{
  return shape;
}

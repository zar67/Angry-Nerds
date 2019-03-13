//
// Created by Zoe on 04/03/2019.
//

#include "Bird.h"

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
  shape.radius = 25;
  speed = 3.5f;
}

/**
 *   @brief   Collision Detection
 *   @details Detects collision against the ground, pigs and blocks
 *   @return  Bool stating whether a collision has happened
 */
bool Bird::collisionDetection(Block blocks[],
                              int block_num,
                              Pig pigs[],
                              int pig_num)
{
  bool collision = false;

  // Ground Collision
  if (spriteComponent()->getSprite()->yPos() > 850 &&
      physics_component->linearVelocity().y >= 0)
  {
    collision = true;
    spriteComponent()->getSprite()->yPos(850);
    physics_component->linearVelocity(
      vector2(physics_component->linearVelocity().x * friction,
              -physics_component->linearVelocity().y * friction));
  }

  // Pig Collision
  for (int i = 0; i < pig_num; i++)
  {
    vector2 point = pigs[i].getShape().CircleCollision(shape);

    if ((point.x != 0 || point.y != 0) &&
        ((point.x < pigs[i].spriteComponent()->getSprite()->xPos() +
                      pigs[i].spriteComponent()->getSprite()->width() / 2 &&
          physicsComponent()->linearVelocity().x >= 0) ||
         (point.x > pigs[i].spriteComponent()->getSprite()->xPos() +
                      pigs[i].spriteComponent()->getSprite()->width() / 2 &&
          physicsComponent()->linearVelocity().x <= 0) ||
         (point.y < pigs[i].spriteComponent()->getSprite()->yPos() +
                      pigs[i].spriteComponent()->getSprite()->height() / 2 &&
          physicsComponent()->linearVelocity().y >= 0) ||
         (point.y > pigs[i].spriteComponent()->getSprite()->yPos() +
                      pigs[i].spriteComponent()->getSprite()->height() / 2 &&
          physicsComponent()->linearVelocity().y <= 0)))
    {
      pigs[i].physicsComponent()->linearVelocity(
        vector2(physicsComponent()->linearVelocity().x,
                physicsComponent()->linearVelocity().y));

      physicsComponent()->linearVelocity(
        vector2(-physicsComponent()->linearVelocity().x * 0.4f,
                -physicsComponent()->linearVelocity().y * 0.4f));
    }
  }

  // Block collision
  for (int i = 0; i < block_num; i++)
  {
    vector2 point = blocks[i].getShape().CircleCollision(shape);

    if (point.x != 0 || point.y != 0)
    {
      int side = getCollisionSide(point, blocks[i].getShape());
      if (side != 0)
      {
        // There is a valid collision
        collision = true;

        blocks[i].physicsComponent()->linearVelocity(
          vector2(physicsComponent()->linearVelocity().x * 2,
                  physicsComponent()->linearVelocity().y * 2));
        // Update velocity based on side hit
        if (side == 1 || side == 2)
        {
          physicsComponent()->linearVelocity(
            vector2(-physicsComponent()->linearVelocity().x * 0.4f,
                    physicsComponent()->linearVelocity().y * 0.4f));
        }
        else if (side == 3 || side == 4)
        {
          physicsComponent()->linearVelocity(
            vector2(physicsComponent()->linearVelocity().x * 0.4f,
                    -physicsComponent()->linearVelocity().y * 0.4f));
        }
      }
    }
  }

  return collision;
}

/**
 *   @brief   Update
 *   @details Calls collision detection, does physics and updates object
 * position
 *   @return  void
 */
void Bird::update(
  double delta_time, Block blocks[], int block_num, Pig pigs[], int pig_num)
{
  bool collision = collisionDetection(blocks, block_num, pigs, pig_num);

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

bool Bird::active()
{
  return alive;
}

void Bird::active(bool a_)
{
  alive = a_;
}

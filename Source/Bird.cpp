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
  sprite_component->getSprite()->xPos(x_);
  sprite_component->getSprite()->yPos(y_);
  sprite_component->getSprite()->width(50);
  sprite_component->getSprite()->height(50);
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
bool Bird::collision(Block* blocks, int block_num, Pig* pigs, int pig_num)
{
  bool collide = false;

  // Ground Collision
  if (groundCollisionDetection(sprite_component->getSprite()->yPos(),
                               sprite_component->getSprite()->height(),
                               physics_component->linearVelocity().y))
  {
    collide = true;
    spriteComponent()->getSprite()->yPos(850);
    physics_component->linearVelocity(
      vector2(physics_component->linearVelocity().x * friction,
              -physics_component->linearVelocity().y * friction));
  }

  // Pig Collision
  for (int i = 0; i < pig_num; i++)
  {
    if (pigs[i].active())
    {
      vector2 point = pigs[i].getShape().CircleCollision(shape);

      if ((point.x != 0 || point.y != 0) &&
          getCollisionSideCir(point, shape) != 0)
      {
        // Damage Pig
        if (pigs[i].physicsComponent()->linearVelocity().x != 0 ||
            pigs[i].physicsComponent()->linearVelocity().y != 0)
        {
          float magnitude =
            pigs[i].physicsComponent()->linearVelocity().length();
          pigs[i].damage(static_cast<int>(magnitude));
        }
        else if (physics_component->linearVelocity().x != 0 ||
                 physics_component->linearVelocity().y != 0)
        {
          float magnitude = physics_component->linearVelocity().length();
          pigs[i].damage(static_cast<int>(magnitude));
        }

        pigs[i].physicsComponent()->linearVelocity(
          vector2(physics_component->linearVelocity().x,
                  physics_component->linearVelocity().y));

        physics_component->linearVelocity(
          vector2(-physics_component->linearVelocity().x * 0.4f,
                  -physics_component->linearVelocity().y * 0.4f));
      }
    }
  }

  // Block collision
  for (int i = 0; i < block_num; i++)
  {
    vector2 point = blocks[i].getShape().CircleCollision(shape);

    if (point.x != 0 || point.y != 0)
    {
      int side = getCollisionSideRect(point, blocks[i].getShape());
      if (side != 0)
      {
        // There is a valid collision
        collide = true;

        blocks[i].physicsComponent()->linearVelocity(
          vector2(physics_component->linearVelocity().x * 2,
                  physics_component->linearVelocity().y * 2));
        // Update velocity based on side hit
        if (side == 1 || side == 2)
        {
          physics_component->linearVelocity(
            vector2(-physics_component->linearVelocity().x * 0.4f,
                    physics_component->linearVelocity().y * 0.4f));
        }
        else if (side == 3 || side == 4)
        {
          physics_component->linearVelocity(
            vector2(physics_component->linearVelocity().x * 0.4f,
                    -physics_component->linearVelocity().y * 0.4f));
        }
      }
    }
    physics_component->linearVelocity().normalise();
  }

  return collide;
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
  bool collide = collision(blocks, block_num, pigs, pig_num);

  vector2 movement = physics_component->updatePosition(delta_time, collide);
  float rotation = physics_component->updateRotation(delta_time, collide);

  float new_x = sprite_component->getSprite()->xPos() +
                movement.x * float(delta_time) * speed;
  float new_y = sprite_component->getSprite()->yPos() +
                movement.y * float(delta_time) * speed;
  sprite_component->getSprite()->xPos(new_x);
  sprite_component->getSprite()->yPos(new_y);

  shape.x = new_x;
  shape.y = new_y;
  sprite_component->getSprite()->rotationInRadians((rotation * (3.14f / 180)) *
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

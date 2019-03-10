//
// Created by Zoe on 10/03/2019.
//

#include "Pig.h"

void Pig::setUpPig(float x_, float y_)
{
  addPhysicsComponent(vector2(0, 0), 0, 60, 50, 50);
  spriteComponent()->getSprite()->xPos(x_);
  spriteComponent()->getSprite()->yPos(y_);
  spriteComponent()->getSprite()->width(60);
  spriteComponent()->getSprite()->height(60);
  shape.x = x_;
  shape.y = y_;
  shape.radius = 30;
  speed = 3.5f;
}

bool Pig::collisionDetection(Block* blocks, int block_num)
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

  // Blocks Collision
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
          vector2(physicsComponent()->linearVelocity().x,
                  physicsComponent()->linearVelocity().y));
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

void Pig::update(double delta_time, Block* blocks, int block_num)
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

Circle Pig::getShape()
{
  return shape;
}

bool Pig::active()
{
  return alive;
}

void Pig::active(bool a_)
{
  alive = a_;
}

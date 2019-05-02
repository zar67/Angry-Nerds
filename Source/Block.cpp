//
// Created by Zoe on 08/03/2019.
//

#include "Block.h"

void Block::setUpBlock(float x_, float y_, float w_, float h_)
{
  addPhysicsComponent(vector2(0, 0), w_, h_);
  sprite_component->getSprite()->xPos(x_);
  sprite_component->getSprite()->yPos(y_);
  sprite_component->getSprite()->width(w_);
  sprite_component->getSprite()->height(h_);
  speed = 1.5f;
}

void Block::collision(Block* blocks, int block_num)
{
  // Ground Collision
  if (groundCollisionDetection(sprite_component->getSprite()->yPos(),
                               sprite_component->getSprite()->height(),
                               physics_component->linearVelocity().y))
  {
    sprite_component->getSprite()->yPos(
      900 - sprite_component->getSprite()->height());
    physics_component->linearVelocity(
      vector2(physics_component->linearVelocity().x * friction,
              -physics_component->linearVelocity().y * friction));
  }

  // Block collide
  for (int i = 0; i < block_num; i++)
  {
    if (blocks[i].spriteComponent()->getSprite()->xPos() !=
          sprite_component->getSprite()->xPos() &&
        blocks[i].spriteComponent()->getSprite()->yPos() !=
          sprite_component->getSprite()->yPos())
    {
      vector2 point =
        Collision::AABBAABB(blocks[i].spriteComponent()->getBoundingBox(),
                            sprite_component->getBoundingBox());

      if (point.x != 0 || point.y != 0)
      {
        int side = getCollisionSideRect(
          point, blocks[i].spriteComponent()->getBoundingBox());
        if (side != 0)
        {
          // There is a valid collide
          blocks[i].physicsComponent()->linearVelocity(
            vector2(physics_component->linearVelocity().x,
                    physics_component->linearVelocity().y));

          switch (side)
          {
            default:
              break;
            case 1:
              physics_component->linearVelocity(
                vector2(-physics_component->linearVelocity().x * 0.4f,
                        physics_component->linearVelocity().y * 0.4f));
              sprite_component->getSprite()->xPos(
                blocks[i].spriteComponent()->getSprite()->xPos() -
                sprite_component->getSprite()->width());
              break;
            case 2:
              physics_component->linearVelocity(
                vector2(-physics_component->linearVelocity().x * 0.4f,
                        physics_component->linearVelocity().y * 0.4f));
              sprite_component->getSprite()->xPos(
                blocks[i].spriteComponent()->getSprite()->xPos() +
                blocks[i].spriteComponent()->getSprite()->width());
              break;
            case 3:
              physics_component->linearVelocity(
                vector2(physics_component->linearVelocity().x * 0.4f,
                        -physics_component->linearVelocity().y * 0.4f));
              sprite_component->getSprite()->yPos(
                blocks[i].spriteComponent()->getSprite()->yPos() -
                sprite_component->getSprite()->height());
              break;
            case 4:
              physics_component->linearVelocity(
                vector2(physics_component->linearVelocity().x * 0.4f,
                        -physics_component->linearVelocity().y * 0.4f));
              sprite_component->getSprite()->yPos(
                blocks[i].spriteComponent()->getSprite()->yPos() +
                blocks[i].spriteComponent()->getSprite()->height());
              break;
          }
        }
      }
    }
    physics_component->linearVelocity().normalise();
  }
}

void Block::update(double delta_time, Block blocks[], int block_num)
{
  collision(blocks, block_num);

  vector2 movement = physics_component->getMovement(delta_time);

  float new_x = sprite_component->getSprite()->xPos() +
                movement.x * float(delta_time) * speed;
  float new_y = sprite_component->getSprite()->yPos() +
                movement.y * float(delta_time) * speed;

  sprite_component->getSprite()->xPos(new_x);
  sprite_component->getSprite()->yPos(new_y);
}
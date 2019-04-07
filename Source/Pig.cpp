//
// Created by Zoe on 10/03/2019.
//

#include "Pig.h"

void Pig::setUpPig(float x_, float y_)
{
  addPhysicsComponent(vector2(0, 0), 50, 50);
  sprite_component->getSprite()->xPos(x_);
  sprite_component->getSprite()->yPos(y_);
  sprite_component->getSprite()->width(60);
  sprite_component->getSprite()->height(60);
  speed = 3.5f;
}

void Pig::collision(Block* blocks, int block_num)
{
  // Ground Collision
  if (groundCollisionDetection(sprite_component->getSprite()->yPos(),
                               sprite_component->getSprite()->height(),
                               physics_component->linearVelocity().y))
  {
    sprite_component->getSprite()->yPos(850);
    physics_component->linearVelocity(
      vector2(physics_component->linearVelocity().x * friction,
              -physics_component->linearVelocity().y * friction));
  }

  // Blocks Collision
  for (int i = 0; i < block_num; i++)
  {
    vector2 point = collision_detection.AABBCircle(
      blocks[i].spriteComponent()->getBoundingBox(),
      sprite_component->getBoundingCircle());

    if (point.x != 0 || point.y != 0)
    {
      int side = getCollisionSideRect(
        point, blocks[i].spriteComponent()->getBoundingBox());
      if (side != 0)
      {
        // There is a valid collision
        blocks[i].physicsComponent()->linearVelocity(
          vector2(physics_component->linearVelocity().x,
                  physics_component->linearVelocity().y));

        switch(side)
        {
          default:
            break;
            case 1:
              physics_component->linearVelocity(vector2(-physics_component->linearVelocity().x * 0.4f, physics_component->linearVelocity().y * 0.4f));
              sprite_component->getSprite()->xPos(blocks[i].spriteComponent()->getSprite()->xPos() - sprite_component->getSprite()->width());
              break;
            case 2:
              physics_component->linearVelocity(vector2(-physics_component->linearVelocity().x * 0.4f, physics_component->linearVelocity().y * 0.4f));
              sprite_component->getSprite()->xPos(blocks[i].spriteComponent()->getSprite()->xPos() + blocks[i].spriteComponent()->getSprite()->width());
              break;
            case 3:
              physics_component->linearVelocity(vector2(physics_component->linearVelocity().x * 0.4f, -physics_component->linearVelocity().y * 0.4f));
              sprite_component->getSprite()->yPos(blocks[i].spriteComponent()->getSprite()->yPos() - sprite_component->getSprite()->height());
              break;
            case 4:
              physics_component->linearVelocity(vector2(physics_component->linearVelocity().x * 0.4f, -physics_component->linearVelocity().y * 0.4f));
                sprite_component->getSprite()->yPos(blocks[i].spriteComponent()->getSprite()->yPos() + blocks[i].spriteComponent()->getSprite()->height());
                break;
        }
      }
    }
    physics_component->linearVelocity().normalise();
  }
}

void Pig::update(double delta_time, Block* blocks, int block_num)
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
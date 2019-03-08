//
// Created by Zoe on 08/03/2019.
//

#include "Block.h"

void Block::setUpBlock(float x_, float y_, float w_, float h_)
{
  addPhysicsComponent(vector2(0, 0), 0, 60, w_, h_);
  spriteComponent()->getSprite()->xPos(x_);
  spriteComponent()->getSprite()->yPos(y_);
  spriteComponent()->getSprite()->width(w_);
  spriteComponent()->getSprite()->height(h_);
  shape.x = x_;
  shape.y = y_;
  shape.width = w_;
  shape.height = h_;
  speed = 1.5f;
}

bool Block::collisionDetection(Block blocks[], int block_num)
{
  // Ground Collision
  if (spriteComponent()->getSprite()->yPos() > 900 - shape.height &&
      physics_component->linearVelocity().y > 0)
  {
    physics_component->linearVelocity(
      vector2(physics_component->linearVelocity().x * friction,
              -physics_component->linearVelocity().y * friction));
    return true;
  }

  // Bird Collision
  // For each bird do AABB/circle collision
  // If hit bird do force updates

  // Pig Collision
  // For each pig do AABB/circle collision
  // If hit pig do force updates

  // Block collision
  // For each block do AABB/AABB collision
  // If hit block do force update

  return false;
}

void Block::update(double delta_time, Block blocks[], int block_num)
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

Rectangle Block::getShape()
{
  return shape;
}

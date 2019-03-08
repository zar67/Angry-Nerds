#pragma once
#include <Engine/OGLGame.h>
#include <string>

#include "Bird.h"
#include "Block.h"
#include "Components/GameObject.h"
#include "Utility/Rectangle.h"

const int NUM_OF_BIRDS = 3;
const int NUM_OF_BLOCKS = 5;

/**
 *  An OpenGL Game based on ASGE.
 */
class Angry : public ASGE::OGLGame
{
 public:
  Angry();
  ~Angry();
  virtual bool init() override;

 private:
  void keyHandler(const ASGE::SharedEventData data);
  void clickHandler(const ASGE::SharedEventData data);
  void setupResolution();
  bool loadBackgrounds();

  virtual void update(const ASGE::GameTime&) override;
  virtual void render(const ASGE::GameTime&) override;

  int key_callback_id = -1;   /**< Key Input Callback ID. */
  int mouse_callback_id = -1; /**< Mouse Input Callback ID. */

  // Add your GameObjects
  GameObject background_layer;
  GameObject menu_layer;
  Bird birds[NUM_OF_BIRDS];
  Block blocks[NUM_OF_BLOCKS];
  int current_bird = NUM_OF_BIRDS - 1;
  bool clicked_on_bird = false;

  double mouse_x = 0;
  double mouse_y = 0;

  bool in_menu = true;
  bool game_over = false;
  bool game_won = false;
};
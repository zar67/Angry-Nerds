#pragma once
#include <Engine/OGLGame.h>
#include <string>

#include "Bird.h"
#include "Block.h"
#include "Components/GameObject.h"
#include "Pig.h"
//#include "Utility/Rectangle.h"

const int NUM_OF_BIRDS = 4;
const int NUM_OF_BLOCKS = 5;
const int NUM_OF_PIGS = 2;

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
  bool setupBirds();
  bool setupPigs();
  bool setupBlocks();

  void restart();

  void moveBirdInCatapult();
  void releaseBird();

  virtual void update(const ASGE::GameTime&) override;
  virtual void render(const ASGE::GameTime&) override;

  int key_callback_id = -1;   /**< Key Input Callback ID. */
  int mouse_callback_id = -1; /**< Mouse Input Callback ID. */

  // Add your GameObjects
  GameObject background_layer;
  GameObject menu_layer;
  GameObject catapult;

  Bird birds[NUM_OF_BIRDS];
  Block blocks[NUM_OF_BLOCKS];
  Pig pigs[NUM_OF_PIGS];

  float pig_positions[NUM_OF_PIGS][2] = { { 1340, 560 }, { 840, 900 } };
  float block_positions[NUM_OF_BLOCKS][2] = {
    { 1024, 760 }, { 1250, 690 }, { 1250, 620 }, { 1390, 690 }, { 1600, 760 }
  };
  int block_sizes[NUM_OF_BLOCKS][2] = {
    { 1, 2 }, { 1, 3 }, { 3, 1 }, { 1, 3 }, { 1, 2 }
  };

  int current_bird = NUM_OF_BIRDS - 1;

  int score = 0;

  bool clicked_on_bird = false;
  bool release_bird = false;

  double mouse_x = 0;
  double mouse_y = 0;

  bool in_menu = true;
  bool game_over = false;
  bool game_won = false;

  bool birds_used = false;
  double stop_timer = 0;
};
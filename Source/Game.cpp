#include <string>

#include "Game.h"
#include <Engine/DebugPrinter.h>
#include <Engine/Input.h>
#include <Engine/InputEvents.h>
#include <Engine/Keys.h>
#include <Engine/Sprite.h>
#include <iostream>

/**
*   @brief   Default Constructor.
*   @details Consider setting the game's width and height
             and even seeding the random number generator.
*/
Angry::Angry()
{
  std::srand(static_cast<unsigned int>(time(nullptr)));
}

/**
 *   @brief   Destructor.
 *   @details Remove any non-managed memory and callbacks.
 */
Angry::~Angry()
{
  this->inputs->unregisterCallback(static_cast<unsigned int>(key_callback_id));
  this->inputs->unregisterCallback(
    static_cast<unsigned int>(mouse_callback_id));
}

/**
*   @brief   Initialises the game.
*   @details The game window is created and all assets required to
                         run the game are loaded. The keyHandler and
clickHandler callback should also be set in the initialise function.
*   @return  True if the game initialised correctly.
*/
bool Angry::init()
{
  setupResolution();
  if (!initAPI())
  {
    return false;
  }

  toggleFPS();
  renderer->setWindowTitle("Angry Birds!");
  renderer->setWindowedMode(ASGE::Renderer::WindowMode::WINDOWED);
  renderer->setClearColour(ASGE::COLOURS::BLACK);

  // input handling functions
  inputs->use_threads = false;

  key_callback_id =
    inputs->addCallbackFnc(ASGE::E_KEY, &Angry::keyHandler, this);

  mouse_callback_id =
    inputs->addCallbackFnc(ASGE::E_MOUSE_CLICK, &Angry::clickHandler, this);

  if (!loadBackgrounds())
  {
    std::cout << "Background not loaded" << std::endl;
    return false;
  }

  if (!menu_layer.addSpriteComponent(renderer.get(),
                                     "data/Textures/Backdrops/menu.jpg"))
  {
    std::cout << "Menu not loaded" << std::endl;
    return false;
  }

  for (int i = 0; i < NUM_OF_BIRDS; i++)
  {
    if (birds[i].addSpriteComponent(renderer.get(), "data/Textures/parrot.png"))
    {
      birds[i].setUpBird(float(i * 60) + 20, 850, 50, vector2(0, 0), 0, 50);
    }
    else
    {
      std::cout << "Bird Sprite " << i << " not loaded" << std::endl;
      return false;
    }
  }

  birds[current_bird].spriteComponent()->getSprite()->xPos(250);
  birds[current_bird].spriteComponent()->getSprite()->yPos(700);

  return true;
}

bool Angry::loadBackgrounds()
{
  std::string filename = "data/Textures/Backdrops/lvl";
  filename += std::to_string(std::rand() % 3 + 1);
  filename += ".png";

  if (!background_layer.addSpriteComponent(renderer.get(), filename))
  {
    return false;
  }

  return true;
}

/**
*   @brief   Sets the game window resolution
*   @details This function is designed to create the window size, any
             aspect ratio scaling factors and safe zones to ensure the
                         game frames when resolutions are changed in size.
*   @return  void
*/
void Angry::setupResolution()
{
  // how will you calculate the game's resolution?
  // will it scale correctly in full screen? what AR will you use?
  // how will the game be framed in native 16:9 resolutions?
  // here are some abritrary values for you to adjust as you see fit
  // https://tinyurl.com/y6sqbr78
  game_width = 1920;
  game_height = 1080;
}

/**
*   @brief   Processes any key inputs
*   @details This function is added as a callback to handle the game's
                         keyboard input. For this game, calls to this function
                         are thread safe, so you may alter the game's state as
you see fit.
*   @param   data The event data relating to key input.
*   @see     KeyEvent
*   @return  void
*/
void Angry::keyHandler(const ASGE::SharedEventData data)
{
  auto key = static_cast<const ASGE::KeyEvent*>(data.get());

  if (key->key == ASGE::KEYS::KEY_ESCAPE)
  {
    signalExit();
  }

  else if (key->key == ASGE::KEYS::KEY_ENTER &&
           key->action == ASGE::KEYS::KEY_PRESSED && key->mods == 0x0004)
  {
    if (renderer->getWindowMode() == ASGE::Renderer::WindowMode::WINDOWED)
    {
      renderer->setWindowedMode(ASGE::Renderer::WindowMode::FULLSCREEN);
    }
    else
    {
      renderer->setWindowedMode(ASGE::Renderer::WindowMode::WINDOWED);
    }
  }

  else if (in_menu && key->key == ASGE::KEYS::KEY_SPACE)
  {
    in_menu = !in_menu;
  }
}

/**
*   @brief   Processes any click inputs
*   @details This function is added as a callback to handle the game's
                     mouse button input. For this game, calls to this function
             are thread safe, so you may alter the game's state as you
             see fit.
*   @param   data The event data relating to key input.
*   @see     ClickEvent
*   @return  void
*/
void Angry::clickHandler(const ASGE::SharedEventData data)
{
  auto click = static_cast<const ASGE::ClickEvent*>(data.get());
  double x_pos = click->xpos;
  double y_pos = click->ypos;

  // If have clicked on bird
  if (click->action == ASGE::MOUSE::BUTTON_PRESSED &&
      birds[current_bird].spriteComponent()->getBoundingBox().isInside(
        float(x_pos), float(y_pos)))
  {
    clicked_on_bird = true;
  }
  else if (click->action == ASGE::MOUSE::BUTTON_RELEASED && clicked_on_bird)
  {
    clicked_on_bird = false;
    // Release bird
  }

  ASGE::DebugPrinter() << x_pos << "," << y_pos << std::endl;
}

/**
*   @brief   Updates the scene
*   @details Prepares the renderer subsystem before drawing the
                     current frame. Once the current frame is has finished
                     the buffers are swapped accordingly and the image shown.
*   @return  void
*/
void Angry::update(const ASGE::GameTime& game_time)
{
  // make sure you use delta time in any movement calculations!
  // auto dt_sec = game_time.delta.count() / 1000.0;

  if (!in_menu)
  {
    if (clicked_on_bird)
    {
      // Update bird position
      inputs->getCursorPos(mouse_x, mouse_y);
      birds[current_bird].spriteComponent()->getSprite()->xPos(
        float(mouse_x) -
        birds[current_bird].spriteComponent()->getSprite()->width() / 2);
      birds[current_bird].spriteComponent()->getSprite()->yPos(
        float(mouse_y) -
        birds[current_bird].spriteComponent()->getSprite()->height() / 2);

      // Limit bird movement
      if (mouse_x < 50 + birds[current_bird].spriteComponent()->getSprite()->width() / 2)
      {
        birds[current_bird].spriteComponent()->getSprite()->xPos(50);
      }
      else if (mouse_x >
               250 +
                 birds[current_bird].spriteComponent()->getSprite()->width() / 2)
      {
        birds[current_bird].spriteComponent()->getSprite()->xPos(250);
      }
      if (mouse_y < 650)
      {
        birds[current_bird].spriteComponent()->getSprite()->yPos(650 - birds[current_bird].spriteComponent()->getSprite()->height() / 2);
      }
      else if (mouse_y > 800 + birds[current_bird].spriteComponent()->getSprite()->height() / 2)
      {
        birds[current_bird].spriteComponent()->getSprite()->yPos(800);
      }
    }

    for (int i = 0; i < NUM_OF_BIRDS; i++)
    {
      if (birds[i].released() == true)
      {
        birds[i].update(game_time.delta.count() / 1000.0f);
      }
    }
  }
}

/**
*   @brief   Renders the scene
*   @details Renders all the game objects to the current frame.
                 Once the current frame is has finished the buffers are
                         swapped accordingly and the image shown.
*   @return  void
*/
void Angry::render(const ASGE::GameTime& game_time)
{
  renderer->setFont(0);

  if (in_menu)
  {
    renderer->renderSprite(*menu_layer.spriteComponent()->getSprite());
  }
  else
  {
    renderer->renderSprite(*background_layer.spriteComponent()->getSprite());

    for (int i = 0; i < NUM_OF_BIRDS; i++)
    {
      renderer->renderSprite(*birds[i].spriteComponent()->getSprite());
    }
  }
}

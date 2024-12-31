#pragma once

#include "graphics/renderer.h"
#include "input/InputManager.h"

class Engine
{
public:
  void init();    // Initializes the engine state.
  void run();     // Main loop
  void cleanup(); // Cleanup resources.

private:
  // Where the renderer and input manager will go next.

};
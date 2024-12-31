#include "Engine.h"
#include <iostream>

void Engine::init()
{
  std::cout << "Engine initialized.\n";
}

void Engine::run()
{
  std::cout << "Engine is now running.\n";
}

void Engine::cleanup()
{
  std::cout << "Engine resources have been resolved.\n";
}
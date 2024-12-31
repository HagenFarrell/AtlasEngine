#include "renderer.h"
#include <iostream>
#include <stdexcept>

Renderer::Renderer()
{
  // Logic for the contructor
}

Renderer::~Renderer()
{
  cleanup();
}

void Renderer::init()
{
  try
  {
    createInstance();
    pickPhysicalDevice();
    createLogicalDevice();
    createSwapchain();
    createCommandbuffers();
    initialized = true;
    std::cout << "Renderer initialized successfully.\n";
  }
  catch (const std::exception &e)
  {
    std::cerr << "Renderer initialization failed: " << e.what() << '\n';
    cleanup();
  }
}
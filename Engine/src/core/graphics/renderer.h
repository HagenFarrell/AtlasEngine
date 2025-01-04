#pragma once

#include <vulkan/vulkan.h>
#include <vector>

class Renderer
{
  public:

    Renderer();
    ~Renderer();

    void init();
    void cleanup();

    void renderFrame();
    bool isInitialized() const;

  private:

    // Helper functions
    void createInstance();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSwapchain();
    void createCommandbuffers();


    // Vulkan objects
    VkInstance instance;
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    VkSwapchainKHR swapchain;
    std::vector<VkCommandBuffer> commandBuffers;

    // State tracking
    bool initialized = false;
};
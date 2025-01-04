#include "Renderer.h"
#include <iostream>
#include <stdexcept>
#include <map>

Renderer::Renderer()
{
  // Constructor logic
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
    std::cout << "Renderer initialized successfully." << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << "Renderer initialization failed: " << e.what() << std::endl;
    cleanup();
  }
}

void Renderer::cleanup()
{
  if (device != VK_NULL_HANDLE)
  {
    vkDeviceWaitIdle(device);
  }
  // Destroy Vulkan resources in reverse order of creation
  if (!commandBuffers.empty())
  {
    // Command buffers are implicitly freed when the command pool is destroyed
  }
  if (swapchain != VK_NULL_HANDLE)
  {
    vkDestroySwapchainKHR(device, swapchain, nullptr);
  }
  if (device != VK_NULL_HANDLE)
  {
    vkDestroyDevice(device, nullptr);
  }
  if (instance != VK_NULL_HANDLE)
  {
    vkDestroyInstance(instance, nullptr);
  }
  initialized = false;
  std::cout << "Renderer resources cleaned up." << std::endl;
}

void Renderer::renderFrame()
{
  if (!initialized)
  {
    throw std::runtime_error("Renderer is not initialized.");
  }
  // Record and submit command buffers for rendering
  std::cout << "Rendering frame..." << std::endl;
}

bool Renderer::isInitialized() const
{
  return initialized;
}

// Helper function implementations

void Renderer::createInstance()
{
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Vulkan Engine";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
  {
    throw std::runtime_error("Failed to create Vulkan instance.");
  }
  std::cout << "Vulkan instance created." << std::endl;
}

void Renderer::pickPhysicalDevice()
{
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  uint32_t deviceCount = 0;

  // Enumerates physical devices so we can query its properties.
  vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

  if (deviceCount == 0)
    throw std::runtime_error("failed to find GPUs with Vulkan support!");

  
  std::vector<VkPhysicalDevice> devices(deviceCount);
  vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

  std::multimap<int, VkPhysicalDevice> canidates;

  for (const auto &device : devices)
  {
    int score = ratePhysicalDevice(device);
    canidates.insert(std::make_pair(score, device));
  }

  // Uses iterator to go through and find positive scores (valid scores)
  // Then selects the most powerful graphics unit available.
  if(canidates.rbegin()->first > 0)
  {
    physicalDevice = canidates.rbegin()->second;
  } else {
    throw std::runtime_error("failed to find a suitable GPU!");
  }

}

bool ratePhysicalDevice(VkPhysicalDevice device)
{
  VkPhysicalDeviceProperties deviceProperties;
  VkPhysicalDeviceFeatures deviceFeatures;

  // Does exactly what it looks like it does hehe
  vkGetPhysicalDeviceProperties(device, &deviceProperties);
  vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

  return deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU
   && deviceFeatures.geometryShader;
}

void Renderer::createLogicalDevice()
{
  // Logic for creating the logical device and queues
  std::cout << "Logical device created." << std::endl;
}

void Renderer::createSwapchain()
{
  // Logic for creating the swapchain
  std::cout << "Swapchain created." << std::endl;
}

void Renderer::createCommandbuffers()
{
  // Logic for creating command buffers
  std::cout << "Command buffers created." << std::endl;
}